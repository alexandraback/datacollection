import java.io.BufferedWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Scanner;
import java.util.TreeSet;

public class C_large1_0 {
	private static long MAX_VALUE = 100000000000000L;
	private String solveCase(Scanner reader, TreeSet<Long> fairAndSquare) {
		long low_A = reader.nextLong();
		long high_B = reader.nextLong();
		return String.valueOf(fairAndSquare.subSet(low_A, true, high_B, true).size());
	}

	private void solve(Scanner reader, BufferedWriter writer) throws Exception {
		long cases_T = new Long(reader.nextLine());

		//Find all fairAndSquare numbers in the range
		TreeSet<Long> fairAndSquare = new TreeSet<>();
		for (long i=1;i<=MAX_VALUE;i++) {
			if (isPalindrome(String.valueOf(i))) {
				long power = (long) Math.pow(i, 2);
				if (power>MAX_VALUE) {
					break;
				}
				if (isPalindrome(String.valueOf(power))) {
					System.out.println(power+" ("+i+"): Fair and square");
					fairAndSquare.add(power);
				}
			}
		}

		for (long case_T = 1; case_T<=cases_T; case_T++) {
			writeOutput(writer, case_T, solveCase(reader, fairAndSquare));
		}
	}

	private boolean isPalindrome(String palindrome) {
		for (int i=0;i<(palindrome.length()+1)/2;i++) {
			if (palindrome.charAt(i)!=palindrome.charAt(palindrome.length()-i-1)) {
				return false;
			}
		}
		return true;
	}

	private void run() throws Exception {
		Path inputFile = Paths.get(getClass().getSimpleName()+".in");
		Path outputFile = Paths.get(getClass().getSimpleName()+".out");

		Charset charset = Charset.forName("US-ASCII");
		try (
				Scanner reader = new Scanner(Files.newBufferedReader(inputFile, charset));
				BufferedWriter writer = Files.newBufferedWriter(outputFile, charset)) {
			solve(reader,writer);
		}
	}

	private void writeOutput(BufferedWriter writer, long case_T, String output) throws Exception {
		String result = String.format("Case #%d: %s",  case_T, output);

		System.out.println(result);
		writer.write(result+"\n");
	}

	public static void main(String... args) throws Exception {
		new C_large1_0().run();
	}
}
