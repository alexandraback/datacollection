
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class CloseMatch1 {

    static Scanner scanner = new Scanner(System.in);
    static PrintWriter writer;
    
    public static void run() throws FileNotFoundException, UnsupportedEncodingException {
        int T = scanner.nextInt();
        writer = new PrintWriter("output");
        for (int i = 0; i < T; i++) {
            Solution solution = new Solution();
            String output = solution.solve();
            out(i + 1, output);
        }
        writer.close();
    }
    
    static void out(int testcase, String result) {
        String output = "Case #" + testcase + ": " + result;
        System.out.println(output);
        writer.println(output);
    }
    
    static class Solution {
        public String solve() {          
            String C = scanner.next();
            String J = scanner.next();
            
            int n = C.length();

            int d = Integer.MAX_VALUE;
            int sc = 0;
            int sj = 0;
            
            int max = digit(1,0,n+1);
            for (int c = 0; c < max; c++) {
                if (valid(c, C)) {
                    for (int j = 0; j < max; j++) {
                        if (valid(j, J)) {
                            if (Math.abs(c - j) < d) {
                                sc = c;
                                sj = j;
                                d = Math.abs(c - j);
                            }
                        }
                    } 
                }
            }
            
            return toString(sc, n) + " " + toString(sj, n);
        }
        
        static String toString(int i, int n) {
            return String.format("%0" + n + "d", i);
        }
        
        static boolean valid(int i, String b) {
            int n = b.length();
            String a = toString(i, n);
            for (int j = 0; j < n; j++) {
                if (b.charAt(j) != '?') {
                    if (a.charAt(j) != b.charAt(j)) {
                        return false;
                    }
                }
            }
            
            return true;
        }
        
        static int digit(char c, int offset, int n) {
            return digit(c - '0', offset, n);
        }
        
        static int digit(int d, int offset, int n) {
            for (int i = 0; i < n - offset - 1; i++) d *= 10;           
            return d;
        }
    }
}
