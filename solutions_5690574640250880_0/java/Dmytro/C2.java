import java.io.*;
import java.util.*;


public class C2 {
	
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = new FileInputStream(new File("src/C-small-attempt0.in"));
		PrintStream output = new PrintStream(new File("src/C-small-attempt0.out"));
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
	
	static Random r = new Random();
	static String solveOneTest() {
		int R = in.nextInt();
		int C = in.nextInt();
		int M = in.nextInt();
		
		int min = Math.min(R, C);
		int max = Math.max(R, C);
		boolean inv = (C != min);
	
		//System.out.println("# R="+R+" C="+C+" M="+M);
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
	
		MineSweep mineSweep = new MineSweep(max, min, matrix);
		boolean test = mineSweep.test();
		
		System.out.println(test);
		System.out.println(ok);
		if (test != ok) System.out.println("###################################################################");
		mineSweep.print();
		
		System.out.println();
		System.out.println();
		System.out.println();
		System.out.println();
	
		String s = "";
		if (test) {
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
				ok =  v == 0;
			} else if (F == 2 || F == 3 || F == 5 || F == 7) {
				calc(C, F);
				ok =  false;
			} else {
				if (!calc(C, F)) 
					if (!calc(F/2, F))
						if (!calc(F/3, F)) System.out.println("ups");
				ok = true;
			}
			//System.out.println("y="+x+" x="+y+" v="+v+" w="+w);
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
	
	static class MineSweep {
		int R;
		int C;
		char[] matrix;
		int[] bombs;
		
		public MineSweep(int R, int C, char[] matrix) {
			this.R = R;
			this.C = C;
			this.matrix = matrix;
			this.bombs = new int[matrix.length];
			for (int i = 0; i < R * C; i++) 
				bombs[i] = -1;
		}
		
		public boolean test() {
			
			for (int r = 0; r < R; r++) {
				for (int c = 0; c < C; c++) {
					int idx = r * C + c;
					if (matrix[idx] == 'c') {
						cnt(r, c);
						
						for (int i = 0; i < R * C; i++) {
							if (matrix[i] == '.' && bombs[i] == -1)
								return false;
						}
						return true;
					}
				}
			}
			return false;
		}
		
		public void print() {
			for (int rr = 0; rr < R; rr++) {
				for (int cc = 0; cc < C; cc++) {
					if (bombs[rr * C + cc] == -1)
						System.out.print(matrix[rr * C + cc]);
					else
						System.out.print(bombs[rr * C + cc]);
				}
				System.out.println();
			}
		}
		
		public void cnt(int r, int c) {
			if (r < 0 || r >= R || c < 0 || c >= C) return;
			int idx = r * C + c;
			if (bombs[idx] >= 0) return;
			
			int cnt = bomb(r + 1, c) 
					+ bomb(r, c + 1)
					+ bomb(r - 1, c) 
					+ bomb(r, c - 1)
					+ bomb(r + 1, c + 1) 
					+ bomb(r - 1, c + 1)
					+ bomb(r - 1, c - 1) 
					+ bomb(r + 1, c - 1);
			bombs[idx] = cnt;
			if (cnt == 0) {
				cnt(r + 1, c);
				cnt(r, c + 1);
				cnt(r - 1, c);
				cnt(r, c - 1);
				cnt(r + 1, c + 1); 
				cnt(r - 1, c + 1);
				cnt(r - 1, c - 1);
				cnt(r + 1, c - 1);
			}
		}
		
		public int bomb(int r, int c) {
			if (r < 0 || r >= R || c < 0 || c >= C) return 0;
			int idx = r * C + c;
			return matrix[idx] == '*' ? 1 : 0;
		}
	}
	
}
