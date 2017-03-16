package Round_1B;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;

public class Problem_A {
	static long [] inp;
	
	static HashMap<String, Integer> dp = new HashMap<String, Integer>();
	 public static int go(long a, int i){
		 if(i >= inp.length)
			 return 0;
		 else if(dp.containsKey(a + " " + i)){
			 return dp.get(a + " " + i);
		 }
		if(a > inp[i]){
			dp.put(a + " " + i,  go(a + inp[i], i + 1));
			return dp.get(a + " " + i);
		}else{
			if(a + a - 1 > a){
				dp.put(a + " " + i,   Math.min(go(a + a - 1 , i) + 1, go(a,i + 1) + 1));
				return dp.get(a + " " + i);
			}
			else{
				dp.put(a + " " + i, go(a,i + 1) + 1);
				return dp.get(a + " " + i);
			}
		}
		
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		PrintWriter out = new PrintWriter("output.out");
		BufferedReader br = new BufferedReader(new InputStreamReader(
				new FileInputStream("A-large.in")));
		int T = Integer.parseInt(br.readLine());
		String [] sp;
		long a = 0;
		int n = 0;
		for (int i = 0; i < T; i++) {
			sp = br.readLine().split(" ");
			a = Long.parseLong(sp[0]);
			n = Integer.parseInt(sp[1]);
			inp = new long[n];
			dp.clear();
			
			sp = br.readLine().split(" ");
			
			for (int j = 0; j < inp.length; j++) {
				inp[j] = Integer.parseInt(sp[j]);
			}
			
			Arrays.sort(inp);
			int count = 0;
			
			out.append("Case #"+(i+1)+": " + go(a, 0)+ "\n");
		}
		out.close();
	}
}
