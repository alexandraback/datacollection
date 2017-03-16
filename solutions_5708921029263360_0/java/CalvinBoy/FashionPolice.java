import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;

import javafx.util.Pair;


public class FashionPolice {
	public static void main(String[] args) {
	
	Scanner scanner = new Scanner(System.in);
	int t = scanner.nextInt();
	for(int cas=1; cas<=t; ++cas) {
		int j = scanner.nextInt();
		int p = scanner.nextInt();
		int s = scanner.nextInt();
		int k = scanner.nextInt();
		int[][] cntA = new int[4][4];
		int[][] cntB = new int[4][4];
		int[][] cntC = new int[4][4];
		int[][][] abc = new int [4][4][4];
		int[][] ans = new int[27][3];
		int ansCnt =0;
		for(int one=1; one<=j; one++) {
			for(int two=1; two<=p; two++)
				for(int three = 1; three<=s; three++){
					if(cntA[one][two] < k && cntB[one][three]<k && cntC[two][three]<k && abc[one][two][three] ==0) {
						ans[ansCnt][0]=one;
						ans[ansCnt][1]=two;
						ans[ansCnt][2]=three;
						cntA[one][two]++;
						cntB[one][three]++;
						cntC[two][three]++;
						abc[one][two][three]++;
						ansCnt++;
					}
				}
			
		}
		System.out.printf("Case #%d: %d\n", cas, ansCnt);
		for(int i=0; i<ansCnt; ++i) {
			System.out.printf("%d %d %d\n", ans[i][0], ans[i][1], ans[i][2]);
		}
	}
}
}
