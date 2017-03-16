package TicTacToeTomek;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class TicTacToeTomek {
	

	
	public static void main(String[] argv) throws IOException {

		System.out.println(System.getProperty("user.dir"));

		File file = new File("./src/TicTacToeTomek/C-small-attempt3.in");
		FileInputStream fis = new FileInputStream(file);
		BufferedReader br = new BufferedReader(new InputStreamReader(fis));
		
		ArrayList<String> resultList = new ArrayList<String>();
		
		int num = Integer.parseInt(br.readLine());
		
		String[] line = new String[3];
		
		for (int i = 0; i < num; i++) {
			System.out.println("Case #" + (i + 1) + ": ");
			line = br.readLine().split(" ");
			getResult(line, resultList);
		}
		
//		for (int i = 0; i < resultList.size(); i++) {
//			System.out.println("Case #" + (i + 1) + ": " + resultList.get(i));
//		}
		
	}
	
	public static void getResult(String[] line, ArrayList<String> resultList) {
	
		int row = Integer.parseInt(line[0]);
		int col = Integer.parseInt(line[1]);
		int mine = Integer.parseInt(line[2]);
		
		board b = new board(row, col);
		
		if (b.subRecurse(row, col, mine) == true) {
			for (int i = 0; i < b.content.length; i++) {
				resultList.add(String.valueOf(b.content[i]));
				System.out.println(String.valueOf(b.content[i]));
			}
		}
		else {
			resultList.add("Impossible");
			System.out.println("Impossible");
		}
		return;
	}
	
	public static class board {
		int row;
		int col;
		boolean plotRow = false;
		boolean plotCol = false;
		char[][] content;
		public board(int r, int c) {
			row = r;
			col = c;
			content = new char[r][c];
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					content[i][j] = '.';
				}
			}
		}
		
		public void drawRowStar(int r) {
			for (int i = 0; i < col; i++) {
				content[r - 1][i] = '*';
			}
			plotRow = true;
		}
		
		public void drawColStar(int c) {
			for (int i = 0; i < row; i++) {
				content[i][c - 1] = '*';
			}
			plotCol = true;
		}
		
		public void mergeTmp(char[][] tmp, int r, int c) {
			int rowOffset = 0;
			int colOffset = 0;
			
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					content[rowOffset + i][colOffset + j] = tmp[i][j];
				}
			}
		}
		
		
		public void constructBase(int r, int c, int mine) {
			int i = 0;
			int j = 0;
			
			char[][] tmp = new char[r][c];
			for (i = 0; i < r; i++) {
				for (j = 0; j < c; j++) {
					tmp[i][j] = '.';
				}
			}
			
			if (mine == 0 || mine == 1) {
				if (mine == 1)
					tmp[r - 1][c - 1] = '*';
				tmp[0][0] = 'c';
				mergeTmp(tmp, r, c);
				return;
			}
			
			if (mine == 2) {
				tmp[r - 1][c - 1] = '*';
				tmp[r - 1][c - 2] = '*';
				tmp[0][0] = 'c';
				mergeTmp(tmp, r, c);
				return;
			}
			if (mine == 3) {
				tmp[r - 1][c - 1] = '*';
				tmp[r - 1][c - 2] = '*';
				tmp[r - 2][c - 1] = '*';
				tmp[0][0] = 'c';
				mergeTmp(tmp, r, c);
				return;
			}
			
			if (r >= 4 && c >= 4) {
				for (int k = 1; k <= mine; k++) {
					if (k == 1) {
						tmp[r - 1][c - 1] = '*';
					}
					if (k == 2) {
						tmp[r - 2][c - 1] = '*';
					}
					if (k == 3) {
						tmp[r - 1][c - 2] = '*';
					}
					if (k > 3) {
						tmp[r - 1][c - k + 1] = '*';
					}
				}
				tmp[(r / 2)][(c / 2) - 1] = 'c';
				mergeTmp(tmp, r, c);
				return;
			}
			
			
			
		}
		
		public boolean isPossible(int r, int c, int mine) {
			if ( ( (r == 2 && c > 1) || (r > 1 && c == 2) ) && mine == 1)
				return false;
//			if (r == 4 && (c == 5 || c == 4) && mine == 3)
//				return false;
//			if (r == 5 && c == 4 && mine == 3)
//				return false;
			if (r == 3 && c == 3 && mine == 2)
				return false;
			if ( ( (r == 2 && c == 3) || (r == 3 && c == 2) ) && mine == 1)
				return false;
			if (r == 2 && c == 2 && mine == 1)
				return false;
			if ((r == 1 && c == 2 && plotRow == true) || (r == 2 && c == 1 && plotCol == true) && mine == 0 )
				return false;
			else return true;
		}
	
		public boolean subRecurse(int row, int col, int mine) {
			
			int tmp = Math.min(row, col);
			
			if (mine < tmp) {
				if (isPossible(row, col, mine)) {
					constructBase(row, col, mine);
					return true;
				}
				else return false;
			}
			else {	
				if (row < col) {
					drawColStar(col);
					return subRecurse(row, col - 1, mine - row);
				}
				else {
					drawRowStar(row);
					return subRecurse(row - 1, col, mine - col);	
				}
			}
		}
	}
	
}