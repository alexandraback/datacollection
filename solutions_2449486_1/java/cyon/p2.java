package qual;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class p2 {

	private static void debug(Object... args) {
		System.out.println(Arrays.deepToString(args));
	}

	private static String solve(BufferedReader br) throws Exception {
		int n=0,m=0;
		StringTokenizer st = new StringTokenizer(br.readLine());
		n=Integer.parseInt(st.nextToken());
		m=Integer.parseInt(st.nextToken());
		int[][]b = new int[n][m];
		for(int i=0;i<n;i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0;j<m;j++) {
				b[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				int rmax = -1;
				for(int k=0;k<m;k++) {
					if(k==j) continue;
					rmax = Math.max(rmax, b[i][k]);
				}
				int cmax = -1;
				for(int k=0;k<n;k++) {
					if(k==i) continue;
					cmax = Math.max(cmax, b[k][j]);
				}
				if(cmax > b[i][j] && rmax > b[i][j]) return "NO";
			}
		}
		return "YES";
	}
		

	public static void main(String[] rags) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int t = Integer.parseInt(br.readLine());
		for (int i = 1; i <= t; i++) {
			pw.println("Case #" + i + ": " + solve(br));
		}
	}
}