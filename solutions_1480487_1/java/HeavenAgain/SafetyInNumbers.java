import java.io.*;
import java.util.*;

public class SafetyInNumbers{
    public static void main(String[] args) throws Exception{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        
        int n = Integer.parseInt(in.readLine());
        
        for(int i = 0; i < n; ++i){
            StringTokenizer st = new StringTokenizer(in.readLine());
            int total = Integer.parseInt(st.nextToken());
            int[] score = new int[total];
            int sum = 0;
            for(int j = 0; j < total; ++j){
                score[j] = Integer.parseInt(st.nextToken());
                sum += score[j];
            }
            double spare = sum;
            double temp = sum;
            sum += sum;
            double average = sum*1.0/total;
            boolean good = true;
            while(good){
                good = false;
                spare = temp;
                for(int j = 0; j < total; ++j){
                    if(score[j] >= average){
                        spare -= score[j]-average;
                    }
                }
                good = average != (spare+temp)/total;
                average = (spare+temp)/total;
            }
            double[] ans = new double[total];
            for(int j = 0; j < total; ++j){
                if(score[j] < average){
                    ans[j] = (average-score[j])/(sum/2)*100;
                }
            }
            out.print("Case #"+(i+1)+":");
            for(int j = 0; j < total; ++j){
                out.printf(" %.6f", ans[j]);
            }
            out.println();
        }
        out.close();
    }
}

    