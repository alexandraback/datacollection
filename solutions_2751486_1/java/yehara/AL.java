package gcj2013.r1c;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class AL {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/r1c/A-large";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");            
            long res = solve(s.next(), s.nextInt());
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static long solve(String s, int n) {
        long res = 0;
        int m = s.length();
        int l = 0;
        int r = 0;
        int con = 0;
        boolean v[] = new boolean[m];
        for(int i=0; i<m; i++) {
            v[i] = isv(s.charAt(i));
        }
        
        while(true) {
            while(con < n && r < m) {
                r++;
                if(v[r-1]) {
                    con = 0;
                } else {
                    con ++;
                }
            }
            if(con < n) break;
            while(r-l >= n) {
                res += m - r + 1;
                l++;
            }
            con = n - 1;
        }
        return res;
    }
    
    static boolean isv(char c) {
        char[] v = {'a','e','i','o','u'};
        for(char vv : v) {
            if(vv == c) return true;
        }
        return false;
    }
    
}
