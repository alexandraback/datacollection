package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class MinesweeperMaster {

	public void solve(String file) {
		try {
			Scanner reader = new Scanner(new File(file));
			reader.nextLine(); // skip first line
			int i = 1;
			String line;
			String[] rcm;
			int r;
			int c;
			int m;
			while(reader.hasNextLine()) {
				line = reader.nextLine();
				rcm = line.split(" ");
				r = Integer.parseInt(rcm[0]); 
				c = Integer.parseInt(rcm[1]); 
				m = Integer.parseInt(rcm[2]); 
				System.out.println("Case #" + i + ":");
				solve(r,c,m);
				i++;
			}
		} 
		catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		}
	}
	
	private String solve(int r, int c, int m) {
		if(m >= r * c || isPrimeUnder7(r, c, m)) {
			System.out.println("Impossible");
		}
		else {
			char[][] attempt = new char[r][c];
			for(int rows = r - 1; rows >= 0; rows--) {
				for(int cols = c - 1; cols >= 0; cols--) {
					if(m > 0) {
						attempt[rows][cols] = '*';
						m--;
					}
					else {
						attempt[rows][cols] = '.';
					}
				}
			}
			attempt[0][0] = 'c';
			while((r != 1 && c != 1) && isInvalid(attempt)) {
				update(attempt); 
			}
			print(attempt);
			
			// 1,1 1,2 1,3 1,4 1,5 Easily true or false
			// 2,1 2,2 2,3 2,4 2,5
			// 3,1 3,2 3,3 3,4 3,5
			// 4,1 4,2 4,3 4,4 4,5
			// 5,1 5,2 5,3 5,4 5,5
		}
		// TODO Auto-generated method stub
		return null;
	}

	private void print(char[][] attempt) {
		for(int i = 0; i < attempt.length; i++) {
			for(int j = 0; j < attempt[0].length; j++) {
				System.out.print(attempt[i][j]);
			}
			System.out.println();
		}
	}

	private void update(char[][] attempt) {
		// pick tallest to move rightward
		int[] opening = pickOpening(attempt);
		
		// pick one to move
		int[] moving = pickMoving(attempt, opening[1]);
		
		// then update by taking moving and putting it in the opening
		attempt[opening[0]][opening[1]] = '*';
		attempt[moving[0]][moving[1]] = '.';
	}

	private int[] pickMoving(char[][] attempt, int i) {
		for(int row = 0; row < attempt.length; row++) {
			for(int col = 0; col < i; col++) {
				if(attempt[row][col] == '*') {
					return new int[]{row,col};
				}
			}
		}
		return null;
	}

	private int[] pickOpening(char[][] attempt) {
		// TODO Auto-generated method stub
		char above;
		char below;
		for(int r = 0; r < attempt.length; r++) {
			for(int c = attempt[0].length - 1; c >= 0; c--) {
				above = attempt[r][c];
				below = attempt[r + 1][c];
				if(above  == '.' && below == '*') {
					return new int[]{r,c};
				}
			}
		}
		return null;
	}

	private boolean isInvalid(char[][] attempt) {
		for(int row = 0; row < attempt.length; row++) {
			if(attempt[row][0] == '.' && attempt[row][1] == '*') {
				return true;
			}
		}
		for(int col = 0; col < attempt[0].length; col++) {
			if(attempt[0][col] == '.' && attempt[1][col] == '*') {
				return true;
			}
		}
		return false;
	}

	private boolean isPrimeUnder7(int r, int c, int m) {
		int test = r * c - m; // if 7, 5, 3, 2, it will not work
		
		if(r == 1 || c == 1) { 
			return false;
		}
		else if((r == 2 || c == 2) && (m%2 == 1 && m != r * c -1)) {
			return true;
		}
		else {
			return test == 7 || test == 5 || test == 3 || test == 2;
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		MinesweeperMaster test = new MinesweeperMaster();
		test.solve("C-small-attempt3.in");
		/*
		test.solve(5,5,23);
		test.solve(3,1,1);
		test.solve(4,7,3);
		test.solve(10,10,82);
		test.solve(50,50,2496);
		test.solve(50,50,2497);
		test.solve(50,50,2498);
		test.solve(50,50,2499);
		test.solve(50,50,2500);
		*/
		/*
		for(int r = 1; r <= 5; r++) {
			for(int c = 1; c <= 5; c++) {
				for(int m = 0; m <= r * c; m++) {
					System.out.println(
							"For r = " + r + 
							", c = " + c + 
							", m = " + m + 
							", false, can win, true, can't win | RESULT = " + test.isPrimeUnder7(r,c,m));
				}
			}
 		}
 		*/
		
		/*
		char[][] input = new char[][]{{'c','*','*'},{'*','*','*'},{'*','*','*'}};
		System.out.println(test.isInvalid(input));
		*/
		/*
		int[] r = test.pickOpening(new char[][]{{'c','.','.',','},{'.','.','.','.'},{'.','*','*','*'},{'*','*','*','*'}});
		System.out.println(r[0] + ", " + r[1]);
		
		int[] a = test.pickOpening(new char[][]{{'c','.','.','.'},{'.','.','.','*'},{'.','.','*','*'},{'*','*','*','*'}});
		System.out.println(a[0] + ", " + a[1]);
		*/
		/*
		int[] r = test.pickMoving((new char[][]{{'c','.','.',','},{'.','.','.','.'},{'.','*','*','*'},{'*','*','*','*'}}, 3);
		System.out.println(r[0] + ", " + r[1]);
		
		int[] a = test.pickOpening(new char[][]{{'c','.','.','.'},{'.','.','.','*'},{'.','.','*','*'},{'*','*','*','*'}});
		System.out.println(a[0] + ", " + a[1]);
		//*/
	}

}
