

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

import com.google.common.collect.HashMultimap;
import com.google.common.collect.Maps;

// Using the Google Guava library.
public class B {
	
	private int n, x, y;
	private double p;

	public B(int n, int x, int y) {
		this.n = n;
		this.x = x;
		this.y = y;
	}

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-small-0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		B [] ba = new B[cases+1];
		int maxN = 1;
		for (int cs = 1; cs <= cases; cs++) {
			int n = in.nextInt();
			int x = in.nextInt();
			int y = in.nextInt();
			ba[cs] = new B(n, x, y);
			maxN = Math.max(n, maxN);
		}
		
		Map<HashMultimap<Integer, Integer>, Double> probs = Maps.newHashMap();
		probs.put(HashMultimap.<Integer,Integer>create(), 1.0);
//		Object [] states = new Object [101];
//		states[0] = boardProb;
		for (int t = 1; t <= maxN; t++) {
//			Map<HashMultimap<Integer, Integer>, Double> probs = (Map<HashMultimap<Integer, Integer>, Double>) states[t-1];
			Map<HashMultimap<Integer, Integer>, Double> nextProbs = Maps.newHashMap();
			for (Entry<HashMultimap<Integer, Integer>, Double> e : probs.entrySet()) {
				HashMultimap<Integer, Integer> keyCopy = HashMultimap.create(e.getKey());
				int minY = minY(keyCopy, 0);
//				if (minY == 0) {
//					keyCopy.put(0, 0);
//					nextProbs.put(keyCopy, e.getValue());
//				} else {
					assign(keyCopy, e.getValue(), nextProbs, 0, minY);
//				}
			}
			for (B b : ba) {
				if (b == null) continue;
				if (b.n == t) {
					double p = 0;
					for (Entry<HashMultimap<Integer, Integer>, Double> e : nextProbs.entrySet()) {
						if (e.getKey().containsEntry(b.x, b.y)) {
							p += e.getValue();
						}
					}
					b.p = p;
				}
			}
			probs = nextProbs;
//			System.out.println(nextProbs);
		}
		for (int cs = 1; cs <= cases; cs++) {
//			int n = in.nextInt();
//			int x = in.nextInt();
//			int y = in.nextInt();
//			Map<HashMultimap<Integer, Integer>, Double> probs = (Map<HashMultimap<Integer, Integer>, Double>) states[n];
//			double p = 0;
//			for (Entry<HashMultimap<Integer, Integer>, Double> e : probs.entrySet()) {
//				if (e.getKey().containsEntry(x, y)) {
//					p += e.getValue();
//				}
//			}
			String caseAns = "Case #"+cs+": "+ba[cs].p;
			out.println(caseAns);
			System.out.println(caseAns);
		}
		out.close();
	}
	
	private static void assign(HashMultimap<Integer, Integer> state, double prob,
			Map<HashMultimap<Integer, Integer>, Double> nextProbs, int x, int y) {
		int cy = y-1;
		int lx = x-1;
		int rx = x+1;
		boolean containsLeft = state.containsEntry(lx, cy);
		boolean containsRight = state.containsEntry(rx, cy);
		if (y == 0 || (containsLeft && containsRight)) {
			state.put(x, y);
			Double lastProb = nextProbs.get(state);
			if (lastProb == null) {
				lastProb = 0.0;
			}
			nextProbs.put(state, lastProb + prob);
		} else if (containsLeft && !containsRight) {
			assign(state, prob, nextProbs, rx, cy);
		} else if (!containsLeft && containsRight) {
			assign(state, prob, nextProbs, lx, cy);
		} else {
			assign(HashMultimap.create(state), prob/2, nextProbs, rx, cy);
			assign(HashMultimap.create(state), prob/2, nextProbs, lx, cy);
		}
	}
	
	private static int minY(HashMultimap<Integer, Integer> m, int x) {
		for (int y = 0; ; y += 2) {
			if (!m.containsEntry(x, y)) {
				return y;
			}
		}
	}
	
}
