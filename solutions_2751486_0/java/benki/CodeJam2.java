import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import javax.swing.text.DefaultEditorKit.CutAction;

public class CodeJam2 {
    
    static double[][] value ; 
    
    public static void main(String[] args) throws IOException {

        BufferedReader reader = new BufferedReader(new FileReader(new File(
                 "/home/girish/Desktop/coding/codejam/input")));
        BufferedWriter writer = new BufferedWriter(new FileWriter(new File(
                "/home/girish/Desktop/coding/codejam/output")));
        
         int t = Integer.parseInt(reader.readLine());
         for (int i = 1; i <= t; i++) {
             String input  = reader.readLine();
             String[] tokens = input.split(" ");
             String inStr = tokens[0];
             int N = Integer.parseInt(tokens[1]);
             long finalAns = getAns(N,inStr);
             writer.write("Case #" + i + ": "+finalAns+"\n");
             //System.out.print("Case #" + i + ": ");
             //System.out.println(finalAns);    
         }
         writer.close();
    }

    private static void init(int N) {
        // TODO Auto-generated method stub
        value = new double[100][100];
        for(int i =0;i<value.length;i++){
            for(int j = 0;j<value[i].length;j++){
                value[i][j] = 0;
            }
        }
        
        for(int i =0;i<N;i++){
            
            for(int k =N;k>=0;k--){
                if(value[0][k] == 0){
                    k--;
                }
            }
        }
        
    }
    
    

    private static long getAns(int N, String inStr) {
       // System.out.println(A);
       // System.out.println(N);
       // System.out.println(values);
        long ans = 0;
        List<Long> numList = new ArrayList<Long>();
        List<Integer> lastR = new ArrayList<Integer>();
        long ct = 0;
        
        char ch = inStr.charAt(0);
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            
        }else
            ct++;

        if(ct >= N){
            lastR.add(0);
        }else
            lastR.add(-1);
        
        for(int i = 1;i<inStr.length();i++){
            
            ch = inStr.charAt(i);
            
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                if(ct > 0){
                    numList.add(ct);
                    ct =0;
                }
            }else
                ct++;
            
            if(ct >= N){
                lastR.add(i-N+1);
            }else
                lastR.add(lastR.get(i-1));
        }
        
        if(ct > 0){
            numList.add(ct);
            ct =0;
        }
        
        for(int i = 0;i<lastR.size();i++){
            long v = lastR.get(i);
            //long ans1 = 
            ans = ans + v+1;
        }
        
        
        return ans;
    }

    private static long getValue(long v, int n) {
        if(v < n)
            return 0;
        if(v == n)
            return 1;
        
        long temp = (v-n+1)*(v-n+2);
        temp = temp/2;
        
        return temp;
    }
    
}

