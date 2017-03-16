import java.util.*;

public class c2 {

	public static int n;
	public static int[] bffs;
	public static int max;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int t = in.nextInt();

		for(int caseN = 1; caseN <= t; caseN++) {
			n = in.nextInt();
			bffs = new int[n];
			for(int i = 0; i < n; i++)
				bffs[i] = in.nextInt() - 1;
			max = 0;
			go(new int[n], new boolean[n], 0);
			//go(new int[]{0, 6, 8, 2, 9, 3, 0, 0, 0, 0}, new boolean[]{true, false, true, true, false, false, true, false, true, true}, 7);
			System.out.println("Case #" + caseN + ": " + max);			
		}

	}

	public static void go(int[] arr, boolean[] used, int pos) {
		//System.out.println(Arrays.toString(arr));
		boolean good = true;
		for(int i = 0; i < pos; i++) {
			int prev = (i + pos - 1) % (pos);
			int next = (i + 1) % (pos);
			//System.out.println(prev + " " + next);
			if(bffs[arr[i]] != arr[prev] && bffs[arr[i]] != arr[next]) {
				good = false;
				break;
			}
		}
		if(good)
			max = Math.max(max, pos);

		if(pos == n) {
			good = true;
			for(int i = 0; i < pos; i++) {
				int prev = (i + pos - 1) % (pos);
				int next = (i + 1) % (pos);
				//System.out.println(prev + " " + next);
				if(bffs[arr[i]] != arr[prev] && bffs[arr[i]] != arr[next]) {
					good = false;
					break;
				}
			}
if(good)
			max = Math.max(max, pos);
			return;
		}

		for(int next = 0; next < n; next++) {
			if(used[next]) continue;
			used[next] = true;
			arr[pos] = next;
			go(arr, used, pos + 1);
			used[next] = false;
		}
	}

}