import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class SpeakingInTongues {

	
	public static void main(String[] args) throws IOException {
		setStandardIO();
		setFileIO("speakingintongues");
		
		String[] taa = {"ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv", "qz"}; 
		String[] tab = {"our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up", "zq"}; 

		Map<Character, Character> map = new HashMap<Character, Character>();
		for (int i = 0; i < taa.length; i++) {
			for (int j = 0; j < taa[i].length(); ++j) {
				char c = taa[i].charAt(j);
				char d = tab[i].charAt(j);
				map.put(c, d);
			}
		}		

		readLine();
		int T = nextInt();
		for (int t = 1; t <= T; ++t) {
			String s = in.readLine();
			print("Case #"+t+": ");
			for (int i = 0; i < s.length(); ++i)
				print(map.get(s.charAt(i)));
			println("");				
		}
		
		flush();
	}

	//~ ----------------------------------------------------------------------------------------------------------------
	//~ - Auxiliary code -----------------------------------------------------------------------------------------------	
	//~ ----------------------------------------------------------------------------------------------------------------
	static BufferedReader in;
	static PrintWriter out;
	static StringTokenizer st;

	private static void setStandardIO() {
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
	}

	private static void setFileIO(String fileName) throws FileNotFoundException, IOException {
		in = new BufferedReader(new FileReader(fileName + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(fileName + ".out")));
	}

	public static void readLine() throws IOException {
		st = new StringTokenizer(in.readLine());
	}

	public static int nextInt() {
		return Integer.parseInt(st.nextToken());
	}

	public static long nextLong() {
		return Long.parseLong(st.nextToken());
	}
	
	public static String nextString() {
		return st.nextToken();
	}

	public static List<String> nextStrings() {
		List<String> strings = new ArrayList<String>();
		while (st.hasMoreTokens())
			strings.add(st.nextToken());		
		
		return strings;
	}
	
	public static void flush() {
		out.flush();
	}
	
	public static void println(Object object) {
		out.println(object);
	}
	
	public static void print(Object object) {
		out.print(object);
	}

	public static long gcd(long a, long b) {
		if (b == 0) return a;
		return gcd(b, a % b);
	}
	
	public static class Pair {
		public long x, y;
		public Pair(long x, long y) {
			this.x = x;
			this.y = y;
		}
		@Override
		public String toString() {
			return "Pair [x=" + x + ", y=" + y + "]";
		}
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + (int) (x ^ (x >>> 32));
			result = prime * result + (int) (y ^ (y >>> 32));
			return result;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
		}		
	}
}
