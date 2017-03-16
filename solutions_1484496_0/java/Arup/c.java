import java.util.*;

public class c {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int N = stdin.nextInt();
			int[] nums = new int[N];

			int thissum = 0;
			for (int i=0; i<N; i++) {
				nums[i] = stdin.nextInt();
				thissum += nums[i];
			}

			int[] allsums = new int[1 << N];
			boolean[] found = new boolean[thissum+1];
			Arrays.fill(found, false);
			System.out.println("Case #"+loop+":");
			boolean flag = false;

			for (int subset=1; subset < (1 << N); subset++) {

				int sum = 0;
				int index = 0;
				int savesubset = subset;
				while (savesubset > 0) {
					if (savesubset%2 == 1)
						sum += nums[index];
					index++;
					savesubset /= 2;
				}
				allsums[subset] = sum;

				if (!found[sum]) {
					found[sum] = true;
				}
				else {
					flag = true;
					int match = 0;
					for (int i=1; i<subset; i++)
						if (allsums[i] == sum)
							match = i;


					savesubset = subset;
					int savematch = match;
					for (int i=0; i<N; i++) {
						if (savematch%2 == 1 && savesubset%2 == 0)
							System.out.print(nums[i]+" ");
						savesubset /= 2;
						savematch /= 2;

					}
					System.out.println();

					savesubset = subset;
					savematch = match;
					for (int i=0; i<N; i++) {
						if (savematch%2 == 0 && savesubset%2 == 1)
							System.out.print(nums[i]+" ");
						savesubset /= 2;
						savematch /= 2;

					}
					System.out.println();
					break;
				}


			}

			if (!flag)
				System.out.println("Impossible");
		}
	}
}