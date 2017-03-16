import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class CJ1 {

	static BufferedReader br;

	public static void main(String[] args) throws IOException {

		File f = new File("input.txt");
		br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		int t = readInt();
		PrintWriter pw=new PrintWriter(new FileWriter(new File("output.txt")));
		
		for (int i = 1; i <= t; i++) {

			int num = solve(readString());
			pw.println("Case #" + i + ": "+num);
			System.out.println(i);
		}
		pw.flush();
		pw.close();
		br.close();

	}

	static int solve(String s) {
		int num = 0;
		for (int i = s.length(); i-- > 0;) {
			if (s.charAt(i) == '-') {
				num = 1;
				for (int j = i; j-- > 0;) {
					if (s.charAt(j) != s.charAt(j + 1))
						num++;
				}
				break;
			}
		}
		return num;
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