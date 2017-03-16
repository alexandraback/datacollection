package googleCodeJam2k16.problemB;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class SolutionB {

	private File input;
	
	private File output;
	
	private String inputSource = "input/B/in.txt";
	
	private String outputSource = "output/B/out.txt";

	private int N;
	
	private int[] readCase(Scanner s) {
		int c = s.nextInt();
		int[] p = new int[(2*c-1)*c+1];
		p[0] = c;
		for(int i=1; i<=(2*c-1)*c;i++) {
			p[i] = s.nextInt();
		}
		return p;
	}
	
	private int[] solveCase(int[] p) {
		int c = p[0];
		int[] h = new int[2501];
		for(int j=0; j<=2500; j++) {
			h[j] = 0;
		}
		for(int i=1; i<p.length; i++) {
			h[p[i]]++;
		}
		int[] sol = new int[c];
		int ind = 0;
		for(int j=0; j<=2500; j++) {
			if(h[j]%2 != 0) {
				sol[ind] = j;
				ind++;
			}
		}
		return sol;
	}
	
	private void printCase(PrintWriter w, int i, int[] sol) {
		w.print("Case #" + i + ":");
		Arrays.stream(sol).forEach(s -> w.print(" " + s));
		w.println();
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
			int[] p = readCase(s);
			int[] sol = solveCase(p);
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
			new SolutionB().solve();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

}
