import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class A {
	static int A, N;
	static int[] nums;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int I = 1; I <= T; I++) {
			A = in.nextInt();
			N = in.nextInt();
			nums = new int[N];
			for (int i = 0; i < N; i++)
				nums[i] = in.nextInt();

			Arrays.sort(nums);
			int oper = 0;
			for (int i = 0; i < N; i++)
				if (nums[i] < A)
					A += nums[i];
				else {
					oper += solve(i);
					break;
				}

			System.out.printf("Case #%d: %d\n", I, oper);
		}
	}

	private static int solve(int idx) {
		Queue<Integer> queue = new LinkedList<Integer>();
		queue.add(A);
		queue.add(idx);
		queue.add(0);

		while (!queue.isEmpty()) {
			int a = queue.poll(), i = queue.poll(), oper = queue.poll();
			if (i == N)
				return oper;

			// add
			int ta = a + a -1, ti = i;
			while(ti < N && nums[ti] < ta)
				ta += nums[ti++];
			queue.add(ta);
			queue.add(ti);
			queue.add(oper + 1);

			// remove
			queue.add(a);
			queue.add(i + 1);
			queue.add(oper + 1);
		}
		return 0;
	}
}
