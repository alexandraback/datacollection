
import java.io.*;
import java.text.*;
import java.math.*;
import java.util.*;

public class J12R13A implements Runnable {
	Scanner in;
	PrintWriter out;
	static String taskname = ".\\src\\A-small-attempt1";
	int test, testn, i, j, k;
	int n;

	public static void main(String[] args) {
		new Thread(new J12R13A()).start();
	}

	public void solve() throws Exception {
		testn = in.nextInt();		

		for (test = 0; test < testn; test++) {
			out.print("Case #" + (test + 1) + ": ");
			n = in.nextInt();
			boolean A[][]=new boolean[n][n];
			boolean visit[] = new boolean [n];
			boolean b=false;	
			for (i = 0; i < n; i++) {
				for (j = 0; j < n; j++) {
					A[i][j]=false;
				}
			}
			for (int i = 0; i < n; i++) {
				int M=in.nextInt(), a;
				for (int j = 0; j < M; j++) {
					A[i][in.nextInt()-1] = true;
				}
			}
			
			Main:
			for (int s = 0; s < n; s++) {
			
				Stack<Integer> stack = new Stack<Integer>(); 
			    for (int i=0; i<n; i++)
			        visit[i] = false;
			    b = false;
			 
			            stack.push(s);
			            visit[s] = true;
			
			            while (!stack.empty())
			            {
			                int a = stack.pop();
			 
			 	                for (int t=0; t<n; t++)
			 	                	if (A[a][t])
			 	                		if (visit[t]){
			 	                			b=true; break Main;
			 	                		} else{
			 	                			stack.push(t);
			 	                			visit[t] = true;
			 	                		}
			            }
			}
			
			if(b) out.print("Yes\n");
			else out.print("No\n");
		}
	}

	void DFS()
	{
		
	}
	@Override
	public void run() {
		try {
			in = new Scanner(new File(taskname + ".in"));
			out = new PrintWriter(taskname+".out");
			//out = new PrintWriter(System.out, true);
			//			in = new BufferedReader( new InputStreamReader(System.in));
			//			out = new BufferedWriter( new OutputStreamWriter(System.out));
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
