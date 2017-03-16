import java.util.*;

public class A{
	
	int[][] G;
	int N;
	boolean[] visited;
	
	public void run(){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		// System.out.println(T);
		for(int i=0; i<T; i++){
			N = sc.nextInt();
			G = new int[N][N];
			visited=new boolean[N];
			
			for(int j=0; j<N; j++){
				int M = sc.nextInt();
				for(int k=0; k<M; k++){
					int m = sc.nextInt()-1;
					G[j][m]=1;
				}
			}
			System.out.print("Case #"+(i+1)+": ");
			execute();
		}
		
		
	}
	
	public boolean dfs(int h){
		// printVisited();
		// System.out.println("observing node:"+h);
		// System.out.println("before visited: "+visited[h]);
		this.visited[h]=true;
		// System.out.println("after visited: "+visited[h]);
		// printVisited();
		for(int i=0; i<N; i++){
			if(G[h][i]==1){
					// System.out.println("Connected to node"+i);
				if(this.visited[i]==true){
					// System.out.println("Visited before");
					return true;
				}
				else{
					if(dfs(i)==true)
						return true;
				}
			}
		}
		return false;
	}
	
	public void clearVisited(){
		for(int i=0; i<N; i++){
			visited[i]=false;
		}
	}
	public void printVisited(){
		for(int i=0; i<N; i++){
			System.out.print(visited[i]+" ");
		}
		System.out.println();
	}
	public void execute(){
		for(int i=0; i<N; i++){
			clearVisited();
			if(dfs(i) == true){
				System.out.println("Yes");
				return;
			}
		}
		System.out.println("No");
	}
	
	public static void main(String[] args){
		A a = new A();
		a.run();
	}
}