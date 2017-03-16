import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("foo.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("foo.out")));
		StringTokenizer st;
		int n = Integer.parseInt(in.readLine());
		for (int cs = 1; cs <= n; cs++) {
			st = new StringTokenizer(in.readLine());
			BigInteger r = new BigInteger(st.nextToken());
			BigInteger t = new BigInteger(st.nextToken());
			BigInteger a = r.multiply(new BigInteger("2"));
			a = a.add(new BigInteger("1"));
			BigInteger low = new BigInteger("0");
			BigInteger high = new BigInteger("2000000000000000000");
			BigInteger mid, tmp;
			while (low.compareTo(high) <= 0) {
				mid = low.add(high);
				mid = mid.divide(new BigInteger("2"));
				tmp = mid.subtract(new BigInteger("1"));
				tmp = tmp.multiply(new BigInteger("2"));
				tmp = a.add(tmp);
				tmp = tmp.multiply(mid);
				if (tmp.compareTo(t) <= 0)
					low = mid.add(new BigInteger("1"));
				else
					high = mid.subtract(new BigInteger("1"));
			}
			System.out.println("Case #" + cs + ": " + high);
		}
	}
}
