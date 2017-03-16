import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class CounterCulture {
	public static void main(String[] args) throws IOException {
		String[] input;
		if (args.length > 0) { input = args; }
		else {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String x = null;
			int size = Integer.parseInt(in.readLine());
			input = new String[size];
			for (int i=0; i<size; i++) {
				input[i] = in.readLine();
			}
		}
		solve(input);
	}
	
	public static void solve(String[] input) {
		int counter = 1;
		int value;
		for (String s: input) {
			value = Integer.parseInt(s); 
			System.out.println("Case #" + counter + ": " + shortestPath(value, 0));
			counter++;
		}
	}
	
	public static int shortestPath(int dest, int depth) {
		if (dest == 1) { return depth+1; }
		int rev = reverseInt(dest);
		if (reverseInt(rev) == dest && rev < dest-1) { return shortestPath(rev, depth+1); }
		return shortestPath(dest-1, depth+1);
	}
	
	public static int reverseInt(int n) {
		String s = "" + n;
		String r = "";
		for (int i=s.length()-1; i>=0; i--) {
			r += s.charAt(i);
		}
		return Integer.parseInt(r);
	}
}