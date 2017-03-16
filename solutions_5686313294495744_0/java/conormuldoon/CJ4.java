import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;

public class CJ4 {

	static BufferedReader br;

	public static void main(String[] args) throws IOException {

		File f = new File("input.in");
		br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		int t = readInt();

		PrintWriter pw = new PrintWriter(new FileWriter(new File("output.txt")));

		for (int i = 1; i <= t; i++) {

			int n = readInt();
			String[][] st = new String[n][];
			for (int j = 0; j < n; j++) {
				st[j]=readString().split(" ");
				
			
				
			}
			String s = solve(st);
			pw.println("Case #" + i + ": " + s);
			pw.flush();
			System.out.println(i);
		}
		pw.close();
		br.close();

	}

	static String solve(String[][] st) {
		int n = st.length;
		
		int mx = 1 << n;
		int mxv = 0;
		l:for (int i = 0; i < mx; i++) {

			HashSet<String> hva = new HashSet<String>();
			HashSet<String> hvb = new HashSet<String>();
			boolean[] hv = new boolean[n];
			int num = 0;

			for (int j = 0; j < n; j++) {

				if (((1 << j) & i) > 0) {
					hv[j] = true;
					hva.add(st[j][0]);
					hvb.add(st[j][1]);
					num++;
				}

			}
			int vl = n - num;
			if (vl <= mxv)
				continue;

			for (int j = 0; j < n; j++) {
				if (!hv[j]) {
					
					if (!hva.contains(st[j][0]) || !hvb.contains(st[j][1]))
						continue l;
				}
			}
			mxv = vl;

		}
		return "" + mxv;
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