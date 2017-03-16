package Runde2;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.text.DecimalFormat;
import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class A {
public static void main(String[] args) throws Exception {
		
		BufferedReader f = new BufferedReader(new FileReader("A.txt"));
		PrintStream out = new PrintStream(new File("output.txt"));
		
		// number of test cases
		int t = Integer.parseInt(f.readLine());
		
		// handle every testcase
		for (int i = 1; i <= t; i++) {
			int n = Integer.parseInt(f.readLine());
			LinkedList[] adj = new LinkedList[n];
			for (int j = 0; j < n; j++) {
				adj[j] = new LinkedList<Integer>();
				String[] st = f.readLine().split(" ");
				int m = Integer.parseInt(st[0]);
				for (int k = 1; k <= m; k++) {
					adj[j].add(Integer.parseInt(st[k]));
				}
			}
			out.println("Case #" + i + ": " + solve(adj) );
		}
	}

private static String solve(LinkedList[] adj) {
	for (int i = 1; i < adj.length+1; i++) {
		if (solve2(i,adj, new boolean[adj.length]))	return "Yes";
	}
	return "No";
}

private static boolean solve2(int i, LinkedList[] adj, boolean[] vis) {
	Iterator it  = adj[i-1].iterator();
	while (it.hasNext()){
		int j = (Integer) it.next();
		if(vis[j-1])
			return true;
		else {
			vis[j-1] = true;
			if( solve2(j,adj,vis)) return true;
		}
	}
	return false;
}


}
