package round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.Queue;

import com.google.common.collect.Iterables;

public class KingdomRush {
	
	public static int min;
	
	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader reader = new BufferedReader(new FileReader("B-small-attempt0.in"));
		
		int n = Integer.parseInt(reader.readLine());
		
		for (int i = 1; i <= n; i++) {
			System.out.println("Case #" + i + ": " + new KingdomRush().kingdom_rush(reader));
		}
	}

	private String kingdom_rush(BufferedReader reader) throws NumberFormatException, IOException {
		int levels = Integer.parseInt(reader.readLine());
		
		int[][] reqs = new int[levels][];
		boolean fine = false;
		for (int i = 0; i < levels; i++) {
			String[] split = reader.readLine().split(" ");
			reqs[i] = new int[] {Integer.parseInt(split[0]), Integer.parseInt(split[1])};
			if (reqs[i][0] == 0 || reqs[i][1] == 0)
				fine = true;
		}
		
		if (!fine)
			return "Too Bad";
		
		boolean[] done = new boolean[levels];
		min = Integer.MAX_VALUE;
		int n = go(reqs, done, 0, 0);
		return "" + n;
	}
	
	private int go(int[][] reqs, boolean[] done, int n, int s) {
		boolean twos = false;
		s = 0;
		n = 0;
		while(!allDone(done)) {
			Level nextLvl = null;
			for (int i = 0; i < reqs.length; i++) {
				if (reqs[i][1] <= s && !done[i]) {
					nextLvl = new Level(i, 2);
					break;
				}
			}

			if (nextLvl == null && !twos) {
				for (int i = 0; i < reqs.length; i++) {
					if (reqs[i][0] <= s) {
						nextLvl = new Level(i, 1);
						break;
					}
				}
			}
			if (nextLvl == null) {
				// grind mode
				int minStars = Integer.MAX_VALUE;
				for (int k = 0; k < reqs.length; k++)
					if (reqs[k][1] > s && !done[k])
						minStars = Math.min(minStars, reqs[k][1]);
				
				if (twos) {
					int d = (minStars - s + 1) / 2;
					n += d;
					s += 2 * d; 
				}
				else {
					n += minStars - s;
					s += minStars - s;
				}
			}
			else {
				n++;
				s += nextLvl.stars;
				if (nextLvl.stars == 2)
					done[nextLvl.lvl] = true;
			}
		}
		return n;
	}
	
	private static boolean allDone(boolean[] done) {
		for (boolean b : done)
			if (!b)
				return false;
		return true;
	}
	
	public class Level {
		int lvl, stars;
		public Level(int l, int s) {
			lvl = l; stars = s;
		}
	}
}
