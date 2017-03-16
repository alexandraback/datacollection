import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.ArrayList;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.math.BigInteger;
import java.util.Collections;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * @author AlexFetisov
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
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskB_InfiniteHouseofPancakes solver = new TaskB_InfiniteHouseofPancakes();
		int testCount = Integer.parseInt(in.next());
		for (int i = 1; i <= testCount; i++)
			solver.solve(i, in, out);
		out.close();
	}
}

class TaskB_InfiniteHouseofPancakes {

    static int[][] dp;
    static {
        dp = new int[1001][1001];
        for (int limit = 1; limit <= 1000; ++limit) {
            int[] curD = new int[1001];
            Arrays.fill(curD, 1000000000);
            for (int j = 1; j <= limit; ++j) {
                curD[j] = 0;
            }
            for (int j = limit + 1; j <= 1000; ++j) {
                for (int p = 1; p <= j-1; ++p) {
                    curD[j] = Math.min(curD[j], curD[p] + curD[j-p] + 1);
                }
            }
            dp[limit] = curD;
        }
    }

    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int countPeople = in.nextInt();
        int[] p = Utils.readIntArray(in, countPeople);


        int limit = ArrayUtils.getMax(p);
        int best = limit;
        for (int lowLimit = 1; lowLimit <= limit; ++lowLimit) {
            int cur = 0;
            for (int j = 0; j < countPeople; ++j) {
                cur += dp[lowLimit][p[j]];
            }
            best = Math.min(best, cur + lowLimit);
        }
        out.println("Case #" + testNumber + ": " + best);
    }
}

class InputReader {
    private BufferedReader reader;
    private StringTokenizer stt;

    public InputReader(InputStream stream) {
        reader = new BufferedReader(new InputStreamReader(stream));
    }

    public String nextLine() {
        try {
            return reader.readLine();
        } catch (IOException e) {
            return null;
        }
    }

    public String nextString() {
        while (stt == null || !stt.hasMoreTokens()) {
            stt = new StringTokenizer(nextLine());
        }
        return stt.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(nextString());
    }

    public String next() {
        return nextString();
    }
}

class Utils {
    public static int[] readIntArray(InputReader in, int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i) {
            a[i] = in.nextInt();
        }
        return a;
    }

}

class ArrayUtils {

    public static int getMax(int[] a) {
        int result = a[0];
        for (int x : a) result = Math.max(result, x);
        return result;
    }

}

