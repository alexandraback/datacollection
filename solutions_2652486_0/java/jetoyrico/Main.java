import java.util.Set;
import java.util.Scanner;
import java.io.OutputStream;
import java.io.IOException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.HashSet;
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
		C solver = new C();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class C {
	public void solve(int testNumber, Scanner in, PrintWriter out) {
		int r = in.nextInt();
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();
		out.print(String.format("Case #%d:\n", testNumber));
		loop:
		for (int i = 0; i < r; ++i) {
			int[] p = IOUtils.readIntArray(in, k);
			for (int a = 2; a <= m; ++a)
				for (int b = 2; b <= m; ++b)
					for (int c = 2; c <= m; ++c) {
						int[] cur = new int[]{a, b, c};
						Set<Integer> set = new HashSet<Integer>();
						for (int mask = 0; mask < BitUtils.two(3); ++mask) {
							int num = 1;
							for (int j = 0; j < 3; ++j)
								if (BitUtils.contain(mask, j))
									num *= cur[j];
							set.add(num);
						}
						boolean ok = true;
						for (int j = 0; j < p.length; ++j) {
							if (!set.contains(p[j])) {
								ok = false;
								break;
							}
						}
						if (ok) {
							out.print(String.format("%d%d%d\n", a, b, c));
							continue loop;
						}
					}
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

class BitUtils {

	public static int two(int x) {
		return (1 << x);
	}

	public static boolean contain(int m, int x) {
		return (m & two(x)) != 0;
	}

	}

