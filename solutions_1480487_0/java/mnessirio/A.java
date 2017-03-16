package gcj_2012;

/**
 * Time: 9:04:05 AM, May 5, 2012
 * @author Maya is the best :-)
 */

import java.util.Scanner;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.DecimalFormat;

public class A {
    
    static Scanner in;
    static String path = "src/gcj_2012/";
    static String taskname = "A-small-attempt4";
    static DecimalFormat df = new DecimalFormat("##.######");
    
    public static double[] solve() {
        double x=0;
        int N=in.nextInt();
        double averageScore;
        double[] m=new double[N];
        boolean[] b=new boolean[N];
        boolean needsRecalculate = false;
        int[] s = new int[N];
        for (int i=0; i<N; i++) {
            s[i]=in.nextInt();
            x+=s[i];
        }
        
        averageScore = x * 2.0 / N;
        
        for (int i=0; i<N; i++) {
            m[i] = (double) 100.0 *(averageScore - s[i] ) / x ;            
            if (m[i]<0) { 
                m[i] = 0.0;
                b[i]=false;
                needsRecalculate = true;
            } else
                b[i]=true;
        }
        
        if (needsRecalculate) {
            double av = 0.0;
            int num=0;
            for (int i=0; i<N; i++) 
                if (b[i]) {
                    av+=s[i]; 
                    num++;
                }
            
            av = av/num + x/num;
           
            for (int i=0; i<N; i++) 
                if (b[i])
                    m[i] = 100.0 * (av - s[i])/x;
        } 
        
        
        return m;
    }
    
    public static void main(String[] args) {
        PrintWriter pW = null;
        
        try {
            pW = new PrintWriter(new FileOutputStream(path
                    + taskname + ".out"));
            try {
                in = new Scanner(new FileInputStream(path
                        + taskname + ".in"));
                int T = in.nextInt();
                for (int caseNumber = 1; caseNumber <= T; caseNumber++) {
                    double[] m = solve();
                    pW.print("Case #" + caseNumber + ": ");
                    for (int i=0; i<m.length; i++) 
                        pW.print(" "+df.format( m[i] ));
                    pW.println();
                }
                in.close();
                pW.close();
            } catch (IOException e) {
                System.out.println("Can not find file " + taskname + ".in");
            }
        } catch (IOException e) {
            System.out.println("Open or create exception with "
                    + taskname + ".out");
        }
    }
}
