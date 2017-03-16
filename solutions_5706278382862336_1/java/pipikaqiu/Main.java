package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }

    public long a,b,k;
    public HashSet<Long> set;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/A-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        set = new HashSet<Long>();
        long temp = 1;
        for (int i = 0; i < 40; i++) {
            temp *= 2;
            set.add(temp);
        }
        set.add(a);
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split("/");
            a = Long.parseLong(split[0]);
            b = Long.parseLong(split[1]);
            long cd = lcd(a, b);
            a /= cd;
            b /= cd;
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            if (!set.contains(b)) {
                bw.write("impossible");
            } else {
                int result = 0;
                while(a<b) {
                    result ++;
                    b /= 2;
                }
                bw.write(Integer.toString(result));
            }
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }

    public int min = 40;
    public long lcd(long a, long b) {
        if (a<b) {
            return lcd(b, a);
        }
        if (a%b==0) {
            return b;
        }
        return lcd(a%b, b);
    }
}