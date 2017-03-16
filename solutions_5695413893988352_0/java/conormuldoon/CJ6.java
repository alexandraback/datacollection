import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CJ6 {

	static BufferedReader br;

	public static void main(String[] args) throws IOException {

		File f = new File("input.in");

		PrintWriter pw = new PrintWriter(new FileWriter(new File("output.txt")));

		br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		int t = readInt();

		for (int i = 1; i <= t; i++) {
			String s0[] = readString().split(" ");

			String s = solve(s0[0], s0[1]);
			pw.println("Case #" + i + ": " + s);
			pw.flush();

			System.out.println(i);

		}
		pw.close();
		br.close();

	}

	static String solve(String s0, String s1) {

		int v0 = 0;
		int v1 = 0;
		int ln = s0.length();

		int mdf = 1001;

		for (int i = 0; i < 1000; i++) {
			l: for (int j = 0; j < 1000; j++) {

				String sa = String.valueOf(i);
				String sb = String.valueOf(j);

				int dfa = ln - sa.length();
				
				if (dfa < 0)
					continue;
				
				for (int k = 0; k < dfa; k++) {
					sa = "0" + sa;
				}
				int dfb = ln - sb.length();
				
				if (dfb < 0)
					continue;
				
				for (int k = 0; k < dfb; k++) {
					sb = "0" + sb;
				}

				for (int k = 0; k < ln; k++) {
					if (s0.charAt(k) != '?' && s0.charAt(k) != sa.charAt(k)) {
						continue l;
					}
					if (s1.charAt(k) != '?' && s1.charAt(k) != sb.charAt(k)) {
						continue l;
					}
				}
				int abs = Math.abs(i - j);
				if (abs < mdf) {
					mdf = abs;
					v0 = i;
					v1 = j;
				}
			}

		}

		String sa = String.valueOf(v0);
		String sb = String.valueOf(v1);

		int dfa = ln - sa.length();
		for (int k = 0; k < dfa; k++) {
			sa = "0" + sa;
		}
		int dfb = ln - sb.length();
		for (int k = 0; k < dfb; k++) {
			sb = "0" + sb;
		}

		return sa + " " + sb;
	}

	static public String readString() throws IOException {
		return br.readLine();

	}

	static public long readLong() throws IOException {
		return Long.parseLong(br.readLine());
	}

	static public int readInt() throws IOException {
		return Integer.parseInt(br.readLine());
	}

	static public int[] readIntArr() throws IOException {
		String[] str = br.readLine().split(" ");
		int arr[] = new int[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = Integer.parseInt(str[i]);
		return arr;
	}

	static public Integer[] readOIntArr() throws IOException {
		String[] str = br.readLine().split(" ");
		Integer arr[] = new Integer[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = new Integer(str[i]);
		return arr;
	}

	static public double[] readDoubleArr() throws IOException {
		String[] str = br.readLine().split(" ");
		double arr[] = new double[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = Double.parseDouble(str[i]);
		return arr;
	}

	static public Double[] readODoubleArr() throws IOException {
		String[] str = br.readLine().split(" ");
		Double arr[] = new Double[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = new Double(str[i]);
		return arr;
	}

	static public long[] readLongArr() throws IOException {
		String[] str = br.readLine().split(" ");
		long arr[] = new long[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = Long.parseLong(str[i]);
		return arr;
	}

	static public Long[] readOLongArr() throws IOException {
		String[] str = br.readLine().split(" ");
		Long arr[] = new Long[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = new Long(str[i]);
		return arr;
	}

	static public double readDouble() throws IOException {
		return Double.parseDouble(br.readLine());
	}
}