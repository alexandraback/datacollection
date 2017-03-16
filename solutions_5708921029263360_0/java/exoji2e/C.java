import java.util.Scanner;
import java.util.ArrayList;
public class C {
	private static  class Choice {
		boolean[] c;
		int amount;
		public Choice(boolean[] b) {
			this.c = new boolean[b.length];
			amount = 0;
			for(int i = 0; i<b.length; i++) {
				this.c[i] = b[i];
				if(b[i])
					amount++;
			}
		}
	}
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int i = 1; i<=T; i++) {
			int j = sc.nextInt();
			int p = sc.nextInt();
			int s = sc.nextInt();
			int k = sc.nextInt();
			int[][] mj = new int[p][s];
			int[][] mp = new int[j][s];
			int[][] ms = new int[j][p];
			boolean[] chosen = new boolean[j*p*s];
			Choice ch = dfs(chosen,0,j,p,s,k,mj,mp,ms);
			
			System.out.println("Case #" + i + ": " + ch.amount);
			for(int a = 0; a<j*p*s; a++) {
				if(ch.c[a]) {
					int jj = a/(p*s);
					int pp = ((a - jj*(p*s))/s);
					int ss = (a - jj*p*s - pp*s);
					System.out.println((jj + 1) + " " + (pp+1) + " " + (ss+1));
				}
			}
		}
	}
	public static Choice dfs(boolean[] chosen, int ww, int j, int p, int s, int k, int[][] mj, int[][] mp, int[][] ms) {
		if(ww == chosen.length) return new Choice(chosen);
		int jj = ww/(p*s);
		int pp = (ww - jj*(p*s))/s;
		int ss = ww - jj*p*s - pp*s;
		int a = mj[pp][ss];
		int b = mp[jj][ss];
		int c = ms[jj][pp];
		if(a<k && b<k && c<k) {
			mj[pp][ss]++;
			mp[jj][ss]++;
			ms[jj][pp]++;
			chosen[ww] = true;
			Choice c1 = dfs(chosen,ww+1,j,p,s,k,mj,mp,ms);
			mj[pp][ss]--;
			mp[jj][ss]--;
			ms[jj][pp]--;
			chosen[ww] = false;
			Choice c2 = dfs(chosen,ww+1,j,p,s,k,mj,mp,ms);
			return c1.amount<c2.amount ? c2 : c1;
		}
		return dfs(chosen,ww+1,j,p,s,k,mj,mp,ms);
	}
}