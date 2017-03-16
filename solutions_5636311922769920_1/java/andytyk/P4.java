import java.io.*;

public class P4 {
	
	public static void main(String [] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("/Users/andykong/Downloads/gcj2016/p4/p4.large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("/Users/andykong/Downloads/gcj2016/p4/p4.large.out"));
		int T = Integer.parseInt(in.readLine());
		for(int cc = 1; cc <= T; cc++) {
			String [] sp = in.readLine().split(" ");
			int K = Integer.parseInt(sp[0]);
			int C = Integer.parseInt(sp[1]);
			int S = Integer.parseInt(sp[2]);
			if(C*S < K) {
				out.printf("Case #%d: IMPOSSIBLE\n",cc);
			} else {
				out.printf("Case #%d:",cc);
				int cv = 0;
				for(int i = 0; i < S; i++) {
					long v = 0;
					int end = cv + C;
					for(; cv < K && cv < end; cv++) {
						v *= K;
						v += cv;
					}
					out.printf(" %d",v+1);
					if(cv == K)
						break;
				}
				out.printf("\n");
			}
		}
		in.close();
		out.close();
	}
	
}
