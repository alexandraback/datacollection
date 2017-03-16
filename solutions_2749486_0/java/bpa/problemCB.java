import java.util.*;
import java.io.*;

public class problemCB implements Runnable {

	BufferedReader br;
	StringTokenizer in;
	PrintWriter out;

	public void solve() throws IOException {
		int t = nextInt();

		for (int k = 0; k < t; k++) {
			int x = nextInt();
			int y = nextInt();
			
			String ans = "";
			
			if (x < 0)
				for (int i = 0; i < -x; i++)
					ans += "EW";
			else
				for (int i = 0; i < x; i++)
					ans += "WE";
			
			if (y < 0)
				for (int i = 0; i < -y; i++)
					ans += "NS";
			else
				for (int i = 0; i < y; i++)
					ans += "SN";

			out.println("Case #" + (k + 1) + ": " + ans);
		}
	}

	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public String nextToken() throws IOException {
		while ((in == null) || (!in.hasMoreTokens()))
			in = new StringTokenizer(br.readLine());
		return in.nextToken();
	}

	public void run() {
		try {
//			br = new BufferedReader(new InputStreamReader(System.in));
//			out = new PrintWriter(System.out);
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			solve();
			out.close();
		} catch (IOException e) {
		}
	}

	public static void main(String[] args) {
		new Thread(new problemCB()).start();
	}
}
