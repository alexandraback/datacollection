import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class A {
//	 static String file = "A";
	static String file = "A-large";

	static long solveDP(int ziel) {
		
		long[] s = new long[1000011];
		Arrays.fill(s, Long.MAX_VALUE);
		s[0] = 0;
		for (int i = 0; i <= ziel; i++) {
			int n1 = i+1;
			s[n1] = Math.min(s[n1], s[i] + 1);
			
			int n2 = (int)reverse(i);
			if (n2 != i) {
				s[n2] = Math.min(s[n2], s[i] + 1);
			}
		}
		
		return s[ziel];
	}

	
	static long solve(long ziel) {

		if (ziel <= 19) {
			return ziel;
		}

		long cost = 10;
		long current = 10;

		int lng = 2;
		char[] z = Long.toString(ziel).toCharArray();
		while (lng < z.length) {
			long localCost = 0;
			for (int i = 0; i < lng / 2 + (lng % 2); i++) {
				localCost *= 10;
				localCost += 9;
			}
			cost += localCost;

			current += localCost;
			current = reverse(current);
			cost++;
			long ncost = (long) Math.pow(10, lng) - current;
			cost += ncost;
			current = (long) Math.pow(10, lng);
			lng++;
		}

		if (ziel == current)
			return cost;

		if (ziel - current < Math.pow(10, lng / 2 + (lng % 2))) {
			cost += ziel - current;
		} else {
			char[] cc = Long.toString(current).toCharArray();
			int last = z.length - 1;
			while (last > 0 && z[last] == '0') {
				last--;
			}
			if (last < z.length / 2) {
				long s2 = solve(ziel - 1);
				return s2 + 1;
			} else {

				cc = new char[cc.length];
				Arrays.fill(cc, '0');
				for (int i = 0; i < z.length / 2; i++) {
					cc[i] = z[i];
					cost += Math.pow(10, i) * (cc[i] - '0');
				}
				cc[cc.length - 1] = '1';
				current = Long.parseLong(new String(cc));
				cost++;
			}

			cost += ziel - current;
		}

		return cost;
	}

	static long reverse(long n) {
		char[] c = Long.toString(n).toCharArray();
		for (int i = 0; i < c.length / 2; i++) {
			char x = c[i];
			c[i] = c[c.length - i - 1];
			c[c.length - i - 1] = x;
		}

		return Long.parseLong(new String(c));
	}

	static int[] intArray(String l) {
		String[] vals = l.split(" ");
		int[] ans = new int[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Integer.valueOf(vals[i]);
		}
		return ans;
	}

	static long[] longArray(String l) {
		String[] vals = l.split(" ");
		long[] ans = new long[vals.length];
		for (int i = 0; i < vals.length; i++) {
			ans[i] = Long.valueOf(vals[i]);
		}
		return ans;
	}

	public static void main(String[] args) throws IOException {
		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 1;
		for (int i = 0; i < problemCount; i++) {
			String line1 = lines.get(currentIndex++);
			long ziel = Long.parseLong(line1);
			String r = "Case #" + (i + 1) + ": " + solve(ziel);

			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
	}
}
