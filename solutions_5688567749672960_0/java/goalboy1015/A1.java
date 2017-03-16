import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class A1 {
	static final Boolean SAMPLE = false;
	static final String PROBLEM = "A";
	static final String INPUT = "small";
	static final String ID = "3";
	static final String PATH = "/Users/wangkai/Documents/codejam-commandline-1.2-beta1/source/";

	public static void main(String[] args) throws Throwable {
		Scanner in = SAMPLE ? new Scanner(System.in) : new Scanner(new File(
				PATH + PROBLEM + "-" + INPUT + "-" + ID + ".in"));
		PrintStream out = SAMPLE ? System.out : new PrintStream(PATH + PROBLEM
				+ "-" + INPUT + "-" + ID + ".out");

		int test = in.nextInt();
		for (int t = 1; t <= test; t++) {
			out.print("Case #" + t + ": ");

			int N = in.nextInt();

			out.println(solve(N));
		}

		out.close();
		in.close();

		System.out.println("finish!");
	}

	static int solve(int target) {
		Set<Integer> history = new HashSet<Integer>();

		Queue<Element> queue = new LinkedList<Element>();
		queue.offer(new Element(1, 1));
		while (true) {
			Element head = queue.poll();

			if (history.contains(head.number)) {
				continue;
			}
			history.add(head.number);

			if (head.number == target) {
				return head.step;
			}
			queue.offer(new Element(head.number + 1, head.step + 1));
			queue.offer(new Element(Integer.parseInt(new StringBuilder(
					head.number + "").reverse().toString()), head.step + 1));
		}
	}
}

class Element {
	int number;
	int step;

	Element(int number, int step) {
		this.number = number;
		this.step = step;
	}
}