import java.util.ArrayList;
import java.util.Scanner;

public class C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int i = 0; i < T; i++) {
			int ans = solve(in);
			System.out.printf("Case #%d: %d\n", i + 1, ans);
		}

	}

	public static int solve(Scanner in) {

		int N = in.nextInt();
		ArrayList<Hiker> hikers = new ArrayList<Hiker>();
		for (int i = 0; i < N; i++) {
			int di = in.nextInt();
			int hi = in.nextInt();
			int mi = in.nextInt();
			for (int h = 0; h < hi; h++) {
				hikers.add(new Hiker(di, mi + h));
			}
		}

		int best = hikers.size();

		for (Hiker h : hikers) {
			best = Math.min(best, solveForSpeed(h, hikers));
		}
		for (Hiker h : hikers) {
			//best = Math.min(best, solveForApproximating(h, hikers));
		}

		return best;
	}

	public static int solveForApproximating(Hiker h, ArrayList<Hiker> hikers) {
		// Make our time of completion line up with theirs
		double timeOfCompletion = (360 - h.start)*h.speed - .0000001;
		Hiker deer = new Hiker(0, timeOfCompletion);

		int ans = 0;

		for (Hiker hiker : hikers) {
			double timeOfIntersection = hiker.intersects(deer);
			if (timeOfIntersection < timeOfCompletion) {
				ans++;
			}
		}

		System.out.println(ans);
		return ans;
	}

	public static int solveForSpeed(Hiker h, ArrayList<Hiker> hikers) {
		double speed = h.speed;
		double timeOfCompletion = speed * 360;
		Hiker deer = new Hiker(0, timeOfCompletion);

		int ans = 0;

		for (Hiker hiker : hikers) {
			double timeOfIntersection = hiker.intersects(deer);
			if (timeOfIntersection < timeOfCompletion) {
				ans++;
			}
		}

		return ans;
	}

	static class Hiker {
		public Hiker(int start, double speed) {
			this.start = start;
			this.speed = speed / 360.0;
		}

		int start; // in degrees
		double speed; // degrees per minute

		public double intersects(Hiker other) {
			if (other.speed == this.speed) {
				return Double.MAX_VALUE;
			}

			Hiker faster, slower;
			if (other.speed > this.speed) {
				faster = other;
				slower = this;
			} else {
				faster = this;
				slower = other;
			}

			double rate = faster.speed - slower.speed;
			if (faster.start < slower.start) {
				return (slower.start - faster.start) / rate;
			} else {
				return ((slower.start + 360) - faster.start) / rate;
			}

		}
	}

}
