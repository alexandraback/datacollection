import java.io.*;
import java.util.*;

public class A {
    
    static class Assert {
        static void check(boolean e) {
            if (!e) {
                throw new Error();
            }
        }
    }

    Scanner in;
    PrintWriter out;

    void solve() {
        int nCases = in.nextInt();
        for (int iCase = 1; iCase <= nCases; iCase++) {
            int size = in.nextInt();
            int a[] = new int[in.nextInt()];
            for (int i = 0; i < a.length; i++) {
                a[i] = in.nextInt();
            }
            Arrays.sort(a);
            int min = a.length;
            if (size > 1) {
                int count = 0;
                for (int last = 0; last < a.length; last++) {
                    while (size <= a[last]) {
                        size += size - 1;
                        count++;
                    }
                    Assert.check(a[last] < size);
                    size += a[last];
                    min = Math.min(min, a.length - last - 1 + count);
                }
            }
            out.println("Case #" + iCase + ": " + min);
        }
    }

    void run() {
        in = new Scanner(System.in);
        out = new PrintWriter(System.out);
        try {
            solve();
        } finally {
            out.close();
        }
    }

    public static void main(String args[]) {
        new A().run();
    }
}
