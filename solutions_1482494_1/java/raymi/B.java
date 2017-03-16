import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;


public class B {
	
	private static class Level {
		public int index;
		public int oneStar;
		public int twoStar;
		public boolean oneStarCompleted;
		
	}

	public static void main(String[] args) {
		try {
			// so eclipse can read file from system in
			System.setIn(new FileInputStream(new File("large.in")));
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(1);
		}
		Scanner scanner = new Scanner(System.in);
		long T = scanner.nextLong();
		scanner.nextLine();
		for (int i = 0; i < T; i++) {
			int N = scanner.nextInt();
			scanner.nextLine();
			List<Level> levels = new ArrayList<Level>();
			Map<Integer, List<Level>> oneStars = new HashMap<Integer, List<Level>>();
			Map<Integer, List<Level>> twoStars = new HashMap<Integer, List<Level>>();
			for (int j = 0; j < N; j++) {
				Level l = new Level();
				l.index = j;
				l.oneStar = scanner.nextInt();
				
				{
					for (int k = l.oneStar; k <= 2*N; k++) {
						List<Level> os = oneStars.get(k);
						if (os == null) {
							os = new ArrayList<Level>();
							oneStars.put(k, os);
						}
						os.add(l);
					}
				}
				l.twoStar = scanner.nextInt();
				{
					for (int k = l.twoStar; k <= 2 * N; k++) {
						List<Level> os = twoStars.get(k);
						if (os == null) {
							os = new ArrayList<Level>();
							twoStars.put(k, os);
						}
						os.add(l);
					}
				}
				levels.add(l);
				if (scanner.hasNext()) {
					scanner.nextLine();
				}
			}
			int stars = 0;
			long played = 0;
			while (true) {
				boolean p = false;
				for (int k = stars; k >= 0; k--) {						
					List<Level> t = twoStars.get(k);
					
					if (t != null && t.size() > 0) {
						Level l = t.get(0);
						play(l, levels, oneStars, twoStars, false);
						played++;
						p = true;
						if (l.oneStarCompleted) {
							stars = stars + 1;
							//System.out.println(l.index + " only get one star");
						} else {
							stars = stars + 2;
							//System.out.println(l.index + " play for two star");
						}
					}
					if (p) break;
				}
				if (!p) {
					Level l = null;
					for (int k = stars; k >= 0; k--) {
						List<Level> o  = oneStars.get(k);
						if (o != null && o.size() > 0) {
							for (Level ol : o) {
								if (l == null || (l != null && ol.twoStar > l.twoStar)) {
									l = ol;
								}
							}							
						}
					}
					if (l != null) {
						played++;
						l.oneStarCompleted = true;
						play(l, levels, oneStars, twoStars, true);
						//System.out.println(l.index + " play for one star");
						stars = stars + 1;
						p = true;
					}
				}
				if (levels.size() == 0) {
					System.out.printf("Case #%d: %d%n", i + 1, played);
					break;
				}
				if (!p) {
					System.out.printf("Case #%d: Too Bad%n", i + 1);
					break;
				}
			}
		}

	}
	
	private static void play(Level l, List<Level> levels, Map<Integer, List<Level>> oneStars, Map<Integer, List<Level>> twoStars, boolean oneStar) {
		if (!oneStar) levels.remove(l);
		for (List<Level> li : oneStars.values()) {
			li.remove(l);
		}
		if (!oneStar) {
			for (List<Level> li : twoStars.values()) {
				li.remove(l);
			}
		}
	}

}
