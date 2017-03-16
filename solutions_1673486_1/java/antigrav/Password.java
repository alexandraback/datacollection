package codejam2.password;

import java.util.Scanner;

import codejam2.CodejamCase;
import codejam2.CodejamRunner;

public class Password extends CodejamRunner implements CodejamCase {
	private int typed;
	private int total;
	private double[] probs;
	
	private String result; 
	
	public Password(Scanner s) {
		typed = s.nextInt();
		total = s.nextInt();
		probs = new double[typed];
		for(int i = 0; i < typed; i++) {
			probs[i] = s.nextDouble();
		}
	}

	public Password() {
	}

	@Override
	public void compute() {
		double[] exp = new double[typed];
		double pip = 1.0;
		for(int i = typed-1; i >= 0; i--) {
			pip *= probs[typed-i-1];
			int keys = total - typed + 2*i + 1;
			exp[i] = pip*keys + (1-pip)*(keys+total+1);			
		}
		// find min and store into result
		double min = total+2;	// starting over
		for(int i = 0; i < typed; i++)
			if (exp[i] < min)
				min = exp[i];

		result = String.valueOf(min);
	}

	@Override
	public String getOutput() {
		return result;
	}

	@Override
	public CodejamCase parseCase(Scanner s) {
		// TODO Auto-generated method stub
		return new Password(s);
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new Password().run(args);
	}

}
