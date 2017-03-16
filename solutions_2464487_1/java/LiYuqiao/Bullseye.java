import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Bullseye {
	public BigInteger solve(BigInteger r, BigInteger t) {
		BigInteger left = new BigInteger("1");
		BigInteger right = t;
		BigInteger mid;
		BigInteger zero = new BigInteger("0");
		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		while (left.compareTo(right) < 0) {
			mid = left.add(right).divide(two);
			if (mid.multiply(two).add(r.multiply(two)).subtract(one)
					.multiply(mid).compareTo(t) <= 0) {
				left = mid.add(one);
			} else {
				right = mid;
			}
		}
		return left.subtract(one);
	}

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(
				"A-large.in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out.txt"));
		Bullseye bs = new Bullseye();
		int T = Integer.parseInt(reader.readLine());
		int k = 1;
		while (k <= T) {
			StringTokenizer st = new StringTokenizer(reader.readLine());
			BigInteger r = new BigInteger(st.nextToken());
			BigInteger t = new BigInteger(st.nextToken());
			writer.write("Case #" + k + ": " + bs.solve(r, t));
			writer.newLine();
			k++;
		}
		reader.close();
		writer.close();
	}
}
