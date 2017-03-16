import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class MinesweeperMaster {

	static int nbNewGoodNeighbours = 1;
	
	public static void main(String[] args) throws IOException{
		
		String fileIn = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/C-small-attempt1.in";
		String fileOut = "C:/Users/Valentin/workspace/GoogleCodeJamQualif/src/test.out";
		System.setIn(new FileInputStream(fileIn));
		BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
		System.setOut(new PrintStream(fileOut));
		
		String line;
		int testCase = 1;
		int columns = 0;
		int rows = 0;
		int mines = 0;
				
		boolean firstLine = true;
		while ((line = stdin.readLine()) != null && line.length() != 0) {
			String[] input = line.split(" ");
			if (firstLine) {
				firstLine = false;
				continue; 
			}
			rows = Integer.parseInt(input[0]);
			columns = Integer.parseInt(input[1]);
			mines = Integer.parseInt(input[2]);
			calculate(rows, columns, mines, testCase);
			testCase++;
		}
		
	}

	private static void calculate(int rows, int columns, int mines, int testCase) {
		System.out.println("Case #" + testCase + ":");
		nbNewGoodNeighbours = 1;
		if (rows * columns <= mines) {
			System.out.println("Impossible");
		}
		else {
			int mineFree = rows * columns - mines;
			int[] insideArray = findBestPositions(rows, columns, mineFree);
			if (insideArray.length != 0) {
				String[][] tab = createTab(rows, columns, insideArray[0], insideArray[1], mineFree);
				boolean isPossible = isPossible(tab, mineFree);
				if (! isPossible) {
					System.out.println("Impossible");
				}
				else {
					for (String[] elem1 : tab) {
						for (String elem2 : elem1) {
							if (elem2.equals("-")) {
								System.out.print(".");
							}
							else System.out.print(elem2);
						}
						System.out.println();
					}
				}
			}
		}
	}

	private static boolean isPossible(String[][] tab, int mineFree) {
		int currentRow = 0;
		int currentColumn = 0;
		tab[0][0] = "c";
		String[][] tempTab = new String[tab.length][tab[0].length];
		System.arraycopy(tab, 0, tempTab, 0, tab.length);
		
		if (!canContinue(currentRow, currentColumn, tempTab, mineFree)) {
			return false;
		}
		return true;
	}

	private static boolean canContinue(int currentRow, int currentColumn,
			String[][] tempTab, int mineFree) {
				
		boolean isLegal = true;
		boolean canGoUp;
		boolean canGoDown;
		boolean canGoLeft;
		boolean canGoRight;
		if (currentRow > 0)
			canGoUp = true;
		else canGoUp = false;
		if (currentColumn > 0)
			canGoLeft = true;
		else canGoLeft = false;
		if (currentRow < tempTab.length - 1)
			canGoDown = true;
		else canGoDown = false;
		if (currentColumn < tempTab[0].length - 1)
			canGoRight = true;
		else canGoRight = false;
		
		if (canGoUp && canGoLeft && isLegal) {
			if (tempTab[currentRow - 1][currentColumn - 1].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoUp && isLegal) {
			if (tempTab[currentRow - 1][currentColumn].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoUp && canGoRight && isLegal) {
			if (tempTab[currentRow - 1][currentColumn + 1].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoLeft && isLegal) {
			if (tempTab[currentRow][currentColumn - 1].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoRight && isLegal) {
			if (tempTab[currentRow][currentColumn + 1].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoDown && canGoLeft && isLegal) {
			if (tempTab[currentRow + 1][currentColumn - 1].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoDown && isLegal) {
			if (tempTab[currentRow + 1][currentColumn].equals("*")) {
				isLegal = false;
			}
		}
		if (canGoDown && canGoRight && isLegal) {
			if (tempTab[currentRow + 1][currentColumn + 1].equals("*")) {
				isLegal = false;
			}
		}
				
		//quit if not 0
		if (! isLegal) {
			return nbNewGoodNeighbours == mineFree;
		}
		
		if (canGoUp && canGoLeft) {
			if (tempTab[currentRow - 1][currentColumn - 1].equals(".")) {
				tempTab[currentRow - 1][currentColumn - 1] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow - 1, currentColumn - 1, tempTab, mineFree);
			}
		}
		if (canGoUp) {
			if (tempTab[currentRow - 1][currentColumn].equals(".")) {
				tempTab[currentRow - 1][currentColumn] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow - 1, currentColumn, tempTab, mineFree);
			}
		}
		if (canGoUp && canGoRight) {
			if (tempTab[currentRow - 1][currentColumn + 1].equals(".")) {
				tempTab[currentRow - 1][currentColumn + 1] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow - 1, currentColumn + 1, tempTab, mineFree);
			}
		}
		if (canGoLeft) {
			if (tempTab[currentRow][currentColumn - 1].equals(".")) {
				tempTab[currentRow][currentColumn - 1] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow, currentColumn - 1, tempTab, mineFree);
			}
		}
		if (canGoRight) {
			if (tempTab[currentRow][currentColumn + 1].equals(".")) {
				tempTab[currentRow][currentColumn + 1] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow, currentColumn + 1, tempTab, mineFree);
			}
		}
		if (canGoDown && canGoLeft) {
			if (tempTab[currentRow + 1][currentColumn - 1].equals(".")) {
				tempTab[currentRow + 1][currentColumn - 1] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow + 1, currentColumn - 1, tempTab, mineFree);
			}
		}
		if (canGoDown) {
			if (tempTab[currentRow + 1][currentColumn].equals(".")) {
				tempTab[currentRow + 1][currentColumn] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow + 1, currentColumn, tempTab, mineFree);
			}
		}
		if (canGoDown && canGoRight) {
			if (tempTab[currentRow + 1][currentColumn + 1].equals(".")) {
				tempTab[currentRow + 1][currentColumn + 1] = "-";
				nbNewGoodNeighbours++;
				canContinue(currentRow + 1, currentColumn + 1, tempTab, mineFree);
			}
		}
		return nbNewGoodNeighbours == mineFree;
	}

	private static String[][] createTab(int rows, int columns, int insideRows, int insideColumns,
			int mineFree) {
		String[][] toReturn = new String[rows][columns];
		int remainingMineFree = mineFree;
		boolean specialCase = false;
		
		//If alone mineFree
		if (mineFree - (insideRows * (insideColumns - 1)) == 1 && mineFree != insideColumns * insideRows) {
			specialCase = true;
		}
		
		for (int i = 0; i < columns; i++) {
			for (int j = 0; j < rows; j++) {
				if (i < insideColumns && j < insideRows && remainingMineFree > 0) {
					if (specialCase && i == insideColumns - 2 && j == insideRows - 1) {
						toReturn[j][i] = "*";
					}
					else {
						toReturn[j][i] = ".";
						remainingMineFree--;
					}
				}
				else {
					toReturn[j][i] = "*";
				}
			}
		}
		return toReturn;
	}

	private static int[] findBestPositions(int rows, int columns, int mineFree) {
		int bestColumns = (int) Math.ceil(Math.sqrt(mineFree));
		int bestRows = (int) Math.ceil((double)(mineFree) / (double)(bestColumns));
		
		while (bestRows > rows || bestColumns > columns) {
			if (bestColumns > columns) {
				bestColumns = columns;
				bestRows = (int) Math.ceil((double)(mineFree) / (double)(bestColumns));
				if (bestRows > rows) {
					System.out.println("Impossible");
					return new int[0];
				}
			}
			else {
				bestRows = rows;
				bestColumns = (int) Math.ceil((double)(mineFree) / (double)(bestRows));
				if (bestColumns > columns) {
					System.out.println("Impossible");
					return new int[0];
				}
			}
		}
		int[] toReturn = {bestRows, bestColumns};
		return toReturn;
	}
	
}
