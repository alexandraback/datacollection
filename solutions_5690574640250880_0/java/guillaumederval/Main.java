import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Queue;
import java.util.Scanner;
import java.util.TreeSet;


public class Main
{
    public static int countM;
    public static int countWhite;
    public static int countCursor;
    public static int countLine;
    public static int countSinceLastLine;
    
    public static int[][] data;
    public static int curLine;
    public static int curCol;
    
    
    public static void outputM(PrintWriter out)
    {
        countM++;
        countSinceLastLine++;
        out.print("*");
        data[curLine][curCol] = 1; curCol++;
    }
    
    public static void outputWhite(PrintWriter out)
    {
        countWhite++;
        countSinceLastLine++;
        out.print(".");
        data[curLine][curCol] = 0; curCol++;
    }
    
    public static void outputCursor(PrintWriter out)
    {
        countCursor++;
        countSinceLastLine++;
        out.print("c");
        data[curLine][curCol] = 2; curCol++;
    }
    
    public static void outputEndLine(PrintWriter out, int C)
    {
        countLine++;
        if(countSinceLastLine != C)
            System.out.println("WTF COUNT C");
        countSinceLastLine = 0;
        curLine++;
        curCol = 0;
        out.println();
    }
    
    public static class Pos
    {
        int x;
        int y;
        public Pos(int x, int y)
        {
            this.x = x;
            this.y = y;
        }
    }
    
    public static void verify(PrintWriter out, int R, int C, int M)
    {
        if(countCursor == 0)
        {
            System.out.println("WTF NO CURSOR!");
            out.println("WTF NO CURSOR!");
        }
        if(countCursor > 1)
        {
            System.out.println("WTF MORE THAN ONE CURSOR!");
            out.println("WTF MORE THAN ONE CURSOR!");
        }
        if(countM != M)
        {
            System.out.println("WTF PROBLEMS WITH MINES");
            out.println("WTF PROBLEMS WITH MINES");
        }
        if(countM + countWhite + countCursor != R*C)
        {
            System.out.println("WTF PROBLEMS WITH COUNT " + countM + " " + countWhite + " " + countCursor);
            out.println("WTF PROBLEMS WITH COUNT " + countM + " " + countWhite + " " + countCursor);
        }
        if(countLine != R)
        {
            System.out.println("WTF PROBLEMS WITH NUMBER OF LINE!");
            out.println("WTF PROBLEMS WITH NUMBER OF LINE!");
        }
        
        Queue<Pos> todo = new LinkedList<Pos>();
        todo.add(new Pos(R-1, C-1));
        while(!todo.isEmpty())
        {
            Pos pos = todo.poll();
            boolean recur = true;
            for(int i = -1; i <= 1; i++)
                for(int j = -1; j <= 1; j++)
                    if(pos.x+i >= 0 && pos.x+i < R && pos.y+j >= 0 && pos.y+j < C)
                        if(data[pos.x+i][pos.y+j] == 1)
                            recur = false;
            if(recur)
            {
                for(int i = -1; i <= 1; i++)
                    for(int j = -1; j <= 1; j++)
                        if(pos.x+i >= 0 && pos.x+i < R && pos.y+j >= 0 && pos.y+j < C)
                            if(data[pos.x+i][pos.y+j] == 0)
                            {
                                data[pos.x+i][pos.y+j] = 2;
                                todo.add(new Pos(pos.x+i, pos.y+j));
                            }
            }
        }
        for(int i = 0; i < R; i++)
            for(int j = 0; j < C; j++)
                if(data[i][j] == 0)
                    System.out.println("OMG WTF!");
    }
    
