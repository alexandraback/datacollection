package r2;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class A {

	private static boolean bfs(ArrayList<ArrayList<Integer>> graph, int source,
			int sink) {
		Queue<Integer> q = new LinkedList<Integer>();
		q.add(source);
		int cnt = 0;
		while (!q.isEmpty()) {
			int curr = q.poll();
			if (curr == sink)
				cnt++;
			if (cnt > 1)
				return true;
			for (int i = 0; i < graph.get(curr).size(); i++)
				q.add(graph.get(curr).get(i));

		}
		return false;
	}

	public static void main(String[] args) throws Exception {
		Scanner myScanner = new Scanner(System.in);
		int t = myScanner.nextInt();
		int cnt = 1;
		label: while (t-- > 0) {
			int n = myScanner.nextInt();
			ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>(
					n + 10);
			ArrayList<Integer> sources = new ArrayList<Integer>();
			ArrayList<Integer> sinks = new ArrayList<Integer>();

			boolean[] notSource = new boolean[n + 1];
			boolean[] notSink = new boolean[n + 1];

			for (int i = 0; i <= n; i++)
				graph.add(new ArrayList<Integer>());
			//
			for (int i = 1; i <= n; i++) {
				int m = myScanner.nextInt(), tmp;
				for (int j = 0; j < m; j++) {
					notSink[i] = true;
					graph.get(i).add(tmp = myScanner.nextInt());
					notSource[tmp] = true;
				}
			}
			//

			for (int i = 1; i < notSource.length; i++)
				if (!notSource[i])
					sources.add(i);

			for (int i = 1; i < notSink.length; i++)
				if (!notSink[i])
					sinks.add(i);
			if(sinks.size()==0||sources.size()==0)
				throw new Exception();
			System.out.print("Case #" + cnt++ + ": ");
			for (int source : sources)
				for (int sink : sinks)
					if (bfs(graph, source, sink)) {
						System.out.println("Yes");
						continue label;
					}
			System.out.println("No");
		}
	}
}
