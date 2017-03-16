import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    private static final int INF = 1<<20;
    int A, N;
    int[] ms;
    int[][] dp;

    int calc(){
	PriorityQueue<E> q = new PriorityQueue<E>();
	q.offer(new E(0, 0, A));
	dp[0][0] = A;
	while(!q.isEmpty()){
	    E e = q.poll();
	    int p = e.pos, c = e.cost, v = e.vol;
	    if(dp[p][c] > v)continue;
	    if(p == N)return c;
	    if(v > ms[p]){
		if(dp[p+1][c] < v+ms[p]){
		    dp[p+1][c] = v+ms[p];
		    q.offer(new E(p+1, c, v+ms[p]));
		}
	    }else{
		if(v+v-1 > ms[p]){
		    if(dp[p+1][c+1] < v+v-1+ms[p]){
			dp[p+1][c+1] = v+v-1+ms[p];
			q.offer(new E(p+1,c+1, v+v-1+ms[p]));
		    }
		}
		if(dp[p+1][c+1] < v){
		    dp[p+1][c+1] = v;
		    q.offer(new E(p+1, c+1, v));
		}
		if(c+1 <= N && dp[p][c+1] < v+v-1){
		    dp[p][c+1] = v+v-1;
		    q.offer(new E(p, c+1, v+v-1));
		}
	    }
	}
	return dp[N][0];
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available

	int T = sc.nextInt();
	for(int o = 1; o <= T; o++){
	    A = sc.nextInt();
	    N = sc.nextInt();
	    System.out.printf("Case #%d: ", o);
	    ms = new int[N];
	    for(int i = 0; i < N; i++)ms[i] = sc.nextInt();
	    Arrays.sort(ms);
	    dp = new int[N+1][N+1];
	    for(int i = 0; i < dp.length; i++)Arrays.fill(dp[i], -1);
	    System.out.println(calc());
	}
    }
}

class E implements Comparable<E>{
    int cost;
    int pos;
    int vol;
    E(int a, int b, int c){
	pos = a; cost = b; vol = c;
    }
    public int compareTo(E e){
	if(cost != e.cost)return this.cost - e.cost;
	if(pos != e.pos)return e.pos - this.pos;
	return e.vol - this.vol;
    }
}
