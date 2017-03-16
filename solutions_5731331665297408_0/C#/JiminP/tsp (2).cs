using System;

public class BTS {
	private int N;
	private string[] zip;
	private bool[,] connected;
	public BTS(int N, int M) {
		this.N = N;
		this.zip = new string[N];
		this.connected = new bool[N,N];
		for(int i=0; i<N; i++){
			this.zip[i] = Console.ReadLine();
			for(int j=0; j<N; j++) this.connected[i, j] = this.connected[j, i] = false;
		}
		for(int i=0; i<M; i++){
			string[] line = Console.ReadLine().Split();
			int x = int.Parse(line[0]),
				y = int.Parse(line[1]);
			x--; y--;
			this.connected[x, y] = this.connected[y, x] = true;
		}
	}
	private int getSmallest() {
		int ret = 0;
		for(int i=1; i<this.N; i++){
			if(String.Compare(this.zip[i], this.zip[ret])<0){
				ret = i;
			}
		}
		return ret;
	}
	private bool visited_all(int[] visited){
		for(int i=0; i<this.N; i++) if(visited[i] == 0) return false;
		return true;
	}
	private bool isReachable(int[] visited, int i){
		int[] queue = new int[this.N];
		bool[] _visited = new bool[this.N];
		for(int k=0; k<this.N; k++){
			queue[k] = -1;
			_visited[k] = false;
		}
		int qb = 0, qe = 1;
		queue[qb] = i;
		while(qb != qe){
			int nxt = queue[qb++];
			if(qb >= this.N) qb = 0;
			if(visited[nxt] == 1) return true;
			_visited[nxt] = true;
			for(int j=0; j<this.N; j++){
				if(_visited[j] || !this.connected[nxt, j] || visited[j] == 2) continue;
				if(visited[j] == 1) return true;
				queue[qe++] = j;
				if(qe >= this.N) qe = 0;
			}
		}
		return false;
	}
	private int[] getNext(int[] visited, int[] chain, int ci){
		int mci = -1, mi = -1;
		bool reachable = true, _reach;
		for(int i=ci; i>=0; i--){
			int c = chain[i];
			if(i > 0) visited[c] = 2;
			for(int j=0; j<this.N; j++){
				if(visited[j] != 0 || !this.connected[c, j]) continue;
				_reach = this.isReachable(visited, j);
				if(_reach && !reachable) continue;
				if((mi == -1) || (reachable && !_reach) || (String.Compare(this.zip[j], this.zip[mi]) < 0)){
					mci = i;
					mi = j;
					reachable = _reach;
				}
			}
			if(!reachable) break;
		}
		for(int i=0; i<=ci; i++) visited[chain[i]] = 1;
		return new int[]{mci, mi};
	}
	public string solve() {
		if(this.N == 1) return this.zip[0];
		int[] visited = new int[this.N];
		int[] chain = new int[this.N+1];
		for(int i=0; i<this.N; i++) visited[i] = 0;
		for(int i=0; i<=this.N; i++) chain[i] = -1;
		int ci = 0;
		int sm = getSmallest();
		chain[ci] = sm; visited[sm] = 1;
		string res = this.zip[sm];
		while(!visited_all(visited)){
			int[] next_visit = getNext(visited, chain, ci);
			while(ci > next_visit[0]){
				visited[chain[ci]] = 2; ci--;
			}
			chain[++ci] = next_visit[1];
			visited[next_visit[1]] = 1;
			res += this.zip[next_visit[1]];
		}
		return res;
	}
	public static void Main(string[] args) {
		int T = int.Parse(Console.ReadLine());
		for(int i=1; i<=T; i++){
			string[] line = Console.ReadLine().Split();
			BTS solver = new BTS(int.Parse(line[0]), int.Parse(line[1]));
			Console.WriteLine("Case #{0}: {1}", i, solver.solve());
		}
	}
}
