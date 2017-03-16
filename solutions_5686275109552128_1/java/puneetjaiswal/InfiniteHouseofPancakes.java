import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class InfiniteHouseofPancakes {

	static int findMinTime(int[] arr) {
		Arrays.sort(arr);
		int max = arr[arr.length - 1];
		int total = max;
		for (int i = max - 1; i >= 1; i--) {
			int sum = 0;
			PriorityQueue<Integer> pq = new PriorityQueue<>();
			for (int j = 0; j < arr.length; j++) {
				pq.add(-1 * arr[j]);
			}

			int out = pq.poll() * -1;
			while (out > i) {
				pq.add((out - i) * -1);
				pq.add(i * -1);
				out = pq.poll() * -1;
				sum++;
			}
			sum += out;
			if (sum < total) {
				total = sum;
			}
		}
		return total;
	}

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		int count = 0;
		while (T-- > 0) {
			count++;
			int num = scan.nextInt();
			int[] A = new int[num];
			for (int i = 0; i < num; i++) {
				A[i] = scan.nextInt();
			}
			System.out.println("Case #" + count + ": " + findMinTime(A));
		}

	}

}
