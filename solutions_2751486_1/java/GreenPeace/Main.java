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
					int n = Integer.valueOf(vals[1]);
					int left_part = 0;
					BigInteger result = BigInteger.ZERO;
					int cons = 0;
					int len = vals[0].length();
					for (int j = 0; j < len; j++) {
						char ch = vals[0].charAt(j);
						if (ch == 'a' || ch == 'o' || ch == 'u' || ch == 'i' || ch == 'e') {
							left_part += cons;
							cons = 0;
							left_part +=1;
						}
						else {
							cons++;
							if (cons == n) {
								cons = n - 1;
								result = result.add(BigInteger.valueOf(left_part + 1).multiply(BigInteger.valueOf(len - j)));
								left_part = 0;
							}
						}
					}
					out.write("Case #"+ (i + 1) +": " + result + "\n");
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