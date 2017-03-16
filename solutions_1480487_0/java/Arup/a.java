import java.util.*;


public class a {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int N = stdin.nextInt();

			int[] judge = new int[N];

			int sum = 0;
			for (int i=0; i<N; i++) {
				judge[i] = stdin.nextInt();
				sum += judge[i];
			}

			double threshold = 2.0*sum/N;
			boolean[] needpts = new boolean[N];

			int numNeedpts = 0;
			int sumNeed = 0;
			for (int i=0; i<N; i++) {
				if (judge[i] < threshold) {
					numNeedpts++;
					needpts[i] = true;
					sumNeed += judge[i];
				}
				else
					needpts[i] = false;
			}

			System.out.print("Case #"+loop+": ");

			for (int i=0; i<N; i++) {

				if (!needpts[i])
					System.out.print("0.0 ");
				else {

					if (numNeedpts > 1) {
						double ans =(double)((sumNeed - judge[i]) + sum - (numNeedpts-1)*judge[i])/numNeedpts;
						System.out.print(100.0*ans/sum+" ");
					}
					else
						System.out.print("100.0 ");

				}
			}
			System.out.println();


		}
	}
}