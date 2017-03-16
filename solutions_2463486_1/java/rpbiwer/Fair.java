import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.TreeSet;


public class Fair {
//	public static HashMap<BigInteger,Boolean> resCache = new HashMap<BigInteger,Boolean>(1000);
	public static TreeSet<Long> fairAndSquareList = new TreeSet<Long>();
	
	private static int nextIntLine(Scanner in) {
		return Integer.parseInt(in.nextLine());
	}

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("output.out");
		f.delete();
		PrintStream out = new PrintStream(f);
//		PrintStream out = System.out;
		
		System.out.print("Compiling list...");
		compileFairAndSquareList();
		System.out.println("Done.");

		Scanner in = new Scanner(new File("input3.in"));
		int numCases = nextIntLine(in);
//		for(;;)System.out.println("\""+in.nextLine()+"\"");
		for(int i = 0; i < numCases; ++i) {
			out.printf("Case #%d: %d\n", i+1, getAnswer(in));
		}
		
		out.close();
		in.close();
	}

	private static void compileFairAndSquareList() {
		for(long l = 1L; l <= 1E7; ++l) {
			if(testFair(l)) {
				long square = (long) Math.pow(l, 2);
				if(testFair(square))
					fairAndSquareList.add(square);
			}
		}
	}

	private static int getAnswer(Scanner in) {
		long min = in.nextLong();
		long max = in.nextLong();

		return fairAndSquareList.subSet(min, true, max, true).size();
	}

	private static boolean testFair(long num) {
		String str = String.valueOf(num);
		for(int i = 0; i < str.length() / 2; ++i) {
			if(str.charAt(i) != str.charAt(str.length() - 1 - i)) return false;
		}
		return true;
	}
}
