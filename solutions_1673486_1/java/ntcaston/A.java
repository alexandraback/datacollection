import java.io.*;
import java.text.DecimalFormat;
import java.util.*;
import java.lang.Math;

public class A {
	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "A-large.in";
	static String outputFile = "A-large.out";
	
	private String readWord() throws Exception {
		int c = in.read();
		while (c>=0 && c<=' ') c = in.read();
		if (c < 0) return "";
		StringBuilder builder = new StringBuilder();
		while (c > ' ') {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	private int readInt() throws Exception {
		return Integer.parseInt(readWord());
	}
	
	private double readDouble() throws Exception {
		return Double.parseDouble(readWord());
	}
	
	private void solve() throws Exception {
		int cases = readInt();
		for (int i = 0; i<cases; i++) {
			StringBuilder bld = new StringBuilder();
			bld.append("Case #" + (i+1) + ": ");
			int A = readInt();
			int B = readInt();
			double[] p = new double[B];
			for (int j = 0; j<A; j++) p[j] = readDouble();
			
			double result = 0;
			double resEnter = 2 + B;
			
			double resKeepType = 0;
			double probCorrect = 1;
			for (int j = 0; j<A; j++) probCorrect *= p[j];
			resKeepType += ((B-A) + 1)*probCorrect + (1-probCorrect)*((B-A) + 2+B);
			
			int Aorig = A;
			double resBSpace = 99999;
			for (int k = 1; k<= Aorig; k++) {
				probCorrect = 1;
				A--;
				for (int j = 0; j<A; j++) probCorrect *= p[j];
				double temp = ((B-A) + 1)*probCorrect + (1-probCorrect)*((B-A) + 2+B);
				temp += k;
				if(temp < resBSpace) resBSpace = temp;
				//System.out.println("temp: " + temp);
			}
			
			
			result = Math.min(resEnter,resKeepType);
			result = Math.min(result,resBSpace);
			/*System.out.println(resKeepType);
			System.out.println(resBSpace);
			System.out.println(resEnter);*/
			String s = String.format("%.6f", result);
			bld.append(s);
			if (i < cases - 1) bld.append("\n");
			System.out.print(bld);
			out.write(bld.toString());
		}
	}
	
	public static void main(String[] args) {
		new A().run();
	}

	private void run() {
		try {
			in = new BufferedReader(new FileReader(inputFile));
			out = new BufferedWriter(new FileWriter(outputFile));
			solve();
			out.flush();
			System.out.println("\ndone!");
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
}
