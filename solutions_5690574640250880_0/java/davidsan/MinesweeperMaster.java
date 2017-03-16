package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.List;

// Google Code Jam 2014 
// Problem C. Minesweeper Master

public class MinesweeperMaster {

	int T;
	List<List<Integer>> tests;
	StringBuilder result;
	boolean[][] visite;
	int[][] plateau;
	int cpt = 0;
	int voisins[][] = { { -1, -1 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 1 },
			{ 1, -1 }, { 1, 0 }, { 1, 1 } };
	int R, C, M;
	private int clickY;
	private int clickX;

	public void parcoursLargeur(int rootX, int rootY) {
		List<int[]> file = new ArrayList<int[]>();
		int[] couple = { rootX, rootY };
		file.add(couple);
		visite[rootX][rootY] = true;
		cpt = 1;

		while (!file.isEmpty()) {
			int[] tete = file.remove(0);
			int mark = 1;
			for (int i = 0; i < voisins.length; i++) {
				int nx = tete[0] + voisins[i][0], ny = tete[1] + voisins[i][1];
				if (nx >= 0 && nx < R && ny >= 0 && ny < C
						&& plateau[nx][ny] == 1) {
					mark = 0;

				}
			}
			if (mark != 0) {
				for (int i = 0; i < voisins.length; i++) {
					int nx = tete[0] + voisins[i][0], ny = tete[1]
							+ voisins[i][1];
					if (nx >= 0 && nx < R && ny >= 0 && ny < C
							&& !visite[nx][ny]) {
						visite[nx][ny] = true;
						cpt++;
						int[] tmp = { nx, ny };
						file.add(tmp);
					}
				}
			}
		}
	}

