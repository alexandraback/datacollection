import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class A {
	public static void main(String ... args) throws Exception{
		
		Scanner in = new Scanner(new File("A-large.in"));
		PrintStream out = new PrintStream(new File("A-large.out"));
		//Scanner in = new Scanner(System.in);
		//PrintStream out = System.out;

		
		int T = in.nextInt();
		in.nextLine();
		
		for(int t=0;t<T;t++){

			int N = in.nextInt();
			boolean d[][] = new boolean[N][N];
			for(int n=0;n<N;n++){
				int M = in.nextInt();
				for(int m=0;m<M;m++){
					d[n][in.nextInt()-1] = true;
				}
			}
		
			out.print("Case #" + (t+1) +": ");
			boolean found = false;
			for(int n=0;n<N;n++){
				boolean[] visited= new boolean[N];
				if(traverse(n,visited,d)){
					found = true;
					break;
				}
			}
			if(found ) out.print("Yes");
			else out.print("No");
			
			
			
		
			
			out.println();
		}
		
		
	}
	static boolean traverse(int start, boolean[] visited,boolean[][] d){
		if(visited[start]) return true;
		visited[start] = true;
		boolean found = false;
		for(int i=0;i<visited.length;i++){
		
			if(d[i][start]){
				if(traverse(i,visited,d)){
					found = true;
					break;
				}
			}
		}
		return found;
	}
}
