import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

public class CJ3 {

	static BufferedReader br;

	static int MX = 50000000;
	static int sq;
	static BigInteger BMX = new BigInteger(String.valueOf(MX));
	static boolean[] prime;
	static List<Integer> p;
	static List<BigInteger> bil;

	public static void main(String[] args) throws IOException {

		sq = (int) Math.sqrt(MX);
		File f = new File("input.txt");
		br = new BufferedReader(new InputStreamReader(new FileInputStream(f)));
		int t = readInt();
		PrintWriter pw = new PrintWriter(new FileWriter(new File("output.txt")));

		prime = new boolean[MX + 1];
		p = new LinkedList<Integer>();
		bil = new LinkedList<BigInteger>();
		Arrays.fill(prime, true);
		prime[0] = false;
		prime[1] = false;

		for (int i = 2; i <= sq; i++)
			if (prime[i])
				for (int k = i * i; k <= MX; k += i)
					prime[k] = false;

		for (int i = 0; i <= MX; i++) {

			if (prime[i]) {
				p.add(i);
				System.out.println(i);
				bil.add(new BigInteger(String.valueOf(i)));
			}
		}

		for (int i = 1; i <= t; i++) {

			int[] arr = readIntArr();
			pw.println("Case #" + i + ": ");
			int n = arr[0];
			int j = arr[1];
			long mx = 1l << n;
			long vl = 1l << (n - 1);
			vl += 1;
			int num = 0;
			List<Long> lst = new LinkedList<Long>();

			l: for (long k = vl; k < mx; k += 2) {
				if (isPrime(k))
					continue;
				// System.out.println("checking "+k);
				for (long l = 3; l < 11; l++) {
					BigInteger bv = bver(k, l);
					// System.out.println(l + " " + k);
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
			for (long k : lst) {
				nv++;
				System.out.println(nv);
				pw.print(Long.toBinaryString(k));

				for (int l = 2; l <= 10; l++) {
					BigInteger bv = bver(k, l);
					BigInteger dv = divisor(bv);
					// if(l==2)System.out.println(k+" "+bv);
					pw.print(" " + dv.toString());
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
		long cur = sq + 1;
		while (cur * cur <= val) {
			if (val % cur == 0)
				return cur;
			cur++;
		}
		System.out.println(isPrime(val));
		return -1;
	}

	static BigInteger divisor(BigInteger val) {

		if (val.compareTo(BMX) < 1) {

			return new BigInteger(String.valueOf(divisor(val.intValue())));
		} else {
			BigInteger bim = new BigInteger(String.valueOf(Long.MAX_VALUE));

			if (val.compareTo(bim) < 1) {
				return new BigInteger(String.valueOf(divisor(val.longValue())));
				
			}

		}

		for (BigInteger i : bil) {
			if (val.mod(i).equals(BigInteger.ZERO))
				return i;

		}

		long cr = sq + 1;
		BigInteger cur = new BigInteger(String.valueOf(cr));
		while (cur.multiply(cur).compareTo(val) < 1) {
			if (val.mod(cur).equals(BigInteger.ZERO))
				return cur;
			cur = cur.add(BigInteger.ONE);
		}
		return null;
	}

	static boolean isPrime(long l) {

		if (l <= MX) {
			return prime[(int) l];
		}
		for (int i : p) {
			if (l % i == 0)
				return false;
		}
		/*long cur = sq + 1;
		while (cur * cur <= l) {
			if (l % cur == 0)
				return false;
			cur++;
		}*/
		return true;
	}

	static boolean isPrime(BigInteger l) {

		if (l.compareTo(BMX) < 1) {

			return prime[l.intValue()];
		} else {
			BigInteger bim = new BigInteger(String.valueOf(Long.MAX_VALUE));

			if (l.compareTo(bim) < 1) {
				return isPrime(l.longValue());
			}

		}

		
		for (BigInteger i : bil) {
			if (l.mod(i).equals(BigInteger.ZERO))
				return false;
		}
		/*
		long cr = sq + 1;
		int num=0;
		BigInteger cur = new BigInteger(String.valueOf(cr));
		while (cur.multiply(cur).compareTo(l) < 1) {
			if (l.mod(cur).equals(BigInteger.ZERO))
				return false;

			num++;
			if(num==1000){
				return true;
			}
			
			//System.out.println(cur+" "+l);
			cur = cur.add(BigInteger.ONE);
		}*/
		return true;
	}

	static BigInteger bver(long num, long b) {
		BigInteger pw = new BigInteger("1");
		BigInteger sm = new BigInteger("0");
		BigInteger bv = new BigInteger(String.valueOf(b));
		while (num > 0) {
			if (num % 2 == 1) {
				sm = sm.add(pw);

			}
			num >>= 1;

			pw = pw.multiply(bv);

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