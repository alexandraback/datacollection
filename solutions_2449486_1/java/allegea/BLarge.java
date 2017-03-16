package gcj2013;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.*;
import java.util.*;
/**
 *
 * @author Alejandro E. Garces
 */
public class BLarge {

    /**
     * @param args the command line arguments
     */
    static boolean checkR(int[][] board, int x, int r, int m)
    {
        for(int i=0;i<m;i++)
        {
            if(board[r][i] == x || board[r][i] == 0)board[r][i] =0;
            else return false;
        }       
        return true;
    }
    
    static boolean checkC(int[][] board, int x, int c, int n)
    {
        for(int i=0;i<n;i++)
        {
            if(board[i][c] == x ||board[i][c] == 0)board[i][c] =0;
            else return false;
        }
                
        return true;
    }
    public static void main(String[] args) throws IOException {
        String file = "B-large";
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
        boolean answer = true;
        int[][] board;
        TreeSet<Integer> mini;
        for(int cc=1;cc<=cases;cc++)
        {
            answer = true;
            mini = new TreeSet<Integer>();
            r = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(r.nextToken());
            int m = Integer.parseInt(r.nextToken());
            board = new int[n][m];

           // System.out.println(n+" - "+m);
                    
            for(int i=0;i<n;i++)
            {
                r = new StringTokenizer(in.readLine());
                //System.out.println(r.countTokens());
                for(int j=0;j<m;j++)
                {
                    board[i][j] = Integer.parseInt(r.nextToken());
                    mini.add(board[i][j]);
                }
            
            }
            
            boolean out = false;
            for(int x:mini)
            {
                for(int i=0;i<n && !out;i++)
                    for(int j=0;j<m && !out;j++)
                        if(board[i][j] == x)
                        {
                            boolean ans1 = checkR(board, x, i, m)||checkC(board, x, j, n);
                            if(ans1 == false)out = true;
                        }
                if(out)break;
            }
            
            for(int i=0;i<n && answer;i++)
                    for(int j=0;j<m && answer;j++)
                        if(board[i][j]>0)answer=false;

            
            System.out.println("Case #"+cc+": "+(answer?"YES":"NO"));
        }
        
        
        in.close();
        System.exit(0);
    }
}
