package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ProbB {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileInputStream(args[0]));
		PrintStream out = new PrintStream(args[1]);
		//PrintStream out = System.out;
		int numT = scanner.nextInt();
		for(int T=1; T<=numT; T++) {
			int E = scanner.nextInt();
			int R = scanner.nextInt();
			int N = scanner.nextInt();
			
			//System.out.println(String.format("Case %d E %d R %d N %d", T, E, R, N));
			
			LinkedList<Long> v = new LinkedList<Long>();
			for(int i=0; i<N; i++) v.add(scanner.nextLong());
			//System.out.println(v);
			
			// easy case, if E <= R we spend max amount on all
			long gain = 0;
			if(E <= R) {
				for(int i=0; i<N; i++) gain += v.poll()*E;
				out.format("Case #%d: %d\n", T, gain);
				continue;
			}
			
			// slow solution
			gain = dfs(E, E, R, v);
			
			
			out.format("Case #%d: %d\n", T, gain);
		}
		scanner.close();
		out.close();
	}

	private static long dfs(int E, int maxE, int R, LinkedList<Long> v) {
		if(E < 0) throw new RuntimeException("E < 0");
		if(E < R) throw new RuntimeException("E < R");
		if(v.size() == 0) throw new RuntimeException("v size is 0");
		if(v.size() == 1) return E * v.peek();
		
		long maxGain = 0;
		long value = v.poll();
		for(int spend = 0; spend <= E; spend++) {
			int nextE = E-spend+R;
			if(nextE > maxE) nextE = maxE;
			long gain = (value * spend) + dfs(nextE, maxE, R,v);
			if(gain > maxGain) { maxGain = gain; }
		}
		v.addFirst(value);
		
		return maxGain;
	}

}
