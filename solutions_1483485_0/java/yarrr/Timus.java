import java.io.*;
import java.util.*;
import java.math.*;

public class Timus implements Runnable {
	BufferedReader in;
	PrintWriter out;
	StringTokenizer st;
	Random rnd;
	
	final String input = "yeqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	final String output = "aozour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

	char[] map = new char[26];
	boolean[] used = new boolean[26];
	
	String solveOne(String line) {
		StringBuilder res = new StringBuilder();
		
		for(int i = 0; i < line.length(); i++) {
			char from = line.charAt(i);
			int fromInd = line.charAt(i) - 'a';
			
			if(!Character.isLetter(from)) {
				res.append(from);
			} else {
				res.append(map[fromInd]);
			}
		}
		
		return res.toString();
	}
	
	void solve() throws IOException {
		Arrays.fill(map, Character.MIN_VALUE);
		
		for(int i = 0; i < input.length(); i++) {
			char from = input.charAt(i), to =  output.charAt(i);
			int fromInd = input.charAt(i) - 'a', toInd = to - 'a';
			
			if(!Character.isLetter(from)) {
				continue;
			}
			
			if(map[fromInd] != Character.MIN_VALUE && map[fromInd] != to) {
				throw new RuntimeException();
			} else {
				map[fromInd] = to;
				used[toInd] = true;
			}
		}
		
		{
			map['z' - 'a'] = 'a' + 16;
			used[16] = true;
		}
		
		for(int i = 'a'; i <= 'z'; i++) {
			if(map[i - 'a'] == Character.MIN_VALUE || !used[i - 'a']) {
				throw new RuntimeException();
			}
		}
		
		int tests = nextInt();
		
		for(int test = 1; test <= tests; test++) {
			out.printf("Case #%d: %s\n", test, solveOne(in.readLine().trim()));
		}
	}

	public static void main(String[] args) {
		new Timus().run();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			rnd = new Random();

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(42);
		}
	}

	String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = in.readLine();

			if (line == null) {
				return null;
			}

			st = new StringTokenizer(line);
		}

		return st.nextToken();
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}