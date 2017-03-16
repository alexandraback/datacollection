import java.io.*;
import java.util.*;


public class D {
	
	static Scanner in;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = new FileInputStream(new File("src/D-large.in"));
		PrintStream output = new PrintStream(new File("src/D-large.out"));
		in = new Scanner(input);
		out = new PrintWriter(output);
		solveMultiTest();
		out.close();
	}
	
	static void solveMultiTest() throws IOException {
		int T = in.nextInt();
		for (int testCase = 1; testCase <= T; testCase++) {
			out.println("Case #" + testCase + ": " + solveOneTest());
		}
	}
	
	static String solveOneTest() {
		int N = in.nextInt();
		ArrayList<Double> n = new ArrayList<Double>();
		ArrayList<Double> k = new ArrayList<Double>();
		for (int i = 0; i < N; i++) {
			n.add(in.nextDouble());
		}		
		for (int i = 0; i < N; i++) {
			k.add(in.nextDouble());
		}		
		
		
		int y = 0;
		int z = 0;
		
		Collections.sort(n);
		Collections.sort(k);
		
		//System.out.println(n);
		//System.out.println(k);
		//System.out.println();
		
		ArrayList<Double> k1 = new ArrayList<Double>(k);
		for (double nc : n) {
			double best = Double.MAX_VALUE; 
			for (double kk : k1) {
				if (kk > nc && kk < best) {
					best = kk;
				}
			}
			if (best == Double.MAX_VALUE) {
				z += 1;
				best = Collections.min(k1);
			}
			k1.remove(best);
		}
		
		int skip = 0;
		while(skip < N && n.get(N - 1) < k.get(N - skip - 1)) {
			skip += 1;
		}
		for (int i = 0; i < skip; i++) {
			n.remove(0);
			k.remove(N - i - 1);
		}
		//System.out.println(n);
		//System.out.println(k);
		//System.out.println();
		
		for (double kc : k) {
			double best = Double.MAX_VALUE; 
			for (double nn : n) {
				if (nn > kc && nn < best) {
					best = nn;
				}
			}
			if (best == Double.MAX_VALUE) {
				best = Collections.min(n);
			} else {
				y += 1;
			}
			n.remove(best);
		}
		//System.out.println(y + " " + z);
		//System.out.println("----------------------------------------------------------");
		
		return y + " " + z;
	}
	
}
