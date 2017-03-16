import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.collect.Sets;

public class A {

	public static void main(String[] args) throws IOException {
		String fileName = "A-small-attempt0.in";
		// String fileName = "A-small.in";
		// String fileName = "A-large.in";

		PrintWriter out = new PrintWriter(fileName + "-out.txt");

		Scanner scan = new Scanner(new File(fileName));
		int n = scan.nextInt();
		for (int counter = 1; counter <= n; counter++) {
			String result = compute(scan);
			String s = String.format("Case #%d: %s", counter, result);
			out.println(s);
			System.out.println(s);
		}
		out.close();
	}

	private static String compute(Scanner scan) {
		Map<Integer, Set<Integer>> edge = Maps.newHashMap();
		
		int n = scan.nextInt(); // # classes
		
		for (int i = 1; i <= n; i++) {
			Set<Integer> set = Sets.newHashSet();  
			edge.put(i, set);
			int m = scan.nextInt(); // # of classes class i inherits from
			for (int j = 0; j < m; j++) {
				set.add(scan.nextInt());
			}
		}
		
		List<Integer> starts = Lists.newArrayList();
		
		// classes without parent
		for (int i = 1; i <= n; i++) {
			boolean start = true;
			for (int j = 1; j <= n; j++) {
				if (edge.get(j).contains(i)) {
					start = false;
					break;
				}
			}
			
			if (start) {
				starts.add(i);
			}
		}
		
		for (int s : starts) {
			Set<Integer> visited = Sets.newHashSet();
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(s);
			while (!q.isEmpty()) {
				int v = q.remove();
				if (visited.contains(v)) {
					return "Yes";
				} else {
					visited.add(v);
				}
				q.addAll(edge.get(v));
			}
		}
		
		return "No";
	}
}
