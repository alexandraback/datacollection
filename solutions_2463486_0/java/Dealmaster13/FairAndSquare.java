import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;


public class FairAndSquare {

	private static BufferedReader br;
	private static BufferedWriter bw;
	
	private static final long maxValue = (long)1E14;
	private static final long maxRoot = (long)Math.sqrt(maxValue);
	
	private static List<Long> fairAndSquareNumbers;
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			// Open input file.
			br = new BufferedReader(new FileReader("input.in"));
			
			// Open output file.
			bw = new BufferedWriter(new FileWriter("output.out"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		} catch (IOException e) {
			e.printStackTrace();
		}

		try {
			// Find all the fair and square numbers.
			findAllFairAndSquareNumbers(1L, maxRoot);
			
			// Initialise input and read number of cases.
			int testCases = Integer.parseInt(br.readLine());

			// For each test case.
			analyseTestCases(testCases);
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		finally {
			try {
				br.close();
				bw.flush();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	private static void findAllFairAndSquareNumbers(long startRoot, long maxRoot) {
		long root = startRoot;
		
		fairAndSquareNumbers = new ArrayList<Long>();
		
		while (root != -1L) {
			fairAndSquareNumbers.add(root * root);
			
			root = findNextFairAndSquareRoot(root + 1, maxRoot);
		}
	}
	
	private static void analyseTestCases(int testCases) throws IOException {
		for (int i = 1; i <= testCases; i++) {
			String input = br.readLine();
			
			String[] inputValues = input.split(" ");

			long startValue = Long.parseLong(inputValues[0]);
			long endValue = Long.parseLong(inputValues[1]);
			
			long count = 0;
			
			int index = 0;
			
			long value = fairAndSquareNumbers.get(index);
			
			while (value <= endValue) {
				if (value >= startValue) {
					count ++;
				}
				
				index ++;
				
				value = fairAndSquareNumbers.get(index);
			}
			
			write("Case #" + i + ": " + count + "\n");
		}
	}
	
	private static long findNextFairAndSquareRoot(long root, long maxRoot) {
		long i = root;
		
		while (i <= maxRoot) {
			if (isPalindrome(i)) {
				if (isPalindrome(i*i)) {
					return i;
				}
			}
			
			i++;
		}
		
		return -1L;
	}
	
	private static long getRoot(long n) {
		return (long)Math.sqrt(n);
	}
	
	private static boolean isPalindrome(long n) {
		return isPalindrome(Long.toString(n).toCharArray());
	}
	
	private static boolean isPalindrome(char[] c) {
		for (int i = 0; i < c.length / 2; i++) {
			if (c[i] != c[c.length - i - 1]) {
				return false;
			}
		}
		
		return true;
	}
	
	private static void write(String s) {
		try {
			bw.write(s);
			System.out.print(s);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
