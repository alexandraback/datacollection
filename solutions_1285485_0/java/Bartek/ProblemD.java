import java.io.PrintWriter;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;

public class ProblemD {

	static enum Direction {
		RIGHT, UP, LEFT, DOWN;
	}

	static class Angle {
		public final int x;
		public final int y;

		public Angle(int x, int y) {
			final int gcd = Math.abs(gcd(x, y));
			this.x = x / gcd;
			this.y = y / gcd;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Angle other = (Angle) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "Angle [x=" + x + ", y=" + y + "]";
		}
	}

	static class Point {
		public final int x;
		public final int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		public int distance2(int x, int y) {
			final int dx = x - this.x;
			final int dy = y - this.y;
			return dx * dx + dy * dy;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Point other = (Point) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		@Override
		public String toString() {
			return "Point [x=" + x + ", y=" + y + "]";
		}
	}

	public static void main(String[] args) {
		final Scanner in = new Scanner(System.in);
		final PrintWriter out = new PrintWriter(System.out);

		final int t = in.nextInt();
		for (int tt = 1; tt <= t; tt++) {
			final int h = (in.nextInt() - 2) * 10;
			final int w = (in.nextInt() - 2) * 10;
			final int d = in.nextInt() * 10;
			final int d2 = d * d;
			in.nextLine();

			int x = 0;
			int y = 0;

			int lineNumber = -1;
			for (int hh = 0; hh < h + 20; hh += 10) {
				final String line = in.nextLine();
				if (line.contains("X")) {
					x = (line.indexOf('X') - 1) * 10 + 5;
					y = lineNumber * 10 + 5;
				}
				lineNumber++;
			}

			final Set<Angle> anglesFound = new HashSet<>();
			final Set<Point> pointsChecked = new HashSet<>(w * h);
			final LinkedList<Point> pointsToCheck = new LinkedList<>();
			pointsToCheck.add(new Point(x, y));

			while (!pointsToCheck.isEmpty()) {
				final Point point = pointsToCheck.poll();

				if (pointsChecked.contains(point)) {
					continue;
				} else {
					pointsChecked.add(point);
				}

				if (point.distance2(x, y) > d2) {
					continue;
				}

				if (point.x != x || point.y != y) {
					final Angle angle = new Angle(point.x - x, point.y - y);
					if (!anglesFound.contains(angle)) {
						anglesFound.add(angle);
					}
				}

				{
					final Point up = new Point(point.x, point.y - 2 * normalizeY(point.y, h));
					if (!pointsChecked.contains(up)) {
						pointsToCheck.add(up);
					}
				}

				{
					final Point down = new Point(point.x, point.y + 2 * (h - normalizeY(point.y, h)));
					if (!pointsChecked.contains(down)) {
						pointsToCheck.add(down);
					}
				}

				{
					final Point left = new Point(point.x - 2 * normalizeX(point.x, w), point.y);
					if (!pointsChecked.contains(left)) {
						pointsToCheck.add(left);
					}
				}

				{
					final Point right = new Point(point.x + 2 * (w - normalizeX(point.x, w)), point.y);
					if (!pointsChecked.contains(right)) {
						pointsToCheck.add(right);
					}
				}
			}

			out.println("Case #" + tt + ": " + anglesFound.size());
		}

		out.flush();
	}

	private static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	
	private static int normalizeX(int x, int w) {
		int result = x % w;
		if (result < 0) {
			return result + w;
		} else {
			return result;
		}
	}
	
	private static int normalizeY(int y, int h) {
		int result = y % h;
		if (result < 0) {
			return result + h;
		} else {
			return result;
		}
	}

}
