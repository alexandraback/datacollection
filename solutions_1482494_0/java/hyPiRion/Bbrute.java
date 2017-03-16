import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Bbrute {
	static BufferedReader stdin = new BufferedReader(
						new InputStreamReader(System.in));
	static StringTokenizer st = new StringTokenizer("");

	public static void main(String[] args) throws Exception {
		int T = readInt();
		for (int t = 1; t <= T; t++){
			int N = readInt();
			LinkedList<Level> lvls = new LinkedList<Bbrute.Level>();
			for (int i = 0; i < N; i++)
				lvls.add(new Level(readInt(), readInt()));
			int steps = min_dfs(lvls, 0, 0);
			if (steps == Integer.MAX_VALUE)
				System.out.format("Case #%d: Too Bad\n", t);
			else
				System.out.format("Case #%d: %d\n", t, steps);
		}
	}
	
	static int min_dfs (LinkedList<Level> lvls, int steps, int stars){
		if (lvls.isEmpty())
			return steps;
		int min = Integer.MAX_VALUE;
		for (Level lvl : lvls) {
			if (lvl.two <= stars){
				LinkedList<Level> n_lvls = deep_cpy(lvls);
				n_lvls.remove(lvl);
				int res = min_dfs(n_lvls, steps+1, stars + 2 - lvl.stars_gained);
				if (res < min)
					return res;
			}
			else if (lvl.stars_gained < 1 && lvl.one <= stars){
				LinkedList<Level> n_lvls = deep_cpy(lvls);
				for (Level lvl_cpy : n_lvls)
					if (lvl.eq(lvl_cpy)){
						lvl_cpy.stars_gained++;
						break;
					}
				int res = min_dfs(n_lvls, steps+1, stars+1);
				if (res < min)
					return res;
			}
		}
		return min;
	}
	
	static LinkedList<Level> deep_cpy(LinkedList<Level> lvls){
		LinkedList<Level> clone = new LinkedList<Bbrute.Level>();
		for (Level lvl : lvls)
			clone.add(lvl);
		return clone;
	}
	
	static class Level {
		public final int one, two;
		public int stars_gained;
		public Level(int one, int two){
			this.one = one;
			this.two = two;
			stars_gained = 0;
		}
		public String toString(){
			return String.format("<%d, %d>", one, two);
		}
		public Level copy(){
			Level l = new Level(one, two);
			l.stars_gained = stars_gained;
			return l;
		}
		public boolean eq(Level other){
			return (one == other.one && two == other.two && stars_gained == other.stars_gained);
		}
	}

	static String readString() throws Exception {
		while (!st.hasMoreTokens()) {
			st = new StringTokenizer(stdin.readLine());
		}
		return st.nextToken();
	}

	static int readInt() throws Exception {
		return Integer.parseInt(readString());
	}

	static double readDouble() throws Exception {
		return Double.parseDouble(readString());
	}
}
