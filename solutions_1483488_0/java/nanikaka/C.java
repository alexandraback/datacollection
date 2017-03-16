package gcj2012.qual;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class C {

	final boolean DEBUG = false;
	final String PACKAGE = "gcj2012/qual";
	final String PROBLEM = "C";
	
	@SuppressWarnings("unchecked")
	void run(){
		if(!DEBUG){
			try {
				System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small.in")));
//				System.setIn(new FileInputStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large.in")));
				System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-small_out.txt")));
//				System.setOut(new PrintStream(new File("./src/"+PACKAGE+"/"+PROBLEM+"-large_out.txt")));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int N = 2000000;
		Set<Integer>[] s = new Set[N+1];
		for(int x=1;x<=N;x++){
			s[x] = new HashSet<Integer>();
			String t = x+"";
			int n = t.length();
			for(int i=0;i<n-1;i++){
				t = t.substring(n-1)+t.substring(0, n-1);
				if(t.charAt(0)=='0')continue;
				int r = Integer.parseInt(t);
				if(x<r&&r<=N)s[x].add(r);
			}
		}
		for(int CASE=1;CASE<=T;CASE++){
			int A = sc.nextInt(), B = sc.nextInt();
			int res = 0;
			for(int i=A;i<=B;i++)for(int x:s[i])if(x<=B)res++;
			System.out.println("Case #"+CASE+": "+res);
		}
	}
	
	public static void main(String[] args) {
		new C().run();
	}
}
