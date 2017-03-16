import static org.junit.Assert.assertEquals;

import java.util.ArrayList;
import java.util.Locale;
import java.util.Scanner;

import org.junit.Test;

// C:/Users/Jaap/workspace/Playground/bin
// C:/Users/Jaap/workspace/Playground/src

public class Round1C2013B {
	static {
		Locale.setDefault(Locale.US);
	}

	@Test
	public void testA() throws Exception {
		assertEquals("WNSEN", solve("3 4"));
	}

	@Test
	public void testB() throws Exception {
		assertEquals("ENSWN", solve("-3 4"));
	}

	static String solve(String testCase) {
		return new Solver(new Scanner(testCase)).solve();
	}

	static class Pos {
		int x, y;

		@Override
		public int hashCode() {
			return x * 31 + y;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pos other = (Pos) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}
	}

	static enum Direction {
		N, E, S, W;

		void move(Pos pos, int distance) {
			switch (this) {
			case N:
				pos.y += distance;
				break;
			case E:
				pos.x += distance;
				break;
			case S:
				pos.y -= distance;
				break;
			case W:
				pos.x -= distance;
				break;
			}
		}
	}

	static class Solver {
		private ArrayList<Direction> moves = new ArrayList<Direction>();
		private Pos target;
		private int speed;

		public Solver(Scanner scanner) {
			this.target = new Pos();
			this.target.x = scanner.nextInt();
			this.target.y = scanner.nextInt();
			this.speed = 1;
		}

		public String solve() {
			solveSimple(0, target.y, Direction.N, Direction.S);
			solveSimple(0, target.x, Direction.E, Direction.W);
			StringBuilder sb = new StringBuilder();
			for (Direction move : moves)
				sb.append(move.name());
			return sb.toString();
		}

		private void solveSimple(int current, int target, Direction posChange, Direction negChange) {
			if (current == target)
				return;
			if (Math.abs(current - target) >= speed) {
				if (current > target) {
					moves.add(negChange);
					int newCurrent = current - speed;
					speed++;
					solveSimple(newCurrent, target, posChange, negChange);
				} else { // current < target
					moves.add(posChange);
					int newCurrent = current + speed;
					speed++;
					solveSimple(newCurrent, target, posChange, negChange);
				}
			} else {
				if (current > target) {
					moves.add(posChange);
					moves.add(negChange);
					int newCurrent = current - 1;
					speed += 2;
					solveSimple(newCurrent, target, posChange, negChange);
				} else { // current < target
					moves.add(negChange);
					moves.add(posChange);
					int newCurrent = current + 1;
					speed += 2;
					solveSimple(newCurrent, target, posChange, negChange);
				}
			}
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int nrOfTestCases = scanner.nextInt();
		for (int caseNr = 1; caseNr <= nrOfTestCases; caseNr++) {
			Object solution = new Solver(scanner).solve();
			System.out.println("Case #" + caseNr + ": " + solution);
		}
	}
}
