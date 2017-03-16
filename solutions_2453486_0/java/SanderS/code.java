package qualification;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class TicTacToeTomek {

	static String PROBLEM_NAME = "TicTacToeTomek";
	static String FILE_ROOT =  "C:/googleCodeJam/";

	static boolean HAS_EMPTY_CELLS;

	// static String INPUT_FILE_NAME = FILE_ROOT + PROBLEM_NAME + "/inputTest";
	static String INPUT_FILE_NAME = FILE_ROOT + PROBLEM_NAME + "/inputExample.txt";

	static String OUTPUT_FILE_NAME = FILE_ROOT + PROBLEM_NAME + "/outputExample.txt";

	static int INPUT_ROWS_PER_PROBLEM = 4;

	private static enum Outcome {

		X_WON("X won"),
		O_WON("O won"),
		DRAW("Draw"),
		NOT_COMPLETED("Game has not completed");

		private String code;

		Outcome(String s) {
			code = s;
		}

		public String getCode() {
			return code;
		}	
	}

	public static void main(String[] args) throws IOException {

		BufferedReader in = new BufferedReader(new FileReader(INPUT_FILE_NAME));
		BufferedWriter out = new BufferedWriter(new FileWriter(OUTPUT_FILE_NAME, false));

		final int total_num_problems = Integer.parseInt(in.readLine());
		int current_problem_number = 1;

		System.out.println("Starting to solve: " + PROBLEM_NAME);
		System.out.println("Input file: " + INPUT_FILE_NAME);
		System.out.println("Output file: " + OUTPUT_FILE_NAME);
		System.out.println("Total number of problems: " + total_num_problems);

		try {
			while (in.ready()) {

				System.out.print("Starting problem: " + current_problem_number + "...");

				if (current_problem_number > 1) {
					out.newLine();
				}

				String[] inputLines = new String[INPUT_ROWS_PER_PROBLEM];

				for(int row = 0; row <INPUT_ROWS_PER_PROBLEM; row++){
					inputLines[row] = in.readLine();
				}

				String solution = determineSolution(inputLines);

				System.out.println("found Solution! It is '" + solution + "'.");
				out.write("Case #" + current_problem_number + ": " + solution);


				current_problem_number++;
				
				// skip the empty line;
				in.readLine();

			} } finally{
				in.close();
				out.flush();
				out.close();
			}

	}

	private static String determineSolution(String[] inputLines) {

		HAS_EMPTY_CELLS = false;
		Outcome outcome = null;

		// check the horizontals
		for (int i = 0; i <4; i++) {
			if ((outcome = checkLine (inputLines[i])) != null) {
				return outcome.getCode();
			}
		}

		// check the verticals
		for (int i = 0; i <4; i++) {

			String verticalLine = inputLines[0].substring(i, i+1) + 
					inputLines[1].substring(i, i+1) +
					inputLines[2].substring(i, i+1) + 
					inputLines[3].substring(i, i+1);

			if ((outcome = checkLine (verticalLine)) != null) {
				return outcome.getCode();
			}
		}

		// check the diagonals
		String diagonal1 = inputLines[0].substring(0,1) + 
				inputLines[1].substring(1,2) +
				inputLines[2].substring(2,3) + 
				inputLines[3].substring(3,4);
		
		String diagonal2 = inputLines[3].substring(0,1) + 
				inputLines[2].substring(1,2) +
				inputLines[1].substring(2,3) + 
				inputLines[0].substring(3,4);

		if ((outcome = checkLine (diagonal1)) != null) {
			return outcome.getCode();
		}

		if ((outcome = checkLine (diagonal2)) != null) {
			return outcome.getCode();
		}

		// Nobody won. Check if draw or ongoing.
		if (HAS_EMPTY_CELLS == true) {
			return outcome.NOT_COMPLETED.getCode();
		} 

		return outcome.DRAW.getCode();
	}

	private static Outcome checkLine(String line) {

		int t_count = 0;
		int x_count = 0;
		int o_count = 0;

		for (int charIndex = 0; charIndex < 4; charIndex++) {

			switch(line.charAt(charIndex)) {
			case '.':	HAS_EMPTY_CELLS = true;
			break;
			case 'X':	x_count++;
			break;
			case 'O':	o_count++;
			break;
			case 'T':	t_count++;
			break;
			}

			if (x_count + t_count == 4) {
				return Outcome.X_WON;
			}

			if (o_count + t_count == 4) {
				return Outcome.O_WON;
			}
		}

		return null;

	}

}