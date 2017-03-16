import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Cookie {
	private static InputStream in;
	private static PrintStream out;
	private static Scanner sc;
	static {
		try {
			in = new FileInputStream("B-small-attempt0.in");
			// System.in;
			out = new PrintStream(new FileOutputStream("out.txt"));
			// System.out;
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		sc = new Scanner(in);
		int numCases = sc.nextInt();
		for (int i = 0; i < numCases; i++) {
			out.println("Case #" + (i + 1) + ": " + solve());
		}
	}

	private static String solve() {
		double cost = sc.nextDouble();
		double prod = sc.nextDouble();
		double target = sc.nextDouble();

		double startLinearTime = 0;
		double speed = 2;
		double totalTime = target / speed;

		boolean optimized = false;
		do {
			double timeToBuyBuilding = cost / speed;

			double startLinearTime2 = startLinearTime + timeToBuyBuilding;
			double speed2 = speed + prod;
			double totalTime2 = (target) / speed2 + startLinearTime2;

			if (totalTime2 < totalTime) {
				optimized = true;
				startLinearTime = startLinearTime2;
				speed = speed2;
				totalTime = totalTime2;
			} else
				optimized = false;
		} while (optimized);
		return "" + totalTime;
	}
}
