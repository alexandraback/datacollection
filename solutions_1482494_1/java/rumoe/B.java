package round1Aj2012;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class B {

	private final String f = "src\\round1Aj2012\\B-large";
	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer token;
		
	private B() throws IOException {
		in = new BufferedReader(new FileReader(f+".in"));
		out = new PrintWriter(f + ".out");
		eat("");
		
		int tests = nextInt();
		for (int i = 1; i <= tests; i++) {
			if(i == 98) {
				System.out.println("etset");
			}
			write("Case #" + i + ": ");
			solve();
		}
		
		in.close();
		out.close();
	}
	
	private void solve() throws IOException {
		int n = nextInt();
		
		ArrayList<Integer[]> level = new ArrayList<Integer[]>();
		for (int i = 0; i < n; i++) {
			level.add(new Integer[]{nextInt(),nextInt()});
			
		}
		
		int plays = 0;
		int stars = 0;
		
		outer:
		while(level.size() > 0) {
			for(int i = 0; i < level.size(); i++) {
				if (level.get(i)[1] <= stars && level.get(i)[0] >= 0) {
					stars += 2;
					level.remove(i);
					plays++;
					continue outer;
				}
			}
			
			for(int i = 0; i < level.size(); i++) {
				if (level.get(i)[1] <= stars && level.get(i)[0] < 0) {
					stars += 1;
					level.remove(i);
					plays++;
					continue outer;
				}
			}
			
			
			int max2StarCapIndex = -1;
			int max2StarCap = -1;
			for(int i = 0; i < level.size(); i++) {
				if (level.get(i)[0] <= stars && level.get(i)[0] >= 0) {
					if (max2StarCap < level.get(i)[1]) {
						max2StarCap = level.get(i)[1];
						max2StarCapIndex = i;
					}
				}
			}
			
			if (max2StarCapIndex >= 0) {
				Integer[] element = level.get(max2StarCapIndex);
				element[0] = -1;
				stars += 1;
				level.set(max2StarCapIndex, element);
				plays++;
				continue;
			}
			
			write("Too Bad\n");
			return;
		}
		
		write(plays + "\n");
	}

	private void printArray(char[][] c) {
		for (char[] i : c) {
			System.out.println(i);
		}
	}
	
	private String next() throws IOException {
		while (!token.hasMoreTokens()) {
			String line = in.readLine();
			if (line == null) {
				return null;
			}
			eat(line);
		}
		return token.nextToken();
	}
		
	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}
	
	private long nextLong() throws IOException {
		return  Long.parseLong(next());
	}
	
	private void eat(String s) {
		token = new StringTokenizer(s);
	}

	private void write(String s) {
		System.out.print(s);
		out.print(s);
	}
	
	public static void main(String[] args) {
		try {
			new B();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
