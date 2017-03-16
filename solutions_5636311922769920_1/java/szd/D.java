import java.io.*;
import java.util.*;

public class D {

	public static void main(String args[]) throws Exception {
		String fn = args.length > 0 ?  args[0] :
		//	"d1.in";
		//	"D-small-attempt0.in";
			"D-large.in";
		LineNumberReader in = new LineNumberReader(new FileReader(fn));
		PrintWriter out = new PrintWriter(new FileWriter(fn.replace(".in", ".out")));
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++) {
			out.print("Case #" + (i+1) + ":");
			StringTokenizer st = new StringTokenizer(in.readLine());
			int K = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int S = Integer.parseInt(st.nextToken());
			int min = (K + (C - 1)) / C;
			if(S >= min) {
				for(int pos = 0; pos < K; pos += C) {
					out.print(' ');
					long base = 1;
					long s = 0;
					for(int c = 0; c < C && pos + c < K; c++) {
						s += base * (pos + c);
						base *= K;
					}
					out.print(s + 1);
				}
			}
			else
				out.print(" IMPOSSIBLE");
			out.println();
			out.flush();
		}
		out.close();
	}
}
