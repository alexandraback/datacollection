import java.util.Arrays;
import java.util.Scanner;


public class DeceitfulWar {
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int caseNum = 1; caseNum <= t; caseNum++) {
			int n = in.nextInt();
			double naomi[] = new double[n];
			double ken[] = new double[n];
			for (int i = 0; i < n; i++) {
				naomi[i] = in.nextDouble();
			}
			for (int i = 0; i < n; i++) {
				ken[i] = in.nextDouble();
			}
			
			Arrays.sort(naomi);
			Arrays.sort(ken);

			int nw = 0;
			int kb = 0, kt = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (naomi[i] > ken[kt]) {
					nw++;
					kb++;
				}
				else {
					kt--;
				}
			}

			int nd = 0;
			kb = 0;
			kt = n - 1;
			for (int i = 0; i < n; i++) {
				if (naomi[i] < ken[kb]) {
					// Ken will always win this one. Naomi deceives him into
					// getting him of his heaviest block.
					kt--;
				}
				else {
					// Naomi deceives Ken into thinking that her lightest
					// block is really heavy. He discards his lightest block,
					// and Naomi wins because hers is heavier.
					nd++;
					kb++;
				}
			}

			System.out.println("Case #" + caseNum + ": " + nd + " " + nw);
		}
	}
}
