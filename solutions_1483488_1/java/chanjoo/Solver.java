package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

interface ISolver {
	public String evaluate();
}
public abstract class Solver implements ISolver {

	protected Scanner in;
	
	public void solve() {
		in = new Scanner(System.in);
		_solve(System.out);
	}
	
	public void solve(File inFile) {
		String filename = inFile.getPath();
		filename = filename.substring(0, filename.lastIndexOf('.'));
		File outFile = new File(filename + ".out");
		try {
			in = new Scanner(inFile);
			_solve(new PrintStream(outFile));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public void solveSampleOf(char number) {
		String name = getClass().getName();
		name = name.substring(name.lastIndexOf('.') + 1);
		solve(new File("inouts/" + name + "/" + number + "-sample.in"));
	}
	
	public void solveSmallOf(char number, int attempt) {
		String name = getClass().getName();
		name = name.substring(name.lastIndexOf('.') + 1);
		solve(new File("inouts/" + name + "/" + number + "-small-attempt" + attempt + ".in"));
	}
	
	public void solveLargeOf(char number) {
		String name = getClass().getName();
		name = name.substring(name.lastIndexOf('.') + 1);
		solve(new File("inouts/" + name + "/" + number + "-large.in"));
	}
	
	private void _solve(PrintStream out) {
		int count = in.nextInt();
		in.nextLine();
		for(int index = 0; index<count; index++) {
			out.append("Case #")
				.append(String.valueOf(index+1))
				.append(": ")
				.append(evaluate())
				.append("\n");
		}
	}
	
	public String solve(String singleTest) {
		in = new Scanner(singleTest);
		return evaluate();
	}
	
}
