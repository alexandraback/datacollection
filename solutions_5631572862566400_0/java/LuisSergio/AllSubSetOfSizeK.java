import java.util.ArrayList;
import java.util.List;
import java.util.Set;

public class AllSubSetOfSizeK {

	public static void subset(int[] A, int k, int start, int currLen, boolean[] used, List<List<Integer>> sets) {

		if (currLen == k) {
			List<Integer> list = new ArrayList<>(k);
			for (int i = 0; i < A.length; i++) {
				if (used[i] == true) {
					list.add(A[i]);
				}
			}
			sets.add(list);
			return;
		}
		if (start == A.length) {
			return;
		}
		// For every index we have two options,
		// 1.. Either we select it, means put true in used[] and make currLen+1
		used[start] = true;
		subset(A, k, start + 1, currLen + 1, used, sets);
		// 2.. OR we dont select it, means put false in used[] and dont increase
		// currLen
		used[start] = false;
		subset(A, k, start + 1, currLen, used, sets);
	}



}