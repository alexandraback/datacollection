import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Stack;


public class Tomek {
	private enum Square {
		blank, x, o, t
	}

	private static int nextIntLine(Scanner in) {
		return Integer.parseInt(in.nextLine());
	}

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("output.out");
		f.delete();
		PrintStream out = new PrintStream(f);
//		PrintStream out = System.out;

		Scanner in = new Scanner(new File("input1.in"));
		int numCases = nextIntLine(in);
//		for(;;)System.out.println("\""+in.nextLine()+"\"");
		for(int i = 0; i < numCases; ++i) {
			out.printf("Case #%d: %s\n", i+1, getAnswer(in));
		}
		
		out.close();
		in.close();
	}
	
	private static String getAnswer(Scanner in) {
		Square[][] field = new Square[4][4];
		boolean incomplete = false;
		String winner = null;

		for(int y = 0; y < 4; ++y) {
			String line = in.nextLine();
			for(int x = 0; x < 4; ++x) {
				if(line.charAt(x) == 'X')
					field[y][x] = Square.x;
				else if(line.charAt(x) == 'O')
					field[y][x] = Square.o;
				else if(line.charAt(x) == 'T')
					field[y][x] = Square.t;
				else {
					field[y][x] = Square.blank;
					incomplete = true;
				}
//				System.out.print(field[y][x].name().charAt(0));
			}
//			System.out.println();
		}
		in.nextLine(); // blank line

		Stack<State> states = new Stack<State>();
		// push diagonals
		states.push(new State(field[0][0], 3, 0, 0, 1, 1));
		states.push(new State(field[0][3], 3, 0, 3, 1, -1));
		// push verticals
		for(int x = 0; x < 4; ++x) {
			states.push(new State(field[0][x], 3, 0, x, 1, 0));
		}
		// push horizontals
		for(int y = 0; y < 4; ++y) {
			states.push(new State(field[y][0], 3, y, 0, 0, 1));
		}

		while(!states.empty()) {
			State s = states.pop();
			if(s.type.equals(Square.blank)) continue;

			if(s.numRemaining==0) {
				if(s.type == Square.x)
					winner = "X";
				else if(s.type == Square.o)
					winner = "O";
				else throw new RuntimeException("winner? " + s.type.name());
				break;
			}

//			System.out.printf("y=%d x=%d yo=%d xo=%d n=%d\n", s.y, s.x, s.yoff, s.xoff, s.numRemaining);
			Square nextSquare = field[s.y + s.yoff][s.x + s.xoff];
			if(testNextSquare(s.type, nextSquare)) {
				Square type = s.type;
				if(type == Square.t) type = nextSquare;
				states.push(s.nextState(type));
			}
		}

		if(winner == null) {
			return (incomplete) ? "Game has not completed" : "Draw";
		} else {
			return winner + " won";
		}
	}

	private static boolean testNextSquare(Square type, Square nextSquare) {
//		System.out.printf("%s %s ", type.name(), nextSquare.name());
		if (type.equals(nextSquare) ||
				(type.equals(Square.t) && !nextSquare.equals(Square.blank)) ||
				(nextSquare.equals(Square.t) && !type.equals(Square.blank))) {
//			System.out.println(true);
			return true;
		} else {
//			System.out.println(false);
			return false;
		}
	}

	public static class State {
		public Square type;
		public int numRemaining;
		public int x;
		public int y;
		public int xoff;
		public int yoff;

		public State(Square s, int n, int y, int x, int yo, int xo) {
			type = s;
			numRemaining = n;
			this.x = x;
			this.y = y;
			xoff = xo;
			yoff = yo;
		}

		public State nextState(Square s) {
			return new State(s, numRemaining - 1, y + yoff, x + xoff, yoff, xoff);
		}
	}
}
