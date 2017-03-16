import java.util.*;

public class B {
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();
	
	for (int nc = 1; nc <= nCase; nc++) {
		int D = scanner.nextInt();
		int[] cakes = new int[D];
		PriorityQueue<Integer> queue = new PriorityQueue<Integer>(D + D, Collections.reverseOrder());
		for (int i = 0; i < D; i++)
			queue.add(cakes[i] = scanner.nextInt());
		
		int ans = queue.peek();
		int min = 0;
		while (queue.peek() > 3) {
			min++;
			int most = queue.poll();
			queue.add(most/2);
			queue.add(most - most/2);
			if (queue.peek() + min < ans)
				ans = queue.peek() + min;
		}
		
		queue.clear();
		for (int i = 0; i < D; i++)
			queue.add(cakes[i]);
		min = 0;
		while (queue.peek() > 3) {
			min++;
			int most = queue.poll();
			if (most >= 9) {
				queue.add(3);
				queue.add(most - 3);
			} else {
				queue.add(most/2);
				queue.add(most - most/2);
			}
			if (queue.peek() + min < ans)
				ans = queue.peek() + min;
		}
		
		System.out.println("Case #" + nc + ": " + ans);
	}
}
}