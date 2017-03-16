import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;


public class RecycledNumbersC {

	static int[] matches;
	static int A, B;
	
	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
		Scanner sc;
		try {
			sc = new Scanner(new FileInputStream("C-large.in"));
		} catch (FileNotFoundException e) {
			sc = new Scanner(System.in); // file not exist, so get input from console
		}
		
		Writer out;
		try {
			out = new OutputStreamWriter(new FileOutputStream("C-large.out"));
		} catch (FileNotFoundException e) {
			out = new OutputStreamWriter(System.out); // use console
		}
		
		int T = sc.nextInt();

		for (int t = 0; t < T; t++) {
			A = sc.nextInt();
			B = sc.nextInt();
			int count = 0;
			
			matches = new int[B];

			for (int i = B; i > A; i--)
				findMatches(i, A);
//				count += findMatches(i, A);
			
			count = countMatches();

			// output
			System.out.println("Case #" + (t + 1) + ": " + count);
			try {
				out.write("Case #" + (t + 1) + ": " + count + "\n");
			} catch (IOException e) {
				// do nothing
			}
		}

		try {
			out.close();
		} catch (IOException e) {
			// do nothing
		}
	}
	
	@SuppressWarnings({ "unchecked", "rawtypes" })
	static void findMatches(Integer input, int min) {
		String number = input.toString();
		ArrayList<Integer> checkNums = new ArrayList<Integer>();
		
		for (int i = 1; i < number.length(); i++) {
			number = digitShift(number);
			Integer nextInt = Integer.parseInt(number);
			if (!checkNums.contains(nextInt))
				checkNums.add(nextInt);
		}
		
		Comparator desc = Collections.reverseOrder();
		Collections.sort(checkNums, desc);
		
		for (Integer n : checkNums) {
			if (n < input && n >= min) {
				matches[n]++;
			}
		}
	}
	
	static int countMatches() {
		int count = 0;
		for (int i = 0; i < B; i++)
			count += matches[i];
		return count;
	}

	static String digitShift(String input) {
		return input.substring(1).concat(input.substring(0, 1));
	}

}
