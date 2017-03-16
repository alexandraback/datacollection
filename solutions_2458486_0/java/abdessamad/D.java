import java.io.File;import java.io.FileOutputStream;import java.io.FileReader;
import java.io.IOException;import java.io.PrintStream;import java.io.PrintWriter;
import java.util.ArrayList;import java.util.Arrays;import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;

public class D {
    
	static int[][] ref,t ; static  int N , M;
    public static void main(String[] arg)throws IOException{
    	Scanner in=new Scanner(new File("D.in"));
    	PrintStream o=System.out;
    	int test=in.nextInt();
    	for(int ind=1; ind<=test; ind++){
    		int K=in.nextInt(); int N=in.nextInt();
          	ArrayList<Integer> startKeys=new ArrayList<Integer>();
          	for(int i=0; i<K; i++) startKeys.add(in.nextInt());
          	ArrayList<vertex> Graph=new ArrayList<vertex>();
          	for(int i=0; i<N; i++){
          		int Op=in.nextInt();
          		int numkeys=in.nextInt();
          		ArrayList<Integer> keysInside=new ArrayList<Integer>();
          		for(int kk=0; kk<numkeys; kk++)
          			keysInside.add(in.nextInt());
          		Graph.add(new vertex(keysInside,Op,i));
          	} 	// Graph ready
          	//dfs
          	boolean findMasterResult=false;
          	
          	for(int beg=0; beg<N; beg++){
          		ArrayList<Integer> senario=new ArrayList<Integer>();//senario.add(beg);
          		if(!startKeys.contains(Graph.get(beg).Opener)) continue;
          		ArrayList<Integer> Queue=new ArrayList<Integer>();
          		boolean[] visited=new boolean[N];
          		Queue.add(beg); visited[beg]=true; senario.add(beg);
          		ArrayList<Integer> currentKeys=(ArrayList<Integer>) startKeys.clone();
          		currentKeys.remove((Integer)Graph.get(beg).Opener);
          		for(Integer x:Graph.get(beg).KeysInside) currentKeys.add(x);
          		while(!Queue.isEmpty()){
          			int u=Queue.remove(0); 
          			//search adj
          			if(findMasterResult) break;
          			while(true){
          				int v=-1;
              			for(int i=0; i<N; i++){
              				if(i==u) continue;
              				if(!visited[i]){
              					if(currentKeys.contains(Graph.get(i).Opener)){
              						v=i;
              						break;
              					}
              				}
              			}
              			if(v==-1){
              				for(int x:Graph.get(u).KeysInside)
              					currentKeys.remove((Integer)x);
              				currentKeys.add(Graph.get(u).Opener);
              				if(allTrue(visited)){
              				    findMasterResult=true;
              				    System.out.print("Case #"+ind+":");
              				    for(int x:senario) System.out.print(" "+(x+1));
              				    System.out.println();
              					
              				}
              				break;
              			}
              			else{
              				visited[v]=true; Queue.add(v); senario.add(v);
              				currentKeys.remove((Integer)Graph.get(v).Opener);
              				for(Integer x:Graph.get(v).KeysInside) currentKeys.add(x);
              				//finish test
              				if(allTrue(visited)){
              				    findMasterResult=true;
              				    System.out.print("Case #"+ind+":");
              				    for(int x:senario) System.out.print(" "+(x+1));
              				    System.out.println();
              					break;
              				}
              			}
          			}
          			// finish search adj
          			
          			
          		}
          		if(findMasterResult){
          			break;
          		}
          		
          	}
          	if(!findMasterResult){
          		 System.out.println("Case #"+ind+": IMPOSSIBLE");
          	}
    	}
    }
	private static boolean allTrue(boolean[] visited) {
		for(boolean x:visited) if(!x) return false;
		return true;
	}
	private static void arP(ArrayList<Integer> senario) {
		System.out.println();
		for(int x:senario)
			System.out.print(x+" ");
		
	}
    
    
}

class vertex {
	ArrayList<Integer> KeysInside;
	int Opener;
	int label;
	vertex(ArrayList<Integer> keysIns,int Op,int labe){
		this.KeysInside=(ArrayList<Integer>) keysIns.clone();
		this.Opener=Op;
		this.label=labe;
	}
	
}