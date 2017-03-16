package codejam.e2014;

import java.util.Locale;
import java.util.Random;
import java.util.Scanner;

public class C {

	static boolean debug = false;
	
	static int R;
	static int C;
	static int M;

	static int mines;
	static int spaces;
	
	static int minWidth;
	
	static boolean swapped;
	static int minX;
	static int maxY;
	static byte board[][];
	
	private static void initBoard() {
		mines = M;
		spaces = R * C - mines;
		
		board = new byte[R][C];
		board[R-1][C-1] = 2;
		
		if (R < C) {
			swapped = false;
			minX = R;
			maxY = C;
		} else {
			swapped = true;
			minX = C;
			maxY = R;
		}		
	}

	private static void printResult() {
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if (board[i][j] == 0)
					System.out.print('.');
				else if (board[i][j] == 2)
					System.out.print('c');
				else
					System.out.print('*');
			}
			System.out.println();				
		}
	}

	private static void set(int x,int y) {
		if (swapped) {
			if (board[x][y] == 0) {
				board[x][y] = 1;
				mines--;
			}
		} else {
			if (board[y][x] == 0) {
				board[y][x] = 1;
				mines--;
			}
		}
	}

	private static void setSpecial(int minWidth, int heigth) {
		int x = minX-minWidth;
		int y = maxY-heigth+1;
		if (debug)
			System.out.println("Setting special at "+x+" "+y);
		set(y,x);
	}
	
	private static void fill() {
		for(int i=0; i<maxY; i++) {
			for(int j=0; j<minX; j++) {
				if (mines == 0)
					return;
				set(i,j);
			}
		}
	}

	private static void fillSmallTo(int minWidth) {
		for(int i=0; i<minX-minWidth; i++) {
			for(int j=0; j<maxY; j++) {
				if (mines == 0)
					return;
				set(j,i);
			}
		}
		if (debug) {
			System.out.println("After fill");
			printResult();
		}
	}
	
	private static void handleCase(int nr) {
		initBoard();

		System.out.println("Case #"+nr+":");
		if (debug)
			System.out.println(""+R+"x"+C+" "+M);
		
		if (mines == 0) {
			printResult();
			return;
		}
		
		if (spaces == 1) {
			fill();
			printResult();
			return;
		}

		if (minX == 1) {
			fill();
			printResult();
			return;
		}

		if (minX == 2) {
			if (spaces % 2 == 1 || spaces == 2) {
				System.out.println("Impossible");
				return;
			}
			fill();
			printResult();
			return;
		}

		// Minimum 3*3
		if (spaces == 2 || spaces == 3 || spaces == 5 || spaces == 7) {
			System.out.println("Impossible");
			return;
		}
		
		for(int minWidth=2; minWidth<=minX; minWidth++) {
			int heigth = ((spaces+minWidth-1)/minWidth);
			if (debug)
				System.out.println("Attempt "+minWidth+"x"+heigth+" "+spaces);
			if (heigth < 2)
				break;
			if (maxY < heigth)
				continue;
			if (spaces % minWidth == 1) {
				if (heigth < 4 || minWidth < 3)
					continue;
				fillSmallTo(minWidth);
				setSpecial(minWidth,heigth);
				fill();
				printResult();
				return;
			}
			fillSmallTo(minWidth);
			fill();
			printResult();
			return;
		}
		
		System.out.println("Not done: "+R+" "+C+" "+M);
		throw new RuntimeException();
		
		
	}
	
	public static void test() {
		R = 4;
		C = 7;
		M = 3;
		handleCase(1);

		R = 7;
		C = 4;
		M = 3;
		handleCase(1);

		R = 8;
		C = 3;
		M = 11;
		handleCase(1);

		
		if (false) {
			Random r = new Random();

			while(true) {
				R = 1+r.nextInt(10);
				C = 1+r.nextInt(10);
				M = r.nextInt(R*C);
				handleCase(1);
			}
		}


		R = 3;
		C = 10;
		M = 2;
		handleCase(1);

		R = 3;
		C = 3;
		M = 5;
		handleCase(1);

		R = 1;
		C = 1;
		M = 0;
		handleCase(1);

		R = 1;
		C = 10;
		M = 0;
		handleCase(1);

		R = 1;
		C = 10;
		M = 3;
		handleCase(1);

		R = 2;
		C = 10;
		M = 1;
		handleCase(1);

		R = 2;
		C = 10;
		M = 4;
		handleCase(1);

		R = 2;
		C = 10;
		M = 16;
		handleCase(1);
		
		R = 2;
		C = 10;
		M = 17;
		handleCase(1);
		
		R = 2;
		C = 10;
		M = 18;
		handleCase(1);

		R = 2;
		C = 10;
		M = 19;
		handleCase(1);
	}
	
	public static void main(String[] args) {
		if (debug) {
			test();
			return;
		}
		
		Scanner scanner = new Scanner(System.in).useLocale(Locale.US);
		int cases = scanner.nextInt();
		
		for(int i=0;i<cases; i++) {
			R = scanner.nextInt();
			C = scanner.nextInt();
			M = scanner.nextInt();
			
			handleCase(i+1);
		}
	}

}
