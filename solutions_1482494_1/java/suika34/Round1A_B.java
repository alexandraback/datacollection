import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;


public class Round1A_B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Round1A_B main = new Round1A_B();
		try {
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
			String line = bf.readLine();
			int T = Integer.parseInt(line);
			for (int testcaseIndex=0; testcaseIndex<T; testcaseIndex++) {
				String testCase = bf.readLine();
				int N = Integer.parseInt(testCase);
				Level[] levels = new Level[N];
				for (int i=0; i<N; i++) {
					testCase = bf.readLine();
					String[] array = testCase.split(" ");
					int a = Integer.parseInt(array[0]);
					int b = Integer.parseInt(array[1]);
					levels[i] = new Level(a, b, 0);
				}
				int out = main.solve(N, levels);
				if (out != -1) {
					System.out.print("Case #"+(testcaseIndex+1)+": ");
					System.out.println(out);
				} else {
					System.out.println("Case #"+(testcaseIndex+1)+": Too Bad");
				}
				
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private int solve(int N, Level[] levels) {
		int ret = 0;
		int star = 0;
		Arrays.sort(levels, new Comparator<Level>() {
			@Override
			public int compare(Level o1, Level o2) {
				return o1.two - o2.two;
			}
		});
		Level[] twostar = Arrays.copyOf(levels, levels.length);
		Arrays.sort(levels, new Comparator<Level>() {
			@Override
			public int compare(Level o1, Level o2) {
				return o2.two - o1.two;
			}
		});
		Level[] onestar = Arrays.copyOf(levels, levels.length);
		
		int twoIndex = 0;
		while (true) {
			while (twoIndex < N) {
				Level level = twostar[twoIndex];
				if (star >= level.two) {
					star += (2 - level.clear);
					level.clear = 2;
					ret++;
					//System.out.println("two "+twoIndex +" star="+star);
					twoIndex++;
				} else {
					break;
				}
			}

			boolean end = true;
			for (int i=0; i<N; i++) {
				if (levels[i].clear < 2) {
					end = false;
					break;
				}
			}
			if (end) {
				break;
			}

			boolean bad = true;
			for (int oneIndex = 0; oneIndex<N; oneIndex++) {
				Level level = onestar[oneIndex];
				if (star >= level.one && level.clear == 0) {
					star += 1;
					level.clear = 1;
					ret++;
					bad = false;
					//System.out.println("one "+oneIndex +" star="+star);
					break;
				}
			}
			
			if (bad) {
				return -1;
			}

		}
		
		return ret;
	}
	
	
	static class Level {
		int one;
		int two;
		int clear;
		
		public Level(int o, int t, int c) {
			one = o;
			two = t;
			clear = c;
		}
		
		@Override
		public String toString() {
			return ""+one+" "+two+" "+clear;
		}
	}
}
