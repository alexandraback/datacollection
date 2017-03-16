import java.util.*;
import java.io.*;
import java.util.HashMap;


public class q3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();
		for (int i=1; i<=t; i++) {
			System.out.print("Case #" + i + ": ");
			int j = in.nextInt();
			int p = in.nextInt();
			int s = in.nextInt();
			int k = in.nextInt();
			int maxMatches=j*p*s;
			System.out.println(Math.min(maxMatches,j*p*k));
			int[][] usedjp = new int[j+1][p+1];
			int[][] usedjs = new int[j+1][s+1];
			int[][] usedps = new int[p+1][s+1];
			for (int a=1; a<=j; a++) {
				for (int b=1; b<=p; b++) {
					for (int c=1; c<=s; c++) {
						usedjp[a][b]=0;
						usedjs[a][c]=0;
						usedps[b][c]=0;
					}
				}
			}
			for (int a=1; a<=j; a++) {
				for (int b = 1; b<=p; b++) {
						for (int c=1; c<=s; c++) {
							int e=-1;
							if (usedjp[a][b]<k && usedjs[a][c]<k && usedps[b][c]<k) {
								e=c;
								usedjp[a][b]++;
								usedjs[a][c]++;
								usedps[b][c]++;
							}
							if (e>0) System.out.println(a + " " + b + " " + e);
						}

				}
			}
		}

	}
}