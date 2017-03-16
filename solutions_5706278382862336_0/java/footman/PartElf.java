import static java.lang.System.in;
import static java.lang.System.out;

import java.io.*;
import java.util.*;

public class PartElf {
	static final double EPS = 1e-10;
	static final double INF = 1 << 31;
	static final double PI = Math.PI;

	public static BufferedReader in;
	public static PrintWriter out;

	StringBuilder sb = new StringBuilder();


	public void run() throws IOException {
		in =new BufferedReader(new FileReader("in.txt"));
		out=new PrintWriter(new FileWriter("out.txt"));

		Scanner sc = new Scanner(in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		String input;
		String [] inputArray;
		for (int t=1; t<=T; t++){
			input = sc.next();
			inputArray = input.split("/");
			long p = Long.valueOf(inputArray[0]);
			long q = Long.valueOf(inputArray[1]);
			sb.append("Case #" + t + ": ");
			long g = gcd(q,p);
			p/=g;
			q/=g;
			for(g=q;g%2==0; g/=2);
			if(g>1) sb.append("impossible");
			else {
				for(g=0; p<q; p*=2,g++);
				sb.append(g);
			}
			sb.append("\n");
		}
		ln(sb);
		sc.close();
		out.close();
	}

	private long gcd(long p, long q) {
		if (q==0) return p;
		return gcd(q,p%q);
	}

	public static void main(String[] args) throws IOException {
		new PartElf().run();
	}
	public static void ln(Object obj) {
		out.print(obj);
	}
}
