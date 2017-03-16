import java.io.*;
import java.util.*;

public class A{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int N = Integer.parseInt(br.readLine());

		for(int p = 0; p < N; p++) {
			int n = Integer.parseInt(br.readLine());


			int ret = answer(n);
			if(n>1) ret = Math.min(ret, answer(n-1)+1);




			pw.println("Case #" + (p+1) + ": " + ret);
		}


		pw.flush();
		pw.close();

	}

	static int answer(int n) {
					int d = (n+"").length();

					int ret = 0;

					for(int i = 1; i < d; i++) {
						int f = i/2;
						int c = i-f;
						ret += pow(10, f) - 1;
						ret += pow(10, c) - 2;
						ret += 2;
					}


					int best = Integer.MAX_VALUE;
					for(int i = 0; i <= d; i++) {
						int nt = n - pow(10,d-1);
						String snt = nt + "";
						while(snt.length() < d) snt = "0" + snt;
						int n1 = parseInt(rev(snt.substring(0,i)));
						int n2 = parseInt(snt.substring(i));

						if(n2 == 0 && i<d) {
							continue;
						} else {
							if(i<d) best = Math.min(best, n1+n2 + 1);
							else best = Math.min(best, nt);
						}
					}
					ret += best;


		/*
					int ff = d/2;
					int cc = d - ff;

					String s1 = rev((n+"").substring(0,ff));
					String s2 = (n+"").substring(ff);

					String t1 = rev((n+"").substring(0,cc));
					String t2 = (n+"").substring(cc);

					int atts = parseInt(s1) + parseInt(s2);
					int attt = parseInt(t1) + parseInt(t2);

					if(parseInt(s1) == 1) atts--;
					if(parseInt(t1) == 1) attt--;

					if(parseInt(t2) == 0 && parseInt(t1) > 1) attt = Integer.MAX_VALUE;
					if(parseInt(s2) == 0 && parseInt(s1) > 1) {
						int q = d-1;
						while((n+"").charAt(q) == '0') q--;

						ret += parseInt((n+"").substring(q)) + parseInt(rev((n+"").substring(0,q)));

					} else ret += Math.min(atts, attt);

		*/

			if(n<10)ret=n;

			return ret;
	}

	static int pow(int b, int p) {
		int ret = 1;
		for(int i = 0; i < p; i++) ret *= b;
		return ret;
	}

	static String rev(String s) {
		String ret = "";

		for(int i = 0; i < s.length(); i++) {
			ret = s.charAt(i) + ret;
		}

		return ret;
	}

	static int parseInt(String s) {
		if(s.equals("")) return 0;
		return Integer.parseInt(s);
	}
}