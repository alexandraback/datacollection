/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }
    
    long [] v;
    long e,r,n;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/B-small-attempt1.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            e = Long.parseLong(split[0]);
            r = Long.parseLong(split[1]);
            n = Long.parseLong(split[2]);
            v = new long[(int) n];
            split = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                v[i] = Long.parseLong(split[i]);
            }
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Long.toString(rec(0, (int)(n-1), e, r)));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
    
    public long rec(int left, int right, long startValue, long endValue){
        // (maxLoc-left+1)*r >= e
        if(left>right) return 0;
        if(left == right) return (startValue-endValue+r)*v[left];
        int maxLoc = left;
        for (int i = left+1; i <= right; i++) {
            if(v[i]>v[maxLoc])
                maxLoc = i;
        }
        long result;
        if(endValue > r){
            if((right - maxLoc+1)*r >= endValue){
                result = rec(left, maxLoc-1, startValue, e) + e*v[maxLoc] + rec(maxLoc+1, right, r, endValue);
            } else {
                result = rec(left, maxLoc-1, startValue, endValue-(right - maxLoc)*r) + (right - maxLoc+1)*r*v[maxLoc];
            }
        } else {
            if((maxLoc-left)*r + startValue >= e){
                result = rec(left, maxLoc-1, startValue, e)+e*v[maxLoc]+rec(maxLoc+1, right, r, endValue);
            } else {
                result = ((maxLoc-left)*r + startValue)*v[maxLoc]+rec(maxLoc+1, right, r, endValue);
            }
        }
        return result;
    }
    
    public class Timer{
        long start;
        void start(){
            start = System.nanoTime();
        }
        double end(){
            return ((double)(System.nanoTime()-start))/1000000000;
        }
    }
}