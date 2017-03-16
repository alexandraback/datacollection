import java.util.*;
import java.io.*;

public class C {
	
	static Scanner in;
	static PrintWriter out;

	public static int transf(char c) {
		if (c=='i') return 2;
		if (c=='j') return 3;
		if (c=='k') return 4;
		if (c=='i') return 2;
		if (c=='j') return 3;
		if (c=='k') return 4;
		throw new RuntimeException("invalid character "+c);
	}
	
	public static int prod(int a, int b) {
		int[][] prod = new int[][] {
				{-1,-2,3,4,0,-4,-3,2,1},
				{2,-1,-4,3,0,-3,4,1,-2},
				{-3,4,-1,2,0,-2,1,-4,3},
				{4,3,2,1,0,-1,-2,-3,-4},
				{0,0,0,0,0,0,0,0,0},
				{-4,-3,-2,-1,0,1,2,3,4},
				{3,-4,1,-2,0,2,-1,4,-3},
				{-2,1,4,-3,0,3,-4,-1,2},
				{1,2,-3,-4,0,4,3,-2,-1},
		};
		return prod[a+4][b+4];
	}

	public static ArrayList<Integer> build(String s) {
		ArrayList<Integer> v = new ArrayList<Integer>();
		int a = 1;
		for (int i = 0; i < s.length(); i++) {
			a = prod(a, transf(s.charAt(i)));
			v.add(a);
		}
		return v;
	}
	
	public static int pow(int b, long n)
	{
	    int r = 1;
	    for (int i = 0; i < n%4;i++)
	    	r = prod(r,b);
	    return r;
	}
	
	public static boolean solve1(long X, String S)
	{
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < Math.min(X, 10); i++)
			sb.append(S);
		ArrayList<Integer> v=build(sb.toString());
		int last = v.get(S.length()-1);
		if (pow(last, X)==-1) {
			for (int i=0; i < v.size();i++)
				if (v.get(i)==2)
					for (int j = i+1; j < v.size(); j++){
						if (v.get(j)==4)
							return true;
					}
		}
		return false;
	}
	
	void solve() {
		in.nextInt();
		long X = in.nextLong();
		String S = in.next();
		out.println(solve1(X,S)?"YES":"NO");
		out.flush();
	}

	public static void main(String[] args) throws Exception {
		String load = "src/C-small-attempt0.in";
		String save = "src/C-small-attempt0.out";
		in = new Scanner(new File(load));
		out = new PrintWriter(new File(save));
		int T = in.nextInt();
		for (int t = 1; t <= T; t++) {
			out.print("Case #" + t + ": ");
			new C().solve();
		}
		out.close();
	}

}
