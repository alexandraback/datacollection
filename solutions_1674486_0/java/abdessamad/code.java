import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;
import static java.lang.Math.*;

public class A {
	static int[][] adj; static boolean[] visited; static int N;
	static void p(Object ...o) { System.out.println(Arrays.deepToString(o));}
	static boolean justPoped; static int[][] path;
	public static void main(String[] argv)throws IOException{
		Scanner in = new Scanner ( System.in );
		int T=in.nextInt();
		for(int test=1; test<=T; test++){		N=in.nextInt(); adj=new int[N][N]; visited=new boolean[N];
			for(int i=0; i<N; i++){				int Mi=in.nextInt();			for(int k=0; k<Mi; k++){ 		int Ck=in.nextInt(); 			adj[i][Ck-1]=1;				}
			}
			//p(adj);
			
			path=new int[N][N];
			boolean finish=false;
			//dfs on each node
			for(int i=0; i<N; i++){
				visited[i]=true;
				Stack<Integer> s=new Stack<Integer>();
				s.add(i);
				while(!s.empty()){
					int peek=s.peek();
					int v=getAdjUnvisited(peek);
					
					if(v==-2){
						finish=true;
						break;
					}
					else if(v==-1){
						s.pop();
					}
					else{
						visited[v]=true;
						s.add(v);
						path[peek][v]=1;
					}
				}
				if(finish)
					break;
				
				//p(path);
				
				finish=false;
				for(int k=0; k<N; k++){
					if(k==i)continue;
					int temp=0;
					for(int a=0; a<N; a++){
							if(a==k) continue;
							  temp+=path[a][k];
					}
					
					if(temp>=2) finish=true;
					
				}
				//refresh visited
				for(int q=0; q<N; q++)
					visited[q]=false;
				
			}
			if(finish)
				System.out.println("Case #"+test+": Yes");
			else
				System.out.println("Case #"+test+": No");
			
		}
	
	}
	static int getAdjUnvisited(int v){
		for(int k=0; k<N; k++){
			if(k==v) continue;
			if(adj[v][k]==1 ){
				if(!visited[k])
					return k;
				else
					path[v][k]=1;
				
			}
		}
		return -1;
	}

}
