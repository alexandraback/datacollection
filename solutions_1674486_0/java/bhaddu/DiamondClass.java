package code.google.codejam2k12.r1cmay6;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class DiamondClass {

	private static Scanner sc = new Scanner(System.in);
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws FileNotFoundException {
		PrintStream f = new PrintStream("Output");
		int T = sc.nextInt();
		for(int i=1;i<=T;i++){
			int N = sc.nextInt();
			Set<Integer>[] arr = new Set[N];
			for(int j=0;j<N;j++){
				arr[j] = new TreeSet<Integer>();
				int M=sc.nextInt();
				for(int k=0;k<M;k++){
					arr[j].add(sc.nextInt() - 1);
				}
			}
			
			f.println("Case #" + i + ": " + (calculate(arr)?"Yes":"No"));
		}
		System.out.println("Done");
	}

	private static boolean calculate(Set<Integer>[] arr) {
		
		for(int i=0;i<arr.length;i++){
			boolean[] visited=new boolean[arr.length];
			visited[i] = true;
			Queue<Integer> q = new LinkedList<Integer>();
			Iterator<Integer> it=arr[i].iterator();
			while(it.hasNext()){
				q.offer(it.next());
			}
			
			while(!q.isEmpty()){
				int node=q.remove();
				if(visited[node]){
					return true;
				}
				
				visited[node] = true;
				it=arr[node].iterator();
				while(it.hasNext()){
					q.offer(it.next());
				}
			}
		}

		return false;
	}
}
