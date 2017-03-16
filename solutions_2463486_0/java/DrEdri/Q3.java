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
		public int A;
		public int B;
	}
				
	
	public static void main(String[] args) {
		String inputFile = args[0];
		parseFile(inputFile);
		try {
			BufferedWriter bw = new BufferedWriter(new FileWriter(inputFile + ".out"));
			for (int i=0; i<probs.length; i++) {
				String output = solveProblem(probs[i]);
				System.out.println(output);
				bw.write("Case #" + (i+1) + ": " + output + "\n");
			}
			bw.flush();
			bw.close();
		} catch (IOException ex) {
			ex.printStackTrace();
		}
	}
	
	private static boolean isPalindrome(int test) {
		String testStr = Integer.toString(test);
		for (int i=0; i<(testStr.length()+1)/2; i++) {
			if (testStr.charAt(i)!=testStr.charAt(testStr.length()-1-i)) {
				return false;
			}
		}
		return true;
	}
	
	
	private static String solveProblem(Problem p) {
		int totFairSquare = 0;
		int sqrtA = (int) Math.ceil(Math.sqrt(p.A));
		int sqrtB = (int) Math.floor(Math.sqrt(p.B));
		for (int i=sqrtA; i<=sqrtB; i++) {
			if (isPalindrome(i)) {
				if (isPalindrome(i*i)) {
					totFairSquare++;
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
				probs[i].A = Integer.parseInt(pieces[0]);
				probs[i].B = Integer.parseInt(pieces[1]);
				line = br.readLine();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
