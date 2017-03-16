import java.util.Scanner;


public class A {
	public static void main(String[] args) throws InterruptedException  {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int casenum = 1;

		Thread.sleep(1000);
		while (T-- > 0) {
			
			
			System.out.print("Case #" + casenum++ + ": " );
			String num = solve(sc);
		}
	}

	private static String solve(Scanner sc) {
		int N = sc.nextInt();
		int[] n = new int[N];
		int X = 0;
		int least = 1000000;
		
		for (int i = 0; i < n.length; i++) {
			n[i] = sc.nextInt();
			X +=n[i];
		}
		double lim = (double)2.0*X/N;
		
		String ans = "";
		for (int i = 0; i < n.length; i++) {
			if(n[i] >= lim) System.out.print("0.000000 ");
			else {
				double par = n[i] / (double)X;
				double left = 2.0 / N - par;
				//double left = 1 - (1.0 / N - par);
				//double r = ((1.000 / N) - n[i] / lim)*2;
				System.out.print(left*100 + " ");
			}
		}
		System.out.println();
		
return "";
	}
}
