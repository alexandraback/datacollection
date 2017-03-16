package googleCodeJam2k16.problemA;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class SolutionA {

	private File input;
	
	private File output;
	
	private String inputSource = "input/A/in.txt";
	
	private String outputSource = "output/A/out.txt";

	private int N;
	
	private String readCase(Scanner s) {
		String a = s.next();
		return a;
	}
	
	private String solveCase(String s) {
		String sol = "";
		for(int i=0; i< s.length(); i++) {
			if(i==0) {
				sol += s.charAt(i);
			} else {
				if(sol.charAt(0) <= s.charAt(i)) {
					sol = s.charAt(i) + sol;
				} else {
					sol += s.charAt(i);
				}
			}
		}
		return sol;
	}
	
	private void printCase(PrintWriter w, int i, String a) {
		w.println("Case #" + i + ": " + a);
	}

	private Scanner readInputFile() throws FileNotFoundException {
		input = new File(inputSource);
		Scanner s = new Scanner(input);
		N = s.nextInt();
		return s;
	}

	private PrintWriter createOutputFile() throws FileNotFoundException {
		output = new File(outputSource);
		PrintWriter w = new PrintWriter(output);
		return w;
	}

	private void compute(Scanner s, PrintWriter w) {
		for(int i = 1; i <= N; i++) {
			String p = readCase(s);
			String sol = solveCase(p);
			printCase(w, i, sol);
		}
	}

	private void solve() throws FileNotFoundException {
		Scanner s = readInputFile();
		PrintWriter w = createOutputFile();
		compute(s, w);
		w.close();
	}

	public static void main(String[] args) {
		try {
			new SolutionA().solve();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
