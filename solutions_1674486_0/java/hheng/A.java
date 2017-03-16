import java.util.*;
import java.io.*;
import java.lang.*;

class A { 
	int[][] paths; 
	int count;
	
  public static void main(String[] args) {
  	(new A()).run();
  }

  public void run() {
  	Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    
    for (int a=0; a<T; a++) {
    	int N = sc.nextInt();
    	paths = new int[N+1][11];
    	for (int i=0; i<N+1; i++) Arrays.fill(paths[i], -1);
    	for (int i=1; i<=N; i++) {
    		int M = sc.nextInt();
    		for (int j=0; j<M; j++) paths[i][j] = sc.nextInt();
    	}
    	
    	int[] pathNumbered = new int[N+1];
    	boolean diamond = false; 
    	for (int i=1; i<=N; i++) {
    		for (int j=1; j<=N; j++) {
    			count = 0;
    			doit(i, j);
    			if (count >= 2) { diamond = true; break; }
    		}
    	}
    	
    	if (diamond) System.out.println("Case #" + (a+1) + ": Yes");
    	else System.out.println("Case #" + (a+1) + ": No");
    	
    }
  }
  
  public void doit(int node, int dest) {
  	if (node == dest) { count++; return; }
  	for (int i=0; i<11; i++) {
  		if (paths[node][i] == -1) break;
  		doit(paths[node][i], dest);
  	}
  }
}


