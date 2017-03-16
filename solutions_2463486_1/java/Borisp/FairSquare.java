import java.io.BufferedWriter;
import java.io.File;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class FairSquare {

	static List<BigInteger> solutions;
	
	private static void addSolution(char [] letters) {
		BigInteger b = new BigInteger(new String(letters));
		b = b.multiply(b);
		if (b.toString().length() < 100) {
			solutions.add(b);
		}
	}
	
	/** Will also add the middle 1 if the letters length is odd. */
	private static void addSolutionExtended(char []letters) {
		addSolution(letters);
		int n = letters.length;
		if (n % 2 == 1) {
			letters[n / 2] = '1';
			addSolution(letters);
			letters[n / 2] = '0';
		}
	}
	
	static public void flipDigits(char []letters, int... idxs) {
		int n = letters.length;
		for (int idx: idxs) {
			char toSet = letters[idx] == '0' ? '1' : '0';
			letters[idx] = toSet;
			letters[n - idx - 1] = toSet;
		}
	}
	
	public static void prepareSolutions() throws IOException {
		solutions = new ArrayList<BigInteger>();
		solutions.add(new BigInteger("1"));
		solutions.add(new BigInteger("4"));
		solutions.add(new BigInteger("9"));
		for (int i = 2; i < 52; i++) {
			char [] letters = new char[i];
			for (int j = 0; j < i; j++) {
				letters[j] = '0';
			}
			letters[0] = '2';
			letters[i - 1] = '2';
			addSolutionExtended(letters);
			letters[0] = '1';
			letters[i - 1] = '1';
			addSolutionExtended(letters);
			if (i % 2 == 1) {
				letters[i / 2] = '2';
				addSolution(letters);
				letters[i / 2] = '0';
			}
			int middle = i / 2;
			for (int j = 1; j < middle; j++) {
				flipDigits(letters, j);
				addSolutionExtended(letters);
				if (i % 2 == 1 && j != i / 2) {
					letters[i / 2] = '2';
					addSolution(letters);
					letters[i / 2] = '0';
				}
				flipDigits(letters, j);
			}
			for (int j = 1; j < middle; j++) {
				for (int k = j + 1; k < middle; k++) {
					flipDigits(letters, j, k);
					addSolutionExtended(letters);
					flipDigits(letters, j, k);
				}
			}
			for (int j = 1; j < middle; j++) {
				for (int k = j + 1; k < middle; k++) {
					for (int l = k + 1; l < middle; l++) {
						flipDigits(letters, j, k, l);
						addSolutionExtended(letters);
						flipDigits(letters, j, k, l);
					}
				}
			}
			for (int j = 1; j < middle; j++) {
				for (int k = j + 1; k < middle; k++) {
					for (int l = k + 1; l < middle; l++) {
						for (int p = l + 1; p < middle; p++) {
							flipDigits(letters, j, k, l, p);
							addSolutionExtended(letters);
							flipDigits(letters, j, k, l, p);
						}
					}
				}
			}
		}
		
		Collections.sort(solutions);
//		FileOutputStream fos = new FileOutputStream(new File("precalc.out"));
//		for (BigInteger solution : solutions) {
//			fos.write((solution.toString() + "\n").getBytes());
//		}
//		fos.flush();
//		fos.close();
	}

	public static void main(String[] args) throws IOException {
		File intput = new File("google.in");
		File output = new File("google.out");
		Scanner sc = new Scanner(intput);
		FileWriter outputBuffer = new FileWriter(output);
		BufferedWriter out = new BufferedWriter(outputBuffer);
		int numTests;
		numTests = sc.nextInt();
		prepareSolutions();
		for(int o = 0; o < numTests; o++)
		{
			out.write("Case #" + (o + 1) + ": ");
			BigInteger begin, end;
			begin = sc.nextBigInteger();
		    end = sc.nextBigInteger();
			int beginIndex = Collections.binarySearch(solutions, begin);
			int endIndex = Collections.binarySearch(solutions, end);
			if (beginIndex < 0) {
				beginIndex = -beginIndex - 1;
			}
			if (endIndex < 0) {
				endIndex = -endIndex - 2;
			}
			out.write("" + (endIndex - beginIndex + 1));
			out.write("\n");
		}
		out.flush();
		out.close();

	}

}
