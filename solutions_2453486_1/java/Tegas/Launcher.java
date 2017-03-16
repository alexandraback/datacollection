import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

class Board {
	public static final char O = 'O';
	public static final char X = 'X';
	public static final char T = 'T';
	public static final char DOT = '.';
	
	public static final int size = 4;
	private char[][] data;
	
	public Board(String representation) {
		
		if (representation.length() != size * size) {
			throw new IllegalArgumentException();			
		}
		
		data = new char[size][];
		for (int i = 0; i < data.length; ++i) {
			data[i] = new char[size];
		}
		
		for (int i = 0; i < representation.length(); ++i) {
			data[i / size][i % size] = representation.charAt(i);
		}
	}

	public boolean isWonO() {
		for (int row = 0; row < size; ++row) {
			
			int nT = 0, nO = 0, nX = 0;
			
			for (int column = 0; column < size; ++column) {

				char c = data[row][column];
				if (c == O) {
					++nO;
				}
				else if (c == X) {
					++nX;
				}
				else if (c == T) {
					++nT;
				}
			}
			
			if (nO + nT == size) {
				return true;
			}			
		}
		
		for (int column = 0; column < size; ++column) {
			
			int nT = 0, nO = 0, nX = 0;
			
			for (int row = 0; row < size; ++row) {

				char c = data[row][column];
				if (c == O) {
					++nO;
				}
				else if (c == X) {
					++nX;
				}
				else if (c == T) {
					++nT;
				}
			}
			
			if (nO + nT == size) {
				return true;
			}			
		}
		
		int nT = 0, nO = 0, nX = 0;		
		for (int rowcolumn = 0; rowcolumn < size; ++rowcolumn) {						

			char c = data[rowcolumn][rowcolumn];
			if (c == O) {
				++nO;
			}
			else if (c == X) {
				++nX;
			}
			else if (c == T) {
				++nT;
			}	
		}		
		if (nO + nT == size) {
			return true;
		}		
		
		nT = 0; nO = 0; nX = 0;		
		for (int row = 0; row < size; ++row) {						

			char c = data[row][size - 1 - row];
			if (c == O) {
				++nO;
			}
			else if (c == X) {
				++nX;
			}
			else if (c == T) {
				++nT;
			}	
		}		
		if (nO + nT == size) {
			return true;
		}		
		
		return false;
	}
	
	public boolean isWonX() {
		for (int row = 0; row < size; ++row) {
			
			int nT = 0, nO = 0, nX = 0;
			
			for (int column = 0; column < size; ++column) {

				char c = data[row][column];
				if (c == O) {
					++nO;
				}
				else if (c == X) {
					++nX;
				}
				else if (c == T) {
					++nT;
				}
			}
			
			if (nX + nT == size) {
				return true;
			}			
		}
		
		for (int column = 0; column < size; ++column) {
			
			int nT = 0, nO = 0, nX = 0;
			
			for (int row = 0; row < size; ++row) {

				char c = data[row][column];
				if (c == O) {
					++nO;
				}
				else if (c == X) {
					++nX;
				}
				else if (c == T) {
					++nT;
				}
			}
			
			if (nX + nT == size) {
				return true;
			}			
		}
		
		int nT = 0, nO = 0, nX = 0;		
		for (int rowcolumn = 0; rowcolumn < size; ++rowcolumn) {						

			char c = data[rowcolumn][rowcolumn];
			if (c == O) {
				++nO;
			}
			else if (c == X) {
				++nX;
			}
			else if (c == T) {
				++nT;
			}	
		}		
		if (nX + nT == size) {
			return true;
		}		
		
		nT = 0; nO = 0; nX = 0;		
		for (int row = 0; row < size; ++row) {						

			char c = data[row][size - 1 - row];
			if (c == O) {
				++nO;
			}
			else if (c == X) {
				++nX;
			}
			else if (c == T) {
				++nT;
			}	
		}		
		if (nX + nT == size) {
			return true;
		}		
		
		return false;
	}
	
	public boolean areEmptyCells() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				if (data[i][j] == DOT) {
					return true;
				}
			}
		}
		return false;		
	}
	
	public void print() {
		for (int i = 0; i < size; ++i) {
			for (int j = 0; j < size; ++j) {
				System.out.print(data[i][j]);
			}
		}
		System.out.println();
	}	
}
	
class Problem1 {
	
	private long T;
	
	public void solve(String in) throws IOException {
		Scanner scanner = new Scanner(new File(in));
		Writer outFile = new FileWriter("OUT"+in);
		
		T = Integer.parseInt(scanner.nextLine());
		
		for (int i = 1; i <= T; ++i) {
			StringBuilder str = new StringBuilder();
			for (int j = 0; j < Board.size; ++j) {
				str.append(scanner.nextLine());
			}
			//empty
			Board board = new Board(str.toString());
			String result;
			if (board.isWonO()) {
				result = "O won";
			}
			else if (board.isWonX()) {
				result = "X won";
			}
			else if (!board.areEmptyCells()) {
				result = "Draw";
			}
			else {
				result = "Game has not completed";				
			}
			outFile.write("Case #"+i+": " + result +'\n');
			
			scanner.nextLine();
		}
		
		outFile.flush();
		outFile.close();		
	}
	
}
public class Launcher {

	public static void main(String[] args) {
		Problem1 problem1 = new Problem1();
		try {
			problem1.solve("A-large.in.txt");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
