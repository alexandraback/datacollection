import java.io.*;
import java.util.*;

public class MinesweeperMaster {
	public static Scanner sc;
	public static int m[][];
	public static int h;
	public static int w;
	public static int mine;
	public static int mine2;
	
	public static String solve() {
		init();

		if (mine == 0)
			return toS();
		
		if (mine == w * h - 1) {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					m[i][j] = 1;
				}
			}
			m[h-1][w-1] = 0;
			return toS();
		}
		
		if (w == 1) {
			if (mine == h) {
				return "Impossible\n";
			} else {
				for (int i = 0; i < mine; i++) {
					m[i][0] = 1;
				}
				return toS();
			}
		}
		
		if (h == 1) {
			if (mine == w) {
				return "Impossible\n";
			} else {
				for (int j = 0; j < mine; j++) {
					m[0][j] = 1;
				}
				return toS();
			}
		}
		
		if (h == 2) {
			if (mine % 2 == 1 || mine == w * h - 2 || mine == w * h) {
				return "Impossible\n";
			} else {
				for (int j = 0; mine > 0;j++) {
					m[0][j] = 1;
					m[1][j] = 1;
					mine -= 2;
				}
				return toS();
			}
		}
		
		if (w == 2) {
			if (mine % 2 == 1 || mine == w * h - 2 || mine == w * h) {
				return "Impossible\n";
			} else {
				for (int i = 0; mine > 0; i++) {
					m[i][0] = 1;
					m[i][1] = 1;
					mine -= 2;
				}
				return toS();
			}
		}
		
//		if (h == 3) {
//			if (mine % 3 == 2 || mine == w * h - 2 || mine == w * h - 3) {
//				return h + " " + w + " " + mine2 + " Impossible\n";
//			} else {
//				for (int j = 0; j < w; j++) {
//					for (int i = 0; i < 3 && mine > 0; i++) {
//						m[i][j] = 1;
//						mine--;
//					}
//				}
//				return toS();
//			}
//		}
//		
//		if (w == 3) {
//			if (mine % 3 == 2 || mine == w * h - 2 || mine == w * h - 3) {
//				return h + " " + w + " " + mine2 + " Impossible\n";
//			} else {
//				for (int i = 0; i < h; i++) {
//					for (int j = 0; j < 3 && mine > 0; j++) {
//						m[i][j] = 1;
//						mine--;
//					}
//				}
//				return toS();
//			}
//		}
		
		int jt = 0;
		int it = 0;
		int a = 0;
		int kkk = 0;
		while (a < 2) {
			if (h - it > w - jt) {
				if (it < h - 2) {
					for (int j = jt; j < w; j++) {
						if (j == w - 2 && mine == 1)
							break;
						m[it][j] = 1;
//						System.out.println(toS());
						mine--;
						if (mine == 0)
							return toS();
					}
					it++;
//					System.out.println(kkk++ + "\n" + toS());
				} else {
					a++;
				}
			} else {
				if (jt < w - 2) {
					for (int i = it; i < h; i++) {
						if (i == h - 2 && mine == 1)
							break;
						m[i][jt] = 1;
//						System.out.println( toS());
						mine--;
						if (mine == 0)
							return toS();
					}
					jt++;
//					System.out.println(kkk++ + "\n" + toS());
				} else {
					a++;
				}
			}
		}
		
		return "Impossible\n";
//		return h + " " + w + " " + mine2 + " Impossible\n";
	}


	public static void init() {
		h = sc.nextInt();
		w = sc.nextInt();
		m = new int[h][w];
		mine = sc.nextInt();
		mine2 = mine;
//		System.out.println(h + " " + w + " " + mine2);
	}
	
	public static String toS() {
//		return "";
		String map = "";
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (m[i][j] == 1) {
					map += "*";
				} else {
					map += ".";
				}
			}
			map += "\n";
		}
		map = map.substring(0, map.length() - 2) + "c\n";
