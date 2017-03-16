package y2012.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class Main {
	
	static class Level {
		int oneStar;
		int twoStar;
		int level;
		int earned;
	}
	
	static int solve(Level[] levels) {
		Level[] by1Star = levels.clone();
		Arrays.sort(by1Star, new Comparator<Level>() {
			@Override
			public int compare(Level o1, Level o2) {
				int c =  o1.oneStar - o2.oneStar;
				if(c != 0) return c;
				return o2.twoStar - o1.twoStar;
			}
		});
		Level[] by2Star = levels;
		Arrays.sort(by2Star, new Comparator<Level>() {
			@Override
			public int compare(Level o1, Level o2) {
				int c =  o1.twoStar - o2.twoStar;
				if(c != 0) return c;
				return o2.oneStar - o1.oneStar;
			}
		});

		int i = 0,j = 0;
		int score = 0;
		int result = 0;
		
		for(;;) {
			if(i == levels.length)
				break;
			if(by2Star[i].twoStar <= score) {
				score += (2 - by2Star[i].earned);
				by2Star[i].earned = 2;
				i++;
			} else {
				while(j < levels.length && by1Star[j].earned > 0) j++;
				if(j == levels.length || by1Star[j].oneStar > score) return -1;
				score++;
				by1Star[j].earned = 1;
				j++;
			}
			result++;
		}
		return result;
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		PrintWriter writer = new PrintWriter(args[1]);
		int testCount = Integer.valueOf(reader.readLine());
		for (int i = 0; i < testCount; i++) {
			int nlevels = Integer.valueOf(reader.readLine());
			Level[] levels = new Level[nlevels];
			for(int j = 0; j < nlevels; j++) {
				String[] fields = reader.readLine().split(" ");
				Level level = new Level();
				level.oneStar = Integer.parseInt(fields[0]);
				level.twoStar = Integer.parseInt(fields[1]);
				level.level = j;
				levels[j] = level;
			}
			
			int times = solve(levels);
			String result = "Case #" + (i + 1) + ": " + (times == -1 ? "Too Bad" : ""+ times);
			writer.println(result);
		}
		writer.close();
	}
}
