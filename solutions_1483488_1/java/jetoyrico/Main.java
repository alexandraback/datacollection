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
			inputStream = new FileInputStream("Main/input.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("Main/output.txt");
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
        int A = in.nextInt(), B = in.nextInt();
        int digit, a = A, ten = 1;
        digit = countDigit(a);
        for (int i = 0; i < digit - 1; ++i) ten *= 10;
        Set<Integer> set = new HashSet<Integer>();
        long ans = 0;
        for (int num = A; num <= B; ++num)
            if (!set.contains(num)) {
                Set<Integer> curSet = new HashSet<Integer>();
                int cur = num;
                curSet.add(cur);
                for (int i = 0; i < digit; ++i) {
                    cur = cur % 10 * ten + cur / 10;
                    if (A <= cur && cur <= B && countDigit(cur) == digit)
                        curSet.add(cur);
                }
                int cnt = curSet.size();
                ans += (cnt * (cnt - 1)) / 2;
                for (int i : curSet) set.add(i);
            }
        out.print(String.format("Case #%d: %d\n", testNumber, ans));
    }

    private int countDigit(int n) {
        int digit = 0;
        while (n > 0) {
            digit++;
            n /= 10;
        }
        return digit;
    }
}

