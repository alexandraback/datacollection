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
	private char _number;
	private String _name;
	
	public Solver(char number) {
		this._number = number;
		this._name = getClass().getName();
		_name = _name.substring(_name.lastIndexOf('.') + 1);
	}
	
	public void solve() {
		in = new Scanner(System.in);
		_solve(System.out);
	}
	
	public void solve(File inFile) {
		String filename = inFile.getPath();
		System.out.println(" in: " + filename);
		filename = filename.substring(0, filename.lastIndexOf('.'));
		File outFile = new File(filename + ".out");
		try {
			in = new Scanner(inFile);
			_solve(new PrintStream(outFile));
			System.out.println("out: " + outFile.getPath());
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public void solveSample() {
		solve(new File("inouts/" + _name + "/" + _number + "-sample.in"));
	}
	
	public void solveSmall(int attempt) {
		solve(new File("inouts/" + _name + "/" + _number + "-small-attempt" + attempt + ".in"));
	}
	
	public void solveLarge() {
		solve(new File("inouts/" + _name + "/" + _number + "-large.in"));
	}
	
	public void solveSmallPractice() {
		solve(new File("inouts/" + _name + "/" + _number + "-small-practice.in"));
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
