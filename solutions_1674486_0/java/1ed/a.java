package Round1C;

import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import Tools.TeePrintStream;

public class a {
	// get Pb Letter for input/output file names.
	public static String pbLetter;
	static {
		pbLetter=new Object() { }.getClass().getEnclosingClass().getName();
		int idx = pbLetter.lastIndexOf('.');
		if(idx != -1) pbLetter = pbLetter.substring(idx+1);
		pbLetter = pbLetter.toUpperCase();
	}
	
	
	public static void main(String[] args) throws Throwable {
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-small.in"));
		Scanner sc = new Scanner(new File("./"+pbLetter+"-small-attempt1.in"));
		//Scanner sc = new Scanner(new File("./"+pbLetter+"-large.in"));
		
		TeePrintStream out= new TeePrintStream(System.out, "./output-"+pbLetter+".txt");
		
		int testCount = sc.nextInt();
		sc.nextLine();
		for (int i = 1; i <= testCount;i++) {
			out.format("Case #%d:",i );
			solve(sc, out);
		}
		out.close();System.out.print("end");
	}

	static void solve(Scanner sc, PrintStream out) {
		int N = sc.nextInt();
		boolean[] seen = new boolean[N];
		ArrayList<int[]> g = new ArrayList<int[]>(N);
		for (int i = 0; i < N; i++) {
			sc.nextLine();
			int nb = sc.nextInt();
			int[] sons = new int[nb];
			for (int j = 0; j < sons.length; j++) {
				sons[j] = sc.nextInt()-1;
			}
			g.add(i, sons);
		}
		for(int i=0; i<N;++i) {
			Arrays.fill(seen, false);
			if(dfs(seen,g,i)) {
				out.println(" Yes");
				return;
			}
		}
		out.println(" No");
	}
	static boolean dfs (boolean[] seen,ArrayList<int[]> g, int idx)
	{
		//System.out.println(idx);
	  if(seen[idx]) {
		   return true;
	  }
	  seen[idx] =  true;
	  for (int i = 0; i < g.get(idx).length; i++) {
		 if(dfs(seen,g,g.get(idx)[i])) return true;
	  }
	  return false;
	}
}