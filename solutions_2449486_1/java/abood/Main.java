/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

/**
 *
 * @author abood
 */
public class Main{

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
        int loop=Integer.parseInt(br.readLine());
        StringTokenizer st;
        int grid[][];
        L: for (int i = 1; i <=loop; i++) {
            st=new StringTokenizer(br.readLine());
            int rows=Integer.parseInt(st.nextToken());
            int cols=Integer.parseInt(st.nextToken());
            grid=new int[rows][cols];
            int maxrow[]=new int [rows];
            int maxcol[]=new int [cols];
            for (int j = 0; j < rows; j++) {
                st=new StringTokenizer(br.readLine());
                for (int k = 0; k < cols; k++) {
                    grid[j][k]=Integer.parseInt(st.nextToken());
                    maxrow[j]=Math.max(maxrow[j], grid[j][k]);
                    maxcol[k]=Math.max(maxcol[k], grid[j][k]);
                }
                
            }
            for (int j = 0; j < rows; j++) {
                for (int k = 0; k < cols; k++) {
                    if(grid[j][k]<maxrow[j]&&grid[j][k]<maxcol[k]){
                        out.printf("Case #%d: NO\n",i);
                        continue L;
                    }
                }
               
            }
            out.printf("Case #%d: YES\n",i);
        }
   out.close();                             
    System.exit(0);    
    }
}
