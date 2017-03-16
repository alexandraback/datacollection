package hu.rycus86;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.OutputStreamWriter;

public class ProblemA {
	
	public static final String SIZE  	= "small";
	public static final String PROBLEM 	= "a";
	public static final String INPUT 	= PROBLEM + "-" + SIZE + ".in";
	public static final String OUTPUT 	= PROBLEM + "-" + SIZE + ".out";
	
	private static class TestCase {
		private final long P, Q;
		
		public TestCase(long P, long Q) {
			this.P = P;
			this.Q = Q;
		}
		
		public long solution() {
			long S = -1L;
			long N = P;
			
			for (int p = 1; p <= 40; p++) {
				N <<= 1;
				if (N >= Q) {
					if (S < 0) {
						S = p;
					}
					
					N -= Q;
					if (N == 0) {
						return S;
					}
				}
			}
			
			return -1;
		}
		
	}
	
	public static void main(String[] args) {
		try (BufferedReader reader = new BufferedReader(new FileReader(INPUT))) {
			int T = Integer.parseInt(reader.readLine());
			
			try (BufferedWriter writer = new BufferedWriter(new FileWriter(OUTPUT))) {
//			try (BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out))) {
				
				for (int C = 0; C < T; C++) {
					writer.write("Case #" + (C+1) + ": ");
					
					String line = reader.readLine();
					String[] parameters = line.split("\\/");
					
					long P = Long.parseLong(parameters[0]);
					long Q = Long.parseLong(parameters[1]);
					
					TestCase testCase = new TestCase(P, Q);
					
					long solution = testCase.solution();
					if (solution < 0) {
						writer.write("impossible");
					} else {
						writer.write(Long.toString(solution));
					}
					
					writer.newLine();
				}
				
			}
		} catch(Exception ex) {
			ex.printStackTrace();
		}
	}
	
}
