package com.google.codejam2014;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class MineSweeper2 {
	
	public static int dx[]=	new int[] {0, 0, 0, 1, 1, 1, -1, -1, -1};
	public static int dy[]=	new int[] {0, -1, 1, -1, 0, 1, -1, 0, 1};	
	public static int r, c;
	public static char[][][] Sol;
	
	public static class Node {
		public int m;
		public char[][] board;
		public int[][] cnt;
		public Node (char[][] board, int[][] cnt) {
			this.board=	new char[board.length][];
			for (int i=	0; i < board.length; ++i) this.board[i]=	board[i].clone ();
			this.cnt=	new int[cnt.length][];
			for (int i=	0; i < cnt.length; ++i) this.cnt[i]=	cnt[i].clone (); 			
		}
		public void compute () {
			m=	0;
			for (int x=	0; x < r; ++x) {
				for (int y=	0; y < c; ++y) {
					m+=	board[x][y] == '*' ? 1 : 0;
					cnt[x][y]=	0;
					for (int k=	0; k < 9; ++k) {
						int x2=	x + dx[k];
						int y2=	y + dy[k];
						if (0 <= x2 && x2 < r && 0 <= y2 && y2 < c && board[x2][y2] == '*') {
							cnt[x][y]++;
						}
					}
				}
			}
		}
		public void set (int x, int y) {
			for (int k=	1; k < 9; ++k) {	// skipping itself
				int x2=	x + dx[k];
				int y2=	y + dy[k];
				if (0 <= x2 && x2 < r && 0 <= y2 && y2 < c && board[x2][y2] == '*') board[x2][y2]=	'.';
			}			
		}
	}
	
	public static void copy (int m, char[][] board) {
		Sol[m]=	new char[r][c];
		for (int i=	0; i < r; ++i) Sol[m][i]=	board[i].clone ();
	}

	public static void main(String[] args) throws Exception {

		Scanner scanner=	new Scanner (new BufferedReader(new FileReader ("/Users/dongcaishen/0411/C-small-attempt2.in")));
//		Scanner scanner=	new Scanner (System.in);
		int nTests=	scanner.nextInt();
		for (int iTest=	1; iTest <= nTests; ++iTest) {
			System.out.println ("Case #" + iTest + ":");
			r=	scanner.nextInt ();
			c=	scanner.nextInt ();
			int m=	scanner.nextInt ();
			// special case
			if (m == r * c - 1) {
				char[][] board=	new char[r][c];
				for (char[] row : board) Arrays.fill (row, '*');
				board[0][0]=	'c';
				output (board);
				continue;
			}
//		r=	5;
//		c=	5;
		Sol=	new char[r * c + 1][][];
		
//		Queue<Node> Q=	new PriorityQueue<Node> ();
		Queue<Node> Q=	new LinkedList<Node> ();
		char[][] board=	new char[r][c];
		int[][] cnt=	new int[r][c];
		for (char[] row : board) Arrays.fill (row, '*');
		for (int[] row : cnt) Arrays.fill (row, 0);
		// corner: r * c - 4
		Node p=	new Node ( board, cnt);
		p.board[0][0]=	'c';
		p.set (0, 0);
		p.compute ();
		Q.add (p);
		copy (p.m, p.board);
		// edge not on corner: r * c - 6
		p=	new Node (board, cnt);
		p.board[0][c / 2]=	'c';
		p.set (0, c / 2);
		p.compute ();
		Q.add (p);
		copy (p.m, p.board);
		// middle: r * c - 9,
		p=	new Node (board, cnt);
		p.board[r / 2][c / 2]=	'c';
		p.set (r / 2, c / 2);
		p.compute ();
		Q.add (p);
		copy (p.m, p.board);
		
		while (!Q.isEmpty ()) {
			p=	Q.poll ();
//			if (Sol[p.m] != null) continue;
			for (int x=	0; x < r; ++x) {
				for (int y=	0; y < c; ++y) {
					if (p.board[x][y] != '*' && p.cnt[x][y] != 0 && Sol[p.m - p.cnt[x][y]] == null) {
						Node q=	new Node (p.board, p.cnt);
						// set all neighbors to '.'
						q.set (x,  y);
						q.compute ();
						Q.add (q);
						copy (q.m, q.board);
					}
				}
			}
		}
		
//		for (int i=	0; i <= r * c; ++i) {
//			System.out.println ("M=" + i);
//			board=	Sol[i];
//			if (board == null)  {
//				System.out.println ("Impossible");
//			} else {
//				for (int x=	0; x < r; ++x) {
//					for (int y=	0; y < c; ++y) {
//						System.out.print (board[x][y]);
//					}
//					System.out.println ();
//				}
//			}
//			System.out.println ();
//		}
		board=	Sol[m];
		if (board == null) {
			System.out.println ("Impossible");
		} else {
			output (board);
		}
		}
		scanner.close ();
	}
	
	public static void output (char[][] board) {
		for (int x=	0; x < r; ++x) {
			for (int y=	0; y < c; ++y) {
				System.out.print (board[x][y]);
			}
			System.out.println ();
		}
	}

}
