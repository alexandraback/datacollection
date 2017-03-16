import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;


public class B {
	private static int e, r, n;
	private static int data[];		

	public static void run() throws IOException {
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("out.txt")));
		BufferedReader in = new BufferedReader(new FileReader("in.txt"));
		
		
		int caseN = Integer.parseInt(in.readLine());
		for (int caseIndex = 1; caseIndex <= caseN; caseIndex++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			e = Integer.parseInt(st.nextToken());
			r = Integer.parseInt(st.nextToken());
			n = Integer.parseInt(st.nextToken());
			
			r = Math.min(e, r);
			
			data = new int[n];
			String[] line = in.readLine().split(" ");
			for (int i = 0; i < line.length; i++) {
				data[i] = Integer.parseInt(line[i]);
			}
			out.println("Case #" + caseIndex + ": " + solve());
		}
		in.close();
		out.close();
	}
	
	private static int solve() {
		int current[] = new int[e + 1];
		int next[] = new int[e + 1];
		Arrays.copyOf(current, 0);
		current[e] = 0;
		
		for (int taskIndex = 0; taskIndex < n; taskIndex++) {
			next = current.clone();
			for (int from = 0; from <= e; from++) {
				for (int to = 0; to <= from; to++) {
					int nextE = Math.min(e, to + r);
					next[nextE] = Math.max(next[nextE], current[from] + data[taskIndex] * (from - to));
				}
			}
			current = next;
		}
		return next[r];
	}
}
