
import com.sun.media.sound.FFT;

import java.io.*;
import java.text.NumberFormat;
import java.util.*;

/**
 * Created by VIET ANH on 27/04/2015.
 */
public class test {

    private static int T;
    private static long oo=Long.MAX_VALUE;
    private static long base=1000000007;
    private static char[] f;
    private static int count=0;
    private static int maxmatch=0;

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(new FileInputStream("test.txt"));
        PrintWriter out = new PrintWriter(new FileOutputStream("output.txt"));
        int T=in.nextInt();
        for (int test = 0; test < T; test++) {
            maxmatch=0;
            count=0;
            double res=0;
            int k=in.nextInt();
            int l=in.nextInt();
            int s = in.nextInt();
            String a=in.next();
            String b = in.next();
            f=new char[s];
            res=solve(a,b,s,0);
            res=(maxmatch*count-res)/count;
            out.println("Case #"+(test+1)+": "+res);
        }
        out.close();
    }

    private static double solve(String a, String b, int s, int i) {
        if (i==s) {
            count++;
            double res=0;
            String x = new String(f);
            int run=0;
            int match=0;
//            System.out.println("a");
            while (x.indexOf(b,run)!=-1) {
                match++;
                run=x.indexOf(b,run)+1;
            }
            maxmatch=Math.max(maxmatch,match);
            res=match;
            return res;
        }
        double res=0;
        for (int j = 0; j < a.length(); j++) {
            char c = a.charAt(j);
            f[i] = c;
            res+=solve(a, b, s, i + 1);
        }
        return res;
    }

}
