import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Round1C2013A {

	private static BufferedReader in;
	private static PrintWriter out;
	private static StringTokenizer input;

	public static void main(String[] args) throws IOException {
		// Initializing ...
		new Round1C2013A();
		// -------------------------------------------------------------------------
		int testCases = nextInt();
		int counter = 0;
		while (testCases-- > 0) {
			counter++;
			// Here put the code..:)
			char[] s = nextString().toCharArray();
			int n = nextInt();
			int count = 0;
			int[] valids = new int[s.length + 10];
			int index = 0;
			for (int i = 0; i < s.length; i++) {
				if (isv(s[i])) {
					count = 0;
				} else {
					count++;
				}
				if (count >= n) {// valid seq
					valids[index++] = i - n+1;
				}
			}
			long c = 0l;
			if(index!=0)
			for (int i = 0; i < s.length; i++) {
				if (valids[index - 1] < i)
					break;
				int start = 0;
				int end = index - 1;
				int itr = 25;
				if(valids[start]>=i)end=start;
				while (itr-- > 0) {
					int mid = (start + end) / 2;
					if (valids[mid] >= i)
						end = mid;
					else
						start = mid;
				}
				c += (s.length) - (valids[end] + n -1);
			}
			writeln("Case #" + counter + ": " + c);
		}
		// -------------------------------------------------------------------------
		// closing up
		end();
		// --------------------------------------------------------------------------

	}

	private static boolean isv(char c) {
		// TODO Auto-generated method stub
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}

	public Round1C2013A() throws IOException {
		// Input Output for Console to be used for trying the test samples of
		// the problem
		in = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		// -------------------------------------------------------------------------
		// Input Output for File to be used for solving the small and large test
		// files
		// in = new BufferedReader(new FileReader("Round1C2013A.in"));
		out = new PrintWriter("Round1C2013A.out");
		// -------------------------------------------------------------------------
		// Initalize Stringtokenizer input
		input = new StringTokenizer(in.readLine());
	}

	private static int nextInt() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Integer.parseInt(input.nextToken());
	}

	private static long nextLong() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Long.parseLong(input.nextToken());
	}

	private static double nextDouble() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return Double.parseDouble(input.nextToken());
	}

	private static String nextString() throws IOException {
		if (!input.hasMoreTokens())
			input = new StringTokenizer(in.readLine());
		return input.nextToken();
	}

	private static void write(String output) {
		out.write(output);
		out.flush();
	}

	private static void writeln(String output) {
		out.write(output + "\n");
		out.flush();
	}

	private static void end() throws IOException {
		in.close();
		out.close();
		System.exit(0);
	}

}
