import java.io.*;
import java.util.*;
import java.math.*;

public class C {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/C-small.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			int[] bff = new int[n];
			for (int j = 0; j < n; j++) {
				bff[j] = sc.nextInt()-1;
			}
			ArrayList<ArrayList<Integer>> cycles = new ArrayList<ArrayList<Integer>>();
			ArrayList<ArrayList<Integer>> hops = new ArrayList<ArrayList<Integer>>();
			HashMap<Integer,ArrayList<ArrayList<Integer>>> hopSet = new HashMap<Integer,ArrayList<ArrayList<Integer>>>();
			for (int j = 0; j < n; j++) {
				ArrayList<Integer> pos = new ArrayList<Integer>();
				HashSet<Integer> ch = new HashSet<Integer>();
				pos.add(j);
				ch.add(j);
				int k = bff[j];
				while (!ch.contains(k)) {
					pos.add(k);
					ch.add(k);
					k = bff[k];
				}
				if (k==pos.get(0))
					cycles.add(pos);
				if (k==pos.get(pos.size()-2)) {
					hops.add(pos);
					if (!hopSet.containsKey(k)) {
						hopSet.put(k, new ArrayList<ArrayList<Integer>>());
					}
					if (!hopSet.containsKey(pos.get(pos.size()-1))) {
						hopSet.put(pos.get(pos.size()-1), new ArrayList<ArrayList<Integer>>());
					}
					hopSet.get(k).add(pos);
				}
			}
			
			int longest = 0;
			for (ArrayList<Integer> cy : cycles) {
				if (cy.size() > longest) {
					longest = cy.size();
				}
			}
			int[] hoplen = new int[n];
			for (ArrayList<Integer> h : hops) {
				int end = h.get(h.size()-1);
				if (h.size() > hoplen[end]) {
					hoplen[end] = h.size();
				}
				
			}
			int thehop = 0;
			for (int j = 0; j < n; j++) {
				if (hoplen[j] > 0)
					thehop += hoplen[j]-1;
			}
			if (thehop > longest)
				longest = thehop;
			
			output += "Case #" + i + ": " + longest + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/C-small.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}