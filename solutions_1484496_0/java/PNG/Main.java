import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Collections;
import java.util.Scanner;
import java.util.Set;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.Sets;

// using google-guava from http://code.google.com/p/guava-libraries/
public class Main {

	public static void main(String[] args) throws Exception {
		Scanner s = new Scanner(new File("input"));
		BufferedWriter w = new BufferedWriter(new FileWriter(new File("output")));
		int cases = s.nextInt();
		s.nextLine();

		for (int i = 1; i <= cases; i++) {
			w.write("Case #");
			w.write(String.valueOf(i));
			w.write(": ");

			solve(s, w);

			w.write("\n");
		}
		w.close();
	}

	private static void solve(Scanner s, BufferedWriter w) throws Exception {
		int N = s.nextInt();
		Set<Integer> nums = Sets.newHashSet();
		for (int i = 0; i < N; i++) {
			nums.add(s.nextInt());
		}

		HashMultimap<Integer, Set<Integer>> map = HashMultimap.create();
		Set<Set<Integer>> permutations = Sets.powerSet(nums);
		for (Set<Integer> set : permutations) {
			if (set.isEmpty()) continue;
			int sum = 0;
			for (Integer integer : set) {
				sum += integer;
			}
			Set<Set<Integer>> existing = map.get(sum);
			if (existing.isEmpty()) {
				map.put(sum, set);
			} else {
				for (Set<Integer> set2 : existing) {
					if (Collections.disjoint(set, set2)) {
						w.write('\n');
						for (Integer integer : set) {
							w.write(String.valueOf(integer));
							w.write(' ');
						}
						w.write('\n');
						for (Integer integer : set2) {
							w.write(String.valueOf(integer));
							w.write(' ');
						}
						return;
					}
				}
				map.put(sum, set);
			}
		}


	}

}
