import java.util.*;

public class Main {
	static int[] M;
	static int[][] adj;
	static int[][] fils;
	static boolean[] vu;
	
	static void dfs(int N, int i, int rac){
		for (int j = 1; j<N+1 ;j++){
			if (adj[i][j]==1){
				fils[rac][j]=1;
				dfs(N, j, rac);
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		
		for (int cas = 1 ; cas<=T; cas++){
			int N = in.nextInt();
			M=new int[N+1];
			adj = new int[N+1][N+1];
			fils = new int[N+1][N+1];
			vu = new boolean[N+1];			
			
			for (int i = 0; i<N; i++){
				M[i+1]=in.nextInt();
				for (int j = 0; j<M[i+1]; j++){
					int k = in.nextInt();
					adj[i+1][k]=1;
				}
			}
			
			for (int i = 1; i<=N; i++) {
				dfs(N, i, i);
				fils[i][i]=1;
			}
			
			boolean result = false;
			
			for (int rac = 1; rac<=N; rac++){
				for (int i = 1; i<=N; i++){
					for (int j = 1; j<i; j++){
						if (adj[rac][i]==1 && adj[rac][j]==1){
							for (int k=1; k<=N; k++){
								if (fils[i][k]==1 && fils[j][k]==1) result = true;
							}
						}
					}
				}
			}
			
			if (result) {
				System.out.println("Case #"+cas+": Yes");
			}else{
				System.out.println("Case #"+cas+": No");
			}
			
		}
	}

}
