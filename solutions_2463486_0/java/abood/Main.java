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
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 *
 * @author abood
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C-small-attempt0.out")));
         ArrayList<Long> nums=new ArrayList<Long>(100);
        for (long i = 1; i <= Long.parseLong("10000000"); i++) {
            
           if(isPal(i)&&isPal(i*i)){
              
                nums.add(i*i);
               // System.out.println(i*i);
           }
          
            
        }
        int loop=Integer.parseInt(br.readLine());
        StringTokenizer st;int count;long z;
        for (int K = 1; K <= loop; K++) {
            st=new StringTokenizer(br.readLine());
            Long A=Long.parseLong(st.nextToken());
            Long B=Long.parseLong(st.nextToken());
             count =0;
             for (int i = 0; i < nums.size(); i++) {
                z=nums.get(i);
                if(z>=A&&z<=B)count++;
                
            }
            out.printf("Case #%d: %d\n",K,count);
        }
   out.close();                             
    System.exit(0);    
    }
     public static boolean isPal(long  x){
        String y=""+x;
        int n=y.length()-1;
        for (int i = 0; i < y.length()/2; i++) {
            if(y.charAt(i)!=y.charAt(n-i))return false;
            
        }
        return true;
    }
}
