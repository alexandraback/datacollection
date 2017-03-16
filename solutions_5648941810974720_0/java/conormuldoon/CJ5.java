import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;

public class CJ5 {

	static BufferedReader br;

	public static void main(String[] args) throws IOException {

		File f = new File("input.txt");
		br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		int t = readInt();
		PrintWriter pw = new PrintWriter(new FileWriter(new File("output.txt")));

		for (int i = 1; i <= t; i++) {

			String s = readString();
			s = solve(s);
			pw.println("Case #" + i + ": " + s);
			pw.flush();
			System.out.println(i);
		}
		pw.close();
		br.close();

	}

	static String solve(String s) {

		String sv[] = new String[10];
		sv[0] = "ZERO";
		sv[1] = "ONE";
		sv[2] = "TWO";
		sv[3] = "THREE";
		sv[4] = "FOUR";
		sv[5] = "FIVE";
		sv[6] = "SIX";
		sv[7] = "SEVEN";
		sv[8] = "EIGHT";
		sv[9] = "NINE";

		char[] ck = new char[10];
		ck[0] = 'Z';
		ck[1] = 'W';
		ck[2] = 'U';
		ck[3] = 'F';
		ck[4] = 'X';

		ck[5] = 'V';
		ck[6] = 'G';
		ck[7] = 'R';
		ck[8] = 'I';
		ck[9] = 'O';
		int[] ord = { 0, 2, 4, 5, 6, 7, 8, 3, 9, 1 };
		int[] num = new int[10];
		char c[] = s.toCharArray();
		int n = c.length;
		boolean[] gn = new boolean[n];
		char[][] ch = new char[10][];
		for (int i = 0; i < 10; i++) {
			ch[i] = sv[i].toCharArray();
		}
		for (int i = 0; i < 10; i++) {
			int nv = num(ck[i], c, gn);
			num[ord[i]] = nv;

			for (int j = 0; j < ch[ord[i]].length; j++) {
				int hv=0;
				int ci=0;
				
				while(hv<nv){
				
					//System.out.println(ch[ord[i]][j]);
					if (!gn[ci] && c[ci] == ch[ord[i]][j]) {
						gn[ci] = true;
						hv++;
					}
					ci++;
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < num[i]; j++) {

				sb.append(i);
			}
		}

		return sb.toString();
	}

	static int num(char cr, char[] c, boolean[] gn) {
		int n = gn.length;

		
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (!gn[i] && c[i] == cr) {
				cnt++;
			}
		}
		return cnt;

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