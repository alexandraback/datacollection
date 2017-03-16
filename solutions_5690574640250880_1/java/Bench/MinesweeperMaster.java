import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class MinesweeperMaster {

	public static void main(String[] args) {
		Scanner scanner = null;
		try {
			scanner = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		int T = scanner.nextInt();
		FileWriter writer = null;
		try {
			writer = new FileWriter(new File("output.txt"));
		} catch (IOException e1) {
			e1.printStackTrace();
		}
		for (int trial = 1; trial <= T; trial++) {
			try {
				writer.write("Case #" + trial + ":\n");
			} catch (IOException e1) {
				e1.printStackTrace();
			}
			try {
				solveTrial(scanner, writer);
			} catch (IOException e) {
				e.printStackTrace();
			}
			/*
			 * try { writer.write("\n"); } catch (IOException e) {
			 * e.printStackTrace(); }
			 */
		}
		try {
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		scanner.close();
	}

	static void solveTrial(Scanner scanner, FileWriter writer)
			throws IOException {
		int R = scanner.nextInt(); // num rows
		int C = scanner.nextInt(); // num columns
		int M = scanner.nextInt(); // num bombs
		int X = R * C - M;
		if (X == 0) {
			writer.write("Impossible\n");
			return;
		}
		if (X == 1) // special case where everything but one is a bomb
		{
			for (int i = 0; i < R - 1; i++) {
				for (int b = 0; b < C; b++)
					writer.write('*');
				writer.write('\n');
			}
			for (int b = 0; b < C - 1; b++)
				writer.write('*');
			writer.write("c\n");
			return;
		} else if (R == 1 || C == 1) {
			for (int i = 0; i < R; i++) {
				for (int b = 0; b < C; b++) {
					if (i * C + b + 1 <= M)
						writer.write('*');
					else if (i == R - 1 && b == C - 1)
						writer.write('c');
					else
						writer.write('.');
				}
				writer.write('\n');
			}
			return;
		} else if (X < 4) {
			writer.write("Impossible\n");
			return;
		} else if (X <= 2 * C) {
			if (X % 2 == 0) // if there are an even number
			{
				for (int i = 0; i < R - 2; i++) {
					for (int b = 0; b < C; b++)
						writer.write('*');
					writer.write('\n');
				}
				for (int i = 0; i < 2; i++) {
					for (int b = 0; b < X / 2; b++) {
						if (i == 1 && b == 0)
							writer.write('c');
						else
							writer.write('.');
					}
					for (int b = X / 2; b < C; b++) {
						writer.write('*');
					}
					writer.write('\n');
				}
				return;
			} else { // if there are an odd number
				if (R < 3 || C < 3 || X < 9) {
					writer.write("Impossible\n");
					return;
				} else {
					for (int i = 0; i < R - 3; i++) {
						for (int b = 0; b < C; b++)
							writer.write('*');
						writer.write('\n');
					}
					writer.write("...");
					for (int i = 0; i < C - 3; i++)
						writer.write('*');
					writer.write('\n');
					for (int i = 0; i < 2; i++) {
						for (int b = 0; b < (X - 3) / 2; b++) {
							if (i == 1 && b == 0)
								writer.write('c');
							else
								writer.write('.');
						}
						for (int b = (X - 3) / 2; b < C; b++)
							writer.write('*');
						writer.write('\n');
					}
				}
			}
			return;
		} else if (X % C == 1) {
			// need at least 4 columns to have an offset of 1
			if (C < 3 || X < 9) {
				writer.write("Impossible\n");
				return;
			}
			if (X / C >= 3) {
				for (int i = 0; i < R - (X / C + 1); i++) {
					for (int b = 0; b < C; b++)
						writer.write('*');
					writer.write('\n');
				}
				writer.write("..");
				for (int i = 0; i < C - 2; i++)
					writer.write('*');
				writer.write("\nc");
				for (int i = 1; i < C - 1; i++)
					writer.write('.');
				writer.write("*\n");

				for (int i = 0; i < X / C + 1 - 2; i++) {
					for (int b = 0; b < C; b++)
						writer.write('.');
					writer.write('\n');
				}
				return;
			} else {
				for (int i = 0; i < R - (X / C + 1); i++) {
					for (int b = 0; b < C; b++)
						writer.write('*');
					writer.write('\n');
				}
				writer.write("...");
				for (int i = 0; i < C - 3; i++)
					writer.write('*');
				writer.write('\n');

				for (int i = 0; i < 2; i++) {
					for (int b = 0; b < C - 1; b++) {
						if (i == 1 && b == 0)
							writer.write('c');
						else
							writer.write('.');
					}
					writer.write("*\n");
				}
				for (int i = 0; i < X / C + 1 - 3; i++) {
					for (int b = 0; b < C; b++)
						writer.write('.');
					writer.write('\n');
				}
				return;
			}
		} else {
			for (int i = 0; i < R - (X / C + 1); i++) {
				for (int b = 0; b < C; b++)
					writer.write('*');
				writer.write('\n');
			}
			if (X % C != 0) {
				for (int i = 0; i < X % C; i++)
					writer.write('.');
				for (int i = X % C; i < C; i++)
					writer.write('*');
				writer.write('\n');
			} else if (M != 0) {
				for (int i = 0; i < C; i++)
					writer.write('*');
				writer.write('\n');
			}

			for (int i = 0; i < X / C; i++) {
				for (int b = 0; b < C; b++) {
					if (i == 1 && b == 0)
						writer.write('c');
					else
						writer.write('.');
				}
				writer.write('\n');
			}
			return;
		}
	}
}
