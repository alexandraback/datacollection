import java.io.*;
import java.util.*;

public class C{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		long N = Long.parseLong(br.readLine());

		for(long p = 0; p < N; p++) {
			long n = Long.parseLong(br.readLine());

			long[] sp = new long[2];
			long[] tt = new long[2];
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

			int ret = 0;
			if(at <= 1) {
				ret = 0;
			} else {
				if(tt[0] * (2*360 - sp[0]) <= tt[1] * (360 - sp[1])) {
					ret = 1;
				}
				if(tt[1] * (2*360 - sp[1]) <= tt[0] * (360 - sp[0])) {
					ret = 1;
				}
			}

			pw.println("Case #" + (p+1) + ": " + ret);
		}


		pw.flush();
		pw.close();

	}
}