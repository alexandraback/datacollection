import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

public class SolutionC {
	private static int testcase = 0;
	private static String inputFile = "C:\\GCJ-Input-Output\\input.txt";
	private static String outputFile = "C:\\GCJ-Input-Output\\output.txt";

	private static long MIN = 1;
	private static long MAX = 1000l;

	private static BufferedWriter writer = null;
	private static TreeSet<Long> ts = new TreeSet<Long>();
	public static void main(String[] args) throws Exception {
		long square = 1;
		long counter = 1;
		while (square <= MAX) {
			square = counter * counter;
			if (isPalindrome(square) && isPalindrome(counter)) {
				ts.add(square);
			}
			counter++;
		}
		//System.out.println(ts.size());
		//System.out.println(ts);

		Scanner scanner = new Scanner(new File(inputFile));
		writer = new BufferedWriter(new FileWriter(new File(outputFile)));
		int tcCount = scanner.nextInt();
		StringBuilder sb = null;
		for (int i = 0; i < tcCount; i++) {
			long start = scanner.nextLong();
			long end = scanner.nextLong();
			NavigableSet<Long> subSet = ts.subSet(start, true, end, true);
			//System.out.println(subSet.size());
			writeOutput(subSet==null?0:subSet.size());
		}
		writer.flush();
		writer.close();
	}

	public static void process(long start, long end) throws Exception {

	}

	public static void writeOutput(long result) throws Exception {
		writer.write("Case #" + ++testcase + ": " + result + "\n");
	}

	private static boolean isPalindrome(long number) {
		String s = Long.toString(number);
		return new StringBuffer(Long.toString(number)).reverse().toString()
				.equals(s);
	}
}
