import java.util.Scanner;
import java.io.PrintStream;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author dvdreddy
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("output.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task solver = new Task();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class Task {


    static int x[][] = new int[1001][1001];

    static {
        long time = System.currentTimeMillis();
        for (int j = 1; j < 1001; j++) {
            for (int i = 1; i <= j; i++) {
                x[i][j] = 0;
            }

            for (int i = j + 1; i < 1001; i++) {
                int maxi = 1000999;
                for (int k = 1; k < i; k++) {
                    maxi = Math.min(1 + x[k][j] + x[i - k][j], maxi);
                }
                x[i][j] = maxi;
            }
        }
        System.out.println("Time Taken for the comp " +
                (System.currentTimeMillis() - time));

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                System.out.print(" " + x[i][j]);
            }
            System.out.println("");
        }
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        // System.out.println("############################");
        int cnt = in.nextInt();
        int[] y = new int[cnt];
        int maxi = 0;
        for (int i = 0; i < cnt; i++) {
            y[i] = in.nextInt();
            maxi = Math.max(maxi, y[i]);
            // System.out.print(" " + y[i]);
        }
        // System.out.println();
        // System.out.println("Maxi is " + maxi);
        int result = 100000;
        for (int i = 1; i <= maxi; i++) {
            int tmp_res = i;
            for (int j = 0; j < cnt; j++) {
                tmp_res += x[y[j]][i];
            }
            result = Math.min(result, tmp_res);
        }
        out.println("Case #" + testNumber + ": " + result);
        // System.out.println("############################");
    }
}

