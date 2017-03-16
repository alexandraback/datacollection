package Round1C;

import java.util.*;
import java.io.*;

/*
 * author:yanghui
 */
public class B {

	class FastIO {
		BufferedReader br;
		StringTokenizer st;
		PrintWriter out;

		public FastIO(File in, File o) {
			try {
				br = new BufferedReader(new FileReader(in));
				out = new PrintWriter(new FileWriter(o));
			} catch (Exception e) {
				e.printStackTrace();
			}
			eat("");
		}

		public FastIO() {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new OutputStreamWriter(System.out));
			eat("");
		}

		public void eat(String s) {
			st = new StringTokenizer(s);
		}

		public String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				throw new IOError(e);
			}
		}

		public boolean hasNext() {
			while (!st.hasMoreTokens()) {
				String s = nextLine();
				if (s == null)
					return false;
				eat(s);
			}
			return true;
		}

		public String next() {
			hasNext();
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

		public void print(String ans) {
			out.print(ans);
			out.flush();
		}

		public void print(int ans) {
			out.print(ans);
			out.flush();
		}

		public void print(long ans) {
			out.print(ans);
			out.flush();
		}

		public void print(double ans) {
			out.print(ans);
			out.flush();
		}

		public void println(String ans) {
			out.println(ans);
			out.flush();
		}

		public void println(int ans) {
			out.println(ans);
			out.flush();
		}

		public void println(long ans) {
			out.println(ans);
			out.flush();
		}

		public void println(double ans) {
			out.println(ans);
			out.flush();
		}

		public void println() {
			println("");
			out.flush();
		}

		public void printf(String arg0, Object... arg1) {
			out.printf(arg0, arg1);
			out.flush();
		}

		public void println(int[] ans) {
			for (int i = 0; i < ans.length; i++)
				print(ans[i] + " ");
			println();
		}

		public void println(long[] ans) {
			for (int i = 0; i < ans.length; i++)
				print(ans[i] + " ");
			println();
		}

		public void println(double[] ans) {
			for (int i = 0; i < ans.length; i++)
				print(ans[i] + " ");
			println();
		}

		public void println(Object... ans) {
			for (Object cur : ans)
				print(cur.toString() + " ");
			println();
		}

		public void println(Object ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(int ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(long ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(double ans[][]) {
			for (int i = 0; i < ans.length; i++) {
				for (int j = 0; j < ans[i].length; i++) {
					print(ans[i] + " ");
				}
				println();
			}
		}

		public void println(List<Object> ans) {
			for (Object i : ans) {
				print(i.toString() + " ");
			}
			println();
		}

		public void close() {
			out.flush();
			out.close();
		}
	}

	FastIO scan = new FastIO(new File("in"), new File("out"));

	// FastIO scan = new FastIO();

	boolean nextPermutation(int[] is) {
		int n = is.length;
		for (int i = n - 1; i > 0; i--) {
			if (is[i - 1] < is[i]) {
				int j = n;
				while (is[i - 1] >= is[--j])
					;
				swap(is, i - 1, j);
				rev(is, i, n);
				return true;
			}
		}
		rev(is, 0, n);
		return false;
	}

	public void rev(int[] is, int begin, int n) {
		int temp[] = Arrays.copyOfRange(is, begin, n);
		for (int i = n - 1; i >= begin; i--) {
			is[i] = temp[n - 1 - i];
		}
	}

	public void swap(int[] is, int i, int j) {
		int temp = is[i];
		is[i] = is[j];
		is[j] = temp;
	}

	public boolean Judge(int is[], String str[]) {
		StringBuffer sb = new StringBuffer();
		for (int i = 0; i < is.length; i++) {
			sb.append(str[is[i]]);
		}
		boolean ans[] = new boolean[26];
		Arrays.fill(ans, false);
		char pre = sb.charAt(0);
		ans[pre - 'a'] = true;
		for (int i = 1; i < sb.length(); i++) {
			if (pre != sb.charAt(i)) {
				pre = sb.charAt(i);
				if (ans[pre - 'a'])
					return false;
				ans[pre - 'a'] = true;
			}
		}
		return true;
	}

	public void work() {

		int n = scan.nextInt();
		int is[] = new int[n];
		for (int i = 0; i < n; i++)
			is[i] = i;
		String str[] = new String[n];
		for (int i = 0; i < n; i++){
			String temp = scan.next();
			String ans = "";
			char pre = temp.charAt(0);
			for(int j = 1 ; j < temp.length() ; j ++){
				if(temp.charAt(j) != pre){
					ans += pre;
					pre = temp.charAt(j);
				}
			}
			ans += pre;
			str[i] = ans;
		}
		int cnt = 0;
		if (Judge(is, str))
			cnt++;
		while (nextPermutation(is)) {
			if (Judge(is, str))
				cnt++;
		}
		scan.println(cnt);
	}

	public void run() {

		int t = scan.nextInt();
		for (int i = 1; i <= t; i++) {
			scan.print("Case #" + i + ": ");
			work();
		}
		scan.close();
	}

	public static void main(String args[]) throws Exception {
		new B().run();
	}
}
