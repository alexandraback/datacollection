import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;


public class Minesweeper {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileReader("minesweeper.txt"));
		
		int tests = scanner.nextInt();
		for(int i = 1; i <= tests; i++) {
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int M = scanner.nextInt();
			Tile[][] solution = new Minesweeper(R, C, M).solve();
			
			
			
			if(solution == null) {
				System.out.println("Case #" + i + ":");
				//System.out.println(R + "," + C + "," + M);
				System.out.println("Impossible");
			} else {
				System.out.println("Case #" + i + ":");
				outputTileGrid(solution, R, C);
				int mines = countMines(solution, R, C);
				if(mines != M) {
					System.err.println(i);
					System.exit(-1);
				}
			}
		}
		
		scanner.close();
		System.exit(0);
	}
	
	enum Tile {
		EMPTY,
		CLICK,
		MINE
	}
	
	int R, C, M;	
	
	public Minesweeper(int R, int C, int M) {
		this.R = R;
		this.C = C;
		this.M = M;
	}
	
	private Tile[][] solve() {
		//Number of free spaces to work with
		int F = R * C - M;
		
		//Trivial cases
		//F = 0, no solution
		if(F == 0) return null;
		
		if(F == 1) {
			Tile[][] result = new Tile[R][C];
			
			for(int row = 0; row < R; row++) {
				for(int col = 0; col < C; col++) {
					result[row][col] = Tile.MINE;
				}
			}
			
			result[0][0] = Tile.CLICK;
			return result;
		}
		
		for(int row = 0; row < R; row++) {
			for(int col = 0; col < C - row; col++) {
				//System.err.println("Trying " + row + ", " + col);
				Tile[][] result = solve(row, col);
				if(result != null) {
					return result;
				}
			}
		}
		
		
		return null;
		
	}
	
	private Tile[][] solve(int r, int c) {
		//Number of free spaces to work with
		int F = R * C - M;
		
		//Assume all start as mines
		Tile[][] tiles = new Tile[R][C];		
		for(int row = 0; row < R; row++) {
			for(int col = 0; col < C; col++) {
				tiles[row][col] = Tile.MINE;
			}
		}
		
		int[][] costs = new int[R][C];
		for(int row = 0; row < R; row++) {
			for(int col = 0; col < C; col++) {
				costs[row][col] = getTileCost(tiles, row, col);
			}
		}
		
		int startCost = costs[r][c];
		if(startCost > F) return null;
		
		//Start the click
		makeTileZero(tiles, costs, r, c);
		tiles[r][c] = Tile.CLICK;
		F -= startCost;
		
		if(F == 0) {
			return tiles;
		}
		
		//Keep looking until there are no optimal spaces remaining
		while(true) {
			//First look for a perfect space
			for(int row = 0; row < R; row++) {
				for(int col = 0; col < C; col++) {
					if(costs[row][col] == F && isAdjacentToZero(tiles, costs, row, col)) {
						makeTileZero(tiles, costs, row, col);
						return tiles;
					}
				}
			}
			
			//Otherwise, use a greedy min algorithm
			int bestTileVal = Integer.MAX_VALUE;
			int bestTileR = -1;
			int bestTileC = -1;
			
			for(int row = 0; row < R; row++) {
				for(int col = 0; col < C; col++) {
					if(costs[row][col] > F) continue;
					if(costs[row][col] == 0) continue;
					
					if(costs[row][col] < bestTileVal && isAdjacentToZero(tiles, costs, row, col)) {
						bestTileVal = costs[row][col];
						bestTileR = row;
						bestTileC = col;
					}
				}
			}
			
			//If none was found exit the function
			if(bestTileR == -1) {
				break;
			}
			
			//Otherwise, take the best space and keep going
			F -= costs[bestTileR][bestTileC];
			makeTileZero(tiles, costs, bestTileR, bestTileC);

		}
		
		return null;
	}
	
	private int getTileCost(Tile[][] tiles, int r, int c) {
		int cost = 0;
		for(int row = r - 1; row <= r + 1; row++) {
			if(row < 0) continue;
			if(row >= R) continue;
			for(int col = c - 1; col <= c + 1; col++) {
				if(col < 0) continue;
				if(col >= C) continue;
				if(tiles[row][col] == Tile.MINE) {
					cost++;
				}
			}
		}
		return cost;
	}
	
	private boolean isAdjacentToZero(Tile[][] tiles, int[][] costs, int r, int c) {
		for(int row = r - 1; row <= r + 1; row++) {
			if(row < 0) continue;
			if(row >= R) continue;
			for(int col = c - 1; col <= c + 1; col++) {
				if(col < 0) continue;
				if(col >= C) continue;
				if(col == c && row == r) continue;
				if(costs[row][col] == 0) return true;
			}
		}
		
		return false;
	}
	
	private void makeTileZero(Tile[][] tiles, int[][] costs, int r, int c) {		
		//System.err.println("make " + r + ", " + c + " zero");
		for(int row = r - 1; row <= r + 1; row++) {
			if(row < 0) continue;
			if(row >= R) continue;
			for(int col = c - 1; col <= c + 1; col++) {
				if(col < 0) continue;
				if(col >= C) continue;
				if(tiles[row][col] == Tile.MINE) {
					tiles[row][col] = Tile.EMPTY;
				}
			}
		}
		
		//Recalculate costs in a 2 radius square.
		for(int row = r - 2; row <= r + 2; row++) {
			if(row < 0) continue;
			if(row >= R) continue;
			for(int col = c - 2; col <= c + 2; col++) {
				if(col < 0) continue;
				if(col >= C) continue;
				costs[row][col] = getTileCost(tiles, row, col);
			}
		}
	}
	
	private static void outputTileGrid(Tile[][] tiles, int R, int C) {
		for(int row = 0; row < R; row++) {
			for(int col = 0; col < C; col++) {
				if(tiles[row][col] == Tile.CLICK) System.out.print("c");
				else if(tiles[row][col] == Tile.EMPTY) System.out.print(".");
				else if(tiles[row][col] == Tile.MINE) System.out.print("*");
			}
			System.out.println();
		}
	}
	
	private static int countMines(Tile[][] tiles, int R, int C) {
		int mines = 0;
		for(int row = 0; row < R; row++) {
			for(int col = 0; col < C; col++) {
				if(tiles[row][col] == Tile.MINE) mines++;
			}
		}
		return mines;
	}
	

}
