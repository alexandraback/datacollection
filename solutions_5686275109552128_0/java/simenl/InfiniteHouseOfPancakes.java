import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;


public class InfiniteHouseOfPancakes {
	
	static String filename = "B-small-attempt1";
	static Scanner sc;
	
	public static void main(String[] args) throws FileNotFoundException{
		System.setIn(new FileInputStream(filename + ".in"));
		System.setOut(new PrintStream(filename + ".out"));
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int casee = 1 ; casee<=t ; casee++){
			System.out.print("Case #" + casee + ": ");
			int d = sc.nextInt();
			System.out.println(solve(d));
		}
	}
	public static int solve(int d){
		int[] ar = new int[d];
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < d; i++){
			ar[i] = sc.nextInt();
		}
		Arrays.sort(ar);
		
		int max = ar[d-1];
		for(int i = 1; i <= max; i++){
			int cnt = 0;
			for(int j = d-1; j >= 0 ; j--){
				int div = (ar[j]-1)/i;
				if(div < 1){
					break;
				}
				cnt += div;
			}
			ans = Math.min(ans, cnt+i);
		}
		

		return ans;
	}
}
