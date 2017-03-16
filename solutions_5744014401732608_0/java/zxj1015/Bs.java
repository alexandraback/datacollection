import java.util.Arrays;
import java.util.*;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigDecimal;

public class Main {
	
	public static void main(String[] args) {
		init();
		Scanner scanner = new Scanner(System.in);
		int cases = scanner.nextInt();
		for (int i = 0; i < cases; ++i) {
			int N = scanner.nextInt();
			long T = scanner.nextLong();
			boolean[][] board = new boolean[N][];
			for (int j = 0; j < N; ++j) {
				board[j] = new boolean[N];
			}
			long upper = 1 << ((N - 1) * N / 2);
			boolean flag = false;
			for (long k = 0; k < upper; ++k) {
				fillBoard(board, k);
				//printBoard(board);
				long num = calNum(board);
				if (num == T) {
					flag = true;
					break;
				}
			}
			if (flag) {
				System.out.printf("Case #%d: POSSIBLE\n", i + 1);
				for (int p = 0; p < N; ++p) {
					for (int j = 0; j < N; ++j) {
						System.out.print(board[p][j] ? '1' : '0');
					}
					System.out.println();
				}
			} else {
				System.out.printf("Case #%d: IMPOSSIBLE\n", i + 1);
			}
		}
	}
	
	static long calNum(boolean[][] board) {
		long[] dp = new long[board.length];
		dp[0] = 1;
		for (int i = 1; i < board.length; ++i) {
			for (int j = 0; j < i; ++j) {
				if (board[j][i]) {
					dp[i] += dp[j];
				}
			}
		}
		return dp[board.length - 1];
	}
	
	static void fillBoard(boolean[][] board, long index) {
		int counter = 0;
		for (int i = 0; i < board.length; ++i) {
			for (int j = i + 1; j < board.length; ++j) {
				if (((index >> counter) & 1) == 1) {
					board[i][j] = true;
				} else {
					board[i][j] = false;
				}
				++counter;
			}
		}
	}
	
	static void printBoard(boolean[][] board) {
		for (int i = 0; i < board.length; ++i) {
			for (int j = 0; j < board.length; ++j) {
				System.out.print(board[i][j] ? '1' : '0');
			}
			System.out.println();
		}
		System.out.println("===============");
	}

	
	
	
	
	
	
	
	
	
	public static void init() {
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("/Users/zxj/Documents/workspace/Algorithm/src/test.in");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
        System.setIn(fis); 
	}
}