//		return mine2 + "\n" + map;
		return map;
	}
	
	public static void main(String[] args) throws Exception {
//		for (int i = 0; i < 21; i++) {
//			System.out.print(" 4 5 " + i);
//		}
		
//		sc = new Scanner(System.in);
		sc = new Scanner(new File("E:\\GitHub\\HHH\\CodeJam\\MinesweeperMaster\\C-small-attempt2.in"));
		int c = sc.nextInt();
		
		String sol = "";
		for (int i = 1; i <= c; i++)
			sol += "Case #" + i + ":\n" + solve();
		
		System.out.print(sol);
		PrintWriter pw = new PrintWriter(new File("E:\\GitHub\\HHH\\CodeJam\\MinesweeperMaster\\C-small-attempt2.out"));
		pw.print(sol);
		pw.close();
	}
}
//
////Problem
////
////Minesweeper is a computer game that became popular in the 1980s, and is still included in some versions of the Microsoft Windows operating system. This problem has a similar idea, but it does not assume you have played Minesweeper.
////
////In this problem, you are playing a game on a grid of identical cells. The content of each cell is initially hidden. There are M mines hidden in M different cells of the grid. No other cells contain mines. You may click on any cell to reveal it. If the revealed cell contains a mine, then the game is over, and you lose. Otherwise, the revealed cell will contain a digit between 0 and 8, inclusive, which corresponds to the number of neighboring cells that contain mines. Two cells are neighbors if they share a corner or an edge. Additionally, if the revealed cell contains a 0, then all of the neighbors of the revealed cell are automatically revealed as well, recursively. When all the cells that don't contain mines have been revealed, the game ends, and you win.
////
////For example, an initial configuration of the board may look like this ('*' denotes a mine, and 'c' is the first clicked cell):
////
////*..*...**.
////....*.....
////..c..*....
////........*.
////..........
////
////There are no mines adjacent to the clicked cell, so when it is revealed, it becomes a 0, and its 8 adjacent cells are revealed as well. This process continues, resulting in the following board:
////
////*..*...**.
////1112*.....
////00012*....
////00001111*.
////00000001..
////
////At this point, there are still un-revealed cells that do not contain mines (denoted by '.' characters), so the player has to click again in order to continue the game.
////
////You want to win the game as quickly as possible. There is nothing quicker than winning in one click. Given the size of the board (R x C) and the number of hidden mines M, is it possible (however unlikely) to win in one click? You may choose where you click. If it is possible, then print any valid mine configuration and the coordinates of your click, following the specifications in the Output section. Otherwise, print "Impossible".
////Input
////
////The first line of the input gives the number of test cases, T. T lines follow. Each line contains three space-separated integers: R, C, and M.
////Output
////
////For each test case, output a line containing "Case #x:", where x is the test case number (starting from 1). On the following R lines, output the board configuration with C characters per line, using '.' to represent an empty cell, '*' to represent a cell that contains a mine, and 'c' to represent the clicked cell.
////
////If there is no possible configuration, then instead of the grid, output a line with "Impossible" instead. If there are multiple possible configurations, output any one of them.
////Limits
////
////0 ¡Ü M < R * C.
////Small dataset
////
////1 ¡Ü T ¡Ü 230.
////1 ¡Ü R, C ¡Ü 5.
////Large dataset
////
////1 ¡Ü T ¡Ü 140.
////1 ¡Ü R, C ¡Ü 50.
////Sample
////
////Input
////
////5
////5 5 23
////3 1 1
////2 2 1
////4 7 3
////10 10 82
////
////
////Output
////	
////Case #1:
////Impossible
////Case #2:
////c
////.
////*
////Case #3:
////Impossible
////Case #4:
////......*
////.c....*
////.......
////..*....
////Case #5:
////**********
////**********
////**********
////****....**
////***.....**
////***.c...**
////***....***
////**********
////**********
////**********
