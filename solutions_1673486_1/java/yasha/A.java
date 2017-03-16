import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;

public class A {

    public static void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("a.in")));
        PrintStream out = new PrintStream(new FileOutputStream("a.out"));
        long n = readInt(in);
        for (int i = 0; i < n; i++) {
            String[] s1 = in.readLine().split(" ");
            int a = Integer.parseInt(s1[0]);
            int b = Integer.parseInt(s1[1]);
            double ans = b + 2;
            String[] ps = in.readLine().split(" ");
            double p = 1;
            for (int pref = 0; pref <= a; pref++) {
                double next = p * ((a - pref) * 2 + b - a + 1) + (1-p) * ((a - pref) * 2 + b - a + 1 + b + 1);
                if (next < ans) {
                    ans = next;
                }
                if (pref < a) {
                    p *= Double.parseDouble(ps[pref]);
                }
            }
            out.print("Case #" + (i + 1) + ": ");
            out.print(ans);
            out.println();
        }
        out.flush();
        out.close();

    }

    private static long readInt(BufferedReader in) {
        try {
            return Long.parseLong(in.readLine());
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }    
}
