import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Comparator;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					String[] vals = br.readLine().split(" ");
					BigInteger r = new BigInteger(vals[0]);
					BigInteger t = new BigInteger(vals[1]);
					BigInteger n = BigInteger.ONE;
					BigInteger two = new BigInteger("2");
					while(true) {
						BigInteger newN = n.multiply(two);
						if (r.multiply(newN).multiply(two).add(newN.multiply(newN).multiply(two)).subtract(newN).compareTo(t) > 0) {
							break;
						}
						else {
							n = newN;
						}
					}
					BigInteger step = n;
					while (step.compareTo(BigInteger.ONE) != 0) {
						step = step.divide(two);
						BigInteger newN = n.add(step);
						if (r.multiply(newN).multiply(two).add(newN.multiply(newN).multiply(two)).subtract(newN).compareTo(t) <= 0) {
							n = newN;
						}
					} 

					out.write("Case #"+ (i + 1) +": " + n + "\n");
				}
				out.close();
		} catch (FileNotFoundException e) {
			// ????
		} catch (IOException e) {
			// ????
		}
	}
	
	private static long divideOnModule(long value, long divider, long module) {
		long res = 0;
		long left = value;
		while(true) {
			res = (res+left/divider) % module;
			left = left % divider;
			if (left == 0) {
				break;
			}
			else {
				left += module;
			}
		}
		return res;
	}
}