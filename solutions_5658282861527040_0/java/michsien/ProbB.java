import java.util.Scanner;


public class ProbB {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int t = scan.nextInt();
		
		for (int i = 1; i <= t; i++) {
			solve(i, scan);
		}
		
		scan.close();

	}
	

	
	public static void solve(int number, Scanner sc) {
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		
		int result = 0;
		
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				int w = i & j;
				for (int x = 0; x < k; x++) {
					if (x == w) {
						result++;
						break;
					}
				}
			}
		}
		
		System.out.println("Case #" + number + ": " + result);
	}
}