package jam.round1.a;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import file.input.InputProcessor;
import file.output.OutputGenerator;

public class Main {

	public static void main(String[] args) throws IOException {
		String file = "A-small-attempt0";
		ProblemInputProcessor pip = new ProblemInputProcessor(file + ".in");
		pip.startProcess();
		OutputGenerator og = new OutputGenerator(file + ".out",
				pip.getNumberOfTestCases());
		for (ProblemInput problemInput : pip) {
			og.printOneLineTestResult(problemInput.solve());
		}
		pip.endProcess();
		og.end();
		System.out.println("Done");
	}

}

class ProblemInputProcessor extends InputProcessor<ProblemInput> {

	public ProblemInputProcessor(String inputFile) {
		super(inputFile);
	}

	@Override
	protected ProblemInput getNextTestCase() {
		String input = getNextLine();
		return new ProblemInput(Integer.parseInt(input));
	}

}

class ProblemInput {
	
	private static Map<Integer,Integer> solutions = new HashMap<Integer, Integer>();
	
	static {
		solutions.put(1, 1);
		for(int i=2; i<=1000000; i++) {
			int sol1 = solutions.get(i-1);
			int sol2 = Integer.MAX_VALUE;
			int unflip = unflip(i);
			if(unflip < i) {
				sol2 = solutions.get(unflip);
			}
			solutions.put(i, (sol1 > sol2 ? sol2 : sol1)+1);
		}
	}
	
	int n;

	public ProblemInput(int n) {
		this.n = n;
	}

	public String solve() {
		return solutions.get(n).toString();
	}
	
	private static int unflip(int i) {
		int s = 0;
		if(i%10 ==0) {
			return Integer.MAX_VALUE;
		}
		while(i > 0) {
			int r = i%10;
			i /= 10;
			s = s*10 + r;
		}
		return s;
	}
	
	

}
