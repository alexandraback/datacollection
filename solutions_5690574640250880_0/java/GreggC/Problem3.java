package com.greggc.codejam;

import java.io.File;
import com.greggc.codejam.utils.FileUtils;

public class Problem3 {
private static final String FILE_NAME = "C-small-attempt2";
	
	public void solve() {
		StringBuilder builder = new StringBuilder();
		File input = new File(FILE_NAME + ".in");
		if (input.exists()) {
			String[] strings = FileUtils.getFileAsString(input);
			int nbTestCases = Integer.parseInt(strings[0]);
			
			for (int i = 0; i < nbTestCases; i++){
				// Algo
				String[] params = strings[i + 1].split(" ");
				int width = Integer.parseInt(params[0]);
				int height = Integer.parseInt(params[1]);
				int nbMines = Integer.parseInt(params[2]);
				
				builder.append(String.format(
						"Case #%s:\n%s",
						i + 1,
						this.getOutput(width, height, nbMines)));
			}
			
			FileUtils.stringToFile(builder.toString(), FILE_NAME + ".out");
		}
	}
	
	public String getOutput(int width, int height, int nbMines) {		
		boolean[][] map = new boolean[width][height];
		map[0][0] = true;
		
		int nbNonMines = ((width * height) - nbMines);
		
		int totalCurrentNonMines = this.getNewAdjacentCellsNb(0, 0, map, width, height) + 1;

		if (height > 1) {
			map[0][1] = true;
		}
		if (width > 1) {
			map[1][0] = true;
		}
		if (height > 1 && width > 1) {
			map[1][1] = true;
		}
		
		int bestWeight = 50;
		int bestX = 0;
		int bestY = 0;
		boolean foundPerfect = false;
		
		while (totalCurrentNonMines < nbNonMines) {
			
			boolean[][] nextPossibleMoves = map;
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					if (nextPossibleMoves[i][j]) {
						int weight = this.getNewAdjacentCellsNb(i, j, map, width, height);
						if (weight > 0 && weight < bestWeight) {
							bestWeight = weight;
							bestX = i;
							bestY = j;
						}
						if (totalCurrentNonMines + weight == nbNonMines) {
							bestWeight = weight;
							bestX = i;
							bestY = j;
							foundPerfect = true;
							break;
						}
					}
				}
				if (foundPerfect) {
					break;
				}
			}
			map[bestX][bestY] = true;
			this.fillAround(map, width, height, bestX, bestY, map);
			totalCurrentNonMines += bestWeight;
			if (foundPerfect) {
				break;
			}
			bestWeight = 50;
		}
		
		StringBuilder result = new StringBuilder();
		if (totalCurrentNonMines != nbNonMines && nbNonMines > 1) {
			result.append("Impossible\n");
		} else {
			int nbMinesResult = 0;
			for (int i = 0; i < width; i++) {
				for (int j = 0; j < height; j++) {
					if (i == 0 && j == 0) {
						result.append('c');
					} else {
						if (map[i][j] && nbNonMines > 1) {
							result.append('.');
						} else {
							result.append('*');
							nbMinesResult++;
						}
					}
				}
				result.append('\n');
			}

			if (nbMinesResult != nbMines) {
				System.out.println(String.format(
						"ERROR : final mines : %s. Should be : %s",
						nbMinesResult,
						nbMines));
				result.append("ERROR\n");
			}
		}
		
		
		return result.toString();
	}
	
	public int getNewAdjacentCellsNb(
			int x,
			int y,
			boolean[][] map,
			int width,
			int height) {
		
		int result = 0;
		
		if (x > 0) {
			if (y > 0) {
				if (!map[x - 1][y - 1]) result++;
			}
			if (!map[x - 1][y    ]) result++;
			if (y < height - 1) {
				if (!map[x - 1][y + 1]) result++;
			}
		}
		
		if (y > 0) {
			if (!map[x    ][y - 1]) result++;
		}
		
		if (y < height - 1) {
			if (!map[x    ][y + 1]) result++;
		}
		
		if (x < width - 1) {
			if (y > 0) {
				if (!map[x + 1][y - 1]) result++;
			}
			if (!map[x + 1][y    ]) result++;
			if (y < height - 1) {
				if (!map[x + 1][y + 1]) result++;
			}
		}
		
		return result;
	}
	
	public boolean[][] getNextPossibleCells(
			boolean[][] map,
			int width,
			int height) {
		
		boolean[][] result = new boolean[width][height];
		
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (map[i][j]) {
					this.fillAround(map, width, height, i, j, result);
				}
			}
		}
		
		return result;
	}
	
	public void fillAround(boolean[][] map, int width, int height, int x, int y, boolean result[][]) {
		if (x > 0) {
			if (y > 0) {
				if (!map[x - 1][y - 1]) result[x-1][y-1] = true;
			}
			if (!map[x - 1][y    ]) result[x-1][y] = true;
			if (y < height - 1) {
				if (!map[x - 1][y + 1]) result[x-1][y+1] = true;
			}
		}
		
		if (y > 0) {
			if (!map[x    ][y - 1]) result[x][y-1] = true;
		}
		
		//if (!map[x    ][y    ]) result[x][y] = true;
		
		if (y < height - 1) {
			if (!map[x    ][y + 1]) result[x][y+1] = true;
		}
		
		if (x < width - 1) {
			if (y > 0) {
				if (!map[x + 1][y - 1]) result[x+1][y-1] = true;
			}
			if (!map[x + 1][y    ]) result[x+1][y] = true;
			if (y < height - 1) {
				if (!map[x + 1][y + 1]) result[x+1][y+1] = true;
			}
		}
	}
}
