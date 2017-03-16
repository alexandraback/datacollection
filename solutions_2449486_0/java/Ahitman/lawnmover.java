/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package codejam;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class lawnmover {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fstream = new FileInputStream("E:/Users/hp/Documents/NetBeansProjects/codejam/src/codejam/B-small-attempt0.in");
        DataInputStream in = new DataInputStream(fstream);
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            String a = br.readLine();
            StringTokenizer st1 = new StringTokenizer(a);
            int n = Integer.parseInt(st1.nextToken());
            int m = Integer.parseInt(st1.nextToken());
            int[][] lawn = new int[n][m];
            int[] rows = new int[n];
            int[] cols = new int[m];
            for(int j=0;j<n;j++){
                a = br.readLine();
                StringTokenizer st2 = new StringTokenizer(a);
                for(int k =0;k<m;k++){
                    int p = Integer.parseInt(st2.nextToken());
                    lawn[j][k]=p;
                    if(p>rows[j]) rows[j]=p;
                }
            }
            for(int k=0;k<m;k++){
                for(int j=0;j<n;j++){
                    if(lawn[j][k]>cols[k]) cols[k] = lawn[j][k];
                }
            }
            int j,k;
            for(j=0;j<n;j++){
                for(k=0;k<m;k++){
                    if(lawn[j][k]<rows[j]&&lawn[j][k]<cols[k]) break;
                }
                if(k<m) break;
            }
            System.out.print("Case #"+i+": ");
            if(j<n) System.out.print("NO");
            else    System.out.print("YES");
            System.out.print('\n');
        }
    }
}
