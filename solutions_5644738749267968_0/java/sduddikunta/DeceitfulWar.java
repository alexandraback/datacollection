import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int ca = 1; ca <= cases; ca++) {
			int blocks = in.nextInt();
			double[] naomi = new double[blocks];
			double[] kenOrig = new double[blocks];
			for (int i = 0; i < blocks; i++) {
				naomi[i] = in.nextDouble();
			}
			for (int i = 0; i < blocks; i++) {
				kenOrig[i] = in.nextDouble();
			}
			double[] ken = Arrays.copyOf(kenOrig, kenOrig.length);
			Arrays.sort(ken);
			int pointsWar = 0;
			for (int i = 0; i < blocks; i++) {
				int blockToUse = -1;
				for (int k = blocks - 1; k >= 0; k--) {
					if (ken[k] < 0)
						continue;
					if (ken[k] > naomi[i])
						blockToUse = k;
					else
						break;
				}
				if (blockToUse == -1) {
					for (int k = 0; k < blocks; k++) {
						if (ken[k] < 0)
							continue;
						else {
							blockToUse = k;
							break;
						}
					}
				}
				if (ken[blockToUse] < naomi[i])
					pointsWar++;
				ken[blockToUse] = -1;
			}
			ken = kenOrig;
			Arrays.sort(ken);
			Arrays.sort(naomi);
			int pointsDeceit = 0;
			int blocksToPlay = blocks;
			int nIndex = 0;
			int kIndex = 0;
			while (blocksToPlay > 0) {
				if (naomi[nIndex] < ken[kIndex]) { // this block always loses
					nIndex++;
					blocksToPlay--;
				} else { // beats ken's smallest
					pointsDeceit++;
					nIndex++;
					kIndex++;
					blocksToPlay--;
				}
			}
			System.out.printf("Case #%d: %d %d%n", ca, pointsDeceit, pointsWar);
		}
	}
}
