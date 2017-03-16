package pl.gg.codejam2015.roundQ.taskC;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class TaskC {
	
	private static class Var {
		enum Sign {
			PLUS(""), MINUS("-");
			
			private final String s;
			
			Sign(String s) {
				this.s = s;
			}
			
			@Override
			public String toString() {
				return s;
			}
		}
		
		enum Value {
			I("i"), J("j"), K("k"), ONE("1");
			
			private final String s;
			
			Value(String s) {
				this.s = s;
			}
			
			@Override
			public String toString() {
				return s;
			}
		}
		
		private Sign sign;
		private Value value;
		
		public Var() {
			sign = Sign.PLUS;
			value = Value.ONE;
		}
		
		public Var(Sign sign, Value value) {
			this.sign = sign;
			this.value = value;
		}
		
		public Var(char c) {
			this.sign = Sign.PLUS;
			switch (c) {
			case '1':
				value = Value.ONE;
				break;
			case 'i':
				value = Value.I;
				break;
			case 'j':
				value = Value.J;
				break;
			case 'k':
				value = Value.K;
				break;
			default:
				throw new IllegalArgumentException();
			}
		}
		
		public Sign getSign() {
			return sign;
		}
		
		public Value getValue() {
			return value;
		}
		
		@Override
		public String toString() {
			return sign.toString() + value.toString();
		}
		
		public Var mul(Var b) {
			Value resultV = Value.ONE;
			Sign resultS = b.getSign() == sign ? Sign.PLUS : Sign.MINUS;
			
			if (Value.ONE == value) {
				resultV = b.getValue();
			} else if (Value.ONE == b.getValue()) {
				resultV = value;
			} else if (value == b.getValue()) {
				resultV = Value.ONE;
				resultS = resultS == Sign.PLUS ? Sign.MINUS : Sign.PLUS;
			} else if (Value.I == value &&  Value.J == b.getValue()) {
				resultV = Value.K;
			} else if (Value.I == value &&  Value.K == b.getValue()) {
				resultV = Value.J;
				resultS = resultS == Sign.PLUS ? Sign.MINUS : Sign.PLUS;
			} else if (Value.J == value &&  Value.I == b.getValue()) {
				resultV = Value.K;
				resultS = resultS == Sign.PLUS ? Sign.MINUS : Sign.PLUS;
			} else if (Value.J == value &&  Value.K == b.getValue()) {
				resultV = Value.I;
			} else if (Value.K == value &&  Value.I == b.getValue()) {
				resultV = Value.J;
			} else if (Value.K == value &&  Value.J == b.getValue()) {
				resultV = Value.I;
				resultS = resultS == Sign.PLUS ? Sign.MINUS : Sign.PLUS;
			}
				
			return new Var(resultS, resultV);
		}
		
		public Var pow(long a) {		
			if (a < 0) {
				throw new IllegalArgumentException();
			} else if (a == 0) {
				return new Var(Sign.PLUS, Value.ONE);
			} else if (a % 2 == 1) {
				return this.mul(this.pow( a - 1));
			} else {
				Var v2 = this.pow(a / 2);
				return v2.mul(v2);
			}
		}
	}
	
	private static boolean solve(String pattern, long repeat) {
		
		//Length test
		long exprSize = pattern.length() * repeat;
		
		if (exprSize < 3) {
			return false;
		}
		
		//Mul test
		Var patternVal = new Var();
		for (long i = 0; i <pattern.length(); i++) {
			patternVal = patternVal.mul(new Var(pattern.charAt((int) i)));
		}
		
		Var exprVal = patternVal.pow(repeat);
		if (exprVal.getSign() != Var.Sign.MINUS || exprVal.getValue() != Var.Value.ONE) {
			return false;
		}
		
		//Left test
		Var leftVal = new Var();
		long leftSize = -1;
		Set<String> cycles = new HashSet<>();
		
		for (long i = 0; i < exprSize; i++) {
			int patternIdx = (int) (i % pattern.length());
			
			String cycle = patternIdx + ";" + leftVal;	
			if (!cycles.add(cycle)) {
				return false;
			}
			
			leftVal = leftVal.mul(new Var(pattern.charAt(patternIdx)));
			if (leftVal.getSign() == Var.Sign.PLUS && leftVal.getValue() == Var.Value.I) {
				leftSize = i;
				break;
			}
		}
		
		if (leftSize == -1) {
			return false;
		}
		
		//Right test
		Var rightVal = new Var();
		cycles.clear();
		
		for (long i = exprSize - 1; i > leftSize; i--) {
			int patternIdx = (int) (i % pattern.length());
			
			String cycle = patternIdx + ";" + rightVal;	
			if (!cycles.add(cycle)) {
				return false;
			}
			
			rightVal = new Var(pattern.charAt(patternIdx)).mul(rightVal);
			if (rightVal.getSign() == Var.Sign.PLUS && rightVal.getValue() == Var.Value.K) {
				return true;
			}
		}
		
		return false;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		//System.setIn(TaskC.class.getResourceAsStream("inC.txt"));
		//System.setIn(TaskC.class.getResourceAsStream("C-large.in"));
		//System.setOut(new PrintStream(new FileOutputStream("C:\\Users\\Grzegorz\\workspace_juno\\CodeJam2015\\src\\pl\\gg\\codejam2015\\roundQ\\taskC\\C-large.out")));
		
		try (Scanner in = new Scanner(System.in)) {
			long nCases = in.nextLong();
			
			for (long i = 1; i <= nCases; i++) {
				long patternSize = in.nextLong();
				long reapeat = in.nextLong();
				String pattern = in.next();
				
				boolean res = solve(pattern, reapeat);
				
				System.out.println("Case #" + i + ": " + (res ? "YES" : "NO"));
			}
		}
	}
}
