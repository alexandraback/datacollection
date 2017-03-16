import java.io.*;
import java.util.*;


public class C {
	
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = new FileInputStream(new File("src/C-large.in"));
		PrintStream output = new PrintStream(new File("src/C-large.out"));
		in = new Scanner(input);
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}
	
	static void solveMultiTest() throws IOException {
		int T = in.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			out.println("Case #" + testCase + ":" + solveOneTest());
		}
	}  
	
	static String solveOneTest() {
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		
		int min = Math.min(R, C);
		int max = Math.max(R, C);
		boolean inv = (C != min);
	
		Calculator calc = new Calculator(max, min, min*max - M);
		boolean ok = calc.ok;
		
		char[] matrix = new char[R * C];
		
		for (int r = 0; r < max; r++) {
			for (int c = 0; c < min; c++) {
				char cell = '*';
				if (c < calc.x) {
					if (r < calc.y) 
						cell = '.';
					if (r == calc.y) {
						if (c < calc.v)
							cell = '.';
					}
					if (r == calc.y + 1) {
						if (c < calc.w)
							cell = '.';
					} 
				}
				if (r == 0 && c == 0) {
					cell = 'c';
				}
				matrix[r * min + c] = cell;
			}
		}
	
		String s = "";
		if (ok) {
			for (int r = 0; r < R; r++) {
				s += "\n";
				for (int c = 0; c < C; c++) {
					int idx = inv ? c * R + r : r * C + c;
					s += matrix[idx];
				}
			}
		} else {
			s = "\nImpossible";
		}
		
		return s;
	}
	
	static class Calculator {
		public int x;
		public int y;
		public int w;
		public int v;
		public boolean ok;
		
		public Calculator(int R, int C, int F) {
			w = 0;
			v = 0;
			if (C == 1) {
				x = 1;
				y = F;
				ok = true;
			} else if (F == 1) {
				x = 1;
				y = 1;
				ok =  true;
			} else if (C == 2) {
				x = 2;
				y = F / 2;
				v = F % 2;
				ok =  v == 0 && y > 1;
			} else if (F == 2 || F == 3 || F == 5 || F == 7) {
				calc(C, F);
				ok =  false;
			} else {
				if (!calc(C, F)) 
					if (!calc(F/2, F))
						if (!calc(F/3, F)) System.out.println("ups");
				ok = true;
			}
		}
		
		private boolean calc(int xx, int F) {
			w = 0;
			v = 0;
			x = xx;
			y = 0;
			if (F % x == 0) {
				y = F / x;
			} else if (F % x > 1) {
				y = F / x;
				v = F % x;
			} else if (F % x == 1) {
				y = F / x - 1;
				w = 2;
				v = x - 1;
			}
			return y >= 2;
		}
	}
		
}
