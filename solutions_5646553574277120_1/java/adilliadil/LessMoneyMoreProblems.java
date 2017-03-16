import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class LessMoneyMoreProblems {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int t = 0; t < T; t++) {
			int C = in.nextInt();
			int D = in.nextInt();
			int V = in.nextInt();
			Queue<Long> q = new LinkedList<>();
			for (int i = 0; i < D; i++) {
				q.add(in.nextLong());
			}
			int count = 0;
			long maxpossible = 0;
			while (maxpossible < V) {
				if (!q.isEmpty()) {
					if (maxpossible + 1 < q.peek()) {
						count++;
						maxpossible += C * (maxpossible + 1);
					} else {
						maxpossible += C * q.poll();
					}
				} else {
					count++;
					maxpossible += C * (maxpossible + 1);
				}
			}
			System.out.println("Case #" + (t + 1) + ": " + count);

		}
	}
}
