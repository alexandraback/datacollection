import java.util.Scanner;


public class B {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) System.out.printf("Case #%d: %d\n", i + 1, exec());
	}
	
	public static int exec() {
		int n = sc.nextInt();
		int s = sc.nextInt();
		int p = sc.nextInt();
		int[] t = new int[n];
		for (int i = 0; i < n; i++) {
			t[i] = sc.nextInt();
		}
		
		int definitelyPossible = Math.max(0, p * 3 - 2);
		int onlyForSpecial = Math.max(0, definitelyPossible - 2);
		
		int count = 0;
		int left = s;
		for (int i = 0; i < n; i++) {
			if (t[i] == 0) count += p == 0 ? 1 : 0;
			else if (t[i] == 1) count += p <= 1 ? 1 : 0;
			else if (t[i] == 2 && p < 2) count++;
			else if (t[i] == 2 && p > 2) ;
			else if (t[i] == 2 && left > 0) {
				left--;
				count++;
			}
			else if (t[i] == 3 && p < 2) count++;
			else if (t[i] == 3 && p > 2) ;
			else if (t[i] == 3 && left > 0) {
				left--;
				count++;
			}
			else if (t[i] >= definitelyPossible) count++;
			else if (t[i] >= onlyForSpecial && left > 0) {
				left--;
				count++;
			}
		}
		
		return count;
	}
}
