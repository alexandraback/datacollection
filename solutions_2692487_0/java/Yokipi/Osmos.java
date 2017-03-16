package roundoneb2013;

import java.io.*;
import java.util.*;


public class Osmos {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File(
				"src/roundoneb2013/Osmos.in")));
		FileWriter out = new FileWriter(new File("src/roundoneb2013/Osmos.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int A = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			
			int[] motes = new int[N];
			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				motes[i] = Integer.parseInt(st.nextToken());
			}

			Arrays.sort(motes);
			
			int answer = absorb(motes, 0, A);
			
			//Formatter format = new Formatter();
			//format.format("%.5f", answer);							 
			out.write("Case #" + t + ": " + answer + "\n");
		}

		in.close();
		out.close();
	}
	
	public static int absorb(int[] motes, int p, int size) {
		if (p >= motes.length) {
			return 0;
		}
		else if (motes[p] < size) {
			return absorb(motes, p+1, size + motes[p]);
		}
		else {
			if (size == 1) {
				return motes.length-p;
			}
			int i = 0;
			while (size <= motes[p]) {
				size = size + (size-1);
				i++;
			}
			if (i >= motes.length-p) {
				return motes.length-p;
			}
			return Math.min(i+absorb(motes, p+1, size+motes[p]), motes.length-p);
		}
	}
}
