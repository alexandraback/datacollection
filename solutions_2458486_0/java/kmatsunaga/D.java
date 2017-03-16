import java.util.*;
public class D {
	Scanner sc = new Scanner(System.in);
	final int MAXN = 200;
	final int MAXK = 200;
	int [] havekeys = new int[MAXK + 1];
	int [] history = new int[MAXN+1];
	int [] open_key = new int[MAXN + 1];
	int [] keynum_in_chests = new int[MAXN + 1];
	int [][] keys_in_chests = new int[MAXN + 1][1000];
	HashSet<Integer> closed = new HashSet<Integer>();
	int N = 0;
	
	boolean dfs(int depth, int used)
	{
		closed.add(used);
		//System.out.println(depth + " " + used);
		if(depth >= N) {
			return true;
		}
		for(int nxt = 1; nxt <= N; nxt++) {
			if(((1<<nxt) & used) != 0) continue; // すでに開けた
			if(havekeys[open_key[nxt]] <= 0) continue; // nxtを開ける鍵はない
			int nxtused = used + (1<<nxt);
			if(closed.contains(nxtused)) continue;
			havekeys[open_key[nxt]] --; // 鍵を使用した
			for(int i = 0; i < keynum_in_chests[nxt]; i++)
				havekeys[keys_in_chests[nxt][i]]++;
			history[depth] = nxt;
			//System.out.println(depth + ":" + nxt);
			boolean ret = dfs(depth+1, nxtused);
			if(ret) return true;
			for(int i = 0; i < keynum_in_chests[nxt]; i++)
				havekeys[keys_in_chests[nxt][i]]--;
			havekeys[open_key[nxt]] ++; // 鍵を使用した
		}
		return false;
	}
	boolean solve()
	{
		int K = sc.nextInt();
		N = sc.nextInt();
		havekeys = new int[MAXK + 1];
		open_key = new int[N + 1];
		closed = new HashSet<Integer>();
		for(int i = 0; i < K; i++) havekeys[sc.nextInt()] ++;
		for(int i = 1; i <= N; i++) {
			open_key[i] = sc.nextInt();
			keynum_in_chests[i] = sc.nextInt();
			for(int j = 0; j < keynum_in_chests[i]; j++){
				keys_in_chests[i][j] = sc.nextInt(); 
			}
		}
		//System.out.println(Arrays.toString(open_key));
		boolean ret = dfs(0, 0);
		return ret;
	}
	void doIt()
	{
		int T = sc.nextInt();
		for(int t = 1; t <= T; t++) {
			boolean state = solve();
			System.out.print("Case #" + t + ":");
			if(state == true) {
				for(int i = 0; i < N; i++) {
					System.out.print(" " + history[i]);
				}
				System.out.println();
			} else System.out.println(" "  + "IMPOSSIBLE");
		}
	}
	public static void main(String[] args) {
		new D().doIt();
	}

}
