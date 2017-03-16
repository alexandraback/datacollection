import java.util.ArrayList;
import java.util.Scanner;

public class a {
	public static void main(String [] arg){
		new a().run();
	}
	Scanner in = new Scanner(System.in);
	void run(){
		int t = in.nextInt();
		for(int i=0;i<t;i++){
			System.out.print("Case #"+(i+1)+": ");
			if(solve())
				System.out.println("Yes");
			else 
				System.out.println("No");
		}
	}
	boolean solve(){
		int n = in.nextInt();
		int [][] adj = new int [n][n];
		
		if(n <= 2)return false;
		
		for(int i=0;i<n;i++){
			int m = in.nextInt();
			for(int j=0;j<m;j++){
				adj[i][in.nextInt()-1] = 1;
			}
		}
		
		for(int i=0;i<n;i++)
			if(allnode(i,adj,n))
				return true;
		return false;
	
	}
	boolean allnode(int x,int[][] adj,int n){
		int[] color = new int [n];
		ArrayList<Integer> queue = new ArrayList<Integer>();
		queue.add(x);
		//color[0] = 1;
		while(!queue.isEmpty()){
			//System.out.println(queue.toString());
			int i = queue.remove(0);
			//System.out.println(i);
			for(int j=0;j<n;j++){
				if(adj[i][j] == 1){
					color[j]++;
					queue.add(j);
				}
				if(color[j] == 2)
					return true;
			}
			
		}
		return false;
	}
}
