import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


public class C {
	static int[] graph;
	static boolean[] taken;
	static boolean[] taken2;
	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream(new File("in.txt")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			System.setOut(new PrintStream(new File("out.txt")));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		Scanner s = new Scanner(System.in);
		
		int z = s.nextInt();
		
		for (int i = 0;i < z; i++ )
		{
			int n = s.nextInt();
			graph = new int[n];
			taken = new boolean[n];
			taken2 = new boolean[n];
			for (int j = 0;j < n; j++) {
				graph[j] = s.nextInt() - 1;
			}
			
			for (int one = 0;one < n; one++) {//first path start
				start = one;
				dfs1(one, 1, -1);
			}
			System.out.println("Case #" + (i + 1) + ": " + max);
			max = 0;
			//count = 0;
		}
	}
	static int max = 0;
	static int start = 0;
	
	static ArrayList<Integer> path = new ArrayList<Integer>();
	static void dfs1(int n, int count, int last) {
		
		if (taken[n]) {

		//	System.out.println("dfs1 FIN:" + (n + 1) +" "+ count +"\\\\" + last +   "    " + Arrays.toString(taken) +  " " + Arrays.toString(graph));
			if (n == start || (path.size() > 2 && path.get(path.size() - 2) == n))
			{	//System.out.println("Woo");
				max = Integer.max(max, count - 1);}
				if ((path.size() > 2 && path.get(path.size() - 2) == n)) {
					for (int j = 0; j < n; j++) {
						dfs2(j, count, path.get(path.size() - 1));
					}
					
				}
			return;
		}
		//System.out.println("dfs1:" + (n + 1) +" "+ count);
		
		taken[n] = true;
		int next = graph[n];
		//count++;
		path.add(n);
		dfs1(next, count+ 1, n);
		taken[n] = false;
		//count--;
		path.remove(path.size() - 1);
	}

	static void dfs2(int n, int count, int target) {
		
		if (taken[n]) {
			if (n==target) {
				max = Integer.max(max, count - 1);
			}
			return;
		}
		//System.out.println("dfs2:" + (n + 1) +" "+ count + " " + target);
		
		taken[n] = true;
		int next = graph[n];
		//count++;
		path.add(n);
		dfs2(next, count+ 1, target);
		taken[n] = false;
		//count--;
		path.remove(path.size() - 1);
	}
}
