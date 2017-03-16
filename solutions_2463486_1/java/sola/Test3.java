import java.io.*;
import java.math.*;
import java.util.*;


public class Test3 {
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    
    public static boolean isPld (String x) {
        return x.equals(new StringBuffer(x).reverse().toString());
    }
    public static void main (String[] args) throws IOException {
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "3.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "3.out"));
        int tc = sc.nextInt();
        for (int tci=1;tci<=tc;tci++) {
            int cnt = 0;
            long A = sc.nextLong();
            //int digitsA = (int)Math.log10((double)B) + 1;
            long B = sc.nextLong();
            //int digitsB = (int)Math.log10((double)B) + 1;
            long halfBase = (long) (10*(long)Math.log10(Math.sqrt(Math.sqrt((double)A))));
            for (long i = halfBase;;i++) {
                String temp = String.valueOf(i);
                String rv = new StringBuffer(temp).reverse().toString();
                long x = Long.valueOf(temp + rv.substring(1,rv.length()));
                x = x*x;
                if (x>B) {
                    break;
                }
                if (x>=A && x<= B && isPld(String.valueOf(x))) {
                    cnt++;
                }
                
                x = Long.valueOf(temp + rv);
                x = x*x;
                if (x>=A && x<= B && isPld(String.valueOf(x))) {
                    cnt++;
                }
            }
            pw.println("Case #" + tci + ": " + cnt);
        }
        pw.flush();
        pw.close();
        sc.close();
    }
}