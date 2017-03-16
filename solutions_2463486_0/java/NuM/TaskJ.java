import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Vector;


public class TaskJ {

	/**
	 * @param args
	 */
	
	static BigInteger reverse(BigInteger x) {
		String s = x.toString();
		StringBuilder sb = new StringBuilder(s);
		sb.reverse();
		BigInteger res = new BigInteger(sb.toString());
		/*BigInteger res = BigInteger.ZERO;
		while (x.compareTo(BigInteger.ZERO) != 0) {
			res = (res.multiply(BigInteger.TEN)).add(x.remainder(BigInteger.TEN));
			x = x.divide(BigInteger.TEN);
		}*/
		return res;
	}
	
	static boolean ispalindrome(BigInteger x) {
		return x.compareTo(reverse(x)) == 0;
	}
	
	static boolean isok(BigInteger x) {
		return ispalindrome(x) && ispalindrome(x.multiply(x));
	}
	static Vector<BigInteger> vb = new Vector<BigInteger>();
	static int solve(BigInteger x) {
		int l = -1;
		int r = vb.size();
		while (r - l > 1) {
			int m = (l+r)>>1;
			if ((vb.elementAt(m).multiply(vb.elementAt(m))).compareTo(x) <= 0) 
				l = m;
			else
				r = m;
		}
		return l+1;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("base.txt"));
		
		while(sc.hasNextBigInteger()) {
			BigInteger b = sc.nextBigInteger();
			vb.add(b);
		}
		
		Scanner read = new Scanner(new File("input.txt"));
		int T = read.nextInt();
		FileWriter fw = new FileWriter(new File("output.txt"));
		for(int i = 1; i <= T; ++i) {
			BigInteger L = read.nextBigInteger();
			BigInteger R = read.nextBigInteger();
			int ans = solve(R) - solve(L.subtract(BigInteger.ONE));
			fw.write("Case #" + Integer.valueOf(i).toString() + ": " + Integer.valueOf(ans).toString() + "\n");
		}
		fw.close();
		/*FileWriter fw = new FileWriter(new File("output.txt"));
		Vector<BigInteger> ans = new Vector<BigInteger>();
		ans.add(BigInteger.valueOf(1));
		ans.add(BigInteger.valueOf(2));
		ans.add(BigInteger.valueOf(3));
		int MAX_LEN = 20;

		int mxb = 0;
		for (int LEN = 0; LEN <= MAX_LEN; ++LEN) {
			System.out.println(LEN);
			for (int msk = 0; msk < (1 << LEN); ++msk) {
				int sum = 0;
				boolean ook = true;
				for (int i = 0; i < LEN; ++i) {
					int curb = (msk>>i)&1;
					sum += curb;
					if (sum > 4) {
						ook = false;
					}
				}
				if (!ook) continue;
				for (int first = 1; first <= 2; ++first) {
					int cb = 0;
					StringBuilder sl = new StringBuilder(Integer.valueOf(first).toString());
					for(int i = 0; i < LEN; ++i) {
						int curb = (msk>>i)&1;
						cb += curb;
						sl = sl.append(curb);
					}
					StringBuilder sr = new StringBuilder(sl);
					sr.reverse();
					StringBuilder tmp = new StringBuilder(sl);
					tmp.append(sr);
					BigInteger v = new BigInteger(tmp.toString());
					if (isok(v)) {
						ans.add(v);
						mxb = Math.max(mxb, cb);
					}
					for(int mid = 0; mid < 3; ++mid) {
						tmp = new StringBuilder(sl);
						tmp.append(mid);
						tmp.append(sr);
						v = new BigInteger(tmp.toString());
						if (isok(v)) {
							ans.add(v);
							mxb = Math.max(mxb, cb);
						}
					}
				}
			}
		}
		BigInteger[] a = new BigInteger[ans.size()];
		for (int i = 0; i < a.length; ++i) a[i] = ans.elementAt(i);
		Arrays.sort(a);
		for (int i = 0; i < a.length; ++i) fw.write(a[i].toString() + "\n");
		fw.close();
		System.out.println(mxb);*/
	}

}
