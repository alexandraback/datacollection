package B;

import java.io.*;

public class B {
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		
		int n = Integer.parseInt(in.readLine());
		for (int i = 0; i < n; ++ i) {
			String st = in.readLine();
			String[] input = st.split(" ");
			
			int T = Integer.parseInt(input[0]);
			int S = Integer.parseInt(input[1]);
			int p = Integer.parseInt(input[2]);
			
			int ans = 0;
			for (int j = 3; j < input.length; ++ j) {
				int t = Integer.parseInt(input[j]);
				if (t / 3 >= p)
					++ ans;
				else
					if (t % 3 == 0)
						if (t / 3 >= 1 && t / 3 + 1 >= p && S > 0) {
							-- S;
							++ ans;
						}
						else {}
					else 
						if (t % 3 == 1)
							if (t / 3 + 1 >= p)
								++ ans;
							else {}
						else 
							if (t / 3 + 1 >= p)
								++ ans;
							else
								if (t / 3 + 2 >= p && S > 0) {
									-- S;
									++ ans;
								}
			}
			out.println("Case #" + (i + 1) + ": " + ans);
		}
		
		out.close();
	}
	
}
