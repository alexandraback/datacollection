/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package tictactoe;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

/**
 *
 * @author Rizal ZAF
 */
public class Lawnmower {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        
        BufferedReader br = null;        
                    
        br = new BufferedReader(new FileReader("B-large.in"));
        FileWriter writer = new FileWriter("lawnmower.out");
        
        int num = Integer.parseInt(br.readLine().trim());
        
        for (int i=0;i<num;i++){
            String[] nm = br.readLine().split(" ");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            
            int[][] lawn = new int[n][m];            
            for(int j=0;j<n;j++){
                String[] st = br.readLine().split(" ");
                for(int k=0;k<m;k++){
                    lawn[j][k] = Integer.parseInt(st[k]);
                }
            }    
            
            boolean valid = true;
            for(int j=0;j<n;j++){                
                for(int k=0;k<m;k++){
                    boolean lh = legalHorizontal(lawn, j, k, n, m);
                    boolean lv = legalVertical(lawn, j, k, n, m);
                    if (!(lh || lv)) {
                        valid = false;
                        break;
                    }
                }
            }
            
            if (valid){
                writer.write("Case #" + (i+1) + ": YES\r\n");
            }
            else{
                writer.write("Case #" + (i+1) + ": NO\r\n");
            }
        }
        
        writer.close();
    }
    
    public static boolean legalHorizontal(int[][] inp, int ni, int mi, int n, int m){
        boolean result = true;
        
        for (int k=0;k<m;k++){
            if (inp[ni][k] > inp[ni][mi]){
                result = false;
                break;
            }
        }
        
        return result;
    }
    
    public static boolean legalVertical(int[][] inp, int ni, int mi, int n, int m){
        boolean result = true;
        
        for (int j=0;j<n;j++){
            if (inp[j][mi] > inp[ni][mi]){
                result = false;
                break;
            }
        }
        
        return result;
    }
    
}
