import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

public class C {
	public static void main(String[] args) throws IOException {
		String fileName = "C-small-attempt0";
		Scanner s = null;
		PrintWriter p = null;
		try {
			s = new Scanner(new FileInputStream(fileName + ".in"));
			p = new PrintWriter(new File(fileName + ".out"));
		} catch (IOException e) {
		}
		int t = s.nextInt();
		for (int i = 0; i < t; i++) {
			int c = s.nextInt(); // number of coins
			int d = s.nextInt(); // number of coin types
			int v = s.nextInt(); // max cost
			int[] den = new int[d];
			ArrayList<Integer> pos = new ArrayList<Integer>();

			for (int x = 0; x < d; x++) {
				int tmp = s.nextInt();
				pos.add(tmp);
				den[x] = tmp;
			}

			// get possibilities
			foo(den, 0, 0, pos);
			
			int ans = 0;
			for (int x = 0; x < v; x++)
				if (!pos.contains(x + 1))
					ans++;

			p.println("Case #" + (i + 1) + ": " + ans);
		}
		p.close();
		s.close();
	}

	public static void foo(int[] a, int start, int sum, ArrayList<Integer> pos) {
		if (a.length != start) {
			int val = sum + a[start];
			pos.add(val);
			foo(a, start + 1, val, pos);
			foo(a, start + 1, sum, pos);
		}
	}
}
