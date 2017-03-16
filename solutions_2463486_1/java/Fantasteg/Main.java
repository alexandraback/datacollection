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
//        T = 1;

        long ns[] = new long[] {1L, 4L, 9L, 121L, 484L, 10201L, 12321L, 14641L, 40804L, 44944L, 1002001L, 1234321L, 4008004L, 100020001L,
                               102030201L, 104060401L, 121242121L, 123454321L, 125686521L, 400080004L, 404090404L, 10000200001L, 10221412201L,
                               12102420121L, 12345654321L, 40000800004L, 1000002000001L, 1002003002001L, 1004006004001L, 1020304030201L,
                               1022325232201L, 1024348434201L, 1210024200121L, 1212225222121L, 1214428244121L, 1232346432321L, 1234567654321L,
                               4000008000004L, 4004009004004L
        };

        for (int k = 1; k <= T; ++k) {
            long a = in.nextLong();
            long b = in.nextLong();

            int ai = -1;
            int bi = -1;
            for (int i = 0; i < ns.length; ++i) {
                if (ns[i] < a) {
                    ai = i;
                }

                if (ns[i] <= b) {
                    bi = i;
                }
            }
            out.println("Case #" + k + ": " + (bi - ai));
        }

//        for (int k = 1; k <= T; ++k) {
//            int a = in.nextInt();
//            int b = in.nextInt();
//            a = 1;
//            b = 10000000;
//
//            int cnt = 0;
//            for (long i = a; i <= b; ++i) {
//                if (isPal(i) && isPal(i*i)) {
//                    System.out.print(i*i + "L, ");
//                    ++cnt;
//                }
//            }
//
//            out.println("Case #" + k + ": " + cnt);
//        }
    }

    }

