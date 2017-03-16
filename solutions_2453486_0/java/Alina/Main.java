import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;


public class Main {
	public static void main(String[] args) throws Exception {
		FileScanner in = new FileScanner("input.txt");
		int n = in.nextInt();
		for (int k = 1; k <= n; k++) {
			boolean hasEmpty = false;
			System.out.print("Case #" + k + ": ");
			char[][] field = new char[4][4];
			for (int i = 0; i < 4; i++) {
				String curr  = in.next();
				for (int j = 0; j < 4; j++) {
					field[i][j] = curr.charAt(j);
					if (field[i][j] == '.') {
						hasEmpty = true;
					}
				}
			}
			
			int row = checkRow(field);
			if (row > 0) {
				if (row == 1) {
					System.out.print("X");
				} else {
					System.out.print("O");
				}
				System.out.println(" won");
				continue;
			}
			
			int column = checkCol(field);
			if (column > 0) {
				if (column == 1) {
					System.out.print("X");
				} else {
					System.out.print("O");
				}
				System.out.println(" won");
				continue;
			}
			
			int diagonal = checkDiag(field);
			if (diagonal > 0) {
				if (diagonal == 1) {
					System.out.print("X");
				} else {
					System.out.print("O");
				}
				System.out.println(" won");
				continue;
			}
			if (hasEmpty) {
				System.out.println("Game has not completed");
			}
			else {
				System.out.println("Draw");
			}
		}
	}
	
	public static int checkDiag(char[][] field){
		char curr = field[0][0];
		if (curr == 'T') {
			curr = field[1][1];
		}
		if (curr != '.') {
			boolean find = true;
			for (int j = 0; j < 4; j++) {
				if (field[j][j] != curr && field[j][j] != 'T') {
					find = false;
					break;
				}
			}
			if (find) {
				if (curr == 'X') {
					return 1;
				}
				return 2;
			}
		}
		
		curr = field[0][3];
		if (curr == 'T') {
			curr = field[1][2];
		}
		if (curr != '.') {
			boolean find = true;
			for (int j = 0; j < 4; j++) {
				if (field[j][3 - j] != curr && field[j][3 - j] != 'T') {
					find = false;
					break;
				}
			}
			if (find) {
				if (curr == 'X') {
					return 1;
				}
				return 2;
			}
		}
		
		return 0;
	}
	
	public static int checkRow(char[][] field){
		for (int i = 0; i < 4; i++){
			char curr = field[i][0];
			if (curr == 'T') {
				curr = field[i][1];
			}
			if (curr == '.') {
				continue;
			}
			boolean find = true;
			for (int j = 0; j < 4; j++) {
				if (field[i][j] != curr && field[i][j] != 'T') {
					find = false;
					break;
				}
			}
			if (find) {
				if (curr == 'X') {
					return 1;
				}
				return 2;
			}
		}
		return 0;
	}
	
	public static int checkCol(char[][] field){
		for (int i = 0; i < 4; i++){
			char curr = field[0][i];
			if (curr == 'T') {
				curr = field[1][i];
			}
			if (curr == '.') {
				continue;
			}
			boolean find = true;
			for (int j = 0; j < 4; j++) {
				if (field[j][i] != curr && field[j][i] != 'T') {
					find = false;
					break;
				}
			}
			if (find) {
				if (curr == 'X') {
					return 1;
				}
				return 2;
			}
		}
		return 0;
	}
	
	public static class FileScanner {
		BufferedReader br;
		StringTokenizer st;

		public FileScanner(String File) throws Exception {
			br = new BufferedReader(new FileReader(File));
		}

		public String getLine() throws IOException {
			return br.readLine();
		}

		String next() throws Exception {
			while (st == null || !st.hasMoreTokens()) {
				st = new StringTokenizer(br.readLine());
			}
			return st.nextToken();
		}

		public int nextInt() throws Exception {
			return Integer.parseInt(next());
		}

		public long nextLong() throws Exception {
			return Long.parseLong(next());
		}

		public double nextDouble() throws Exception {
			return Double.parseDouble(next());
		}
	}
}
