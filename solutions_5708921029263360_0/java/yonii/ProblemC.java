import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ProblemC {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(
				System.in)));
		in = new Scanner(new File("C-small-attempt1.in"));
		
		int T = in.nextInt();
		for (int i=1; i<=T; i++) {
			int J = in.nextInt();
			int P = in.nextInt();
			int S = in.nextInt();
			int K = in.nextInt();
			int[][] JP = new int[J+1][P+1];
			int[][] JS = new int[J+1][S+1];
			int[][] PS = new int[P+1][S+1];
			
			StringBuilder sb = new StringBuilder();
			int cnt = 0;
			for (int k=1; k<=K; k++) {
				for (int j=1; j<=J; j++) {
					for (int p=1; p<=P; p++) {
						for (int s=1; s<=S; s++) {
							if (JP[j][p] < K && JS[j][s] < K && PS[p][s] < K) {
								JP[j][p]++;
								JS[j][s]++;
								PS[p][s]++;
								sb.append('\n');
								sb.append(j);
								sb.append(' ');
								sb.append(p);
								sb.append(' ');
								sb.append(s);
								cnt++;
								break;
							}
						}
					}
				}
			}
			
			System.out.printf("Case #%d: %d", i, cnt);
			System.out.println(sb.toString());
		}
	}
}