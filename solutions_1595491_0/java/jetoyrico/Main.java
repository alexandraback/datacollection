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
		B solver = new B();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class B {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
        int N = in.nextInt(), S = in.nextInt(), p = in.nextInt();
        int[] ts = IOUtils.readIntArray(in, N);
        int cnt = 0;
        boolean[] used = new boolean[N];
        int noSurpriseScoreMin = Math.max(p * 3 - 2, 0);
        int surpriseScoreMin = Math.max(p * 3 - 4, 2);
        for (int i = 0; i < ts.length; ++i)
            if (ts[i] >= noSurpriseScoreMin) {
                used[i] = true;
                cnt++;
            }
        for (int i = 0; i < ts.length; ++i)
            if (!used[i] && S > 0 && ts[i] >= surpriseScoreMin) {
                cnt++;
                S--;
            }
        out.print(String.format("Case #%d: %d\n", testNumber, cnt));
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

