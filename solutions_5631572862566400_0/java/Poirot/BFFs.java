
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

/**
 * @author Poirot
 *
 */
public class BFFs {

	public static int get(int[] nums) {
		int N = nums.length - 1;
		HashSet<Integer> triple = new HashSet<>();
		HashMap<Integer, HashSet<Integer>> mv = new HashMap<>();
		for (int i = 1; i <= N; i++) {
			if (mv.containsKey(nums[i])) {
				mv.get(nums[i]).add(i);
			} else {
				HashSet<Integer> set = new HashSet<>();
				set.add(i);
				mv.put(nums[i], set);
			}
		}
		// System.out.println(mv);
		int res = 0;
		for (int i = 1; i <= N; i++) {
			int begin = i;
			int preIndex = begin;
			int curIndex = nums[preIndex];
			int tempMax = 2;
//			System.out.println(preIndex + " " + curIndex + " " + nums[curIndex]);
			HashSet<Integer> tempSet = new HashSet<>();
			tempSet.add(preIndex);
			tempSet.add(curIndex);
			while (!tempSet.contains(nums[curIndex])) {
				preIndex = curIndex;
				curIndex = nums[curIndex];
				tempSet.add(curIndex);
				tempMax++;
			}
			if (nums[curIndex] == begin) {
				res = Math.max(res, tempMax);
			} else if (nums[curIndex] == preIndex) {
				triple.addAll(tempSet);
//				System.out.println(preIndex + " " + curIndex + " " + nums[curIndex]);
				if (mv.get(curIndex).size() >= 2) {
					tempMax++;
				}
				res = Math.max(res, tempMax);
			}
//			if (tempMax == 4) {
//				System.out.println(begin);
//			} 
		}
		return Math.max(res, triple.size());
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int t = in.nextInt();
		for (int i = 1; i <= t; ++i) {
			int N = in.nextInt();
			int[] nums = new int[N + 1];
			for (int j = 1; j <= N; j++) {
				nums[j] = in.nextInt();
			}
			System.out.println("Case #" + i + ": " + get(nums));
		}
	}
}
