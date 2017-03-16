package prop;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Prop {

	
	public static void main(String[] args) throws IOException {
		
		BufferedReader in = new BufferedReader(new InputStreamReader(new FileInputStream("A-small.in")));
		PrintWriter out = new PrintWriter(new FileOutputStream("small.out"));
		
		int T = Integer.parseInt(in.readLine());
		for (int CASE = 1; CASE <= T;CASE ++) {
			int N, X, Y;
			StringTokenizer st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			X = Integer.parseInt(st.nextToken());
			Y = Integer.parseInt(st.nextToken());
			
			
			int[] min_max = getMinMax(X, Y);
			BigDecimal b = new BigDecimal(1);;
			if (N <= min_max[0]) {
				
			} else {
				int m = min_max[1] - N;
				for (int i = 0;i < m;i++) {
					b = b.multiply(new BigDecimal("0.5"));
				}
			}
			out.println("Case #"+CASE+": " + b);
		}
		out.close();
		in.close();
	}

	static int sum (int val) {
		int s = 0;
		for (int i = 1;i <= val;i++)
			s+=i;
		return s;
	}
	
	private static int[] getMinMax(int x, int y) {
		
		if (x == 0) {
			return new int[] {sum(x+y+1), sum(x+y+1)};
		}
		
		int min = sum((x + y ) - 1);
		min += (y + 1);
		int max = min + (x + y) ;
		return new int[] {min, max};
	}
}
