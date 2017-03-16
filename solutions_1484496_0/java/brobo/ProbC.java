import java.io.*;
import java.util.*;

public class ProbC {
	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new File("input/C-small-attempt0.in"));
		PrintWriter output = new PrintWriter(new File("output/probCres.out"));
		int lines = input.nextInt();
		input.nextLine();
		tests: for (int cline = 0; cline < lines; cline++) {
			output.println("Case #" + (cline+1) + ": ");
			List<List<Integer>> res = new ArrayList<List<Integer>>();
			List<Integer> sums = new ArrayList<Integer>();
			int n = input.nextInt();
			int[] nums = new int[n];
			for (int i=0; i<n; i++) {
				nums[i] = input.nextInt();
			}
			for (int i=0; i<Math.pow(2,n); i++) {
				List<Integer> cur = new ArrayList<Integer>();
				for (int j=0; j<n; j++) {
					if ((i >> j & 1) == 1) {
						cur.add(nums[j]);
					}
				}
				res.add(cur);
				int sum = 0;
				for (int x=0; x<cur.size(); x++) {
					sum += cur.get(x);
				}
				System.out.println(cur.toString() + " " + sum);
				if (sums.contains(sum)) {
					//You found a match! :D
					int index = sums.indexOf(sum);
					for (int x=0; x<res.get(index).size(); x++) {
						output.print(res.get(index).get(x) + " ");
					}
					output.println();
					for (int x=0; x<cur.size(); x++) {
						output.print(cur.get(x) + " ");
					}
					output.println();
					continue tests;
				} else {
					sums.add(sum);
				}
			}
			output.println("Impossible");
		}
		output.close();
	}
}