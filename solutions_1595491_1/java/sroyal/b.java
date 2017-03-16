import java.util.*;
import java.io.*;
public class b{
	public static int[] nums;
	public static int[][] memo;
	public static int p;
	public static void main(String[] args) throws IOException{
		Scanner br = new Scanner(new File("b.in"));
		PrintWriter out = new PrintWriter(new File("b.out"));
		int cases = br.nextInt();
		for(int c = 0;c<cases;c++){
			int n = br.nextInt();
			int s = br.nextInt();
			p = br.nextInt();
			nums = new int[n];
			for(int i = 0;i<n;i++){
				nums[i] = br.nextInt();
			}
			memo = new int[n][s+1];
			for(int i = 0;i<n;i++){
				Arrays.fill(memo[i], -1);
			}
			out.println("Case #"+(c+1)+": "+go(0, s));
		}
		out.close();
	}
	public static int go(int pos, int left){
		if(pos == nums.length){
			return 0;
		}
		if(left < 0){
			return -100000;
		}
		if(memo[pos][left] != -1){
			return memo[pos][left];
		}
		int best = 0;
		for(int i = 0;i<11;i++){
			for(int j = i;j<11;j++){
				int k = (nums[pos]-i)-j;
				if(k < j){
					continue;
				}
				if(k-i > 2){
					continue;
				}
				if(k-i == 2 && left > 0){
					best = Math.max(best, go(pos+1, left-1)+ (k >= p ? 1 : 0));
				}
				else if(k-i < 2){
					best = Math.max(best, go(pos+1, left)+ (k >= p ? 1 : 0));
				}
			}
		}
		return memo[pos][left] = best;
		
	}
}
