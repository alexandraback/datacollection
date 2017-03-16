import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;

public class Q3 {
	public static Problem[] probs;

	static class Problem {
		public long A;
		public long B;
	}
				
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				long time1 = System.currentTimeMillis();
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
				long time2 = System.currentTimeMillis();
				System.out.println("Took " + (time2-time1) + " ms");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
	
	private static boolean isPalindrome(long test) {
		String testStr = Long.toString(test);
		for (int i=0; i<(testStr.length()+1)/2; i++) {
			if (testStr.charAt(i)!=testStr.charAt(testStr.length()-1-i)) {
				return false;
			}
		}
		return true;
	}
	
	
	private static String solveProblem(Problem p) {
		int totFairSquare = 0;
		long sqrtA = (long) Math.ceil(Math.sqrt(p.A));
		long sqrtB = (long) Math.floor(Math.sqrt(p.B));
		int sqrtAlength = Long.toString(sqrtA).length();
		int sqrtBlength = Long.toString(sqrtB).length();
		for (int i=sqrtAlength; i<=sqrtBlength; i++) {
			long initialFrontHalf = 1;
			for (int j=0; j<(i-1)/2; j++) {
				initialFrontHalf *= 10;
			}
			for (long j=initialFrontHalf; j<10*initialFrontHalf; j++) {
				long initial = j;
				for (int k=(i-((i-1)/2+1))-1; k>=0; k--) {
					initial = 10*initial + Integer.parseInt(Long.toString(j).charAt(k) + "");
				}
				if (initial<sqrtA) {
					continue;
				}
				if (initial>sqrtB) {
					break;
				}
//				if (!isPalindrome(initial)) {
//					System.out.println("Whoops!  " + initial + " is not a palindrome.");
//					System.exit(1);
//				}
				if (isPalindrome(initial*initial)) {
					totFairSquare++;
//					System.out.println(initial*initial);
				}
				
			}
		}
		return totFairSquare + "";
	}
	

	public static void parseFile(String inputFile) {
		BufferedReader br;
		try {
			br = new BufferedReader(new FileReader(inputFile));
			String line = br.readLine();
			probs = new Problem[Integer.parseInt(line)];
			line = br.readLine();
			for (int i=0; i<probs.length; i++) {
				probs[i] = new Problem();
				String[] pieces = line.split(" ");
				probs[i].A = Long.parseLong(pieces[0]);
				probs[i].B = Long.parseLong(pieces[1]);
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
