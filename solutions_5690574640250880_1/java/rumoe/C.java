package j2014.qual;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

@SuppressWarnings("all")
public class C {

	private static final String FILE_NAME = "C-large";	
	
	private static final String RELATIVE_PATH;
	static {
		String p = C.class.getPackage().getName();
		p = p.replace('.', '\\');
		RELATIVE_PATH = "src\\" + p + "\\" + FILE_NAME;
	}
	
	private Scanner in;
	private PrintStream out;
	
	public C () throws FileNotFoundException {
		in = new Scanner(new File(RELATIVE_PATH + ".in"));	
		out = new PrintStream(RELATIVE_PATH + ".out"); 
			
		int cases = nextInt();	
		for (int i = 1; i <= cases; i++) {
			print("Case #" + i + ": ");
			solve();
			println();
		}	

		out.close();
		System.out.println("\nDONE!");
	}
	
	private void solve() {
		int R = nextInt();
		int C = nextInt();
		int M = nextInt();
		
		boolean swapped = false;
		if (R > C) {
			int t = R;
			R = C;
			C = t;
			swapped = true;
		}
		
		char[][] field = new char[R][C];
		for (char[] r : field) {
			Arrays.fill(r, '*');
		}
		
		
		int emptyFields = R * C - M;
		
		if (emptyFields > 1) {
			if (R == 1) {
				for (int i = 0; i < emptyFields; i++) {
					field[0][i] = '.';
				}
			} else if (R == 2) {
				if (emptyFields % 2 != 0 || emptyFields == 2) {
					printImpossible();
					return;
				}
				for (int i = 0; i < emptyFields / 2; i++) {
					field[1][i] = field[0][i] = '.';
				}
			} else {		
				if (emptyFields == 2 || emptyFields == 3 || emptyFields == 5 || emptyFields == 7) {
					printImpossible();
					return;
				}
				
				// get rectangle
				int c = 2, r = 2;
				
				for (; r <= R; r++) {
					if (c * r > emptyFields) {
						r--;
						break;
					}
				}
				if (r > R) r--;
				
				for (; c <= C; c++) {
					if (c * r > emptyFields) {
						c--;
						break;
					}
				}
				if (c > C) c--;
				
				fillRect(r, c, field);
				emptyFields -= r * c;
				
				if (emptyFields == 1) {
					field[r - 1][c - 1] = '*';
					emptyFields++; 						
				
					if (c == 2) {
						field[r - 1][c - 2] = '*';
						emptyFields++;
					}
				}
				
				for (int i = 0; i < emptyFields; i++) {
					field[i][c] = '.';
				}
			}
		}
		
		field[0][0] = 'c';
		printField(field, swapped);
	}
	
	void fillRect(int r, int c, char[][] field) {
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				field[i][j] = '.';
			}
		}
	}
	
	void printImpossible() {
		println();
		print("Impossible");
	}
	
	void printField(char[][] field, boolean swapped) {
		int R = field.length;
		int C = field[0].length;
		
		int row = swapped? C : R;
		int col = swapped? R : C;
		
		for (int i = 0; i < row; i++) {
			println();
			for (int j = 0; j < col; j++) {
				if (swapped) {
					print(field[j][i]);
				} else {
					print(field[i][j]);
				}
			}
		}	
	}
	
	/*
	 * Manage input
	 */
	private String next() {
		return in.next();
	}
	private int nextInt() {
		return in.nextInt();
	}
	private long nextLong() {
		return in.nextLong();
	}

	/*
	 * Manage output
	 */
	private void print(String s) { 
		System.out.print(s);
		out.print(s); 
	}	
	private void print(int i) { 
		System.out.print(i);
		out.print(i); 
	}	
	private void print(char c) {
		System.out.print(c);
		out.print(c);
	}
	private void print(Object o) {
		System.out.print(o);
		print(o);
	}
	private void println() { 
		System.out.println();
		out.println(); 
	}
	
	public static void main(String[] args) {
		try {
			new C();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
