package round0;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashSet;
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
		int numPairs = 0;
		int A = input.A;
		int B = input.B;
		
		//worry about duplicates
		HashSet<Tuple> combinations = new HashSet<Tuple>(1000000);

		for(int n=A; n<=B; n++) {
			int numDigits = 1;
			int div = 10;
			while(n/div != 0) {
				numDigits++;
				div *= 10;
			}
			int div2 = 10;
			for(int digitsToMove = 1; digitsToMove < numDigits; digitsToMove++){
				div /= 10;
				int m = n/div2 + n%div2 * div;
				if(m >= A && n >=A && m <=B && n <=B && n < m) {
					Tuple t = new Tuple(n,m);
					if(!combinations.contains(t)) {
						numPairs++;
						combinations.add(t);
					}
				}
				div2 *=10;				
			}
		}
		
		_out.println("Case #" + caseIndex +": " + numPairs);
	}
	
	private class Tuple {
		int n;
		int m;
		public Tuple (int n, int m) {
			this.n = n;
			this.m = m;
		}
		@Override
		public int hashCode() {
			return m + n;
		}
		@Override
		public boolean equals(Object obj) {
			Tuple other = (Tuple)obj;
			if (m != other.m)
				return false;
			if (n != other.n)
				return false;
			return true;
		}
	}
	
	private Input[] readInputs() throws Exception {
		
		Scanner scanner = new Scanner(_in);
		_numTestCases = scanner.nextInt();
		Input[] inputs = new Input[_numTestCases];
		for(int i=0; i < _numTestCases; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			inputs[i] = new Input(A,B);
		}
		return inputs;
	}
	
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
		new Dance(in).calculate();
	}
	
	
	private class Input {
		int A;
		int B;
		
		public Input(int A, int B) {
			this.A = A;
			this.B = B;
		}
	}
}
