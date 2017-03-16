package QualificationRound;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

public class RecycledNumbers {
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("recyclednumbers.in"));
		System.setOut(new PrintStream("recyclednumbers.out"));
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine());
		for(int t = 1; t <= T; t++) {
			System.out.print("Case #" + t + ": ");
			
			String[] parts = bf.readLine().trim().split("[ ]+");
			int from = Integer.parseInt(parts[0]);
			int to = Integer.parseInt(parts[1]);
			
			boolean[] explored = new boolean[to - from + 1];
			
			long result = 0l;
			for(int i = from; i <= to; i++) {
				if(explored[i - from]) continue;
				
				long count = 0L;
				String s = Integer.toString(i);
				int length = s.length();
				for(int j = 0; j < length; j++) {
					s = s.substring(s.length() - 1) + s.substring(0, s.length() - 1);
					if(s.charAt(0) == '0') continue;
					
					int n = Integer.parseInt(s);
					if(n < from || n > to) continue;
					if(explored[n - from]) continue;
					explored[n - from] = true;
					count++;
				}
				
				result += count * (count - 1l) / 2l;
			}
			
			System.out.println(result);
		}
	}

}
