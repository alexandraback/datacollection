import java.io.PrintStream;
import java.io.BufferedReader;
import java.util.Comparator;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Collection;
import java.util.List;
import java.io.InputStreamReader;
import java.io.IOException;
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
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int countPeople = in.nextInt();
        int[] p = Utils.readIntArray(in, countPeople);
        best = ArrayUtils.getMax(p);
        List<Integer> pp = new ArrayList<Integer>();
        for (int i = 0; i < p.length; ++i) {
            pp.add(p[i]);
        }
        rec(pp, 0);
        System.err.println("!");
        out.println("Case #" + testNumber + ": " + best);
    }

    private void rec(List<Integer> p, int steps) {
        if (p.size() == 0) {
            best = Math.min(best, steps);
            return;
        }

        Collections.sort(p);
        Collections.reverse(p);
        if (steps >= best) return;
        best = Math.min(best, steps + p.get(0));

        // add minute and split
        for (int newAm = 1; newAm < p.get(0); ++newAm) {
            List<Integer> newP = new ArrayList<Integer>(p);
            newP.remove(0);
            newP.add(newAm);
            newP.add(p.get(0) - newAm);
            rec(newP, steps + 1);
        }
    }

    int best;
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

