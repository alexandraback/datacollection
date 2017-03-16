/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package gcj2013;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 *
 * @author Alejandro E. Garces
 */
public class GCJ2013 {

  
    /**
     * @param args the command line arguments
     */
    static boolean checkR(int[][] board, int x, int r, int m)
    {
        for(int i=0;i<m;i++)
            if(board[r][i] != x)return false;
                
        return true;
    }
    
    static boolean checkC(int[][] board, int x, int c, int n)
    {
        for(int i=0;i<n;i++)
            if(board[i][c] != x)return false;
                
        return true;
    }
    public static void main(String[] args) throws IOException {
        String file = "B-small-attempt0";
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
        int[] minR, minC;
        for(int cc=1;cc<=cases;cc++)
        {
            answer = true;
            r = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(r.nextToken());
            int m = Integer.parseInt(r.nextToken());
            board = new int[n][m];
            minR = new int[n];
            minC = new int[m];
            Arrays.fill(minR, 1000);
            Arrays.fill(minC, 1000);
           // System.out.println(n+" - "+m);
                    
            for(int i=0;i<n;i++)
            {
                r = new StringTokenizer(in.readLine());
                //System.out.println(r.countTokens());
                for(int j=0;j<m;j++)
                    board[i][j] = Integer.parseInt(r.nextToken());
            
            }
            
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    minR[i] = Math.min(minR[i], board[i][j]);
                
            
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++)
                    minC[i] = Math.min(minC[i], board[j][i]);
                
            
            for(int i=0;i<n && answer;i++)
                for(int j=0;j<m && answer;j++)
                {
                    boolean ans1 = true;
                    boolean ans2 = true;
                    if(board[i][j] == minR[i]) ans1=checkR(board, minR[i], i, m)||checkC(board, minR[i], j, n);
                    if(board[i][j] == minC[j]) ans2=checkR(board, minC[j], i, m)||checkC(board, minC[j], j, n);
                    answer=ans1||ans2;
                    
                }
            
            System.out.println("Case #"+cc+": "+(answer?"YES":"NO"));
        }
        
        
        in.close();
        System.exit(0);
    }
}
