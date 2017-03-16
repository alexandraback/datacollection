/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2013;

import java.io.*;
import java.util.StringTokenizer;

/**
 *
 * @author Alejandro E. Garces
 */
public class GCJ2013 {

    /**
     * @param args the command line arguments
     */
    static char[][] board;
    static public boolean win(char player)
    {
        boolean answer = true;
        
        for(int i=0;i<4;i++)
        {
            answer = true;
            for(int j=0;j<4;j++)
                answer&=(board[i][j] == player ||board[i][j] == 'T');
            if(answer)return true;
        }
        
        for(int i=0;i<4;i++)
        {
            answer = true;
            for(int j=0;j<4;j++)
                answer&=(board[j][i] == player ||board[j][i] == 'T');
            if(answer)return true;
        }
        
        answer = true;
        for(int i=0;i<4;i++)
             answer&=(board[i][4-1-i] == player ||board[i][4-1-i] == 'T');
        
        if(answer)return true;
        
        answer = true;
        for(int i=0;i<4;i++)
             answer&=(board[i][i] == player ||board[i][i] == 'T');
        
        return answer;
    }
    
    static int count()
    {
        int answer = 0;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)if(board[i][j]=='.')answer++;
        
        return answer;
    }
    
    public static void main(String[] args) throws IOException {
        String file = "A-large";
        String line = "";
        StringTokenizer r;
        
        System.setIn(new FileInputStream(file+".in"));
        System.setOut(new PrintStream(new FileOutputStream(file+"O.out")));
        
        /////////////////////
        //Input from Console
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        //Scanner in = new Scanner(System.in);
        
        /////////////////////
        //Input from file
        //BufferedReader in = new BufferedReader(new FileReader(file+".txt"));
        //Scanner in = new Scanner(new File(file+".txt"));
        //FileWriter archivo = new FileWriter(file+"O.txt");
        //PrintWriter out = new PrintWriter(archivo);
        //out.flush();
        ////////////////////
        
        int cases = Integer.parseInt(in.readLine());
        int answer = -1;
        String[] toPrint = {"X won","O won","Draw", "Game has not completed"};
        for(int cc=1;cc<=cases;cc++)
        {
            board = new char[4][4];
            for(int i=0;i<4;i++)
                board[i] = in.readLine().toCharArray();
            
            boolean winO = win('O');
            boolean winX = win('X');
           // System.out.println(winO+" - "+winX);
            if(winO == true && winX == true)answer = 2;
            else if(winO == false && winX == false)
            {
                answer = 3;
                if(count() == 0)answer = 2;
            }
            else if(winO == true && winX == false)answer = 1;
            else answer = 0;
            
            System.out.println("Case #"+cc+": "+toPrint[answer]);
            in.readLine();
        }
        
        
        in.close();
        System.exit(0);
    }
}
