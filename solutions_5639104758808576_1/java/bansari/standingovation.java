/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import static googlecodejam.treasure.tkeys;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 *
 * @author Bansari
 */
public class standingovation {
      public static void main(String ar[]) throws Exception{
        BufferedReader f = new BufferedReader(new FileReader("standingovation.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
        int totacases = Integer.parseInt(f.readLine());
        for(int a = 0;a<totacases;a++){
            StringTokenizer st = new StringTokenizer(f.readLine());
            int smax = Integer.parseInt(st.nextToken());
            String people = st.nextToken();
            int[] s = new int[smax+1];
            for(int j = 0;j<smax+1;j++){
                s[j] = Integer.parseInt(people.charAt(j)+"");
            }
//            int start = 0;
            int count = 0;
            int standingpeople = 0;
            
            for(int shynessfactor = 0;shynessfactor<smax+1;shynessfactor++){
               int ab = s[shynessfactor];//1
               if(shynessfactor == 0){
                   standingpeople=ab;
                   continue;
               }               
               if(shynessfactor > (standingpeople)){
                   count = count+1;
                   standingpeople = standingpeople+1+ab;
               }else{
                   standingpeople = standingpeople+ab;//st=1
               }                
            }
            System.out.println("Case #"+(a+1)+": "+count); 
            out.println("Case #"+(a+1)+": "+count);
        }
        f.close();
        out.close();
        
    }
}
