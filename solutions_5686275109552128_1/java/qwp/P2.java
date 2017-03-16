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

			Collections.sort(lst, Collections.reverseOrder());
			int res = solve(lst);
			System.out.println("Case #" + i + ": " + res);
		}
		in.close();
	}
	
	public static int solve(List<Integer> lst) {
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
}
