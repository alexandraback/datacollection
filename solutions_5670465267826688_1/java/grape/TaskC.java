package qual2015;

import static util.io.SuperPrinter.*;
import static java.lang.Math.*;

import java.util.HashMap;
import java.util.Stack;

import util.io.InputParser;
import util.io.OutputGenerator;


public class TaskC {

	static final OutputGenerator og = new OutputGenerator();
	static final InputParser ip = new InputParser("input/c/C-large.in", og);
//	static final InputParser ip = new InputParser("input/c/test.in", og);
//	static final InputParser ip = new InputParser("input/c/C-large-practice.in", og);
	
	
	public static void main(String[] args) {
//		testScheme();
//		testMult();
		final int noCases = ip.i();
		while(true) {
			long[] tmp = ip.la();
			final long L = tmp[0];
			final long X = tmp[1];
			final long inputLength = L * Math.min(X, 2);
			final String input = repeat(ip.s(), (int)Math.min(X, 2));
			
		System.out.println(input.substring(0,min(100, input.length())));
			
			assert(input.length() == inputLength);
			
			char[] inputChars = input.toCharArray();
			int[] intputAsInts = new int[inputChars.length];
			for(int i=0; i<inputChars.length; i++)
				intputAsInts[i] = toInt(inputChars[i]);
			
			String output = parse(intputAsInts) ? "YES" : "NO";
			og.oCase(output);
		}
	}
	
	static final boolean parse(int[] input) {
		int[] pattern = {2,3,4};

		
		
		int noBacktrackings = -1;
		
		int indexOfI = -1;
		int indexOfJ = -1;
		int indexOfK = -1;
		
		int cumPrefix = 1;
		for(int inputIdx = 0; inputIdx < input.length; inputIdx++) {		// iterate over the input...
			cumPrefix = mult(cumPrefix, input[inputIdx]);
			if(cumPrefix == 2) {	// matched the i
				indexOfI = inputIdx;
				break;
			}
		}
		if(indexOfI == -1)
			return false;
		
		cumPrefix = 1;
		for(int inputIdx = indexOfI + 1; inputIdx < input.length; inputIdx++) {		// iterate over the input...
			cumPrefix = mult(cumPrefix, input[inputIdx]);
			if(cumPrefix == 3) {	// matched the i
				indexOfJ = inputIdx;
				break;
			}
		}
		if(indexOfJ == -1)
			return false;
		
		cumPrefix = 1;
		for(int inputIdx = indexOfJ + 1; inputIdx < input.length; inputIdx++) {		// iterate over the input...
			cumPrefix = mult(cumPrefix, input[inputIdx]);
			if(cumPrefix == 4) {	// matched the i
				indexOfK = inputIdx;
				break;
			}
		}
		if(indexOfK == -1)
			return false;
		
		
		cumPrefix = 1;
		for(int inputIdx = indexOfK + 1; inputIdx < input.length; inputIdx++) {		// iterate over the input...
			cumPrefix = mult(cumPrefix, input[inputIdx]);
		}
		
		if(cumPrefix != 1)
			return false;
		
		return true;
	}
	
	
	
	static final int[][] mtrx = new int[5][5];
	static final String[][] strScheme = 
		{
			{"0","0","0","0","0"},
			{"0","1","i","j","k"},
			{"0","i","-1","k","-j"},
			{"0","j","-k","-1","i"},
			{"0","k","j","-i","-1"},
		};
	
	static final int[][] scheme = new int[5][5];
	
	static {
		for(int i=0; i<strScheme.length; i++) {
			for(int j=0; j<strScheme.length; j++) {
				scheme[i][j] = toInt(strScheme[i][j]);
			}
		}
	}
	
	
	
	static final int mult(int a, int b) {
		int sign = (int) Math.signum(a * b);
//		sign *= a < 0 ? -1 : 1;
//		sign *= b < 0 ? -1 : 1;
		int absResult = scheme[abs(a)][abs(b)];
		return absResult * sign;
	}
	
	static final void testMult() {
		String[][] testCases = {{"j", "j", "-1"},{"i", "j", "k"},{"1", "1", "1"},{"1", "k", "k"},
				{"j", "k", "i"},{"i", "k", "-j"},{"-i", "-i", "-1"},{"-i", "j", "-k"},
				{"-i", "k", "j"},{"-1", "1", "-1"}};
		
		for(String[] c : testCases) {
			assert(mult(toInt(c[0]),toInt(c[1])) == toInt(c[2]));
		}
		System.out.println("All okay!");
	}
	
	static final void testScheme() {
		pt(strScheme);
		br();
		pt(scheme);
		
		for(int i=1; i<scheme.length; i++) {
			System.out.println();
			for(int j=1; j<scheme.length; j++) {
				System.out.print("\t" + toString(scheme[i][j]));
			}
		}
		br();
	}


	
	static final String toString(int i) {
		String sign = i < 0 ? "-" : "";
		switch (Math.abs(i)) {
		case 1:
			return sign + "1";
		case 2:
			return sign + "i";
		case 3:
			return sign + "j";
		case 4:
			return sign + "k";
		default:
			return "0";
		}
	}
	
	static final int toInt(String s) {
		int sign = s.startsWith("-") ? -1 : 1;
		String absStr = s.startsWith("-") ? s.substring(1) : s; 
		switch (absStr) {
		case "1":
			return 1 * sign;
		case "i":
			return 2 * sign;
		case "j":
			return 3 * sign;
		case "k":
			return 4 * sign;
		default:
			return 0;
		}
	}
	
	
	static final HashMap<Character, Integer> map = new HashMap<>();
	static {
		map.put('1', 1);
		map.put('i', 2);
		map.put('j', 3);
		map.put('k', 4);
	}
	
	
	static final int toInt(char c) {
		return map.get(c);
	}

	
	static final String repeat(String s, int times) {
		StringBuilder sb = new StringBuilder();
		for(int i=0; i< times; i++)
			sb.append(s);
		return sb.toString();
	}
}