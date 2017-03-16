package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class Dance {
	BufferedReader _in;
	PrintWriter _out;
	
	int _numTestCases;
	Input[] _inputs;
	
	public Dance(BufferedReader in) throws Exception {
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
		int maxGP = 0;
		int surprisesAvailable = input.S;
		for(int i=0; i < input.N; i++) {
			int mp = input.tpts[i]/3;
			int modulo = input.tpts[i]%3;
			switch(modulo) {
			case 0:
				if(mp >= input.p) {
					maxGP++;
				} else if(mp+1 >= input.p && mp > 0 && surprisesAvailable > 0) {
					maxGP++;
					surprisesAvailable--;
				}					
				break;
			case 1:
				if(mp+1 >= input.p) {
					maxGP++;
				}
				break;
			case 2:
				if(mp+1 >= input.p) {
					maxGP++;
				} else if(mp+2 >= input.p && surprisesAvailable > 0) {
					maxGP++;
					surprisesAvailable--;
				}	
				break;
			default:
				//not needed	
			}
			
		}
		
		_out.println("Case #" + caseIndex +": " + maxGP);
	}
	
	private Input[] readInputs() throws Exception {
		
		Scanner scanner = new Scanner(_in);
		_numTestCases = scanner.nextInt();
		Input[] inputs = new Input[_numTestCases];
		for(int i=0; i < _numTestCases; i++) {
			int N = scanner.nextInt();
			int S = scanner.nextInt();
			int p = scanner.nextInt();
			int [] tpts = new int[N];
			for(int j=0; j < N; j++)
				tpts[j] = scanner.nextInt();
			inputs[i] = new Input(N, S, p, tpts);
		}
		return inputs;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		new Dance(in).calculate();
	}
	
	
	private class Input {
		int N;
		int S;
		int p;
		int[] tpts;
		
		public Input(int N, int S, int p, int[] tpts) {
			this.N = N;
			this.S = S;
			this.p = p;
			this.tpts = tpts;
		}
	}
}
