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
			inputStream = new FileInputStream("tc/input.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("tc/output.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		Scanner in = new Scanner(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
	int res = 0;
	int e, r, n;
	int[] v;

    public void solve(int testNumber, Scanner in, PrintWriter out) {
	    e = in.nextInt();
	    r = in.nextInt();
	    n = in.nextInt();
	    v = IOUtils.readIntArray(in, n);
	    res = 0;
	    go(0, e, 0);
	    out.print(String.format("Case #%d: %d\n", testNumber, res));
    }

	private void go(int curIndex, int curEnergy, int curValue) {
		if (curIndex == n) {
			res = Math.max(res, curValue);
			return;
		}
		for (int ee = curEnergy; ee >= 0; --ee) {
			int gain = v[curIndex] * ee;
			int nextEnergy = Math.min(e, curEnergy - ee + r);
			go(curIndex + 1, nextEnergy, curValue + gain);
		}
	}
}

class IOUtils {
    public static int[] readIntArray(Scanner in, int size) {
        int[] array = new int[size];
        for (int i = 0; i < size; i++)
            array[i] = in.nextInt();
        return array;
    }

    }

