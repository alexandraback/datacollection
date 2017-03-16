/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam12;

import java.io.*;
import java.util.StringTokenizer;

/**
 *
 * @author Mohamed Ibrahim (MIM)
 */
public class Problem_B {
    public static void main(String[] args) throws IOException {
        
        BufferedReader r = new BufferedReader(new FileReader("B-large.in"));
        PrintWriter w = new PrintWriter(new BufferedWriter(new FileWriter("B-large.out")));
        
        int nCases = Integer.parseInt(r.readLine());
        
        for (Integer k = 1; k <= nCases; k++) {
            int ret=0;
            w.print("Case #" + k + ": ");
            String line=r.readLine();
            StringTokenizer st = new StringTokenizer(line);
            int n= Integer.parseInt(st.nextToken());
            int more= Integer.parseInt(st.nextToken());
            int p= Integer.parseInt(st.nextToken());
            
            for (int i = 0; i <n; i++) {
                int cur= Integer.parseInt(st.nextToken());
                int div=cur/3;
                int rem=cur-div*3;
                if(p==0){
                    ret=n;
                    break;
                }
                if(cur==0)continue;
                if(div>=p)ret++;
                else{
                    if(p-div==1 && rem>0)ret++;
                    else if(p-div==1 && more>0){
                        ret++;
                        more--;
                    }
                    else if(p-div==2 && rem==2 && more>0){
                        ret++;
                        more--;
                    }
         /*           else if(p-div==2 && more>0 && rem>0){
                        ret++;
                        more--;
                    }*/
                }
            }
            
            w.println(ret);
        }
        w.close();
        
        
    }
}
