import java.util.*;
import java.io.*;

public class Main{
	
	private static final int ONE = 1;
	private static final int I = 2;
	private static final int J = 3;
	private static final int K = 4;
	
	private static final int[][] MULT = new int[][]{
		{0, 0, 0, 0, 0},
		{0, 1, I, J, K},
		{0, I, -ONE, K, -J},
		{0, J, -K, -ONE, I},
		{0, K, J, -I, -ONE}
	};
	private static int mult(int x1, int x2){
		int sign = 1;
		if (x1 < 0){
			x1 = -x1;
			sign = -sign;
		}
		
		if (x2 < 0){
			x2 = -x2;
			sign = -sign;
		}
		
		return sign * MULT[x1][x2];
	}
	
	
	private static final int[] PARSE = new int[128];
	static{
		PARSE['i'] = I;
		PARSE['j'] = J;
		PARSE['k'] = K;
	}
	private static int[] parse(String s){
		int[] p = new int[s.length()];
		for (int i = 0; i < p.length; ++i)
			p[i] = PARSE[s.charAt(i)];
		return p;
	}

	
	
	private static final char[] ENCODE = new char[5];
	static{
		ENCODE[0] = '0';
		ENCODE[ONE] = '1';
		ENCODE[I] = 'i';
		ENCODE[J] = 'j';
		ENCODE[K] = 'k';
	}
	private static String encode(int v){
		if (v < 0)
			return "-" + ENCODE[-v];
		else
			return "" + ENCODE[v];
	}
	


	private static boolean solve(int[] l, int x){
		int len = l.length;
		int lenx = x*l.length;
		
		int[] front = new int[lenx];
		front[0] = l[0];
		for (int i = 1; i < lenx; ++i)
			front[i] = mult(front[i-1], l[i%len]);
		
//		System.out.print("front = [");
//		for (int i = 0; i < front.length; ++i)
//			System.out.print(encode(front[i]) + (i == front.length - 1 ? "" : ","));
//		System.out.println("]");
		
		int[] back = new int[lenx];
		back[lenx-1] = l[len-1];
		for (int i = lenx-2; i >= 0; --i)
			back[i] = mult(l[i%len], back[i+1]);
		
//		System.out.print("back = [");
//		for (int i = 0; i < back.length; ++i)
//			System.out.print(encode(back[i]) + (i == back.length - 1 ? "" : ","));
//		System.out.println("]");
		
		for (int i = 0; i < lenx-2; ++i){
			if (front[i] != I)
				continue;
			
//			System.out.println("Trying front=" + i);
			
			int mid = l[(i+1)%len];
			for (int j = i+2; j < lenx; ++j){
//				System.out.println("mid=" + encode(mid) + ", back=" + encode(back[j]));
				if ((mid == J) && (back[j] == K))
					return true;
				
				mid = mult(mid, l[j%len]);
			}
		}
		
		return false;
	}
	
	
	public static void main(String[] args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int tc = Integer.parseInt(in.readLine());
		
		for (int t = 1; t <= tc; ++t){
			args = in.readLine().split(" ");
			int l = Integer.parseInt(args[0]);
			long x = Long.parseLong(args[1]);
			if (x > 8)
				x = 8 + x%4;
			
			String s = in.readLine();
			System.out.printf("Case #%d: %s\n", t,
							  solve(parse(s), (int)x) ? "YES" : "NO");
		}
	}
	
	

}