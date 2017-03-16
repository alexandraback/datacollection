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
        solveFast(testNumber, in, out);
    }

    private void solveFast(int testNumber, Scanner in, PrintWriter out) {
        double c = in.nextDouble();
        double f = in.nextDouble();
        double x = in.nextDouble();

        int left = 0;
        int right = (int) Math.ceil(x);

        while (left <= right) {
            int middle1 = (int) Math.floor((left * 2 + right) / 3.0);
            int middle2 = (int) Math.ceil((left + right * 2) / 3.0);
            if (timeNeeded(middle1, c, f, x) < timeNeeded(middle2, c, f, x)) {
                right = middle2 - 1;
            } else {
                left = middle1 + 1;
            }
        }

        out.printf("Case #%d: %.7f\n", testNumber, timeNeeded(right, c, f, x));
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

