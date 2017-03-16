

import java.util.*;
import java.io.*;

public class Treasure {
	
	static int N;
	static int[] cntKeys;
	static boolean[] used;
	static LinkedList<Integer>[] chests, keys;
	
	public static void main(String[] args) {
		Kattio io = new Kattio(System.in);
		
		int tests = io.getInt();
		for (int test = 1; test <= tests; test++) {
			int K = io.getInt();
			N = io.getInt();
			chests = new LinkedList[200];
			keys = new LinkedList[N];
			cntKeys = new int[200];
			for (int i = 0; i < 200; i++) chests[i] = new LinkedList<Integer>();
			for (int i = 0; i < N; i++) keys[i] = new LinkedList<Integer>();
			for (int i = 0; i < K; i++) cntKeys[io.getInt() - 1]++;
			for (int i = 0; i < N; i++) {
				int T = io.getInt();
				int Ki = io.getInt();
				chests[T - 1].add(i);
				for (int j = 0; j < Ki; j++) {
					keys[i].add(io.getInt() - 1);
				}
			}
			used = new boolean[N];
			int opened = 0;
			int[] res = new int[N];
			while (true) {
				int bestChest = -1;
				int keyType = -1;
				for (int key = 0; key < 200; key++) {
					if (cntKeys[key] > 0) {
						int chestsLeft = 0;
						for (int chest : chests[key]) {
							if (!used[chest]) {
								chestsLeft++;
							}
						}
						for (int chest : chests[key]) {
							if (!used[chest]) {
								if (cntKeys[key] > 1 || chestsLeft == 1 || dfs(chest, key, new boolean[N])) {
									if (bestChest == -1 || bestChest > chest) {
										bestChest = chest;
										keyType = key;
									}
								}
							}
						}
					}
				}
				if (bestChest == -1) {
					break;
				} else {
					cntKeys[keyType]--;
					used[bestChest] = true;
					for (int key : keys[bestChest]) {
						cntKeys[key]++;
					}
					res[opened++] = bestChest + 1;
				}
			}
			io.print("Case #" + test + ":");
			if (opened < N) {
				io.println(" IMPOSSIBLE");
			} else {
				for (int i = 0; i < N; i++) {
					io.print(" " + res[i]);
				}
				io.println();
			}
		}
		
		io.close();
	}
	
	static boolean dfs(int chest, int goalKey, boolean[] visited) {
		if (visited[chest]) return false;
		visited[chest] = true;
		for (int key : keys[chest]) {
			if (key == goalKey) {
				return true;
			}
			for (int newChest : chests[key]) {
				if (!used[chest] && dfs(newChest, goalKey, visited)) return true;
			}
		}
		return false;
	}
	
	static class Kattio extends PrintWriter {
	    public Kattio(InputStream i) {
		super(new BufferedOutputStream(System.out));
		r = new BufferedReader(new InputStreamReader(i));
	    }
	    public Kattio(InputStream i, OutputStream o) {
		super(new BufferedOutputStream(o));
		r = new BufferedReader(new InputStreamReader(i));
	    }

	    public boolean hasMoreTokens() {
		return peekToken() != null;
	    }

	    public int getInt() {
		return Integer.parseInt(nextToken());
	    }

	    public double getDouble() { 
		return Double.parseDouble(nextToken());
	    }

	    public long getLong() {
		return Long.parseLong(nextToken());
	    }

	    public String getWord() {
		return nextToken();
	    }

	    private BufferedReader r;
	    private String line;
	    private StringTokenizer st;
	    private String token;

	    private String peekToken() {
		if (token == null) 
		    try {
			while (st == null || !st.hasMoreTokens()) {
			    line = r.readLine();
			    if (line == null) return null;
			    st = new StringTokenizer(line);
			}
			token = st.nextToken();
		    } catch (IOException e) { }
		return token;
	    }

	    private String nextToken() {
		String ans = peekToken();
		token = null;
		return ans;
	    }
	}
}
