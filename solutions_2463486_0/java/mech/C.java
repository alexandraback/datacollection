package codejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

public class C {

	/*public static boolean isPalindrome(String s) {
		int len = s.length();
		for (int i = 0; i < len / 2; i++)
			if (s.charAt(i) != s.charAt(len - i - 1))
				return false;
		return true;
	}

	 public static ArrayList<Long> precalcStage1() {
		ArrayList<Long> result = new ArrayList<Long>();

		for (long i = 1; i <= 3000000000l; i++) {
			if (i % 1000000 == 0)
				System.out.println(i / 1000000l + " out of " + 3000l);
			if (isPalindrome(Long.toString(i))
					&& isPalindrome(Long.toString(i * i)))
				result.add(i);
		}

		return result;
	}*/

	public static List<String> fourOnes(int k) {
		ArrayList<String> result = new ArrayList<String>();

		StringBuffer buffer = new StringBuffer();
		buffer.setLength(k);

		for (int i2 = 0; i2 < k; i2++)
			for (int i3 = 0; i3 < k; i3++)
				for (int i4 = 0; i4 < k; i4++) {
					for (int i = 0; i < k; i++)
						buffer.setCharAt(i, '0');

					buffer.setCharAt(0, '1');

					buffer.setCharAt(i2, '1');
					buffer.setCharAt(i3, '1');
					buffer.setCharAt(i4, '1');

					result.add(buffer.toString());
				}

		return result;
	}

	public static List<String> twoOnes(int k) {
		ArrayList<String> result = new ArrayList<String>();

		StringBuffer buffer = new StringBuffer();
		buffer.setLength(k);

		for (int i2 = 0; i2 < k; i2++) {
			for (int i = 0; i < k; i++)

				buffer.setCharAt(i, '0');
			buffer.setCharAt(0, '1');

			buffer.setCharAt(i2, '1');

			result.add(buffer.toString());
		}

		return result;
	}

	public static String reverse(String s) {
		StringBuffer result = new StringBuffer();

		for (int i = 0; i < s.length(); i++)
			result.append(s.charAt(s.length() - i - 1));

		return result.toString();
	}

	public static TreeSet<BigInteger> findAllBases() {
		TreeSet<BigInteger> result = new TreeSet<BigInteger>();
		
		result.add(new BigInteger("1"));
		result.add(new BigInteger("2"));
		result.add(new BigInteger("3"));

		for (int k = 1; k < 26; k++) {
			List<String> four = fourOnes(k);
			for (String s : four) {
				result.add(new BigInteger(s + "1" + reverse(s)));
				result.add(new BigInteger(s + "0" + reverse(s)));
				result.add(new BigInteger(s + reverse(s)));
			}

			List<String> two = twoOnes(k);
			for (String s : two)
				result.add(new BigInteger(s + "2" + reverse(s)));

			StringBuffer buf = new StringBuffer();
			buf.setLength(k);
			for (int i = 0; i < k; i++)
				buf.setCharAt(i, '0');
			buf.setCharAt(0, '2');

			String ss = buf.toString();

			result.add(new BigInteger(ss + "0" + reverse(ss)));
			result.add(new BigInteger(ss + "1" + reverse(ss)));
			result.add(new BigInteger(ss + reverse(ss)));
		}

		return result;
	}
	
	public static TreeSet<BigInteger> findAll() {
		TreeSet<BigInteger> result = new TreeSet<BigInteger>();
		
		TreeSet<BigInteger> bases = findAllBases();
		
		for (BigInteger i: bases )
			result.add(i.multiply(i));
		
		return result;
	}

	public static void main(String[] args) {
		File in = new File ("E:\\Dev\\CodeJam2013\\Qual\\io\\C-small-attempt0.in");
		File out = new File("E:\\Dev\\CodeJam2013\\Qual\\io\\C-small-attempt0.out");
		
		TreeSet<BigInteger> solution = findAll();

		try {
			BufferedReader reader = new BufferedReader(new FileReader(in));
			PrintWriter writer = new PrintWriter(out);

			int n = Integer.parseInt(reader.readLine());

			for (int i = 1; i <= n; i++) {
				String[] line = reader.readLine().split(" ");
				
				BigInteger from = new BigInteger(line[0]);
				BigInteger to = new BigInteger(line[1]).add(BigInteger.ONE);
				
				writer.println ("Case #" + i + ": " + solution.subSet(from, to).size());
			}

			writer.close();

		} catch (Throwable e) {
			throw new RuntimeException(e);
		}

	}

}
