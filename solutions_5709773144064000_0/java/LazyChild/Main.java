import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
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
		TaskB solver = new TaskB();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB {
    public void solve(int testNumber, Scanner in, PrintWriter out) {
        solveSlow(testNumber, in, out);
    }

    private void solveSlow(int testNumber, Scanner in, PrintWriter out) {
        double c = in.nextDouble();
        double f = in.nextDouble();
        double x = in.nextDouble();

        int n = (int) Math.ceil(x);

        double answer = Double.MAX_VALUE;
        for (int i = 0; i <= n; ++i) {
            answer = Math.min(answer, timeNeeded(i, c, f, x));
        }

        out.printf("Case #%d: %.7f\n", testNumber, answer);
    }

    private double timeNeeded(int n, double c, double f, double x) {
        double result = 0;
        for (int i = 0; i < n; ++i) {
            result += c / (2 + i * f);
        }
        result += x / (2 + n * f);
        return result;
    }
}

