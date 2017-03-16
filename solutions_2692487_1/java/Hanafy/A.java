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
			
			if(A == 1){
				System.out.printf("Case #%d: %d\n", I, N);
				continue;
			}
			Arrays.sort(nums);
			int[] temp = new int[N];
			for (int i = 0; i < N; i++)
				if (A  > nums[i]) {
					A += nums[i];
				} else {
					while (A <= nums[i]) {
						A += A - 1;
						temp[i]++;
					}
					A += nums[i];
				}

			int[] temp2 = new int[N];
			temp2[N - 1] = temp[N - 1];
			for (int i = N - 2; i >= 0; i--)
				temp2[i] = temp[i] + temp2[i + 1];

			int sum = 0;
			for (int i = 0; i < N; i++)
				if (N - i < temp2[i]) {
					sum += N - i;
					break;
				} else
					sum += temp[i];

			System.out.printf("Case #%d: %d\n", I, sum);
		}
	}
}
