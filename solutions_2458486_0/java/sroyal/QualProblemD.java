import java.util.*;
public class QualProblemD {
	public static int[] memo;
	public static int[] next;
	public static int[] start;
	public static int[] need;
	public static ArrayList<Integer>[] g;
	public static int n;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			int k = br.nextInt();
			n = br.nextInt();
			start = new int[41];
			for(int i = 0;i<k;i++){
				start[br.nextInt()-1]++;
			}
			need = new int[n];
			g = new ArrayList[n];
			for(int i = 0;i<n;i++){
				need[i] = br.nextInt()-1;
				g[i] = new ArrayList<Integer>();
				int am = br.nextInt();
				for(int j = 0;j<am;j++){
					g[i].add(br.nextInt()-1);
				}
			}
			memo = new int[(1<<n)];
			next = new int[(1<<n)];
			Arrays.fill(memo, -1);
			int ans = go(0);
			if(ans == 0){
				System.out.println("Case #"+c+": IMPOSSIBLE");
			}
			else{
				System.out.print("Case #"+c+":");
				int cur = 0;
				while(Integer.bitCount(cur) < n){
					System.out.print(" "+(next[cur]+1));
					cur = cur|(1<<next[cur]);
				}
				System.out.println();
			}
		}
	}
	public static int go(int mask){
		if(Integer.bitCount(mask) == n){
			return 1;
		}
		if(memo[mask] != -1){
			return memo[mask];
		}
		int ans = 0;
		int[] have = new int[41];
		for(int i = 0;i<41;i++){
			have[i]+=start[i];
		}
		for(int i = 0;i<n;i++){
			if((mask & (1<<i)) > 0){
				have[need[i]]--;
				for(int j = 0;j<g[i].size();j++){
					have[g[i].get(j)]++;
				}
			}
		}
		for(int i = 0;i<n;i++){
			if(have[need[i]] > 0 && (mask & (1<<i)) == 0){
				int res = go(mask|(1<<i));
				if(res == 1){
					ans = 1;
					next[mask] = i;
					break;
				}
			}
		}
		return memo[mask] = ans;
	}
}
