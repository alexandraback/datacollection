import java.io.*;
import java.math.*;
import java.util.*;

public class FairSquare {

	public static boolean isPal(String str) {
		for (int i = 0; i < str.length()/2; i++) {
			if (str.charAt(i) != str.charAt(str.length()-1-i)) return false;
		}
		return true;
	}

	public static void go(String str, int total, int digits) {
		if (digits <= 0 || total >= 10) return;
		if (!str.equals("")) check(str);
		for (int i = 0; i < 3; i++) {
			String cand = "" + i + str + i;
			go(cand,total+2*i*i,digits-2);
		}
	}

	public static void check(String cand) {
		BigInteger b = new BigInteger(cand);
		b = b.pow(2);
		if (isPal(b.toString())) {
			found.add(b);
		}
	}

	static Set<BigInteger> found = new HashSet<BigInteger>();

	public static String getLine(BufferedReader buf) {
		String ret = null;
		try {
			ret = buf.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return ret;
	}

	public static int count(BigInteger[] data, BigInteger from, BigInteger to) {
		int cnt = 0;
		for (int i = 0; i < data.length; i++) {
			if (data[i].compareTo(from) >= 0 && data[i].compareTo(to) <= 0) cnt++;
		}
		return cnt;
	}

	public static void main(String[] args) {
		check("1"); check("2"); check("3");
		go("",0,60);
		go("0",0,60);
		go("1",1,60);
		go("2",4,60);
		go("3",9,60);
		BigInteger[] data = new BigInteger[found.size()];
		int p = 0;
		for (BigInteger b : found) data[p++] = b;
		Arrays.sort(data);
		BufferedReader buf = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(getLine(buf));
		for (int i = 0; i < T; i++) {
			String[] line = getLine(buf).split(" ");
			System.out.println("Case #" + (i+1) + ": " + count(data, new BigInteger(line[0]), new BigInteger(line[1])));
		}
	}

}
