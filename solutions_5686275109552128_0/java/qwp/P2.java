import java.util.*;

public class P2 {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int num = Integer.parseInt(in.nextLine());
		for (int i = 1; i <= num; i++) {
			List<Integer> lst = new ArrayList<>();
			int n = Integer.parseInt(in.nextLine());
			String[] ss = in.nextLine().split(" ");
			for (int j = 0; j < n; j++)
				lst.add(Integer.parseInt(ss[j]));

//			System.out.println(lst);
			Collections.sort(lst, Collections.reverseOrder());
			int res = solve(lst);
//			int ans = Integer.parseInt(ss[n]);
			System.out.println("Case #" + i + ": " + res);
//			System.out.println("expected: " + ans);
//			if (res != ans)
//				throw new Exception();
//			System.out.println();
		}
		in.close();
	}
	
	public static int solve(List<Integer> lst) {
//		return solve(0, lst);
		int min = lst.get(0);
		for (int i = lst.get(0) - 1; i >= 2; i--) {
			int split = 0;
			for (int j = 0; j < lst.size() && lst.get(j) > i; j++) {
				split += (lst.get(j) - 1) / i;
			}
			if (min > i + split)
				min = i + split;
		}
		return min;
	}
	
//	private static int solve(int i, List<Integer> lst) {
//		int ans = i + lst.get(0);
//		if (lst.get(0) <= 3) {
//			return ans;
//		}
//		
//		int n = lst.remove(0);
//		if (n % 2 == 0) {
//			lst.add(n/2);
//			lst.add(n/2);
////			System.out.println(Collections.binarySearch(lst, n/2, Collections.reverseOrder()));
////			lst.add(Collections.binarySearch(lst, n/2, Collections.reverseOrder()) + 1, n/2);
////			System.out.println(Collections.binarySearch(lst, n/2, Collections.reverseOrder()));
////			lst.add(Collections.binarySearch(lst, n/2, Collections.reverseOrder()) + 1, n/2);
//		} else {
//			lst.add(3);
//			lst.add(n - 3);
////			System.out.println(Collections.binarySearch(lst, n/2, Collections.reverseOrder()));
////			lst.add(Collections.binarySearch(lst, n/2 + 1, Collections.reverseOrder()) + 1, n/2 + 1);
////			System.out.println(Collections.binarySearch(lst, n/2, Collections.reverseOrder()));
////			lst.add(Collections.binarySearch(lst, n/2, Collections.reverseOrder()) + 1, n/2);
//		}
//		Collections.sort(lst, Collections.reverseOrder());
//		return Math.min(ans,  solve(i + 1, lst));
//	}
}
