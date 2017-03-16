import java.io.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		long N = Long.parseLong(br.readLine());

		for(long p = 0; p < N; p++) {
			long n = Long.parseLong(br.readLine());

			long[] sp = new long[500000];
			long[] tt = new long[500000];
			int at = 0;

			for(int i = 0; i < n; i++) {
				String[] s = br.readLine().split(" ");

				int spt = Integer.parseInt(s[0]);
				int nht = Integer.parseInt(s[1]);
				int ttt = Integer.parseInt(s[2]);

				for(int j = 0; j < nht; j++) {
					sp[at] = spt;
					tt[at] = ttt + j;
					at++;
				}
			}

			long ret = at-1;
			for(int i = 0; i < at; i++) {
				int tret = 0;
				long v = tt[i]*(2*360 - sp[i]);
				for(int j = 0; j < at; j++) {
					if(j == i) continue;
					long nl = (v + tt[j]*sp[j])/(360*tt[j]);
					tret += nl == 0 ? 1 : nl-1;
				}
				if(tret >= 0) ret = Math.min(ret, tret);
			}

			pw.println("Case #" + (p+1) + ": " + ret);
		}


		pw.flush();
		pw.close();

	}
}