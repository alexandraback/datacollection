import java.util.*;
import java.io.*;
public class TicTacToeTomek {
	public static void main(String[] args) {

		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner s = new Scanner(input);
		int T = s.nextInt();
		nextCase:
		for (int x = 1; x <=T; x++) {
			s.nextLine();
			char[][] matrix = new char[4][4];
			boolean isNotOver = false;
			for (int i = 0; i < 4; i++) {
				String row = s.nextLine();
				for (int j = 0; j < 4; j++) {
					matrix[i][j] = row.charAt(j);
					if (matrix[i][j] == '.') {
						isNotOver = true;
					}
				}
			}
			// Check rows
			rowCheck:
			for (int i = 0; i < 4; i++) {
				switch(matrix[i][0]) {
					case 'X':
						for (int j = 1; j < 4; j++) {
							if (matrix[i][j] == 'O' || matrix[i][j] == '.') {
								// This is useless.
								// Check next row.
								continue rowCheck;
							}
						}
						System.out.println("Case #" + x + ": X won");
						continue nextCase;

					case 'O':
						for (int j = 1; j < 4; j++) {
							if (matrix[i][j] == 'X' || matrix[i][j] == '.') {
								// This is useless.
								// Check next row.
								continue rowCheck;
							}
						}
						System.out.println("Case #" + x + ": O won");
						continue nextCase;

					case '.':
						continue rowCheck;

					case 'T':
						switch(matrix[i][1]) {
							case 'X':
								for (int j = 2; j < 4; j++) {
									if (matrix[i][j] == 'O' || matrix[i][j] == '.') {
										// This is useless.
										// Check next row.
										continue rowCheck;
									}
								}
								System.out.println("Case #" + x + ": X won");
								continue nextCase;
							case 'O':
								for (int j = 2; j < 4; j++) {
									if (matrix[i][j] == 'X' || matrix[i][j] == '.') {
										// This is useless.
										// Check next row.
										continue rowCheck;
									}
								}
								System.out.println("Case #" + x + ": O won");
								continue nextCase;
							case '.':
								continue rowCheck;
						}
				}
			}
			// Check column
			columnCheck:
			for (int j = 0; j < 4; j++) {
				switch(matrix[0][j]) {
					case 'X':
						for (int i = 1; i < 4; i++) {
							if (matrix[i][j] == 'O' || matrix[i][j] == '.') {
								// This is useless.
								// Check next column.
								continue columnCheck;
							}
						}
						System.out.println("Case #" + x + ": X won");
						continue nextCase;

					case 'O':
						for (int i = 1; i < 4; i++) {
							if (matrix[i][j] == 'X' || matrix[i][j] == '.') {
								// This is useless.
								// Check next column.
								continue columnCheck;
							}
						}
						System.out.println("Case #" + x + ": O won");
						continue nextCase;

					case '.':
						continue columnCheck;

					case 'T':
						switch(matrix[1][j]) {
							case 'X':
								for (int i = 2; i < 4; i++) {
									if (matrix[i][j] == 'O' || matrix[i][j] == '.') {
										// This is useless.
										// Check next column.
										continue columnCheck;
									}
								}
								System.out.println("Case #" + x + ": X won");
								continue nextCase;
							case 'O':
								for (int i = 2; i < 4; i++) {
									if (matrix[i][j] == 'X' || matrix[i][j] == '.') {
										// This is useless.
										// Check next column.
										continue columnCheck;
									}
								}
								System.out.println("Case #" + x + ": O won");
								continue nextCase;
							case '.':
								continue columnCheck;
						}
				}
			}
			// Check diagonals
			boolean notValid = false;
			switch(matrix[0][0]) {
				case 'X':
					for (int i = 1; i < 4; i++) {
						if (matrix[i][i] == 'O' || matrix[i][i] == '.') {
							// This is useless.
							// Check next column.
							notValid = true;
						}
					}
					if (notValid) {
						break;
					}
					System.out.println("Case #" + x + ": X won");
					continue nextCase;

				case 'O':
					for (int i = 1; i < 4; i++) {
						if (matrix[i][i] == 'X' || matrix[i][i] == '.') {
							// This is useless.
							// Check next column.
							notValid = true;
						}
					}
					if (notValid) {
						break;
					}
					System.out.println("Case #" + x + ": O won");
					continue nextCase;

				case '.':
					break;

				case 'T':
					switch(matrix[1][1]) {
						case 'X':
							for (int i = 2; i < 4; i++) {
								if (matrix[i][i] == 'O' || matrix[i][i] == '.') {
									// This is useless.
									// Check next column.
									notValid = true;
								}
							}
							if (notValid) {
								break;
							}
							System.out.println("Case #" + x + ": X won");
							continue nextCase;
						case 'O':
							for (int i = 2; i < 4; i++) {
								if (matrix[i][i] == 'X' || matrix[i][i] == '.') {
									// This is useless.
									// Check next column.
									notValid = true;
								}
							}
							if (notValid) {
								break;
							}
							System.out.println("Case #" + x + ": O won");
							continue nextCase;
						case '.':
							break;
					}
			}
			notValid = false;
			switch(matrix[0][3]) {
				case 'X':
					for (int i = 1; i < 4; i++) {
						if (matrix[i][3-i] == 'O' || matrix[i][3-i] == '.') {
							// This is useless.
							// Check next column.
							notValid = true;
						}
					}
					if (notValid) {
						break;
					}
					System.out.println("Case #" + x + ": X won");
					continue nextCase;

				case 'O':
					for (int i = 1; i < 4; i++) {
						if (matrix[i][3-i] == 'X' || matrix[i][3-i] == '.') {
							// This is useless.
							// Check next column.
							notValid = true;
						}
					}
					if (notValid) {
						break;
					}
					System.out.println("Case #" + x + ": O won");
					continue nextCase;

				case '.':
					break;

				case 'T':
					switch(matrix[1][3-1]) {
						case 'X':
							for (int i = 2; i < 4; i++) {
								if (matrix[i][3-i] == 'O' || matrix[i][3-i] == '.') {
									// This is useless.
									// Check next column.
									notValid = true;
								}
							}
							if (notValid) {
								break;
							}
							System.out.println("Case #" + x + ": X won");
							continue nextCase;
						case 'O':
							for (int i = 2; i < 4; i++) {
								if (matrix[i][3-i] == 'X' || matrix[i][3-i] == '.') {
									// This is useless.
									// Check next column.
									notValid = true;
								}
							}
							if (notValid) {
								break;
							}
							System.out.println("Case #" + x + ": O won");
							continue nextCase;
						case '.':
							break;
					}
			}
			
			System.out.println("Case #" + x + ": " + (isNotOver?"Game has not completed":"Draw"));
		}
	}
}