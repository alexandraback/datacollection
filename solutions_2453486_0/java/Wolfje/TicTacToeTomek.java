import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Scanner;


public class TicTacToeTomek {
	public static void main(String[] args) throws Exception {
		new TicTacToeTomek();
	}

	public TicTacToeTomek() throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("input_a_large.txt"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(
				"output-a.txt")));
		Scanner scan = new Scanner(in);
		int tests = scan.nextInt();
		for (int test = 0; test < tests; test++) {
			char[][] data = new char[4][];
			for ( int i = 0; i < 4; i++) data[i] = scan.next().toCharArray();
			String result = check(data);
			String answer = String.format("Case #%d: %s\n", test + 1, result);
			System.out.print(answer);
			out.print(answer);
		}
		out.close();
	}
	
	public String check(char[][] data) {
		char[] x = new char[4];
		for ( int r = 0; r < 4; r++) {
			// check row
			String s = checkWin(data[r]);
			if ( s != null ) return s;
			for ( int c = 0; c < 4; c++) x[c] = data[c][r];
			s = checkWin(x);
			if ( s != null ) return s;
		}
		for ( int i = 0; i < 4; i++) x[i] = data[i][i];
		String s = checkWin(x);
		if ( s != null) return s;
		for ( int i = 0; i < 4; i++) x[i] = data[3-i][i];
		s = checkWin(x);
		if ( s != null ) return s;
		int y = 0;
		for ( char[] a: data)
			for ( char b: a) if ( b == '.') y++;
		return y == 0 ? "Draw" : "Game has not completed";		
	}
	
	public String checkWin(char[] data) {
		int tCount = 0;
		int xCount = 0;
		int oCount = 0;
		for ( int i = 0; i < 4; i++) {
			if ( data[i] == 'T') tCount++;
			if ( data[i] == 'O') oCount++;
			if ( data[i] == 'X') xCount++;
		}
		if ( oCount == 4 || ( oCount == 3 && tCount ==1) ) return "O won";
		if ( xCount == 4 || ( xCount == 3 && tCount ==1) ) return "X won";
		return null;
	}
}
