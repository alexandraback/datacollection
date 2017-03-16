package gcj2013.r1c;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
    
    static PrintWriter out;

    public static void main(String[] args) throws IOException {
        String name = "gcj2013/r1c/A-small";
        Scanner s = new Scanner(new File(name + ".in"));
        int count = s.nextInt();
        out = new PrintWriter(new BufferedWriter(new FileWriter(name + ".out")));
        // out = new PrintWriter(System.out);
        for (int i = 1; i <= count; i++) {
            out.print("Case #" + i + ": ");            
            int res = solve(s.next(), s.nextInt());
            out.print(res);
            out.println();          
        }
        out.close();
    }

    static int solve(String s, int n) {
        int c = 0;
        for(int i=0; i<s.length(); i++) {
            for(int j=i+1; j<s.length()+1; j++) {
                String ss = s.substring(i, j);
                if(v(ss) >= n) c++;
            }
        }
        return c;
    }
    
    static int v (String s) {
        int max = 0;
        int l = 0;
        for(char c : s.toCharArray()) {
            if(!isv(c)) {
                l++;
                max = Math.max(max, l);
                
            } else {
                l = 0;
            }
        }
        return max;
    }
    
    static boolean isv(char c) {
        char[] v = {'a','e','i','o','u'};
        for(char vv : v) {
            if(vv == c) return true;
        }
        return false;
    }
    
}
