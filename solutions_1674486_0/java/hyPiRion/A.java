// compile and run java classname < infile > outfile

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class A {
	static BufferedReader stdin = new BufferedReader(
						new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");
	static HashSet<Integer> visited;
	static HashSet<Integer>[] clss;

	public static void main(String[] args) throws Exception {
		int T = readInt();
		for (int t = 1; t <= T; t++){
			int N = readInt();
			clss = new HashSet[N];
			for (int i = 0; i < N; i++){
				int size = readInt();
				clss[i] = new HashSet<Integer>();
				for (int j = 0; j < size; j++)
					clss[i].add(readInt()-1);
			}
			boolean diamond = false;
			for (int i = 0; i < N; i++){
				visited = new HashSet<Integer>();
				if (match(i)){
					diamond = true;
					break;
				}
			}
			
			System.out.format("Case #%d: %s\n", t, diamond ? "Yes" : "No");
		}
	}
	
	static boolean match(int start){
		if (visited.contains(start))
			return true;
		
		visited.add(start);
		boolean hit = false;
		for (int j : clss[start]){
			if (match(j)){
				hit = true;
				break;
			}
		}

		return hit;
	}

	static String readString() throws Exception {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}

	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}

	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
}
