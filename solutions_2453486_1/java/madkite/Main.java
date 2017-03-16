import java.io.*;
import java.util.concurrent.*;

/**
 * @author Roman Kosenko <madkite@gmail.com>
 */
public class Main extends SingleThreadSolution<Object> {
	public static void main(String[] args) throws Exception {
		solve(new SolutionFactory<Object>() {
			public Callable<Object> read(BufferedReader br) throws IOException {
				String[] board = new String[]{br.readLine(), br.readLine(), br.readLine(), br.readLine()};
				String end = br.readLine();
				if(end != null && !end.isEmpty())
					throw new IllegalArgumentException();
				return new Main(board);
			}
		}, "google/src/gcj2013qr/" + "A-large.in");
	}
	private final String[] board;
	public Main(String[] board) {
		assert board.length == 4;
		for(String line : board)
			assert line.length() == 4;
		this.board = board;
	}
	public String call() throws Exception {
		if(won('X'))
			return "X won";
		if(won('O'))
			return "O won";
		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				if(board[i].charAt(j) == '.')
					return "Game has not completed";
			}
		}
		return "Draw";
	}
	public boolean won(char p) {
		h: for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				char m = board[i].charAt(j);
				if(m != 'T' && m != p)
					continue h;
			}
			return true;
		}
		v: for(int i = 0; i < 4; i++) {
			for(int j = 0; j < 4; j++) {
				char m = board[j].charAt(i);
				if(m != 'T' && m != p)
					continue v;
			}
			return true;
		}
		for(int i = 0;; i++) {
			if(i == 4)
				return true;
			char m = board[i].charAt(i);
			if(m != 'T' && m != p)
				break;
		}
		for(int i = 0;; i++) {
			if(i == 4)
				return true;
			char m = board[i].charAt(3 - i);
			if(m != 'T' && m != p)
				break;
		}
		return false;
	}
}
interface SolutionFactory<V> {
	Callable<V> read(BufferedReader br) throws IOException;
}
abstract class SingleThreadSolution<V> implements Callable<V> {
	protected static void solve(SolutionFactory factory, String input) throws Exception {
		String output = null;
		if(input.endsWith(".in"))
			output = input.substring(0, input.length() - 2) + "out";
		solve(factory, input, output);
	}
	protected static void solve(SolutionFactory factory, String input, String output) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(input));
		if(output != null)
			System.setOut(new PrintStream(output));
		solve(factory, br);
	}
	protected static void solve(SolutionFactory factory, BufferedReader br) throws Exception {
		long time = System.currentTimeMillis();
		int t = Integer.parseInt(br.readLine());
		for(int i = 0; i < t; i++)
			System.out.println("Case #" + (i + 1) + ": " + factory.read(br).call());
		time = System.currentTimeMillis() - time;
		Thread.sleep(100);
		System.err.println(time);
	}
}
