import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Locale;
import java.util.StringTokenizer;

public class Solution implements Runnable {
	
	private static final int MINDIF = 5;
	
	private BufferedReader in;
	private StringTokenizer st;
	private PrintWriter out;
	
	private Node[] tree;
	
	private int solve(int[] a) {
		int[][] x = new int[MINDIF][a.length + 1];
		for (int i = 0; i < x.length; i++) {
			for (int j = 0; j < x[i].length; j++) {
				x[i][j] = -1;
			}
		}
		update(x, 0, 0, 0);
		int[] currentSkip = new int[MINDIF * tree.length];
		int[] currentNode = new int[MINDIF * tree.length];
		int[][] currentMin = new int[MINDIF][tree.length];
		int currentCount = 0;
		int[] nextSkip = new int[MINDIF * tree.length];
		int[] nextNode = new int[MINDIF * tree.length];
		int[][] nextMin = new int[MINDIF][tree.length];
		int nextCount = 0;
		int[][] addedStates = new int[MINDIF][tree.length];
		int mytrue = 0;
		for (int i = 0; i < a.length; i++) {
			currentCount = 0;
			for (int j = 0; j < MINDIF; j++) {
				if (x[j][i] != -1) {
					currentSkip[currentCount] = j;
					currentNode[currentCount] = 0;
					currentMin[j][0] = x[j][i];
					currentCount++;
				}
			}
			int ii = i;
			while (currentCount > 0) {
				for (int j = 0; j < currentCount; j++) {
					if (tree[currentNode[j]].acc) {
						int skip = currentSkip[j];
						int node = currentNode[j];
						int done = ii;
						update(x, skip, done, currentMin[skip][node]);
					}
					
				}
				
				if (ii == a.length) {
					break;
				}
				int c = a[ii];
				mytrue++;
				nextCount = 0;
				for (int j = 0; j < currentCount; j++) {
					Node node = tree[currentNode[j]];
					int skip = currentSkip[j];
					int min = currentMin[skip][currentNode[j]];
					if (node.children == null) {
						continue;
					}
					for (int cc = 0; cc < node.children.length; cc++) {
						int nNode = node.children[cc];
						if (nNode != -1) {
							if (c == cc) {
								int nSkip = Math.max(0, skip - 1);
								nextCount = insert(mytrue, addedStates, 
										nextSkip, nextNode, nextMin, nextCount, 
										nSkip, nNode, min);
							} else if (skip == 0) {
								int nSkip = MINDIF - 1;
								nextCount = insert(mytrue, addedStates,
										nextSkip, nextNode, nextMin, nextCount,
										nSkip, nNode, min + 1);
							}
						}
					}
				}
				
				int[] tmp = nextSkip;
				nextSkip = currentSkip;
				currentSkip = tmp;
				
				tmp = nextNode;
				nextNode = currentNode;
				currentNode = tmp;
				
				int[][] tmp2 = nextMin;
				nextMin = currentMin;
				currentMin = tmp2;
				
				currentCount = nextCount;
				
				ii++;
			}
		}
		int result = Integer.MAX_VALUE;
		for (int i = 0; i < x.length; i++) {
			if (x[i][a.length] != -1) {
				result = Math.min(result, x[i][a.length]);
			}
		}
		return result;
	}
	
	private int insert(int mytrue, int[][] addedStates, 
			int[] nextSkip, int[] nextNode, int[][] nextMin, int nextCount, 
			int nSkip, int nNode, int nMin) {
		if (addedStates[nSkip][nNode] == mytrue) {
			nextMin[nSkip][nNode] = Math.min(nextMin[nSkip][nNode], nMin);
			return nextCount;
		}
		nextSkip[nextCount] = nSkip;
		nextNode[nextCount] = nNode;
		nextMin[nSkip][nNode] = nMin;
		nextCount++;
		addedStates[nSkip][nNode] = mytrue;
		return nextCount;
	}

	private void update(int[][] x, int skip, int done, int value) {
		if (x[skip][done] == -1 || x[skip][done] > value) {
			x[skip][done] = value;
		}
	}

	private void solve() throws IOException {
		System.out.println("Started.");
		tree = buildTree("dic.txt");
		System.out.println("Loaded.");
		
		int t = nextInt();
		for (int test = 1; test <= t; test++) {
			String s = next();
			int[] a = new int[s.length()];
			for (int i = 0; i < a.length; i++) {
				a[i] = s.charAt(i) - 'a';
			}
			int answer = solve(a);
			out.println("Case #" + test + ": " + answer);
			System.out.println("Done " + test + ".");
		}
	}
	
	private Node[] buildTree(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		ArrayList<Node> result = new ArrayList<Node>();
		result.add(new Node());
		while (true) {
			String word = br.readLine();
			if (word == null) {
				break;
			}
			if (word.isEmpty()) {
				System.out.println("Botva!");
				System.exit(1);
			}
			int[] w = new int[word.length()];
			for (int i = 0; i < w.length; i++) {
				w[i] = word.charAt(i) - 'a';
			}
			addWord(result, 0, w, 0);
		}
		br.close();
		return result.toArray(new Node[result.size()]);
	}
	
	private void addWord(ArrayList<Node> result, int currentIndex, int[] w, int done) {
		if (done == w.length) {
			result.get(currentIndex).acc = true;
			return;
		}
		int c = w[done];
		Node current = result.get(currentIndex);
		if (current.children == null) {
			current.children = new int['z' - 'a' + 1];
			for (int i = 0; i < current.children.length; i++) {
				current.children[i] = -1;
			}
		}
		if (current.children[c] == -1) {
			current.children[c] = result.size();
			result.add(new Node());
		}
		addWord(result, current.children[c], w, done + 1);
	}

	@Override
	public void run() {
		try {
			solve();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		} finally {
			out.close();
		}
	}
	
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private String next() throws IOException {
		while (!st.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			st = new StringTokenizer(line);
		}
		return st.nextToken();
	}
	
	public Solution(String filename) {
		try {
			in = new BufferedReader(new FileReader(filename + ".in"));
			st = new StringTokenizer("");
			out = new PrintWriter(new FileWriter(filename + ".out"));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
	}
	
	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new Solution("data").run();
	}
	
	public static class Node {
		public boolean acc;
		public int[] children;
	}
}
