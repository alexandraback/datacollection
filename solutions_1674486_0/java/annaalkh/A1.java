import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class A1 {
	static int currentLabel;
	static boolean[] exp;
	static int[] f;
	static ArrayList<Integer> quee=new ArrayList<Integer>();
	static boolean flag;
	static boolean[] temp;
	
	public static void main(String[] args) {
		try {
		PrintStream out = new PrintStream(new File("a1.txt"));
		System.setOut(out);
		Scanner theIn=new Scanner(new File("A-small-attempt1.in"));
		//Scanner theIn=new Scanner(new File("test.txt"));
		
		int t=theIn.nextInt();
		for (int i=1; i<=t; i++) {	//i - number of case
			int n=theIn.nextInt();
			currentLabel=n;
			exp=new boolean[n+1];
			f=new int[n+1];
			flag=false;
			quee=new ArrayList<Integer>();
			ArrayList<Integer>[] tops=new ArrayList[n+1];
			for (int j=1; j<=n; j++) {
				//j - number of top
				if (tops[j]==null) tops[j]=new ArrayList<Integer>();
				int k=theIn.nextInt();
				for (int r=1; r<=k; r++) {
					int s=theIn.nextInt();
					tops[j].add(s);
				}
			}
			dfs_loop(tops);
			
			exp=new boolean[n+1];
			for (int j=n-1; j>=1; j--) {
				if (!exp[quee.get(j)]) {
					temp=new boolean[n+1];
					dfs2(tops, quee.get(j));
					if (flag) break;
				}
			}
			if (flag) System.out.println("Case #"+i+": Yes"); else System.out.println("Case #"+i+": No");
		}
		} catch (Exception e) {}
	}
	
	static void dfs_loop(ArrayList<Integer>[] graph) {
		for (int i=1; i<=graph.length-1; i++) {
			if (!exp[i]) dfs(graph, i);
		}
	}
	static void dfs(ArrayList<Integer>[] graph, int v) {
		exp[v]=true;
		for (int x: graph[v]) {
			if (!exp[x]) {
				exp[x]=true;
				dfs(graph, x);
			}
		}
		f[v]=currentLabel;
		quee.add(v);
		currentLabel--;
	}
	static void dfs2(ArrayList<Integer>[] graph, int v) {
		
		exp[v]=true;
		/*if (temp[v]) {
			flag=true;
			return;
		}*/
		temp[v]=true;
		for (int x: graph[v]) {
			if (temp[x]) {
				flag=true;
				return;
			}
			temp[x]=true;
			if (!exp[x]) {
				exp[x]=true;
				//temp[x]=true;
				dfs2(graph, x);
				/*if (temp[v]) {
					flag=true;
					return;
				}*/
				//temp[x]=true;
			}
		}
	}
}