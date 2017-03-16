package GoogleCodeJam.ed2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.LinkedList;

public class Round1BB {

	private String inputFile;
	private String outputFile;

	private BufferedReader reader = null;
	private BufferedWriter writer = null;
	
	private int[][] ceils;
	private int[][] floors;
	private double[][] times;
	private int waterLevel;
	
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		Round1BB round1BB = new Round1BB("round1BB.in", "round1BB.out");
		round1BB.run();
	}

	private void run() throws Exception {
		openFiles();
		solve();
		closeFiles();
	}


	private void solve() throws Exception {
		int tests = Integer.valueOf(reader.readLine());
		for (int test=1; test<=tests; test++) {
			int lines,columns;
			String[] line = reader.readLine().split(" ");
			waterLevel = Integer.valueOf(line[0]);
			lines = Integer.valueOf(line[1]);
			columns = Integer.valueOf(line[2]);
			
			ceils = new int[lines][columns];
			floors = new int[lines][columns];
			times = new double[lines][columns];
			
			for (int i=0; i<lines; i++) {
				line = reader.readLine().split(" ");
				for (int j=0; j<columns; j++) {
					ceils[i][j] = Integer.valueOf(line[j]);
				}
			}
			
			for (int i=0; i<lines; i++) {
				line = reader.readLine().split(" ");
				for (int j=0; j<columns; j++) {
					floors[i][j] = Integer.valueOf(line[j]);
				}
			}
			
			times = new double[lines][columns];
			for (int i=0; i<lines; i++) {
				for (int j=0; j<columns; j++) {
					times[i][j] = Double.MAX_VALUE;
				}
			}
			
			
			LinkedList<Cell> cells = new LinkedList<Cell>();
			Cell cell = new Cell();
			cell.x=0;
			cell.y=0;
			cells.addLast(cell);
			times[0][0] = 0;
			
			while (cells.size()>0) {
				cell = cells.removeFirst();
				int x = cell.x;
				int y = cell.y;
				if ((x>0) && canMove(x, y, x-1, y)){
					tryToMove(x,y,x-1,y,cells);
				}
				if ((y>0) && canMove(x, y, x, y-1)){
					tryToMove(x,y,x,y-1,cells);
				}
				if ((x<lines-1) && canMove(x, y, x+1, y)){
					tryToMove(x,y,x+1,y,cells);
				}
				if ((y<columns-1) && canMove(x, y, x, y+1)){
					tryToMove(x,y,x,y+1,cells);
				}
			}
			
			writer.write("Case #"+test+": "+times[lines-1][columns-1]+"\n");
		}
	}

	private void tryToMove(int fromX, int fromY, int toX, int toY, LinkedList<Cell> cells) {
		if (times[fromX][fromY]>=times[toX][toY]) {
			return;
		}
		double moveTime = getMoveTime(fromX, fromY, toX, toY);
		if (times[toX][toY]>moveTime) {
			Cell cell = new Cell();
			cell.x = toX;
			cell.y = toY;
			times[toX][toY] = moveTime;
			cells.addLast(cell);
		}
	}

	private double getMoveTime(int fromX, int fromY, int toX, int toY) {
		double moveTime = times[fromX][fromY];
		double distance = ceils[toX][toY]-waterLevel+moveTime*10;
		if (distance<50) {
			moveTime += (50-distance)/10;
		}
		if (moveTime>0) {
			if (floors[fromX][fromY]+20<=waterLevel-moveTime*10) {
				moveTime+=1;
			}
			else {
				moveTime+=10;
			}
		}
		return moveTime;
	}

	private boolean canMove(int fromX, int fromY, int toX, int toY) {
		if ((ceils[toX][toY]-floors[toX][toY]>=50) && (ceils[toX][toY]-floors[fromX][fromY]>=50) && (ceils[fromX][fromY]-floors[toX][toY]>=50)) {
			return true;
		}
		return false;
	}
	
	public Round1BB(String inputFile, String outputFile) {
		this.inputFile = inputFile;
		this.outputFile = outputFile;
	}
	
	private void closeFiles() {
		try {
			reader.close();
			writer.close();
		}
		catch (Exception e) {
			throw new RuntimeException();
		}

	}
	
	private void openFiles() {
		try {
			reader = new BufferedReader(new FileReader(inputFile));
			writer = new BufferedWriter(new FileWriter(outputFile));
		}
		catch (Exception e) {
			throw new RuntimeException("File initialization failed");
		}
	}
	
	private class Cell {
		public int x;
		public int y;
	}
}
