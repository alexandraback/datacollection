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
	
	private static final String FILE = "../B-small-attempt2";
	
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

	private int solve1(LinkedList<Integer> ps) {
		// System.err.println(ps);
		
		int head = ps.removeLast();
		
		if (head <= 3) {
			return head;
		}
		
		int max = head;
		for (int div = 2; div <= Math.ceil(head / 3.0); div++) {
			LinkedList<Integer> ps2 = new LinkedList<Integer>(ps);
			int part = head / div;
			int remaining = head % div;
			for (int i = 0; i < remaining; i++) {
				ps2.push(part+1);
			}
			for (int i = remaining; i < div; i++) {
				ps2.push(part);
			}
			Collections.sort(ps2);
			
			int s = solve1(ps2) + (div-1);
			
			if (s < max) {
				max = s;
			}
		}
		
		return max;
	}
}

