package codejam2012;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class DiamondInheritance {
	public static void main(String[] args) throws FileNotFoundException {
		new DiamondInheritance().run();
	}
	
	boolean[][] connect;
	boolean[][] visit;
	int n;
	int m;
	int pathCount;
	private void run() throws FileNotFoundException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		in = new Scanner(new FileInputStream(new File("/home/mosaick/sample-in.txt")));
		out = new PrintWriter(new FileOutputStream("/home/mosaick/sample-out.txt"));
		
		int t = in.nextInt();
		for (int i = 0; i < t; i++) {
			n = in.nextInt();
			connect = new boolean[n + 1][n + 1];
			visit = new boolean[n + 1][n + 1];
			for (int node = 1 ; node <= n; node++) {
				m = in.nextInt();
				for (int j = 1; j <= m; j++) {
					connect[in.nextInt()][node] = true;
				}
			} 
			
			pathCount = 0;
			for (int n1 = 1; n1 <= n; n1++) {
				if (pathCount > 1) break;
				for (int n2 = 1; n2 <= n; n2++) {
					if (pathCount > 1) break; 
					pathCount = 0;
					if (n1 != n2) {
						dfs(n1, n2);
					}
				}
			}
			out.printf("Case #%d: %s", (i+1), (pathCount > 1 ? "Yes" : "No"));
			out.println();
		}
		out.flush();
	}
	private void dfs(int curNode, int goalNode) {
		if (curNode == goalNode) {
			pathCount++;
			return ;
		}
		if (pathCount > 1) return;
		
		for (int node = 1; node <= n; node++) {
			if (!visit[curNode][node] && connect[curNode][node]) {
				visit[curNode][node] = true;
				dfs(node, goalNode);
				visit[curNode][node] = false;
			}
		}
	}
}
