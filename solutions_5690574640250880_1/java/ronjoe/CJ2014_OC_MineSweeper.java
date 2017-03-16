package org.rtc.codeJam;

import java.io.*;
import java.util.Arrays;
import java.util.List;

public class CJ2014_OC_MineSweeper {

	public CJ2014_OC_MineSweeper(String inFile, String outFile) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			int numCases = getInt(br);
			for (int i = 0; i < numCases; i++) {
				String line = br.readLine();
				String[] nums = line.split(" +");

				int rows = Integer.parseInt(nums[0]);
				int cols = Integer.parseInt(nums[1]);
				int mines = Integer.parseInt(nums[2]);
				int clear = cols * rows - mines;

				String outStr = "Case #" + (i + 1) + ":";
				put(bw, outStr);
				// put(bw, rows + " " + cols + " " + mines + " " + clear);

				List<Integer> imposs1 = Arrays.asList(2, 3, 5, 7);

				boolean isOdd = clear % 2 == 1;
				boolean isSingleRow = rows == 1 || cols == 1;
				boolean isPossible;

				if (isSingleRow) {
					isPossible = clear > 0;
				} else if (clear == 1) {
					isPossible = true;
				} else if (imposs1.contains(clear)) {
					isPossible = false;
				} else if (isOdd && (cols == 2 || rows == 2)) {
					isPossible = false;
				} else {
					isPossible = (clear >= 4 || clear == 1);
				}

				char[][] board = null;

				if (!isPossible) {
					put(bw, "Impossible");

				} else if (clear == 1) {
					board = createBoard(rows, cols, '*');
					board[0][0] = 'c';

				} else if (isSingleRow) {
					board = createBoard(rows, cols, '.');
					int numMines = 0;
					out:
					for (int x = 0; x < cols; x++) {
						for (int y = 0; y < rows; y++) {
							if (numMines < mines) {
								board[x][y] = '*';
								numMines++;
								if (numMines == mines) {
									break;
								}
							}
						}
					}
					board[cols - 1][rows - 1] = 'c';

				} else {
					board = createBoard(rows, cols, '*');

					boolean ok = false;
					boolean shift = false;
					int c = cols;
					while (c >= 2) {
						int rows2fill = clear / c;
						int finalRow = clear % c;
						if (rows2fill == 2 && finalRow != 1) {
							ok = true;
						} else if (rows2fill > 2) {
							if (finalRow == 1) {
								shift = true;
							}
							ok = true;
						}
						if (ok) {
							break;
						}
						c--;
					}

					if (!ok) {
						put(bw, "NOT OK!");
					}

					int numClear = 0;
					out:
					for (int y = 0; y < rows; y++) {
						for (int x = 0; x < c; x++) {
							if (numClear == clear - 2 && shift) {
								shift = false;
							} else {
								board[x][y] = '.';
								numClear++;
								if (numClear == clear) {
									break out;
								}
							}
//							show(bw, board);
//							put(bw, "");
						}
					}

					board[0][0] = 'c';
				}

				if (isPossible) {
					show(bw, board);
				}
				// bw.newLine();
			}
			br.close();
			bw.close();

		} catch (Exception e) {
			System.err.println(e);
		}
	}

	public static void main(String[] args) {
		// String fileName = args[0];
		// String fileName = "inMineSweeper.txt";
		// String fileName = "C-small-attempt1.in";
		String fileName = "C-large.in";
		new CJ2014_OC_MineSweeper(fileName, "out.txt");
	}

	private char[][] createBoard(int rows, int cols, char ch) {
		char[][] board = new char[cols][rows];
		for (int x = 0; x < cols; x++) {
			for (int y = 0; y < rows; y++) {
				board[x][y] = ch;
			}
		}
		return board;
	}

	public void CJ2014_OC_MineSweeper_OLD(String inFile, String outFile) {
		try {
			BufferedReader br = new BufferedReader(new FileReader(inFile));
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
			int numCases = getInt(br);
			for (int i = 0; i < numCases; i++) {
				String line = br.readLine();
				String[] nums = line.split(" +");

				int cols = Integer.parseInt(nums[0]);
				int rows = Integer.parseInt(nums[1]);
				int mines = Integer.parseInt(nums[2]);

				String outStr = "Case #" + (i + 1) + ":";
				put(bw, outStr);

				boolean isSpecial = (rows == 1 || cols == 1) || mines == cols * rows - 1;
				boolean possible = true;
				if (rows == 1 || cols == 1) {
					possible = (mines < cols || mines < rows);
				} else if (mines > cols * rows - 4 && !isSpecial) {
					possible = false;
				}

				if (!possible) {
					put(bw, "Impossible");
				} else {
					char[][] board = new char[rows][cols];
					for (int x = 0; x < rows; x++) {
						for (int y = 0; y < cols; y++) {
							board[x][y] = '.';
						}
					}
					//show(bw, board);

					int numM = 0;
					int rcMax = cols > rows ? cols : rows;
					OUT:
					for (int xx = 0; xx < rcMax * 2; xx++) {
						int x = xx;
						int y = 0;
						while (x >= 0) {
							if (!isSpecial && x >= rows - 2 && y >= cols - 2) {
								System.out.println("skip");
							} else if (x < rows && y < cols && numM < mines) {
								board[x][y] = '*';
								numM++;
								if (numM == mines) {
									break OUT;
								}
								//show(bw, board);
							}
							x--;
							y++;
						}
					}

					board[rows - 1][cols - 1] = 'c';
					show(bw, board);
				}

				// System.out.println(outStr);
				// bw.write(outStr, 0, outStr.length());
				bw.newLine();
			}
			br.close();
			bw.close();

		} catch (Exception e) {
			System.err.println(e);
		}
	}

	private void show(BufferedWriter bw, char[][] board) throws IOException {
		StringBuilder out = new StringBuilder();
		int cols = board[0].length;
		int rows = board.length;
		for (int y = 0; y < cols; y++) {
			for (int x = 0; x < rows; x++) {
				out.append(board[x][y]);
			}
			put(bw, out.toString());
			out.delete(0, out.length());
		}
	}

	private void put(BufferedWriter bw, String s) throws IOException {
		System.out.println(s);
		bw.write(s, 0, s.length());
		bw.newLine();
	}

	private int getInt(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Integer.parseInt(line);
	}

	private double getDouble(BufferedReader br) throws IOException {
		String line = br.readLine();
		return Double.parseDouble(line);
	}

	private int[] getSet(BufferedReader br, int row) throws IOException {
		String[] set1 = null;
		for (int i = 0; i < 4; i++) {
			String nums = br.readLine();
			if (i == row - 1) {
				set1 = nums.split(" ");
			}
		}
		int[] set = new int[4];
		for (int i = 0; i < 4; i++) {
			set[i] = Integer.parseInt(set1[i]);
		}
		return set;
	}
}
