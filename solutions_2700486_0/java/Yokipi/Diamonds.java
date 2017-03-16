package roundoneb2013;

import java.io.*;
import java.util.*;


public class Diamonds {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File(
				"src/roundoneb2013/Diamonds.in")));
		FileWriter out = new FileWriter(new File(
				"src/roundoneb2013/Diamonds.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			
			double answer = 0;
			
			int R = (Math.abs(X)+Y)-1;
			int req = ((R)*(R+1))/2;
			R+=2;
			int shell = ((R)*(R+1))/2 - req;
			if (req >= N) {
				answer = 0;
			}
			else if (N >= shell + req) {
				answer = 1;
			}
			else if (Y == R-1) {
				answer = 0;
			}
			else if (N-req > (shell/2)+Y) {
				answer = 1;
			}
			else {
				int left = N-req;
				int needed = Y+1;
				answer = 0;
				for (int i = needed; i <= left; i++) {
					double p = 1;
					for (int j = 1; j <= left; j++) {
						p = p * j * 0.5;
						if (j <= i) {
							p = p / j;
						}
						else {
							p = p / (left-j+1);
						}
					}
					answer = answer + p;
				}
			}

			//Formatter format = new Formatter();
			//format.format("%.5f", answer);							 
			out.write("Case #" + t + ": " + answer + "\n");
		}

		in.close();
		out.close();
	}
}
