package qual.c;

import java.io.BufferedWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Locale;
import java.util.Scanner;

public class C_small_4 {
	private void solve(long case_T, Scanner reader, BufferedWriter writer) throws Exception {
		int rows = reader.nextInt();
		int cols = reader.nextInt();
		int mines = reader.nextInt();
		int empty = rows*cols-mines;
		if (empty<=0) {
			writeOutput(writer, case_T, "Impossible");
			return;
		}

		//Fill the grid with bombs
		String[][] grid = new String[rows][cols];
		for (int row=0;row<rows;row++) {
			for (int col=0;col<cols;col++) {
				grid[row][col] = "*";
			}
		}

		//Single column mines are simple
		if (cols == 1) {
			for (int row=0;row<empty;row++) {
				grid[row][0] = ".";
			}
		}
		else if (rows == 1) {
			for (int col=0;col<empty;col++) {
				grid[0][col] = ".";
			}
		}
		else {
			if (empty==2 || empty==3 || empty==5 || empty==7 || (empty>1 && empty%2==1 && (cols==2 || rows==2))) {
				writeOutput(writer, case_T, "Impossible");
				return;
			}

			//Add 2 empty fields at a time
			int nextCol=0;
			int nextRow=0;
			while (empty>0) {
				if (nextRow==0) {
					grid[nextRow][nextCol] = ".";
					if (empty>1 && rows>1) {
						grid[nextRow+1][nextCol] = ".";
					}
					empty-=2;
					nextCol++;
					if (nextCol>=cols || empty==3 && rows>2) {
						nextRow+=2;
						nextCol=0;
					}
				}
				else {
					int colsLeftOnRow = cols-nextCol;
					while (empty>0 && colsLeftOnRow>1 || colsLeftOnRow==1 && (empty>2 || empty==1)) {
						grid[nextRow][nextCol] = ".";
						empty--;
						nextCol++;
						colsLeftOnRow = cols-nextCol;
					}
					nextRow+=1;
					nextCol=0;
				}
			}
		}

		//Set the starting position
		grid[0][0] = "c";
		writeOutput(writer, case_T, grid);
	}

	private void writeOutput(BufferedWriter writer, long case_T, String[][] grid) throws Exception {
		String result = String.format("Case #%d:",  case_T);
		System.out.println(result);
		writer.write(result+"\n");

		for (int row=0;row<grid.length;row++) {
			for (int col=0;col<grid[row].length;col++) {
				writer.write(grid[row][col]);
				System.out.print(grid[row][col]);
			}
			writer.write("\n");
			System.out.println("");
		}
	}

	private void writeOutput(BufferedWriter writer, long case_T, String output) throws Exception {
		String result = String.format("Case #%d:\n%s",  case_T, output);
		System.out.println(result);
		writer.write(result+"\n");
	}

	private void run() throws Exception {
		Locale.setDefault(Locale.US);

		String filename = "src/qual/c/C-small-attempt4";
		Path inputFile = Paths.get(filename+".in");
		Path outputFile = Paths.get(filename+".out");

		System.out.println("Input file:  "+inputFile.toFile().getAbsolutePath());
		System.out.println("Output file: "+outputFile.toFile().getAbsolutePath());

		try (
				Scanner reader = new Scanner(Files.newBufferedReader(inputFile));
				BufferedWriter writer = Files.newBufferedWriter(outputFile)) {
			long cases_T = new Long(reader.nextLine());

			for (long case_T = 1; case_T<=cases_T; case_T++) {
				solve(case_T, reader, writer);
			}
		}
	}

	public static void main(String... args) throws Exception {
		new C_small_4().run();
	}
}
