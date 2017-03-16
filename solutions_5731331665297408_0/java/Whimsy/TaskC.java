import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class TaskC {
	Scanner in = new Scanner(System.in);
//	PrintStream out = System.out;
	PrintWriter out = null;
	Graph g;
	ArrayList<String> arr;
	String ans;

	
	public TaskC() {
		try {
//			in = new Scanner(new File("c.in"));
			in = new Scanner(new File("C-small-attempt0.in"));
			out = new PrintWriter("C.out");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	public static void main(String[] args) {
		new TaskC().solve();
	}
	private void solve() {
		int testCase = in.nextInt();
		for (int i = 0;i<testCase;++i){
			work(i+1);
		}
		out.close();
	}
	private void work(int test) {
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		g = new Graph(n);
		arr = new ArrayList<String>();
		for (int i = 0;i<n;++i){
			arr.add(in.next());
		}
		
		for (int i = 0;i<m;++i){
			int u = in.nextInt();
			int v = in.nextInt();
			g.addEdge(u-1, v-1);
		}
		ans = "";
		for (int i = 0;i<n;++i){
			ans += "99999";
		}
		
		boolean [] bo = new boolean[n];
		
		int [] stack = new int[n];
		int sp = 0;
		for (int i = 0;i<n;++i){
			bo[i] = true;
			stack[sp++] = i;
			dfs(arr.get(i),1,bo,stack,sp);
			--sp;
			bo[i] = false;
		}
		
		
		
		out.printf("Case #%d: ", test);
		out.printf(ans + "\n");
	}
	private void dfs(String cur, int cnt,boolean [] bo,int [] stack, int sp) {
		
		if (cnt == g.V()){
			if (cur.compareTo(ans)<0){
				ans = cur;
			}
			return;
		}
		
		if (cur.compareTo(ans.substring(0,cnt*5)) >0 ) {
			return;
		}
		for (int k = sp;k>=1;--k){
			int [] tmp = new int[g.V()];
			for (int i = 0;i<k;++i){
				tmp[i] = stack[i];
			}
			int u = stack[k-1];
			for (Integer e : g.adj(u)){
				if (!bo[e]){
					bo[e] = true;
					tmp[k] = e;
					dfs(cur + arr.get(e), cnt+1, bo, tmp, k+1 );
					bo[e] = false;
				}
			}
		}
	}
}
