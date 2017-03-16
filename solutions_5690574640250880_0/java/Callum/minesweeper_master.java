import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class minesweeper_master {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt1.in"));
		PrintWriter pw = new PrintWriter("C-small.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 0; test < t; test++) {
			pw.println("Case #" + (test + 1) + ":");
			StringTokenizer st = new StringTokenizer(br.readLine());
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());
			int o = r * c - m;
			
			char[][] field = new char[r][c];
			
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					field[i][j] = '*';
				}
			}
			
			field[0][0] = '1';
			
			field = recurse(field.clone(), o - 1);
			
			if (field != null) {
				field[0][0] = 'c';
				for (int i = 0; i < r; i++) {
					for (int j = 0; j < c; j++) {
						if (field[i][j] == '1') {
							pw.print('.');
						} else {
							pw.print(field[i][j]);
						}
					}
					pw.println();
				}
			} else {
				pw.println("Impossible");
			}
		}
		
		br.close();
		pw.close();
	}
	
	public static char[][] recurse(char[][] field, int o) {
		if (o < 0) {
			return null;
		}
		if (o == 0) {
			return field;
		}
		
		for (int i = 0; i < field.length; i++) {
			for (int j = 0; j < field[0].length; j++) {
				if (field[i][j] == '1') {
					char[][] temp = new char[field.length][field[0].length];
					for (int q = 0; q < field.length; q++) {
						temp[q] = Arrays.copyOf(field[q], field[q].length);
					}
					int tempo = o;
					temp[i][j] = '.';
					if (i > 0) {
						if (temp[i - 1][j] == '*') {
							temp[i - 1][j] = '1';
							tempo--;
						}
						if (j > 0) {
							if (temp[i - 1][j - 1] == '*') {
								temp[i - 1][j - 1] = '1';
								tempo--;
							}
						}
						if (j < field[0].length - 1) {
							if (temp[i - 1][j + 1] == '*') {
								temp[i - 1][j + 1] = '1';
								tempo--;
							}
						}
					}
					if (j > 0) {
						if (temp[i][j - 1] == '*') {
							temp[i][j - 1] = '1';
							tempo--;
						}
					}
					if (j < temp[0].length - 1) {
						if (temp[i][j + 1] == '*') {
							temp[i][j + 1] = '1';
							tempo--;
						}
					}
					if (i < field.length - 1) {
						if (temp[i + 1][j] == '*') {
							temp[i + 1][j] = '1';
							tempo--;
						}
						if (j > 0) {
							if (temp[i + 1][j - 1] == '*') {
								temp[i + 1][j - 1] = '1';
								tempo--;
							}
						}
						if (j < temp[0].length - 1) {
							if (temp[i + 1][j + 1] == '*') {
								temp[i + 1][j + 1] = '1';
								tempo--;
							}
						}
					}
					char[][] tep = recurse(temp.clone(), tempo);
					if (tep != null) {
						return tep;
					}
				}
			}
		}
		
		return null;
	} 
}