import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class B {
	public static void main(String[] args) throws InterruptedException  {
		Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		int casenum = 1;

		Thread.sleep(1000);
		
		while (T-- > 0) {
			System.out.println("Case #" + casenum++ + ": ");
			if(!solve(sc)) System.out.println("Impossible");
			
			
		}
	}

	private static boolean solve(Scanner sc) {
		int N = sc.nextInt();
		int[] n = new int[N];
		int X = 0;
		int least = 1000000;
		
		for (int i = 0; i < n.length; i++) {
			n[i] = sc.nextInt();
			X +=n[i];
			
		}
		
		HashMap<Integer, Integer> comb = new HashMap<Integer, Integer>();
		
		for (Integer i = 0; i < 1<<N; i++) {
			//System.out.println(i);
			int num = 0;
			for (int j = 0; j < N; j++) {
				num += ((i & (1<<j))>>j)*n[j];
			}
			//System.out.println("Sum for " + i + " is " + num);
			if(comb.containsKey(num)){
				//System.out.println("Found it for " + Integer.toBinaryString(i) + " and " + Integer.toBinaryString(comb.get(num)) + " sum is " + num);
				for (int j = 0; j < N; j++) {
					if((i&(1<<j)) != 0) System.out.print( n[j] + " ");
				}
				System.out.println("");
				int i2 = comb.get(num);
				for (int j = 0; j < N; j++) {
					if((i2&(1<<j)) != 0) System.out.print( n[j] + " ");
				}
				System.out.println("");
				return true;
			} else {
				comb.put(num, i);
			}
		}
		return false;
	}
}
