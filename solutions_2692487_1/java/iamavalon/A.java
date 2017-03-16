import java.io.*;
import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter out = null;
		try {
			in = new Scanner(new File("A-large.in"));
			out = new PrintWriter("output.txt");
		} catch (Exception e) {
			e.printStackTrace();
		}
		long T = in.nextLong();
		for(long c = 0; c < T; c++){
			long A = in.nextLong();
			int N = in.nextInt();
			long[] motes = new long[N];
			for(int i = 0; i < N; i++){
				motes[i] = in.nextLong();
			}
			Arrays.sort(motes);
			long best = N;
			for(int i = 0; i < N; i++){
				long cost = N-i-1;
				long cur = A;
				for(int j = 0; j <= i; j++){
					long last = cur;
					while(cur <= motes[j]){
						cur = 2*cur-1;
						cost++;
						if(last == cur) {
							cost = 1L<<60;
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

