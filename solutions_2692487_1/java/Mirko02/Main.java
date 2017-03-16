import java.util.Arrays;
import java.util.Scanner;


public class Main {

	private Scanner in;
	
	private long x;
	private int n;
	
	public static void main(String[] args) {
		Main main = new Main();
		main.doWork();
	}

	private void doWork() {
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			System.out.println("Case #" + (i + 1) + ": " + doCase());
		}
	}
	
	private long doCase() {
		x = in.nextLong();
		n = in.nextInt();
		
		int[] a = new int[n];
		
		long ans = n;

		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		if (x == 1)
			return ans;
		
		Arrays.sort(a);
		
		long fin = n;
		long ini = 0;
		for (int i = 0; i < n; i++) {
			fin--;
			
			while (x <= a[i]) {
				x *= 2;
				x--;
				ini++;
			}
			
			x += a[i];
			
			if (ini + fin < ans) {
				ans = ini + fin;
			}
		}
		
		return ans;
	}
	
	public Main() {
		in = new Scanner(System.in);
	}
}
