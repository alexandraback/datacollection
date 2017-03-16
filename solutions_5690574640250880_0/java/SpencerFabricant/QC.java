package spikemf.googlecodejam.rounds;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;


public class QC {
	private enum CellStatus {
		CLICK, EXPLORED, FREE, MINE
	}
	static String infilename = "C-small-attempt0.in";
	static String outfilename = "qc.out";
	static BufferedWriter out;
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new FileReader(infilename));
		int cases = Integer.parseInt(br.readLine());
		for (int i=0;i<cases;i++) {
			handleLine(br.readLine());
		}
		br.close();
		if (out != null) out.close();
	}
	static int caseNumber = 1;
	public static void writeLine(CellStatus[][] minefield) throws IOException {
		if (out == null) {
			out = new BufferedWriter(new FileWriter(outfilename));
		}
		out.write("Case #" + (caseNumber++) + ":");
		if (minefield == null) out.write("\nImpossible");
		else {
			for (int i=0;i<minefield.length;i++) {
				out.write("\n");
				for (int j=0;j<minefield[0].length;j++) {
					if (minefield[i][j] == CellStatus.MINE) {
						out.write("*");
					} else if (minefield[i][j] == CellStatus.CLICK) {
						out.write("c");
					} else {
						out.write(".");
					}
				}
			}
		}
		out.write("\n");
	}
	public static void handleLine(String line) throws IOException {
		String[] strings = line.split(" ");
		int R = Integer.parseInt(strings[0]);
		int C = Integer.parseInt(strings[1]);
		int M = Integer.parseInt(strings[2]);
		
		
		CellStatus[][] minefield = new CellStatus[R][C];
		for (int i=0;i<R;i++) {
			for (int j=0;j<C;j++) {
				minefield[i][j] = CellStatus.MINE;
			}
		}
		if (M == R*C-1) {
			minefield[0][0] = CellStatus.CLICK;
			writeLine(minefield);
			return;
		}
		
		CellStatus[][] newMinefield = exploreMinefield(minefield, R*C - M, R/2, C/2);
		if (newMinefield != null) {
			newMinefield[R/2][C/2] = CellStatus.CLICK;
			writeLine(newMinefield);
		}
		else {
			newMinefield = exploreMinefield(minefield, R*C - M, 0,0);
			if (newMinefield != null) newMinefield[0][0] = CellStatus.CLICK;
			writeLine(newMinefield);
		}
	}
	public static CellStatus[][] exploreMinefield(
			CellStatus[][] oldMinefield,
			int remainingFreeBlocks,
			int x, int y) {
		/* x and y are coordinates of current iteration */
		int R = oldMinefield.length; int C = oldMinefield[0].length;
		
		CellStatus[][] newMinefield = new CellStatus[R][C];
		for (int i=0;i<R;i++) {
			for (int j=0;j<C;j++) {
				newMinefield[i][j] = oldMinefield[i][j];
			}
		}
		
		if (remainingFreeBlocks == 0) {
			return oldMinefield;
		}
		
		/* clear out minefield */
		for (int i=x-1; i<=x+1;i++) {
			for (int j=y-1;j<=y+1;j++) {
				if (i < 0 || i >= R) continue;
				if (j<0 || j>= C) continue;
				
				if (newMinefield[i][j] == CellStatus.MINE) {
					newMinefield[i][j] = CellStatus.FREE;
					remainingFreeBlocks--;
				}
			}
		}
		newMinefield[x][y] = CellStatus.EXPLORED;
		
		if (remainingFreeBlocks < 0) {
			return null;
		}
		if (remainingFreeBlocks == 0) {
			return newMinefield;
		}
		/* M > 0 */
		
		for (int i=x-1;i<=x+1;i++) {
			for (int j=y-1;j<=y+1;j++) {
				if (i<0 || j<0 || i>=R || j>=C) continue;
				if (newMinefield[i][j] != CellStatus.FREE) continue; 
				CellStatus[][] candMinefield = exploreMinefield(newMinefield, remainingFreeBlocks, i, j);
				if (candMinefield == null) continue;
				else {
					return candMinefield;
				}
			}
		}
		return null;
	}
}
