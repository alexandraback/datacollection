import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;


public class Guessing {
	private static int nextIntLine(Scanner in) {
		return Integer.parseInt(in.nextLine());
	}

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("output.out");
		f.delete();
		PrintStream out = new PrintStream(f);
//		PrintStream out = System.out;

		Scanner in = new Scanner(new File("input3.in"));
		int numCases = nextIntLine(in);
//		for(;;)System.out.println("\""+in.nextLine()+"\"");
		for(int i = 0; i < numCases; ++i) {
			out.printf("Case #%d:\n", i+1);
			getAnswer(in, out);
		}
		
		out.close();
		in.close();
	}
	
	private static HashMap<Integer,int[]> factorCache = new HashMap<Integer,int[]>();

	private static void getAnswer(Scanner in, PrintStream out) {
		int prodSetNum = in.nextInt();
		int n = in.nextInt();
		int m = in.nextInt();
		int k = in.nextInt();

		for(int i = 0; i < prodSetNum; ++i) {
			out.printf("%s\n", getGuess(in, out, n, m, k));
		}
	}

	private static String getGuess(Scanner in, PrintStream out, int n, int m, int k) {
		int[] facFreq = new int[m+1];
		for(int i = 0; i < k; ++i) {
			int num = in.nextInt();
			int[] factors = getFactors(num, m);
			for(int j = 2; j < factors.length; ++j) {
				facFreq[j] += factors[j];
			}
		}

		TreeSet<Guess> guesses = new TreeSet<Guess>();
		for(int i = 2; i < m+1; ++i) {
			guesses.add(new Guess(i, facFreq[i]));
		}
		
		StringBuilder res = new StringBuilder();
		for(int i = 0; i < n; ++i) {
			Guess g = guesses.pollLast();
			res.append(g.num);
			guesses.add(new Guess(g.num, g.occurrances - 1));
		}
		
		return res.toString();
	}

	private static int[] getFactors(int num, int m) {
		if(factorCache.containsKey(num))
			return factorCache.get(num);
		
		int f = m;
		int[] res = new int[m+1];
		while(f > 1) {
			if(num % f == 0) {
				num /= f;
				res[f]++;
			} else {
				--f;
			}
		}
		
		return res;
	}
	
	public static class Guess implements Comparable<Guess> {
		public int num;
		public int occurrances;
		public Guess(int n, int o) {
			num = n;
			occurrances = o;
		}
		@Override
		public int compareTo(Guess o) {
			return occurrances - o.occurrances;
		}
	}
}
