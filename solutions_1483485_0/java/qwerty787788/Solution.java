import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		int cases = in.nextInt();
		String s1 = "qz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
		String s1ans = "zq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
		//
		char arr[] = new char[30];
		for (char c = 'a'; c <= 'z'; c++) {
			arr[c-'a'] = '0';
			for (int i = 0; i < s1.length(); i++)
				if (c == s1.charAt(i)) {
					arr[c-'a'] = s1ans.charAt(i);
				}
			if (arr[c-'a'] == '0') out.println(c);
		}
		for (int nowCase = 1; nowCase <= cases; nowCase++) {
			String test = in.readLine();
			//
			out.print("Case #");
			out.print(nowCase);
			out.print(": ");
			for (int i = 0; i < test.length(); i++) {
				if (test.charAt(i) == ' ') 
					out.print(" "); else
				    out.print(arr[test.charAt(i)-'a']);
			}
			out.println();
		}
	}

	public void run() {
		try {
			in = new FastScanner(new File("a.in"));
			out = new PrintWriter(new File("a.out"));

			//in = new FastScanner(System.in);
			//out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
		
		String readLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return " ";
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}