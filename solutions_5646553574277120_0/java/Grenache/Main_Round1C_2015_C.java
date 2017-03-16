import java.util.HashSet;
import java.util.Scanner;


public class Main_Round1C_2015_C {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int t = sc.nextInt();
		for (int casei = 1; casei <= t; casei++) {
			int c = sc.nextInt();
			int d = sc.nextInt();
			int v = sc.nextInt();
			
			int[] coins = new int[d];
			for (int i = 0; i < d; i++) {
				coins[i] = sc.nextInt();
			}

			HashSet<Integer> hs = new HashSet<Integer>();
			hs.add(0);

			for (int e : coins) {
				addHashSet(hs, e, c);
			}

			int count = 0;
			for (int i = 1; i <= v; i++) {
				if(!hs.contains(i)) {
					addHashSet(hs, i, c);
					count++;
				}
			}
			
			System.out.printf("Case #%d: %d\n", casei, count);
		}

		sc.close();
	}
	
	private static void addHashSet(HashSet<Integer> hs, int c, int n) {
		for (int i = 0; i < n; i++) {
			Integer[] tmp = new Integer[0];
			tmp = hs.toArray(tmp);
			for (int e : tmp) {
				hs.add(e + c);
			}
		}
		
		return;
	}
}
