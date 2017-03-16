import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

public class X {
	public static void main(String[] args) throws FileNotFoundException {
		new X().run();
	}
	
	// private static final String FILE = "../B-small-attempt2";
	private static final String FILE = "../B-large";
	
	private Scanner scanner;
	private PrintWriter out;
	
	void run() throws FileNotFoundException {
		scanner = new Scanner(new File(FILE + ".in"));
		out = new PrintWriter(new File(FILE + ".out"));
		
		int n = scanner.nextInt();
		for (int i = 1; i <= n; i++) {
			solve(i);
		}
		
		scanner.close();
		out.close();
	}
	
	void solve(int index) {
		int d = scanner.nextInt();
		LinkedList<Integer> ps = new LinkedList<>();
		for (int i = 0; i < d; i++) {
			ps.add(scanner.nextInt());
		}
		
		Collections.sort(ps);
		
		out.println("Case #" + index + ": " + solve1(ps));
	}
	
	private int costToReduce(int base, int target) {
		return (int) Math.ceil(((double)base) / target) - 1;
	}

	private int solve1(LinkedList<Integer> ps) {
		int max = ps.getLast();
		int minCost = max;
		
		for (int target = 1; target <= max; target++) {
			int cost = 0;
			for (int x : ps) {
				cost += costToReduce(x, target);
			}
			cost += target;
			
			// System.err.println("Target=" + target + ", Cost=" + cost);
			
			if (cost < minCost) {
				minCost = cost;
			}
		}
		
		return minCost;
	}
}

