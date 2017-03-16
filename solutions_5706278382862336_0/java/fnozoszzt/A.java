package Round1A;

import java.util.*;
import java.io.*;

/*
 * author:yanghui
 */
public class A {

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

	public String trans(int n, int l) {
		String str = Integer.toBinaryString(n);
		while (str.length() < l)
			str = "0" + str;
		return str;
	}

	public ArrayList<String> getList(String str, int l) {
		ArrayList<String> ans = new ArrayList<String>();
		for (String i : data) {
			ans.add(i);
		}
		for (int i = 0; i < l; i++) {
			if (str.charAt(i) == '1') {
				for (int j = 0; j < ans.size(); j++) {
					char temp[] = ans.get(j).toCharArray();
					if (temp[i] == '0')
						temp[i] = '1';
					else
						temp[i] = '0';
					ans.set(j, new String(temp));
				}
			}
		}
		return ans;
	}

	public boolean Judge(ArrayList<String> cur) {
		Collections.sort(cur);
		for (int i = 0; i < cur.size(); i++) {
			if (!cur.get(i).equals(comp.get(i))) {
				return false;
			}
		}
		return true;
	}

	public int cal(int n) {
		String str = Integer.toBinaryString(n);
		int cnt = 0;
		for (int i = 0; i < str.length(); i++)
			if (str.charAt(i) == '1')
				cnt++;
		return cnt;
	}

	public ArrayList<String> data = new ArrayList<String>();
	public ArrayList<String> comp = new ArrayList<String>();

	public void work() {
		data.clear();
		comp.clear();
		int n = scan.nextInt();
		int l = scan.nextInt();
		for (int i = 0; i < n; i++) {
			data.add(scan.next());
		}
		for (int i = 0; i < n; i++) {
			comp.add(scan.next());
		}
		Collections.sort(comp);
		int max = (int) Math.pow(2, l) - 1;
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i <= max; i++) {
			ArrayList<String> temp = getList(trans(i, l), l);
			if (Judge(temp)) {
				ans = Math.min(ans, cal(i));
			}
		}
		if (ans == Integer.MAX_VALUE) {
			scan.println("NOT POSSIBLE");
		} else
			scan.println(ans);
	}

	public void run() {

		int n = scan.nextInt();
		for (int i = 1; i <= n; i++) {
			scan.print("Case #" + i + ": ");
			work();
		}
		scan.close();
	}

	public static void main(String args[]) throws Exception {
		new A().run();
	}
}
