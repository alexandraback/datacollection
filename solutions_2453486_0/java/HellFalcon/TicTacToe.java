import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.Closeable;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class TicTacToe {

	private static final class Result extends LinkedList<String> {
		
		private static final long serialVersionUID = 201212121200L;

		public void writeTo(Appendable appendable) throws IOException {
			for (String line : this) {
				appendable.append(line + "\n");
			}
		}
	}

	private static final class Solver implements Callable<Result> {
		
		private int testId;
		private char[][] board = new char[4][4];
		
		public Solver(int testId, String[] board) {
			this.testId = testId;
			for (int i = 0; i < 4; i++) this.board[i] = board[i].toCharArray();
		}
		
		boolean check(int i, int j, int di, int dj, char ch) {
			for (int q = 0; q < 4; q++) {
				if (!(board[i][j] == ch | board[i][j] == 'T')) return false;
				i += di;
				j += dj;
			}
			return true;
		}
		
		public Result call() {
			boolean xWon = false;
			// - X
			xWon |= check(0, 0, 1, 1, 'X');
			xWon |= check(0, 3, 1, -1, 'X');
			for (int i = 0; i < 4; i++) {
				xWon |= check(i, 0, 0, 1, 'X');				
				xWon |= check(0, i, 1, 0, 'X');				
			}
			boolean oWon = false;
			// - O
			oWon |= check(0, 0, 1, 1, 'O');
			oWon |= check(0, 3, 1, -1, 'O');
			for (int i = 0; i < 4; i++) {
				oWon |= check(i, 0, 0, 1, 'O');
				oWon |= check(0, i, 1, 0, 'O');				
			}
			boolean inProgress = false;
			mainLoop:
			for (int i = 0; i < 4; i++)
				for (int j = 0; j < 4; j++)
					if (board[i][j] == '.') {
						inProgress = true;
						break mainLoop;
					}
			String answer;
			if (xWon)
				answer = "X won";
			else if (oWon)
				answer = "O won";
			else if (inProgress)
				answer = "Game has not completed";
			else 
				answer = "Draw";
			Result result = new Result();
			result.add("Case #" + testId + ": " + answer);
			return result;
		}
	}
	
	private static void release(Closeable resource) {
		if (resource == null) return;
		try {
			resource.close();
		}
		catch (IOException ignore) {};
	}

	private static void release(ExecutorService resource) {
		if (resource == null) return;
		resource.shutdown();
	}

	public static void main(String[] args) {
		long startTime = System.currentTimeMillis();
		BufferedReader in = null;
		BufferedWriter out = null;
		ExecutorService executor = null;
		try {
			in = new BufferedReader(new FileReader(new File("A-small-attempt0.in")), 256 << 10);
			out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			executor = Executors.newFixedThreadPool(5);
			List<Future<Result>> results = new LinkedList<Future<Result>>();

			int testsNumber = Integer.parseInt(in.readLine().trim());
			for (int testId = 1; testId <= testsNumber; testId++) {
				String[] board = new String[4];
				for (int i = 0; i < 4; i++) board[i] = in.readLine().trim();
				results.add(executor.submit(new Solver(testId, board)));
				in.readLine();
			}
			int testId = 1;
			for (Future<Result> future : results) {
				future.get().writeTo(out);
				System.out.println("Test #" + testId++ + " is completed");
			}
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
		finally {
			release(in);
			release(out);
			release(executor);
		}
		System.out.println("Execution completed in approximately " + (System.currentTimeMillis() - startTime) + " milliseconds");
	}
}
