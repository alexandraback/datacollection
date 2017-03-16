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
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/A-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        BigInteger TWO = BigInteger.valueOf(2);
        BigInteger FOUR = BigInteger.valueOf(4);
        BigInteger EIGHT = BigInteger.valueOf(8);
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            BigInteger r = new BigInteger(split[0]);
            BigInteger t = new BigInteger(split[1]);
            BigInteger sq = r.subtract(BigInteger.ONE).multiply(r).multiply(FOUR).add(BigInteger.ONE).add(t.multiply(EIGHT));
            BigInteger left = BigInteger.ONE;
            BigInteger right = t.multiply(TWO).add(BigInteger.ONE);
            BigInteger middle;
            while(left.compareTo(right)<=0){
                middle = left.add(right).divide(TWO);
                int cmp = middle.multiply(middle).compareTo(sq);
                if(cmp<0){
                    left = middle.add(BigInteger.ONE);
                } else if (cmp>0){
                    right = middle.subtract(BigInteger.ONE);
                } else {
                    left = middle.add(BigInteger.ONE);
                    right = middle.add(BigInteger.ZERO);
                }
            }
            //4*r*r-4*r+1+8*t;
            //long result = (int) Math.floor(((-2)*r+1+sqrt(sq.toString()))/4);
            //BigInteger result = sqrt(sq.toString()).add(BigInteger.ONE).add(r.multiply(BigInteger.valueOf(-2))).divide(BigInteger.valueOf(4));
            BigInteger result = right.add(BigInteger.ONE).subtract(r.multiply(TWO)).divide(FOUR);
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(result.toString());
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }

    public BigInteger sqrt(String theNumber) {
        int length = theNumber.length(), i;
        BigInteger res = BigInteger.ZERO;
        BigInteger twenty = BigInteger.valueOf(20);
        BigInteger t, x = BigInteger.ZERO, v, few = BigInteger.ZERO;
        BigInteger hg = BigInteger.valueOf(100);
        String tmpString = null;
        int pos = 2 - length % 2;
        tmpString = theNumber.substring(0, pos);
        while (true) {
            BigInteger tmp1 = BigInteger.valueOf(Integer.parseInt(tmpString));
            v = few.multiply(hg).add(tmp1);
            if (res.compareTo(BigInteger.ZERO) == 0) {
                i = 9;
            } else {
                i = v.divide(res.multiply(twenty)).intValue();
            }
            for (; i >= 0; i--) {
                BigInteger tmp2 = BigInteger.valueOf(i).multiply(BigInteger.valueOf(i));
                t = res.multiply(twenty).add(tmp2);
                if (t.compareTo(v) <= 0) {
                    x = t;
                    break;
                }
            }
            res = res.multiply(BigInteger.TEN).add(BigInteger.valueOf(i));
            few = v.subtract(x);
            pos++;
            if (pos > length) {
                break;
            }
            tmpString = theNumber.substring(pos - 1, ++pos);
        }
        return res;
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