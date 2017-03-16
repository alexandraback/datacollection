import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;

public class GCJ1 {

	static BufferedReader br;

	public static void main(String[] args) {

		try {
			br = new BufferedReader(new InputStreamReader(new FileInputStream(
					new File("input.txt"))));
			int numCase = readInt();
			PrintWriter out = new PrintWriter(new FileWriter("output.txt"));
			for (int ncs = 0; ncs < numCase; ncs++) {

				StringBuilder sb = new StringBuilder("Case #");
				sb.append(ncs + 1);
				sb.append(": ");
				sb.append(process());
				out.println(sb.toString());
				out.flush();
			}
			br.close();
			out.close();

		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	static String process() throws IOException {
		int n = readInt();
		int cnt = 1;
		// System.out.println(n);
		for (int i = 2; i < n; i++) {
			String s = "" + i;
			cnt++;
			String st = "";
			for (int j = s.length(); j-- > 0;) {
				st += s.charAt(j);

			}
			int iv = Integer.parseInt(st);
			if (iv <= n && iv > i) {
				i = iv - 1;
			}
		}
		if (n > 1)
			cnt++;
		return "" + cnt;
	}

	static public String readLine() throws IOException {
		return br.readLine();

	}

	static public String readString() throws IOException {
		return br.readLine();

	}

	static public long readlong() throws IOException {
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

	static public double[] readDoubleArr() throws IOException {
		String[] str = br.readLine().split(" ");
		double arr[] = new double[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = Double.parseDouble(str[i]);
		return arr;
	}

	static public long[] readLongArr() throws IOException {
		String[] str = br.readLine().split(" ");
		long arr[] = new long[str.length];
		for (int i = 0; i < arr.length; i++)
			arr[i] = Long.parseLong(str[i]);
		return arr;
	}

	static public double readDouble() throws IOException {
		return Double.parseDouble(br.readLine());
	}
}
