import java.io.*;
import java.util.*;
import java.math.*;

public class A {
    public static void main(String[] args) { 
        OutputStream outputStream = System.out;
        PrintWriter out = new PrintWriter(outputStream);

        Application solver = new Application();
        solver.solve(System.in, out);

        out.close();
    }
}

class Application {
    long gcd(long a, long b) {
        long t;
        while (b != 0) {
            t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    public int isPowerTwo(long q) {
        while (q > 1) {
            if (q % 2 == 0) {
                q /= 2;
            }
            else {
                return -1;
            }
        }
        return 1;
    }

    public void solve(InputStream in, PrintWriter out) {
        Scanner scanner = new Scanner(in);

        int T = scanner.nextInt();
        scanner.nextLine();

        for (int t = 1; t <= T; t++) {
            String line = scanner.nextLine();
            String[] arr = line.split("/");

            long p = Long.parseLong(arr[0]);
            long q = Long.parseLong(arr[1]);
            long g = gcd(p, q);

            p /= g;
            q /= g;
            int power2 = isPowerTwo(q);

            if (power2 > 0) {
                int c = 0;
                while (p < q) {
                    p *= 2;
                    c++;
                }
                out.println("Case #" + t + ": " + c);
            }
            else {
                out.println("Case #" + t + ": impossible");
            }
        }
    }
}
