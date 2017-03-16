import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;


public class FairAndSquare {
	static List<BigInteger> numbers = new ArrayList<BigInteger>();
	
	public static boolean isFairAndSquare(BigInteger l) {
		String s = l.toString();
		
		for (int i = 0; i < s.length() / 2; ++i) {
			if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
				return false;
			}
		}
		return true;
	}
	
	public static void init() {
		for (long i = 0; i <= 1 << 10; ++i) {
			BigInteger j = BigInteger.valueOf(i * i);
			if (isFairAndSquare(BigInteger.valueOf(i)) && isFairAndSquare(j)) {
				numbers.add(j);
				System.out.println(j);
			}
		}
	}
	
	public static int find(BigInteger key) {
		return Collections.binarySearch(numbers, key);
		
	}
	
	public static void main(String[] args) throws IOException {
		init();
		
//		String filename = "/Users/JP90713/Downloads/test";
		String filename = "/Users/JP90713/Downloads/C-small-attempt1.in.txt";
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		PrintStream stream = new PrintStream("result.txt");
		
		int stages = Integer.parseInt(reader.readLine());
		for (int stage = 1; stage <= stages; ++stage) {
			String[] minMax = reader.readLine().split("\\s+");
			BigInteger min = new BigInteger(minMax[0]);
			BigInteger max = new BigInteger(minMax[1]);

			int count = 0;
			for (BigInteger number : numbers) {
				if (min.compareTo(number) <= 0 &&
				    number.compareTo(max) <= 0) {
					++count;
				}
			}

			stream.printf("Case #%d: %d\n", stage, count);		
		}

	}
}
