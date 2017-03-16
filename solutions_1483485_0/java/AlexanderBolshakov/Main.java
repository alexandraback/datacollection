import java.io.*;
import java.security.SecureRandom;
import java.util.*;
import java.math.*;
import java.awt.geom.*;

import static java.lang.Math.*;

public class Main implements Runnable {
	
	static String filename = "A-small-attempt0";
	
	char[] table = new char[26];
	
	String[] encoded = new String[] {
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
		"y qee",
		"z"
	};
	
	String[] decoded = new String[] {
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
		"a zoo",
		"q"
	};
	
	void buildTable() {
		for (int i = 0; i < encoded.length; i++) {
			for (int j = 0; j < encoded[i].length(); j++) {
				if (encoded[i].charAt(j) == ' ')
					continue;
				table[encoded[i].charAt(j) - 'a'] = decoded[i].charAt(j);
			}
		}
	}
	
	public void solve() throws Exception {
		buildTable();
		/*
		for (int i = 0; i < 26; i++) {
			out.printf("%c = %c\n", (char)('a' + i), table[i]);
		}
		*/
		int t = sc.nextInt();
		for (int Case = 1; Case <= t; Case++) {
			String str = in.readLine();
			out.printf("Case #%d: ", Case);
			for (int i = 0; i < str.length(); i++) {
				if (str.charAt(i) == ' ') {
					out.print(str.charAt(i));
				} else {
					out.print(table[str.charAt(i) - 'a']);
				}
			}
			out.println();
		}
	}
	
	BufferedReader in;
	PrintWriter out;
	FastScanner sc;
	
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "", 1 << 25).start();
	}
	
	@Override
	public void run() {
		try {
			init();
			solve();
		} catch (Exception e) {
			throw new RuntimeException(e);
		} finally {
			out.close();
		}
	}
	
	void init() throws Exception {
		in = new BufferedReader(new FileReader(filename + ".in"));
		out = new PrintWriter(new FileWriter(filename + ".out"));
		sc = new FastScanner(in);
	}
}

class FastScanner {
	
	BufferedReader reader;
	StringTokenizer strTok;
	
	public FastScanner(BufferedReader reader) {
		this.reader = reader;
	}
	
	public String nextToken() throws IOException {
		while (strTok == null || !strTok.hasMoreTokens()) {
			strTok = new StringTokenizer(reader.readLine());
		}
		
		return strTok.nextToken();
	}
	
	public int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	public long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
	
	public BigInteger nextBigInteger() throws IOException {
		return new BigInteger(nextToken());
	}
	
}
