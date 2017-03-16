import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("A-small-attempt0.in"));
			out = new PrintWriter("output.txt");
		} catch (Exception e) {
			e.printStackTrace();
		}
		int T = in.nextInt();
		for(int c = 0; c < T; c++){
			int A = in.nextInt();
			int N = in.nextInt();
			int[] motes = new int[N];
			for(int i = 0; i < N; i++){
				motes[i] = in.nextInt();
			}
			Arrays.sort(motes);
			int best = N;
			for(int i = 0; i < N; i++){
				int cost = N-i-1;
				int cur = A;
				for(int j = 0; j <= i; j++){
					int last = cur;
					while(cur <= motes[j]){
						cur = 2*cur-1;
						cost++;
						if(last == cur) {
							cost = 1<<30;
							break;
						}
					}
					cur = cur + motes[j];
				}
				best = Math.min(best, cost);
			}
			out.println("Case #" + (c+1) +": "+ best);
		}
		in.close();
		out.close();
	}

}