	public int parcoursProfondeur() {
		resetPlateau();
		int i, j, nrofLibre = R * C - M;
		i = 0;
		j = 0;
		/** linéaire, axe horizontal */
		for (int m = 0; m < M; m++) {
			plateau[i][j] = 1;
			if (j == plateau[0].length - 1) {
				j = 0;
				i++;
			} else {
				j++;
			}
		}
		for (int x = 0; x < R; x++) {
			for (int y = 0; y < C; y++) {
				if (plateau[x][y] == 0) {
					cpt = 0;
					resetVisite();
					parcoursLargeur(x, y);
					if (cpt == nrofLibre) {
						clickX = x;
						clickY = y;
						return 1;
					}
				}
			}
		}

		i = 0;
		j = 0;
		/** linéaire, axe vertical */
		for (int m = 0; m < M; m++) {
			plateau[i][j] = 1;
			if (i == plateau.length - 1) {
				i = 0;
				j++;
			} else {
				i++;
			}
		}
		for (int x = 0; x < R; x++) {
			for (int y = 0; y < C; y++) {
				if (plateau[x][y] == 0) {
					cpt = 0;
					resetVisite();
					parcoursLargeur(x, y);
					if (cpt == nrofLibre) {
						clickX = x;
						clickY = y;
						return 1;
					}
				}
			}
		}

		// custom
		for (int k = 0; k < C; k++) {
			for (int k2 = 0; k2 < R; k2++) {
				for (int k3 = 0; k3 < R; k3++) {
					for (int drop = 0; drop < R; drop++) {
						for (int drop2 = 0; drop2 < C; drop2++) {
							resetPlateau();
							i = 0;
							j = 0;
							for (int m = 0; m < M; m++) {
								plateau[i][j] = 1;
								int nj = j;
								if (i >= drop) {
									nj = j + k;
								}
								if (i >= drop2) {
									nj = j + k3;
								}
								if (nj >= plateau[i].length - 1) {
									j = 0;
									i++;
									if (i >= R) {
										break;
									}
								} else {
									j++;
								}
							}

							for (int x = 0; x < R; x++) {
								for (int y = 0; y < C; y++) {
									if (plateau[x][y] == 0) {
										cpt = 0;
										resetVisite();
										parcoursLargeur(x, y);
										if (cpt == nrofLibre) {
											clickX = x;
											clickY = y;
											return 1;
										}
									}
								}
							}

							resetPlateau();
							i = 0;
							j = 0;
							for (int m = 0; m < M; m++) {
								plateau[i][j] = 1;
								int ni = i;
								if (j >= drop) {
									ni = i + k;
								}

								if (j >= drop2) {
									ni = i + k3;
								}
								if (ni >= plateau.length - 1) {
									i = 0;
									j++;
									if (j >= C) {
										break;
									}
								} else {
									i++;
								}
							}

							for (int x = 0; x < R; x++) {
								for (int y = 0; y < C; y++) {
									if (plateau[x][y] == 0) {
										cpt = 0;
										resetVisite();
										parcoursLargeur(x, y);
										if (cpt == nrofLibre) {
											clickX = x;
											clickY = y;
											return 1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		return 0;
	}

	public void resetVisite() {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				visite[i][j] = false;
			}
		}
	}

	public void resetPlateau() {
		for (int i = 0; i < plateau.length; i++) {
			for (int j = 0; j < plateau[0].length; j++) {
				plateau[i][j] = 0;
			}
		}
	}

	public void computeResult() {
		for (int numTest = 0; numTest < T; numTest++) {
			R = tests.get(numTest).get(0);
			C = tests.get(numTest).get(1);
			M = tests.get(numTest).get(2);

			plateau = new int[R][C];
			visite = new boolean[R][C];
			for (int i = 0; i < R; i++) {
				for (int j = 0; j < C; j++) {
					visite[i][j] = false;
					plateau[i][j] = 0;
				}
			}

			result.append("Case #");
			result.append((numTest + 1));
			result.append(": ");
			if (parcoursProfondeur() == 0) {
				result.append(System.lineSeparator());
				result.append("Impossible");
			} else {

				char res[][] = checkBoard();
				if (!isFinished(res)) {
					throw new Error("pb");
				}
				char[][] board = new char[R][C];
				for (int i = 0; i < board.length; i++) {
					for (int j = 0; j < board[0].length; j++) {
						if (clickX == i && clickY == j) {
							board[i][j] = 'c';
						} else if (plateau[i][j] == 0) {
							board[i][j] = '.';
						} else if (plateau[i][j] == 1) {
							board[i][j] = '*';
						}
					}
				}
				for (int i = 0; i < board.length; i++) {
					result.append(System.lineSeparator());
					result.append(String.valueOf(board[i]));
				}
			}
			result.append(System.lineSeparator());
		}
	}

	private boolean isFinished(char[][] plateau) {
		for (int i = 0; i < plateau.length; i++) {
			for (int j = 0; j < plateau[0].length; j++) {
				if (plateau[i][j] == '.') {
					return false;
				}
			}
		}
		return true;
	}

	private char[][] checkBoard() {
		char[][] plateauAfterClick = new char[plateau.length][plateau[0].length];

		for (int i = 0; i < plateauAfterClick.length; i++) {
			for (int j = 0; j < plateauAfterClick[0].length; j++) {
				if (plateau[i][j] == 0) {
					plateauAfterClick[i][j] = '.';
				} else if (plateau[i][j] == 1) {
					plateauAfterClick[i][j] = '*';
				}
			}
		}
		int xc = clickX;
		int yc = clickY;
		plateauAfterClick[xc][yc] = 'c';

		List<int[]> tasks = new ArrayList<int[]>();
		for (int i = -1; i < 2; i++) {
			for (int j = -1; j < 2; j++) {
				int x = xc + i;
				int y = yc + j;
				if (x < 0 || y < 0 || x >= plateauAfterClick.length
						|| y >= plateauAfterClick[0].length) {
					continue;
				}
				char contenu = plateauAfterClick[x][y];
				switch (contenu) {
				case '.':
					int nrofMines = 0;
					for (int i2 = -1; i2 < 2; i2++) {
						for (int j2 = -1; j2 < 2; j2++) {
							int x2 = x + i2;
							int y2 = y + j2;
							if (x2 < 0 || y2 < 0
									|| x2 >= plateauAfterClick.length
									|| y2 >= plateauAfterClick[0].length
									|| (x2 == x && y2 == y)) {
								continue;
							}
							if (plateauAfterClick[x2][y2] == '*') {
								nrofMines++;
							}
						}
					}
					plateauAfterClick[x][y] = Character.forDigit(nrofMines, 10);

					if (plateauAfterClick[x][y] == '0') {
						int coord[] = { x, y };
						tasks.add(coord);
					}
					break;
				default:
					break;
				}

			}
		}

		while (!tasks.isEmpty()) {
			int[] task = tasks.remove(0);
			int xTarget = task[0];
			int yTarget = task[1];
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					int x = xTarget + i;
					int y = yTarget + j;
					if (x < 0 || y < 0 || x >= plateauAfterClick.length
							|| y >= plateauAfterClick[0].length) {
						continue;
					}
					char contenu = plateauAfterClick[x][y];
					switch (contenu) {
					case '.':
						int nrofMines = 0;
						for (int i2 = -1; i2 < 2; i2++) {
							for (int j2 = -1; j2 < 2; j2++) {
								int x2 = x + i2;
								int y2 = y + j2;
								if (x2 < 0 || y2 < 0
										|| x2 >= plateauAfterClick.length
										|| y2 >= plateauAfterClick[0].length
										|| (x2 == x && y2 == y)) {
									continue;
								}
								if (plateauAfterClick[x2][y2] == '*') {
									nrofMines++;
								}
							}
						}
						plateauAfterClick[x][y] = Character.forDigit(nrofMines,
								10);

						if (plateauAfterClick[x][y] == '0') {
							int coord[] = { x, y };
							tasks.add(coord);
						}
						break;
					default:
						break;
					}
				}
			}

		}
		// result.append(System.lineSeparator());
		// result.append("TEST");
		// for (int i = 0; i < plateauAfterClick.length; i++) {
		// result.append(System.lineSeparator());
		// result.append(String.valueOf(plateauAfterClick[i]));
		// }
		// result.append(System.lineSeparator());
		return plateauAfterClick;
	}

	public int nrofMines(char[][] plateau) {
		int cpt = 0;
		for (int i = 0; i < plateau.length; i++) {
			for (int j = 0; j < plateau[0].length; j++) {
				if (plateau[i][j] == '*') {
					cpt++;
				}
			}
		}
		return cpt;
	}

	public MinesweeperMaster(String filename) {
		super();
		tests = new ArrayList<List<Integer>>();
		try {
			readFile(filename);
		} catch (IOException e) {
			e.printStackTrace();
		}

		result = new StringBuilder();
		computeResult();
	}

	public void readFile(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = br.readLine();
		T = Integer.parseInt(line);

		try {
			for (int cpt = 0; cpt < T; cpt++) {
				line = br.readLine();
				String[] param = line.split(" ");
				List<Integer> l = new ArrayList<Integer>();
				for (int j = 0; j < param.length; j++) {
					l.add(Integer.parseInt(param[j]));
				}
				tests.add(l);
			}
		} finally {
			br.close();
		}

	}

	public static void main(String[] args) {
		MinesweeperMaster mt = new MinesweeperMaster(args[0]);
		System.out.println(mt.result.toString());
		PrintWriter writer;
		try {
			writer = new PrintWriter(args[0].substring(0,
					args[0].lastIndexOf('.'))
					+ ".out", "UTF-8");
			writer.println(mt.result.toString());
			writer.close();
		} catch (FileNotFoundException | UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}
}
