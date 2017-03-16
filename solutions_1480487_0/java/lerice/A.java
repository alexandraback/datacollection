import java.util.Scanner;

public class A {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int nCases = sc.nextInt();
		for (int i = 1; i <= nCases; i++) {
			int nContest = sc.nextInt();
			int[] judgePoint = new int[nContest];
			int totalPoint = 0;
			int maxPoint = 0;
			System.out.print("Case #" + i + ":");
			for (int j = 0; j < nContest; j++) {
				judgePoint[j] = sc.nextInt();
				if (j == 0) maxPoint = judgePoint[j];
				if (j != 0 && judgePoint[j] > maxPoint) maxPoint = judgePoint[j];
				totalPoint += judgePoint[j];
			}
			double[] difference = new double[nContest];
			double totalDifference = 0;
			for (int k = 0; k < nContest; k++) {
				difference[k] = ((double)(maxPoint - judgePoint[k])) / totalPoint * 100;
				totalDifference += difference[k];
			}
			double baseDiff  = (100 - totalDifference) / nContest;
			double[] percent = new double[nContest];
			for (int xx = 0; xx < nContest; xx++) {
				percent[xx] = difference[xx] + baseDiff;
			}

			boolean hasNeg = (baseDiff < 0);
			while (hasNeg) {
				double maxNeg = percent[0];
				for (int cc = 1; cc < nContest; cc++) {
					if (percent[cc] < maxNeg) maxNeg = percent[cc];
				}
				double totalPercent = 0;
				int nonZeroContest = 0;
				for (int vv = 0; vv < nContest; vv++) {
					percent[vv] -= maxNeg;
					totalPercent += percent[vv];
					if (percent[vv] != 0) nonZeroContest++;
				}
				for (int bb = 0; bb < nContest; bb++) {
					if (percent[bb] != 0) percent[bb] -= (totalPercent - 100) / nonZeroContest;
				}
				hasNeg = false;
				for (int nn = 0; nn < nContest; nn++) {
					if (percent[nn] < -0.0000005) hasNeg = true;
				}
			}

			for (int zz = 0; zz < nContest; zz++) {
				System.out.printf(" %.6f",(percent[zz]));
			}
			System.out.print("\n");
		}
	}
}