    public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException
    {
        //Scanner scan = new Scanner(System.in);
        //PrintStream out = System.out;
        
        Scanner scan = new Scanner(new BufferedReader(new FileReader("/Users/guillaumederval/Desktop/C-small-attempt3.in")));
        PrintWriter out = new PrintWriter (new BufferedWriter(new OutputStreamWriter( new FileOutputStream("/Users/guillaumederval/Desktop/out.txt"), "utf-8")));
        scan.useLocale(Locale.US);
        int nbTests = scan.nextInt();
        for (int test = 0; test < nbTests; test++)
        {
            int R = scan.nextInt();
            int C = scan.nextInt();
            int M = scan.nextInt();
            
            countM = 0;
            countWhite = 0;
            countCursor = 0;
            countLine = 0;
            countSinceLastLine = 0;
            data = new int[R][C];
            curLine = 0;
            curCol = 0;
            
            int curR = R;
            int curC = C;
            int curM = M;
            while(curM != 0)
            {
                if(curR <= curM && curC <= curM)
                {
                    if(curR > curC)
                    {
                        curR--;
                        curM -= curC;
                    }
                    else
                    {
                        curC--;
                        curM -= curR;
                    }
                }
                else if(curR <= curM)
                {
                    curC--;
                    curM -= curR;
                }
                else if(curC <= curM)
                {
                    curR--;
                    curM -= curC;
                }
                else
                    break;
            }
            
            out.println("Case #"+(test+1)+":");
            //out.println(R + " " + C + " " + M);
            //out.println(curR + " " + curC + " " + curM);
            
            if(curC == 1 && curR == 1) //curM is 0
            {
                for(int i = 0; i < R-curR; i++)
                {
                    for(int j = 0; j < C; j++)
                        outputM(out);
                    outputEndLine(out,C);
                }
                for(int j = 0; j < C-curC; j++)
                    outputM(out);
                outputCursor(out);
                outputEndLine(out,C);
                verify(out, R, C, M);
                continue;
            }
            
            if((curC == 2 || curR == 2) && !(curC >= 2 && curR >= 2 && curM == 0))
            {
                if(curC == 1 && C == 1)
                {
                    for(int i = 0; i < M; i++)
                    { outputM(out); outputEndLine(out,C); }
                    for(int i = 0; i < R-M-1; i++)
                    { outputWhite(out); outputEndLine(out,C); }
                    outputCursor(out); outputEndLine(out,C);
                    verify(out, R, C, M);
                }
                else if(curR == 1 && R == 1)
                {
                    for(int i = 0; i < M; i++)
                        outputM(out);
                    for(int i = 0; i < C-M-1; i++)
                        outputWhite(out);
                    outputCursor(out); outputEndLine(out,C);
                    verify(out, R, C, M);
                }
                else if(curR == 2 && R == 2 && curC > 1 && curM == 0)
                {
                    for(int i = 0; i < M/2; i++)
                        outputM(out);
                    for(int i = 0; i < C-M/2; i++)
                        outputWhite(out);
                    outputEndLine(out,C);
                    for(int i = 0; i < M/2; i++)
                        outputM(out);
                    for(int i = 0; i < C-M/2-1; i++)
                        outputWhite(out);
                    outputCursor(out); outputEndLine(out,C);
                    verify(out, R, C, M);
                }
                else if(curC == 2 && C == 2 && curR > 1 && curM == 0)
                {
                    for(int i = 0; i < M/2; i++)
                    {
                        outputM(out);
                        outputM(out);
                        outputEndLine(out,C);
                    }
                    for(int i = 0; i < R-M/2-1; i++)
                    {
                        outputWhite(out);
                        outputWhite(out);
                        outputEndLine(out,C);
                    }
                    outputWhite(out);
                    outputCursor(out);
                    outputEndLine(out,C);
                    verify(out, R, C, M);
                }
                else
                {
                    out.println("Impossible");
                    System.out.println("Impossible 1: "+ curR + " " + curC + " " + curM);
                }
                continue;
            }
            
            if(curM <= Math.max(curR, curC)-2 && curR <= curC)
            {
                for(int i = 0; i < R-curR; i++)
                {
                    for(int j = 0; j < C; j++)
                        outputM(out);
                    outputEndLine(out,C);
                }
                for(int i = 0; i < curR; i++)
                {
                    for(int j = 0; j < C-curC; j++)
                        outputM(out);
                    if(i == 0)
                    {
                        for(int j = 0; j < curM; j++)
                            outputM(out);
                        for(int j = 0; j < curC-curM-1; j++)
                            outputWhite(out);
                        if(i == curR-1)
                            outputCursor(out);
                        else
                            outputWhite(out);
                    }
                    else if(i == curR-1)
                    {
                        for(int j = 0; j < curC-1; j++)
                            outputWhite(out);
                        outputCursor(out);
                    }
                    else
                    {
                        for(int j = 0; j < curC; j++)
                            outputWhite(out);
                    }
                    outputEndLine(out,C);
                }
                verify(out, R, C, M);
            }
            else if(curM <= Math.max(curR, curC)-2 && curR > curC)
            {
                for(int i = 0; i < R-curR; i++)
                {
                    for(int j = 0; j < C; j++)
                        outputM(out);
                    outputEndLine(out,C);
                }
                for(int i = 0; i < curR; i++)
                {
                    for(int j = 0; j < C-curC; j++)
                        outputM(out);
                    if(i < curM)
                        outputM(out);
                    else if(curC != 1)
                        outputWhite(out);
                    for(int j = 0; j < curC-2; j++)
                        outputWhite(out);
                    if(i == curR-1)
                        outputCursor(out);
                    else
                        outputWhite(out);
                    outputEndLine(out,C);
                }
                verify(out, R, C, M);
            }
            else //curM == Math.max(curR, curC)-1
            {
                if(curR < 5 || curC < 5)
                {
                    if(curR == 4 && curC == 4 && curM == 3)
                    {
                        for(int i = 0; i < R-curR; i++)
                        {
                            for(int j = 0; j < C; j++)
                                outputM(out);
                            outputEndLine(out,C);
                        }
                        for(int j = 0; j < C-curC; j++) outputM(out);
                        outputM(out);outputM(out);outputWhite(out);outputWhite(out);outputEndLine(out,C);
                        for(int j = 0; j < C-curC; j++) outputM(out);
                        outputM(out);outputWhite(out);outputWhite(out);outputWhite(out);outputEndLine(out,C);
                        for(int j = 0; j < C-curC; j++) outputM(out);
                        outputWhite(out);outputWhite(out);outputWhite(out);outputWhite(out);outputEndLine(out,C);
                        for(int j = 0; j < C-curC; j++) outputM(out);
                        outputWhite(out);outputWhite(out);outputWhite(out);outputCursor(out);outputEndLine(out,C);
                    }
                    else
                    {
                        out.println("Impossible");
                        System.out.println("Impossible 2: "+ curR + " " + curC + " " + curM + "|" + R + " " + C + " " + M);
                    }
                }
                else if(curR <= curC)
                {
                    for(int i = 0; i < R-curR; i++)
                    {
                        for(int j = 0; j < C; j++)
                            outputM(out);
                        outputEndLine(out,C);
                    }
                    for(int i = 0; i < curR; i++)
                    {
                        for(int j = 0; j < C-curC; j++)
                            outputM(out);
                        if(i == 0)
                        {
                            for(int j = 0; j < curM-1; j++)
                                outputM(out);
                            outputWhite(out);
                            outputWhite(out);
                        }
                        else if(i == curR-1)
                        {
                            outputM(out);
                            for(int j = 0; j < curC-2; j++)
                                outputWhite(out);
                            outputCursor(out);
                        }
                        else
                        {
                            for(int j = 0; j < curC; j++)
                                outputWhite(out);
                        }
                        outputEndLine(out,C);
                    }
                    verify(out, R, C, M);
                }
                else
                {
                    for(int i = 0; i < R-curR; i++)
                    {
                        for(int j = 0; j < C; j++)
                            outputM(out);
                        outputEndLine(out,C);
                    }
                    for(int i = 0; i < curR; i++)
                    {
                        for(int j = 0; j < C-curC; j++)
                            outputM(out);
                        if(i < curM-1)
                            outputM(out);
                        else
                            outputWhite(out);
                        for(int j = 0; j < curC-2; j++)
                            outputWhite(out);
                        if(i == curR-1)
                            outputCursor(out);
                        else if(i == 0)
                            outputM(out);
                        else
                            outputWhite(out);
                        outputEndLine(out,C);
                    }
                    verify(out, R, C, M);
                }
            }
        }
        out.close();
    }
}
