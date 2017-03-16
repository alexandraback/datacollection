import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Set;


public class C {
	
	private static final String NAME = "C-small";

	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader("in/" + NAME + ".in"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("out/" + NAME + ".out"));
		try {
			int t = Integer.parseInt(reader.readLine());
			for (int i = 0; i < t; ++i) {
				String[] v = reader.readLine().split(" ");
				int n = Integer.parseInt(v[0]);
				final int[] nums = new int[n];
				for (int j = 0; j < n; ++j) {
					nums[j] = Integer.parseInt(v[j + 1]);
				}
				Map<Integer, Set<Integer>> res = new HashMap<Integer, Set<Integer>>();
				res.put(0, new HashSet<Integer>() {
					{
						add(0);
					}
				});
				Set<Integer> result1 = null;
				Set<Integer> result2 = null;
				loop:for (int j = 0; j < n; ++j) {
					Set<Res> toAdd = new HashSet<Res>();
					for (Entry<Integer, Set<Integer>> re : res.entrySet()) {
						Res newRe = new Res(re, nums[j]);
						if (res.containsKey(newRe.sum)) {
							result1 = newRe.steps;
							result2 = res.get(newRe.sum);
							break loop;
						}
						toAdd.add(newRe);
					}
					for (Res r : toAdd) {
						res.put(r.sum, r.steps);
					}
				}
				
				writer.write("Case #" + (i + 1) + ":");
				writer.newLine();
				if (result1 == null) {
					writer.write("Impossible");
				} else {
					Set<Integer> intersection = new HashSet<Integer>(result1);
					intersection.retainAll(result2);
					result1.removeAll(intersection);
					result2.removeAll(intersection);
					boolean first = true;
					for (Integer r : result1) {
						if (first) {
							first = false;
							writer.write("" + r);
						} else {
							writer.write(" " + r);
						}
					}
					writer.newLine();
					first = true;
					for (Integer r : result2) {
						if (first) {
							first = false;
							writer.write("" + r);
						} else {
							writer.write(" " + r);
						}
					}
				}
				
				writer.newLine();
			}
		} finally {
			reader.close();
			writer.close();
		}
	}
	
	static class Res {
		public Set<Integer> steps = new HashSet<Integer>();
		public int sum = 0;
		
		public Res(int elem) {
			steps.add(elem);
			sum = elem;
		}
		
		public Res(Entry<Integer, Set<Integer>> old, int elem) {
			steps.addAll(old.getValue());
			steps.add(elem);
			sum = old.getKey() + elem;
		}
	}

}
