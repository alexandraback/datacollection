package Jam2012.R1C;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

/**
 *
 * @author alei
 */
public class A1 {
     public static void main(String[]Args) throws FileNotFoundException{
        Scanner sn = new Scanner(new FileInputStream("A-small-attempt.in"));
        System.setOut(new PrintStream("A-small-attempt.out"));
        int nCases = sn.nextInt();        
        for (int i = 0; i < nCases; i++) {
            sn.nextLine();
            int nClasses = sn.nextInt();
            sn.nextLine();
            int[][]g = new int[nClasses][nClasses];
            for (int j = 0; j < nClasses; j++) {                
                int nInh = sn.nextInt();
                for (int k = 0; k < nInh; k++) {                    
                    int cl = sn.nextInt();
                    g[j][cl-1] = 1;
                }                
            }    
            //printMatr(g);
            boolean is =  isDiamond(g,nClasses,0,nClasses-1);
            String msg = is?"Yes":"No";
            System.out.println("Case #"+(i+1+": "+msg));
            
        }
        
    }
     public static void printMatr(int[][]m){
         for (int i = 0; i < m.length; i++) {
             if(i==0){
                  for(int j = 0; j < m[i].length; j++){
                      if(j==0){
                          System.out.print("  ");
                      }
                      System.out.print(" "+(j+1)%10);
                  }
                  System.out.println();
             }             
             for (int j = 0; j < m[i].length; j++) {                 
                 if(j==0){
                     System.out.print((i+1)%10+"]");
                 }
                 System.out.print(" "+m[i][j]);
             }
             System.out.println();
         }
     }
             
    public static boolean isDiamond(int[][] g,int size,int start,int end){
        int[][] s = new int[size][size];
        boolean is = false;
        int[]processedRows = new int[size];
        /*
        for(int i=0;i<g.length;i++){
            for (int j = i+1; j < g.length && !is; j++) {
                if(j!=i){
                    is = fillRow(s, g, j,processedRows);
                }                
            }   
        }        
        */
        for (int i = 0; i < size && !is; i++) {
            is = fillRow(s,g,i,processedRows);                        
        }
        //System.out.println("sols:");
        //printMatr(s);
        return is;
    }
    public static boolean fillRow(int[][]s,int[][]g,int start,int[]prs){
        boolean is = false;
        if(prs[start]==1){            
        }
        else{            
            for (int j = 0; j < g.length && !is; j++) {
                //if(j!=start){
                if(g[start][j]==1 && j!=start){
                    is = fillRow(s, g, j,prs);
                }                
            }
            for (int j = 0; j < g.length && !is; j++) {
                if(j!=start){
                    if(g[start][j]==1){
                        s[start][j] += 1;
                    }
                    for (int i =0; i < g.length; i++) {
                        if(g[start][i]==1 && i!=j){
                            s[start][j] += s[i][j];      
                        }                    
                    }
                    if(s[start][j]>=2){
                        is = true;
                    }   
                }                
            }        
            prs[start] = 1;
            //System.out.println("fillingRow->"+(start+1));
                    
            //printMatr(s);
        }        
        return is;            

    }
    
}
