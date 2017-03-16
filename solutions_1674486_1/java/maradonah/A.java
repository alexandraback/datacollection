import java.io.*;
import java.util.*;
import java.math.*;

public class A {
	static LinkedList <Integer> topSort;
	static int [] indegree;
	static boolean [] visited;
	static ArrayList <Integer> [] adjMat;
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("A-large.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter("A-large.out");
		int cases = Integer.parseInt(br.readLine().trim());
		StringTokenizer st;
		for (int c = 1; c <= cases; c++) {
			int N = Integer.parseInt(br.readLine().trim());
			adjMat = new ArrayList [N];
			for (int i = 0; i < adjMat.length; i++) {
				adjMat [i] = new ArrayList<Integer>();
			}
			indegree = new int [N];
			LinkedList <Integer> q = new LinkedList<Integer>();
			for (int i = 0; i < adjMat.length; i++) {
				st = new StringTokenizer(br.readLine());
				int nebs = Integer.parseInt(st.nextToken());
				indegree [i]++; 
				for (int j = 0; j < nebs; j++) {
					int neighbor = Integer.parseInt(st.nextToken())-1;
					adjMat [neighbor].add(i);
				}
			}
			topSort = new LinkedList<Integer>();
			visited = new boolean [N];
			for (int i = 0; i < adjMat.length; i++) {
				if(!visited [i]){
					visited [i] = true;
					DFS(i);
				}
			}
			int [][] ways = new int [N][N];
			boolean can = false;
			for(int i = 0; i < N && !can;i++) {
				can = false;
				ways [i][i] = 1;
				for (int node:topSort) {
					if(node == i || ways [i][node] > 0) {
						for(int neb:adjMat [node]) {
							ways [i][neb] += ways [i][node];
						}
					}
				}
				for(int j = 0; j < N && !can;j++)
					if(ways [i][j] > 1)
						can = true;
			}
			out.println("Case #" + c + ": " + (can?"Yes":"No"));
		}
		out.close();
		long finish = System.currentTimeMillis();
		System.out.println(finish - start);
	}
	public static void DFS(int i) {
		for (int node:adjMat [i]) {
			if(!visited [node]) {
				visited [node] = true;
				DFS(node);
			}
		}
		topSort.addFirst(i);
	}
}