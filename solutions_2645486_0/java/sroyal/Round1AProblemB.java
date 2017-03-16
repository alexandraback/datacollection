import java.util.*;
public class Round1AProblemB {
	public static int n, maxe, regain;
	public static int[] stuff;
	public static int[][] memo;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			maxe = br.nextInt();
			regain = br.nextInt();
			n = br.nextInt();
			stuff = new int[n];
			for(int i = 0;i<n;i++){
				stuff[i] = br.nextInt();
			}
			memo = new int[n][maxe+1];
			for(int i = 0;i<n;i++){
				Arrays.fill(memo[i], -1);
			}
			System.out.println("Case #"+c+": "+go(0, maxe));
		}
	}
	public static int go(int pos, int energy){
		if(pos == n){
			return 0;
		}
		if(memo[pos][energy] != -1){
			return memo[pos][energy];
		}
		int best = 0;
		for(int i = 0;i<=energy;i++){
			best = Math.max(best, go(pos+1, Math.min(energy-i+regain, maxe))+stuff[pos]*i);
		}
		return memo[pos][energy] = best;
	}
}
