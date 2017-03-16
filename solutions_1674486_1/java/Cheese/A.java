import java.text.*;
import java.io.*;
import java.util.*;
import java.lang.Math;

public class A
{
	public class Node {
		public int id;
		public LinkedList<Integer> children;
		public Node (int a, LinkedList<Integer> b) {
			id = a;
			children = b;
		}
	}
	
	public static boolean solve(LinkedList<Integer> seen, int node, LinkedList<Integer>[] arr, int N) {
		
		//System.out.println(arr[node].length);
		for(int i = 0; i < arr[node].size(); i++) {
	
			//System.out.println("node: " + node + " i: " + i);
			int parent = arr[node].get(i);
			//System.out.println(node + " is a child of " + parent);
			//for(int a = 0; a < seen.size(); a++) System.out.print(seen.get(a)+" ");
			//System.out.println("\n");	
			//System.out.println("node: " + node + " i: " + i);
			if(seen.contains(parent)) {
				//System.out.println("true: parent =  " + node);
				return true;
			}
			
			//System.out.println("node: " + node + " i: " + i);
			seen.addFirst(parent);
			if(solve(seen, parent, arr, N)) return true;
			
		}
		return false;
	}
	
	public static void main(String[] args) throws Exception
	{
	
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		String str;
		
		int T = Integer.parseInt(br.readLine());
		String [] ss;
		for(int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			
			int N = Integer.parseInt(br.readLine());
			
			//int[][] arr = new int[N][];
			LinkedList[] arr = new LinkedList[N];
			
			
			for(int i = 0; i < N; i++) {
				ss = br.readLine().split(" ");
				int M = Integer.parseInt(ss[0]);
				LinkedList<Integer> tt = new LinkedList<Integer>();
				for(int j =0 ; j < M; j++) {
					tt.addFirst(Integer.parseInt(ss[j+1])-1);
				}
				arr[i] = tt;
			}
			
			/*System.out.println("TEST");
			for(int i = 0; i < N; i++) {
				for (int a = 0; a < arr[i].size(); a ++) {
					System.out.print(arr[i].get(a) + " ");
				}
				System.out.println();
			}
			System.out.println();*/
			
			boolean b = false;
			LinkedList<Integer> seen = new LinkedList<Integer>();
			for(int i = 0; i < N; i++) {
				seen.clear();
				//System.out.println("CASE NODE: " + i);
				if(solve(seen, i, arr, N)) {
					b = true;
					break;
				}
			}
			
			System.out.println(b?"Yes":"No");
		}
		
	}
}