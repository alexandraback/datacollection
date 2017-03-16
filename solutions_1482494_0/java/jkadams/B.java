import java.util.*;
public class B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		CASE: for (int ca = 1 ;ca <= T; ca++){
			int n = s.nextInt();
			int[][] arr = new int[n][2];
			for (int i = 0; i < n; i++) {
				arr[i][0] = s.nextInt();
				arr[i][1] = s.nextInt();
			}
			Arrays.sort(arr, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			int stars = 0;
			boolean[] used = new boolean[n], used2 = new boolean[n];
			int ans = 0;
			for (int L = 0; L < n; L++) {
				while (arr[L][1] > stars) {
					boolean found = false;
					for (int R = n-1; R >= 0 && !found; R--) {
						if (arr[R][0] <= stars && !used2[R] && !used[R]) {
							used[R] = true;
							ans++;
							stars++;
							found = true;
//	System.out.println("*1: "+R+"/"+stars);
						}
					}
					if (!found) {
						System.out.printf("Case #%d: Too Bad\n",ca);
						continue CASE;
					}
				}
				if (used[L]) stars++;
				else stars += 2;
				used2[L] = true;
//	System.out.println("*2: "+L+"/"+stars);
				ans++;
			}
			System.out.printf("Case #%d: %d\n",ca,ans);
		}
	}
}
