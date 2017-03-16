import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.StringTokenizer;


public class Q3 {
	private static void run(int CASE) throws Exception {
		HashSet<String> countedSet = new HashSet<String>();
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(readLine());
		int A = parseInt(st.nextToken());
		int B = parseInt(st.nextToken());
		int count = 0;
		for (int n = A; n < B; n++) {
			countedSet.clear();
			String sA = toStr(n);
			for (int c = 1; c < sA.length(); c++) {
				sb.delete(0, sb.length());
				sb.append(sA.substring(c)).append(sA.substring(0, c));
				String sM = sb.toString();
				if(sM.charAt(0)=='0') continue;
				if(countedSet.contains(sM)) continue;
				countedSet.add(sM);
				int m = parseInt(sM);
				if(n<m && m<=B) count++;
			}
		}
		printf("Case #%d: %d\n", CASE, count);
	}
	
	private static String toStr(int i) {
		return String.valueOf(i);
	}

	//-- Supporting --//
	static BufferedReader in;
	static PrintWriter out;
	static {
		try {
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("out.txt"));
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args) throws Exception {
		int N = Integer.parseInt(readLine());
		for (int c = 1; c <= N; c++) {
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
