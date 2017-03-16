package C;

import java.io.*;
import java.util.*;

public class C {
	
	static int[] pow = {10, 100, 1000, 10000, 100000, 1000000};
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("C.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("C.out")));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; ++ i) {
			String st = in.readLine();
			String[] input = st.split(" ");
			
			int A = Integer.parseInt(input[0]);
			int B = Integer.parseInt(input[1]);
			
			int t = A;
			int digits = 0;
			while (t > 0) {
				t /= 10;
				++ digits;
			}
			
			int ans = 0;
			for (int j = A; j < B; ++ j) {
				Set<Integer> set = new HashSet<Integer>();
				for (int k = 0; k < digits - 1; ++ k) {
					int m = j / pow[k] + (j % pow[k]) * pow[digits - 1 - k - 1];
					if (j < m && m <= B && !set.contains(m)) {
						set.add(m);
						++ ans;
					}
				}
			}
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		
		in.close();
		out.close();
	}
	
}
