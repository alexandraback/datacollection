package kingdom;

import java.util.*;
import java.io.*;
import java.math.*;


public class Kingdom {
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new FileReader(new File("src/kingdom/kingdom.in")));
		FileWriter out = new FileWriter(new File("src/kingdom/kingdom.out"));
		
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String s = in.readLine();
			StringTokenizer st = new StringTokenizer(s);
			
			int N = Integer.parseInt(st.nextToken());
			
			int[] star1 = new int[N];
			int[] star2 = new int[N];
			
			for (int i = 0; i < N; i++) {
				String s2 = in.readLine();
				StringTokenizer st2 = new StringTokenizer(s2);
				
				star1[i] = Integer.parseInt(st2.nextToken());
				star2[i] = Integer.parseInt(st2.nextToken());
			}
			
			int stars = 0;

			int levels_played = 0;
			int levels_unplayed = N*2;
			
			while (levels_unplayed > 0) {
				boolean played = false;
				for (int i = 0; i < N; i++) {
					if (star2[i] <= stars) {
						star2[i] = Integer.MAX_VALUE;
						if (star1[i] == Integer.MAX_VALUE) {
							stars--;
							levels_unplayed++;
						}
						else star1[i] = Integer.MAX_VALUE;
						stars += 2;
						levels_unplayed -= 2;
						played = true;
						break;
					}
				}
				if (!played) {
					int best_i = -1;
					int best = 0;
					for (int i = 0; i < N; i++) {
						if (star1[i] <= stars) {
							if (star2[i] > best) {
								best = star2[i];
								best_i = i;
							}
						}
					}
					if (best_i == -1) break;
					else {
						star1[best_i] = Integer.MAX_VALUE;
						stars += 1;
						levels_unplayed -= 1;
					}
				}
				
				levels_played++;
			}
			
			
			String answer_s = (levels_unplayed > 0) ? "Too Bad" : levels_played + "";
								 
			out.write("Case #" + t + ": " + answer_s + "\n");
		}
		in.close();
		out.close();
		
	}
}
