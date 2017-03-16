import java.io.*;
import java.util.*;
public class BFFs {
	static PrintWriter w; static final String url = "C-large.in";
	
	static int[] next; static int N;
	static boolean[] loop;
	public static void main(String...thegame)throws Exception{
		BufferedReader br = new BufferedReader(new FileReader(new File(url)));
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		w = new PrintWriter("bffs.txt", "UTF-8");
		int T = Integer.parseInt(br.readLine());
		for(int t = 0; t < T; t++){
			N = Integer.parseInt(br.readLine());
			next = new int[N]; loop = new boolean[N];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int i = 0; i < N; i++){
				next[i] = Integer.parseInt(st.nextToken())-1;
			}
			String out = String.format("Case #%d: %d",t+1,process());
			w.println(out);
			//System.out.println(out);
		}
		w.close();
	}
	static ArrayList<Integer>[] prev;
	static boolean[] check;
	static int[] loops;
	static int loopcount;
	public static int process(){
		int disjres = 0;
		prev = new ArrayList[N];
		for(int i = 0; i < N; i++) prev[i] = new ArrayList<>();
		loopcount = 0;
		for(int i = 0; i < N; i++){
			prev[next[i]].add(i);
			if(next[next[i]] == i) {
				loop[i] = true;
				loopcount++;
			}
		}
		check = new boolean[N];
		for(int i = 0; i < N; i++){
			if(loop[i]){
				disjres += bfs(i);
			}
		}
		loops = new int[N];
		int maxloop = 0;
		for(int i = 0; i < N; i++){
			if(!check[i]){
				fs(i);
			}
		}
		for(int k: loops){
			maxloop = Math.max(maxloop, k);
		}
		return Math.max(maxloop, disjres);
	}
	public static void fs(int u){
		int[] dist = new int[N];
		dist[u] = 1; check[u] = true;
		while(true){
			int v = next[u];
			if(check[v] && dist[v] > 0){
				loops[v] = dist[u] - dist[v] + 1;
				return;
			}
			else if(check[v]) return;
			check[v] = true;
			dist[v] = dist[u]+1;
			u = v;
		}
	}
	public static int bfs(int u){
		int rec = next[u];
		int res = 1;
		ArrayList<Integer> q = new ArrayList<>();
		q.add(u);
		int[] dist = new int[N]; dist[u] = 1;
		while(!q.isEmpty()){
			u = q.remove(0);
			for(int v: prev[u]){
				if(v == rec) continue;
				q.add(v);
				dist[v] = dist[u]+1;
			}
			check[u] = true;
		}
		for(int k: dist) res = Math.max(res, k);
		return res;
	}
}
