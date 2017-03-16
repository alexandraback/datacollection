package round1;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;


public class Password {
	BufferedReader _in;
	PrintWriter _out;
	
	int _numTestCases;
	Input[] _inputs;
	
	public Password(BufferedReader in) throws Exception {
		this._in = in;
		this._out = new PrintWriter("answers.out");
	}

	public void calculate() throws Exception {
		this._inputs = readInputs();
		
		for(int i=0; i < _inputs.length; i++) {
			processInput(_inputs[i], i+1);
		}
		_out.flush();
		_out.close();
	}
	
	
	private void processInput(Input input, int caseIndex) {
		double stepsExpected = 0;
		int A = input.A;
		int B = input.B;
		double[] p = input.p;
		
		//probability that input is correct up to ith character
		double[] pc = new double[A];
		for(int i=0; i < A; i++) {
			if(i == 0) {
				pc[i] = p[i];
			} else {
				pc[i] = pc[i-1] * p[i];
			}			
		}
		
		//number of keystrokes if finishing the password
		//good case
		int stepsg = B - A + 1;
		//bad case
		int stepsb = stepsg + B + 1;
		
		double stepsComplete = stepsg * pc[A -1] + stepsb * (1 - pc[A-1]); 

		//number of keystrokes if press enter
		double stepsAbort = 1 + B + 1;
		
		//now find steps needed if deleted  up to A keys
		
		//find min of steps neeeded when deleting keys 1 by one
		double stepsDeletion = Double.MAX_VALUE;
		for(int d = 1; d < A; d++) {
			stepsg = d + d + B-A + 1;
			stepsb = stepsg + B + 1;
			double stepsD = stepsg * pc[A - d - 1] + stepsb * (1 - pc[A - d - 1]); 
			stepsDeletion = Math.min(stepsDeletion, stepsD);
		}
		
		//delete ALl case;
		stepsDeletion = Math.min(stepsDeletion, A+B+1);
		
		stepsExpected = Math.min(Math.min(stepsComplete, stepsAbort), stepsDeletion);
		
		//best case num characters
		
		//2 5
		//0.6 0.6 7
		
		_out.println("Case #" + caseIndex +": " + stepsExpected);
	}
	
	
	private Input[] readInputs() throws Exception {
		
		Scanner scanner = new Scanner(_in);
		_numTestCases = scanner.nextInt();
		Input[] inputs = new Input[_numTestCases];
		for(int i=0; i < _numTestCases; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			double[] p = new double[A];
			for(int j=0; j < A; j++) {
				p[j] = scanner.nextDouble();
			}
			inputs[i] = new Input(A,B,p);
		}
		_in.close();
		return inputs;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		new Password(in).calculate();
	}
	
	
	private class Input {
		int A;
		int B;
		double[] p;
		
		public Input(int A, int B, double[] p) {
			this.A = A;
			this.B = B;
			this.p = p;
		}
	}
}
