package qualification2013;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

@SuppressWarnings("unused")
class A {

	private boolean log = true;
	
	private static final String FILE_PATH 	= "src//qualification2013//";
	private static final String FILE_NAME 	= "A-small-attempt0";
	
	private static final File INPUT_FILE 	= new File(FILE_PATH + FILE_NAME + ".in");
	private static final File OUTPUT_FILE 	= new File(FILE_PATH + FILE_NAME + ".out");
	
	private Scanner sc;
	private PrintWriter pw;
	
	private A() throws IOException {
		sc = new Scanner(INPUT_FILE);
		pw = new PrintWriter(OUTPUT_FILE);
				
		final int C = sc.nextInt();
		
		for (int i = 1; i <= C; i++) {
			write(String.format("Case #%d: ", i));
			solve();
			write("\n");
		}
		
		pw.flush();
		pw.close();
		sc.close();
		System.out.println("Done!");
	}
	
	private void solve() {
		char[][] fieldO = new char[4][4];
		char[][] fieldX = new char[4][4];
		boolean done = true;
		for (int i = 0; i < 4; i++) {
			String line = sc.next();
			if (line.contains(".")) done = false;
			String line1 = line.replace('T', 'O');
			String line2 = line.replace('T', 'X');
			fieldO[i] = line1.toCharArray();		
			fieldX[i] = line2.toCharArray(); 
			
		}		
		
		boolean o = won(fieldO, 'O');
		boolean x = won(fieldX, 'X');
		
		
		if (o && x) {
			System.out.println("af");
			write("Draw");
		} else if (x){
			write("X won");
		} else if (o) {
			write("O won");
		} else if (done){
			write("Draw");
		} else {
			write("Game has not completed");
		}
	}
	
	private boolean won(char[][] f, char p) {
		for (int r = 0; r < 4; r++) {
			if (f[r][1] == f[r][2] && f[r][3] == f[r][0] && f[r][3] == f[r][2] && f[r][2] == p)
				return true;
		}
		for (int r = 0; r < 4; r++) {
			if (f[0][r] == f[1][r] && f[2][r] == f[3][r] && f[0][r] == f[3][r] && f[2][r] == p)
				return true;
		}
		
		if (f[0][0] == f[1][1] && f[2][2] == f[3][3] && f[3][3] == f[0][0] && f[0][0] == p) return true;
		if (f[0][3] == f[1][2] && f[2][1] == f[3][0] && f[3][0] == f[0][3] && f[3][0] == p) return true;
		
		return false;
	}
	
	
	
	private void write(String s) {
		pw.write(s);
		if(log) System.out.print(s);
	}
	
	private void write(int i) 	{ write(Integer.toString(i)); }
	private void write(long i)  { write(Long.toString(i)); }
	
	public static void main(String[] args) {
		try {
			new A();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
