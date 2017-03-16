import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class Q2 {
	private static void run(int CASE) throws Exception {
		StringTokenizer st = new StringTokenizer(readLine());
		int count = 0;
		int N = parseInt(st.nextToken());
		int S = parseInt(st.nextToken());
		int p = parseInt(st.nextToken());
		for (int i = 0; i < N; i++) {
			int total = parseInt(st.nextToken());
			int min = (int) Math.floor(total/3.0);
			int max = (int) Math.ceil(total/3.0);
			if(max>=p) {
				count++;
			} else if(max>=p-1 && S>0 && max+1<=total) {
				int left = total-(max+1);
				if((max+1) - Math.floor(left/2.0) <= 2) {
					S--;
					count++;
				}
			}
		}
		printf("Case #%d: %d\n", CASE, count);
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("B-small-attempt2.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int T = Integer.parseInt(readLine());
		for (int c = 1; c <= T; c++) {
			run(c);
		}
		in.close();
		out.close();
	}

	private static String readLine() throws IOException {
		return in.readLine();
	}

	private static void printf(String str, Object... o) {
		System.out.printf(str, o);
		out.printf(str, o);
	}

	private static int parseInt(String t) {
		return Integer.parseInt(t);
	}
}
