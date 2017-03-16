import java.io.*;
import java.util.*;

public class A {

	public static void main(String args[]) throws Exception {
		String fn = args.length > 0 ?  args[0] :
		//	"A-.in";
			"A-small-attempt0.in";
		//	"A-large.in";
		LineNumberReader in = new LineNumberReader(new FileReader(fn));
		PrintWriter out = new PrintWriter(new FileWriter(fn.replace(".in", ".out")));
		int T = Integer.parseInt(in.readLine());
		for(int i = 0; i < T; i++) {
			out.print("Case #" + (i+1) + ": ");
			String S = in.readLine();
			String Z = "";
			for(int j = 0; j < S.length(); j++) {
				String z1 = S.charAt(j) + Z;
				String z2 = Z + S.charAt(j);
				if(z1.compareTo(z2) >= 0)
					Z = z1;
				else
					Z = z2;
			}
			out.println(Z);
			out.flush();
		}
		out.close();
	}
}
