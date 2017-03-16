import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author Dzmitry Paulenka
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task_C solver = new Task_C();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task_C {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        int T = in.nextInt();
        for (int k = 1; k <= T; ++k) {
            int a = in.nextInt();
            int b = in.nextInt();

            int cnt = 0;
            for (int i = a; i <= b; ++i) {
                int s = (int) Math.sqrt(i);
                if (s*s == i && isPal(s) && isPal(i) ) {
                    ++cnt;
                }
            }

            out.println("Case #" + k + ": " + cnt);
        }
    }

    private boolean isPal(int s) {
        String ss = String.valueOf(s);
        return new StringBuilder(ss).reverse().toString().equals(ss);
    }
}

