package Round1A;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class KingdomRush {
	
	static class Level implements Comparable<Level> {
		int oneStar;
		int twoStar;
		int id;
		
		public Level(int oneStar, int twoStar, int id) {
			this.oneStar = oneStar;
			this.twoStar = twoStar;
			this.id = id;
		}
		
		public int compareTo(Level o) {
			if(oneStar == o.oneStar) return twoStar - o.twoStar;
			return oneStar - o.oneStar;
		}
		
		public String toString() {
			return "[" + oneStar + "," + twoStar + "]";
		}
	}
	
	public static Level[] levels;
	public static int N;
	public static boolean[] oneStarTaken;
	public static boolean[] twoStarTaken;
	public static int actStars;	
	
	public static void main(String[] args) throws Exception {
		System.setIn(new FileInputStream("kingdomrush.in"));
		System.setOut(new PrintStream("kingdomrush.out"));
		
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(bf.readLine().trim());
		for(int t = 1; t <= T; t++) {
			N = Integer.parseInt(bf.readLine().trim());
			levels = new Level[N];
			
			for(int i = 0; i < N; i++) {
				String[] parts = bf.readLine().trim().split("[ ]+");
				int oneStar = Integer.parseInt(parts[0]);
				int twoStar = Integer.parseInt(parts[1]);
				
				levels[i] = new Level(oneStar, twoStar, i);
			}
			Arrays.sort(levels);
			
			oneStarTaken = new boolean[N];
			twoStarTaken = new boolean[N];
			int levelsPlayed = 0;
			actStars = 0;
			
			for(int i = 0; i < N + 1; i++) {
				boolean incremented = true;
				while(incremented) {
					incremented = false;
					for(int j = 0; j < N; j++) {
						if(twoStarTaken[j]) continue;
						if(actStars >= levels[j].twoStar) {
							if(oneStarTaken[j]) actStars++;
							else actStars += 2;
							
							oneStarTaken[j] = true;
							twoStarTaken[j] = true;
							levelsPlayed++;
							incremented = true;
						}
					}
				}
				
				for(int j = N - 1; j >= 0; j--) {
					if(oneStarTaken[j]) continue;
					if(actStars >= levels[j].oneStar) {
						oneStarTaken[j] = true;
						actStars++;
						levelsPlayed++;
						break;
					}
				}
			}
			
			int twoStarCount = 0;
			for(int i = 0; i < N; i++) if(twoStarTaken[i]) twoStarCount++;
			
			if(twoStarCount < N)
				System.out.println("Case #" + t + ": Too Bad");
			else
				System.out.println("Case #" + t + ": " + levelsPlayed);
		}
	}
	
}
