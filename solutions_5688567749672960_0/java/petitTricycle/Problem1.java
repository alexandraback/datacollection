
import java.io.*;
import java.util.*;

public class Problem1 {
	public static Scanner in = new Scanner(System.in);
	public static PrintWriter PW = new PrintWriter(System.out);

	public static int test(int[] pancakes, int d) throws IOException {
		int cuts = 0;
		for (int i = 1000; i > d; i--)
			cuts += pancakes[i] * (((i + d - 1) / d) - 1);

		return d + cuts;
	}

	public static int rev(int s) {
		int res = 0;
		while (s != 0) {
			res *= 10;
			res += s % 10;
			s /= 10;
		}
		return res;
	}

	public static void main(String[] args) throws IOException {
		int cases = in.nextInt();

		int[] low = new int[1000001];

		for (int i = 1; i < 1000001; i++)
			low[i] = i;

		for (int i = 1; i < 1000001; i++)
			if (rev(rev(i)) == i)
				if (low[i - 1] > low[rev(i)])
					low[i] = low[rev(i)] + 1;
				else
					low[i] = low[i - 1] + 1;
			else
				low[i] = low[i - 1] + 1;
		
		for (int c = 1; c <= cases; c++) {
			int n = in.nextInt();
			PW.println("Case #" + c + ": " + low[n]);
		}

		PW.close();
	}
}