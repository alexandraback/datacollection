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

/**
 *
 * @author hp
 */
public class fairandsquaresmall {
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream fstream = new FileInputStream("E:/Users/hp/Documents/NetBeansProjects/codejam/src/codejam/C-small-attempt0.in");
        DataInputStream in = new DataInputStream(fstream);
        BufferedReader br = new BufferedReader(new InputStreamReader(in));
        int cases = Integer.parseInt(br.readLine());
        for (int i = 1; i <= cases; i++) {
            String a = br.readLine();
            StringTokenizer st1 = new StringTokenizer(a);
            int n = Integer.parseInt(st1.nextToken());
            int m = Integer.parseInt(st1.nextToken());
            int l = (int) Math.ceil(Math.sqrt(n));
            int count = 0;
            while(true){
                if(l*l>m) break;
                if(l%10==0){
                    l=l+1;
                    continue;
                }
                String p = Integer.toString(l);
                char[] p2 = p.toCharArray();
                int j;
                for(j=0;j<p.length();j++){
                    if(p2[j] != p2[p.length()-1-j])break;
                }
                if(j<p.length()){
                    l=l+1;
                    continue;
                }
                int k=l*l;
                if(k%10==0){
                    l=l+1;
                    continue;
                }
                p = Integer.toString(k);
                char[] p3 = p.toCharArray();
                j=0;
                for(j=0;j<p.length();j++){
                    if(p3[j] != p3[p.length()-1-j])break;
                }
                if(j<p.length()){
                    l=l+1;
                    continue;
                }
                count=count+1;
                l=l+1;
            }
            System.out.println("Case #"+i+": "+count);
        }
    }
}
