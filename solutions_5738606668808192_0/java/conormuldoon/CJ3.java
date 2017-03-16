import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class CJ3 {

	static BufferedReader br;

	static int MX = 100000000;
	static int SQ = 10000;
	static boolean[] prime;
	static List<Integer> p;

	public static void main(String[] args) throws IOException {

		File f = new File("input.txt");
		br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		int t = readInt();
		PrintWriter pw = new PrintWriter(new FileWriter(new File("output.txt")));

		prime = new boolean[MX + 1];
		p = new LinkedList<Integer>();
		Arrays.fill(prime, true);
		prime[0] = false;
		prime[1] = false;

		for (int i = 2; i <= SQ; i++)
			if (prime[i])
				for (int k = i * i; k <= MX; k += i)
					prime[k] = false;
		for (int i = 0; i <= MX; i++) {

			if (prime[i])
				p.add(i);
		}

		for (int i = 1; i <= t; i++) {

			int[] arr = readIntArr();
			pw.println("Case #" + i + ": ");
			int n = arr[0];
			int j = arr[1];
			int mx = 1 << n;
			int vl = 1 << (n - 1);
			vl += 1;
			int num = 0;
			List<Integer> lst = new LinkedList<Integer>();

			l:for (int k = vl; k < mx; k += 2) {
				if (prime[k])
					continue;
				for (int l = 3; l < 11; l++) {
					long bv = bver(k, l);
					if (isPrime((bv)))
						continue l;
				}
				lst.add(k);
				num++;
				System.out.println(num);
				if (num == j) {
					break;
				}
			}

			int nv = 0;
			for (int k : lst) {
				nv++;
				System.out.println(nv);
				pw.print(Integer.toBinaryString(k));

				for (int l = 2; l <= 10; l++) {
					long bv = bver(k, l);
					long dv = divisor(bv);
					pw.print(" " + dv);
				}
				pw.println();
			}

		}
		pw.flush();
		pw.close();
		br.close();

	}

	static long divisor(long val) {

		for (long i : p) {
			if (val % i == 0)
				return i;
		}
		long cur = SQ + 1;
		while (cur * cur <= val) {
			if (val % cur == 0)
				return cur;
			cur++;
		}
		System.out.println(isPrime(val));
		return -1;
	}

	static boolean isPrime(long l) {

		if (l <= MX) {
			return prime[(int) l];
		}
		for (int i : p) {
			if (l % i == 0)
				return false;
		}
		long cur = SQ + 1;
		while (cur * cur <= l) {
			if (l % cur == 0)
				return false;
			cur++;
		}
		return true;
	}

	static long bver(int num, int b) {
		long pw = 1;
		long sm = 0;
		while (num > 0) {
			if (num % 2 == 1) {
				sm += pw;
			}
			num /= 2;
			pw *= b;
		}
		return sm;
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