package codejam;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FilenameFilter;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

interface ISolver {
	public void read(Scanner in);
	public String evaluate();
}
public abstract class Solver implements ISolver {

	public enum Type { Sample, Small, Large, PracticeSmall, PracticeLarge }
	
	private Scanner in;
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
	
	private String getFilename(Type type) {
		StringBuilder filename = new StringBuilder("inouts/"+ _name + "/" + _number + "-");
		switch(type) {
		case Large:
			filename.append("large");
			break;
		case PracticeLarge:
			filename.append("small-practice");
			break;
		case PracticeSmall:
			filename.append("small-practice");
			break;
		case Sample:
			filename.append("sample");
			break;
		case Small:
			filename.append("small-attempt" + getLatestSmallAttempt());
			break;
		}
		filename.append(".in");
		return filename.toString();
	}
	
	private int getLatestSmallAttempt() {
		File dir = new File("inouts/" + _name + "/");
		String[] files = dir.list(new FilenameFilter() {
			@Override
			public boolean accept(File dir, String name) {
				return name.startsWith(_number + "-small-attempt") && name.endsWith(".in");
			}
		});
		if(files.length==0) return -1;
		Arrays.sort(files);
		String filename = files[files.length-1];
		filename = filename.substring("X-small-attempt".length(), filename.length()-3);
		return Integer.parseInt(filename);
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
	
	public void solveLargePractice() {
		solve(new File("inouts/" + _name + "/" + _number + "-large-practice.in"));
	}
	
	private void _solve(PrintStream out) {
		int count = in.nextInt();
		in.nextLine();
		for(int index = 0; index<count; index++) {
			read(in);
			out.append("Case #")
				.append(String.valueOf(index+1))
				.append(": ")
				.append(evaluate())
				.append("\n");
		}
	}
	
	public void test(Type type, int case_id) {
		String filename = getFilename(type);
		File inFile = new File(filename);
		filename = filename.substring(0, filename.lastIndexOf('.'));
		File outFile = new File(filename + ".out");
		try {
			in = new Scanner(inFile);
			_test(case_id, new PrintStream(outFile));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	private void _test(int case_id, PrintStream out) {
		int count = in.nextInt();
		in.nextLine();
		for(int index = 0; index<count; index++) {
			read(in);
			if(index!=case_id) continue;
			out.append("Case #")
				.append(String.valueOf(index+1))
				.append(": ")
				.append(evaluate())
				.append("\n");
		}
	}
	
	public String solve(String singleTest) {
		in = new Scanner(singleTest);
		read(in);
		return evaluate();
	}
	
}
