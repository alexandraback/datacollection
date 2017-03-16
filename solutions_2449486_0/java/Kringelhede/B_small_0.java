import java.io.BufferedWriter;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class B_small_0 {
	private String solveCase(Scanner reader) {
		byte rows_N = reader.nextByte();
		byte cols_M = reader.nextByte();
		byte[][] lawn = new byte[rows_N][cols_M];
		byte maxHeight = 0;

		//Read the lawn
		for (int row=0; row<rows_N;row++) {
			for (int col=0;col<cols_M;col++) {
				lawn[row][col] = reader.nextByte();
				maxHeight = (byte) Math.max(maxHeight, lawn[row][col]);
			}
		}

		//Check if possible
		for (int row=0; row<rows_N;row++) {
			for (int col=0;col<cols_M;col++) {
				if (lawn[row][col]<maxHeight) {
					if (!possible(lawn,row,col)) {
						return "NO";
					}
				}
			}
		}

		return "YES";
	}

	private boolean possible(byte[][] lawn, int r, int c) {
		boolean rowPossible = true;
		boolean colPossible = true;

		for (int row=0; row<lawn.length;row++) {
			if (lawn[row][c]>lawn[r][c]) {
				rowPossible = false;
				break;
			}
		}

		for (int col=0;col<lawn[r].length;col++) {
			if (lawn[r][col]>lawn[r][c]) {
				colPossible = false;
				break;
			}
		}

		return rowPossible || colPossible;
	}

	private void solve(Scanner reader, BufferedWriter writer) throws Exception {
		long cases_T = new Long(reader.nextLine());

		for (long case_T = 1; case_T<=cases_T; case_T++) {
			writeOutput(writer, case_T, solveCase(reader));
		}
	}

	private void run() throws Exception {
		Path inputFile = Paths.get(getClass().getSimpleName()+".in");
		Path outputFile = Paths.get(getClass().getSimpleName()+".out");

		Charset charset = Charset.forName("US-ASCII");
		try (
				Scanner reader = new Scanner(Files.newBufferedReader(inputFile, charset));
				BufferedWriter writer = Files.newBufferedWriter(outputFile, charset)) {
			solve(reader,writer);
		}
	}

	private void writeOutput(BufferedWriter writer, long case_T, String output) throws Exception {
		String result = String.format("Case #%d: %s",  case_T, output);

		System.out.println(result);
		writer.write(result+"\n");
	}

	public static void main(String... args) throws Exception {
		new B_small_0().run();
	}
}
