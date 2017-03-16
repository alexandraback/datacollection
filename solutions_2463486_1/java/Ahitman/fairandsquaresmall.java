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
import java.math.BigInteger;
import java.util.StringTokenizer;

/**
 *
 * @author hp
 */
public class fairandsquaresmall {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fstream = new FileInputStream("E:/Users/hp/Documents/NetBeansProjects/codejam/src/codejam/C-large-1.in");
        DataInputStream in = new DataInputStream(fstream);
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        BigInteger[] no = new BigInteger[50];
        FileInputStream fstream2 = new FileInputStream("E:/Users/hp/Documents/NetBeansProjects/codejam/src/codejam/data.txt");
        DataInputStream in2 = new DataInputStream(fstream2);
        BufferedReader br2 = new BufferedReader(new InputStreamReader(in2));
        for(int x=0;x<no.length;x++){
            no[x] = new BigInteger(br2.readLine());
        }
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            String a = br.readLine();
            StringTokenizer st1 = new StringTokenizer(a);
            BigInteger m = new BigInteger(st1.nextToken());
            BigInteger n = new BigInteger(st1.nextToken());
            int y;
            int count=0;
            for(y=0;y<no.length;y++){
                if(no[y].compareTo(m)==-1) continue;
                if(no[y].compareTo(m)>=0 && no[y].compareTo(n)<=0) count = count+1;
                if(no[y].compareTo(n)==1) break;
            }
            System.out.println("Case #"+i+": "+count);
            
        }
    }
}
