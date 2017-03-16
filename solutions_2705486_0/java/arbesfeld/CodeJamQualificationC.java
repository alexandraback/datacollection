import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;

public class CodeJamQualificationC 
{
	static int distance(String s1, String s2) {
		int prevDiff = -10;
		int count = 0;
		for(int i = 0; i < s1.length(); i++) {
			if(s1.charAt(i) != s2.charAt(i)) {
				if(i - prevDiff < 5) {
					return -1;
				}
				count++;
				prevDiff = i;
			}
		}
		return count;
	}
	private static void solve() throws IOException {
		int T = nextInt();
		int INF = 1000000;
		BufferedReader bd = new BufferedReader(new FileReader("dictionary.txt"));
		HashSet<String>[] dict = new HashSet[11];
		for(int i = 0; i < 11; i++) {
			dict[i] = new HashSet<String>();
		}

		String line = bd.readLine();
		while(line != null) {
			dict[line.length()].add(line);
			line = bd.readLine();
		}
		for(int t = 1; t <= T; t++) {
			String s = nextToken();
			int l = s.length();
			// cost to finish i letters of the word
			int[] dist = new int[l+1];
			Arrays.fill(dist, INF);
			dist[0] = 0;
			for(int i = 0; i < l; i++) {
				for(int j = Math.max(-1, i - 10); j < i; j++) {
					if(dist[j+1] == INF)
						continue;
					
					int newWordLength = i - j;
					String newWord = s.substring(j+1, i+1);
					int bestDiff = INF;
					Iterator<String> it = dict[newWordLength].iterator();
					while(it.hasNext()) {
						String dictWord = it.next();
						int diff = distance(newWord, dictWord);
						if(diff != -1) {
							bestDiff = Math.min(diff, bestDiff);
						}
					}
					dist[i+1] = Math.min(dist[i+1], dist[j+1] + bestDiff);
				}
			}
			int res = dist[l];
			out.println("Case #" + t + ": " + res);
		}
	}
	
	public static void main(String[] args) {
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter(new FileWriter("output.txt"));
			solve();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(239);
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}