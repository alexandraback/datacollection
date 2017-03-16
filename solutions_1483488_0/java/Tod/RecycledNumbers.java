import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Scanner;


public class RecycledNumbers {
	
	static ArrayList<intMapping> included;
	
	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
		Scanner sc;
		try {
			sc = new Scanner(new FileInputStream("C-small-attempt0.in"));
		} catch (FileNotFoundException e) {
			sc = new Scanner(System.in); // file not exist, so get input from console
		}

		Writer out;
		try {
			out = new OutputStreamWriter(new FileOutputStream("C-small.out"));
		} catch (FileNotFoundException e) {
			out = new OutputStreamWriter(System.out); // use console
		}
		
		int T = sc.nextInt();
//		sc.nextLine();
		
		for (int t = 0; t < T; t++) {
			int A = sc.nextInt(), B = sc.nextInt();
			int count = 0;
			included = new ArrayList<intMapping>();
			
			for (int max = B; max > A; max--) {
				count += countShitMatches(max, A);
			}
			
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

	static int countShitMatches(Integer input, int min) {
		int count = 0;
		String number = input.toString();
		for (int i = 1; i < number.length(); i++) {
			number = digitShift(number);
			int result = Integer.parseInt(number);
			if (result >= min && result < input)
				if (!mappingExists(input, result)) {
					included.add(new intMapping(input, result));
					count++;
			}
		}
		
		return count;
	}
	
	static String digitShift(String input) { // moves first digit to end of number represented by a String
		return input.substring(1).concat(input.substring(0, 1));
	}
	
//	static Boolean mappingExists(Integer k, Integer v) {
//		return included.contains(new intMapping(k, v));
//	}

//	static Boolean mappingExists(Integer k, Integer v) {
//		intMapping test = new intMapping(k, v);
//		
//		for (intMapping m : included) {
//			if (m.equals(test))
//				return true;
//		}
//		
//		return false;
//	}
	
	static Boolean mappingExists(Integer k, Integer v) {
		for (intMapping m : included) {
			if (m.key == k && m.value == v)
				return true;
			if (m.key == v && m.value == k)
				return true;
		}
		
		return false;
	}
	
	static class intMapping { //implements Comparable<intMapping> {
		public int key, value;
		
		public intMapping(int k, int v) {
			key = k;
			value = v;
		}

//		@Override
//		public int compareTo(intMapping other) {
//			if ((other.key == this.key && other.value == this.value) || (other.key == this.value && other.value == this.key))
//				return 0;
//			else return 1;
//		}
	}
}
