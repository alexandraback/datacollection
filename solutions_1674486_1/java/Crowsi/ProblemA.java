package round1c;

import java.util.Scanner;
import java.util.Vector;

public class ProblemA {
	
		static Scanner scan = new Scanner(System.in);
	
		public static void main(String[] args) {
	
			int cases = scan.nextInt();
			
			for ( int i = 1; i <= cases; i++ ) {
				System.out.println("Case #" + i + ": " + solveCase());
			}
		}
	
		static Vector<Integer>[] edges;
		static int N;
		
		public static String solveCase() {
			
			
			N = scan.nextInt();
			edges = new Vector[N];                  			
			
			for ( int i = 0; i < N; i++ ) {
				
				int numEdges = scan.nextInt();
				
				edges[i] = new Vector<Integer>();
				
				for ( int j = 0; j < numEdges; j++ ) 
					edges[i].add(scan.nextInt()-1);
				
			}
			
			return startSearchFromDummy() ? "Yes" : "No";
			
		}
		
		static int[] visited;
		static int curSearch = -1;
		
		public static boolean startSearchFromDummy() {
			
			for ( int i = 0; i < N; i++ ) {
				visited = new int[N];
				curSearch = i;
				if ( DFS(i) ) {
					return true;
				}
			}
			
			return false;
		}
		
		public static boolean DFS(int curNode) {
			
			
			if (  curSearch == curNode && visited[curNode] >= 1 /*not a loop*/ ) {
				return false;
			}
			
			visited[curNode]++;
			
			if ( visited[curNode] >= 2) {
				return true;
			}
			
			for ( Integer n : edges[curNode] ) {
				if ( DFS(n) ) {
					return true;
				}
			}
			
			return false;
			
		}
			
}
