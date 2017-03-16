import java.io.*;
import java.util.*;

public class D {

	public static void main(String args[]) throws Exception {
		String fn = args.length > 0 ?  args[0] :
		//	"d1.in";
			"D-small-attempt0.in";
		//	"D-large.in";
		LineNumberReader in = new LineNumberReader(new FileReader(fn));
		PrintWriter out = new PrintWriter(new FileWriter(fn.replace(".in", ".out")));
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++) {
			out.print("Case #" + (i+1) + ":");
			StringTokenizer st = new StringTokenizer(in.readLine());
			int K = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int S = Integer.parseInt(st.nextToken());
			if(S == K) {
				for(int s = 1; s <= S; s++) {
					out.print(' ');
					out.print(s);
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
