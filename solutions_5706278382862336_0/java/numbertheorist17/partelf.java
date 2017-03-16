/*
 * partelf
 * Girish Venkat
 */

import java.io.*;
import java.util.*;

public class partelf {
    public static int T;
    public static long P, Q;
    
    public static long gcd(long a, long b) {
        if (a % b==0 || b % a==0) return Math.min(a,b);
        return gcd(Math.max(a,b) % Math.min(a,b), Math.min(a,b));
    }
    
    public static boolean isPower2(long k) {
        long r=1;
        while (r<k) r*=2;
        return (r==k);
    }
    
    public static int largest2(long a) {
        long r=1;
        int num=0;
        while (r<=a) {
            r*=2;
            num++;
        }
        return num-1;
    }
    
    public static void main(String[] args) throws Exception {
        Scanner in=new Scanner(new File("partelf.in"));
        PrintStream out=new PrintStream(new File("partelf.out"));
        T=Integer.parseInt(in.nextLine());
        for (int i=1; i<=T; i++) {
            String s=in.nextLine();
            out.print("Case #"+i+": ");
            P=Long.parseLong(s.substring(0,s.indexOf("/")));
            Q=Long.parseLong(s.substring(s.indexOf("/")+1));
            long g=gcd(P,Q);
            P/=g;
            Q/=g;
            if (!isPower2(Q)) {
                out.println("impossible");
            }
            else {
                out.println(largest2(Q)-largest2(P));
            }
        }
    }
}