import java.util.Scanner;
import java.util.HashMap;
import java.util.TreeSet;
import java.util.Comparator;

public class AttemptTwo {

	boolean DEBUG = true;
	static TreeSet<Combo> combinations;
	static HashMap<Combination, Integer> mini_combinations = new HashMap<Combination, Integer>();

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int t = 0; t < tests; ++t) {
			int j = sc.nextInt(),
				p = sc.nextInt(),
				s = sc.nextInt(),
				k = sc.nextInt();


			//JP = 0, JS = 1, PS = 2
			for(int x = 1; x <= j; ++x) {
				for(int y = 1; y <= p; ++y) {
					Combination comb = new Combination(x, y, 0);
					mini_combinations.put(comb, 0);
				}
				for(int z = 1; z <= s; ++z) {
					Combination comb = new Combination(x, z, 5);
					mini_combinations.put(comb, 0);
				}
			}
			for(int y = 1; y <= p; ++y) {
				for(int z = 1; z <= s; ++z){
					Combination comb = new Combination(y, z, 10);
					mini_combinations.put(comb, 0);
				}
			}

			combinations = new TreeSet<Combo>(new JSPComparator());
			for(int x = 1; x <= j; ++x) {
				for(int y = 1; y <= p; ++y) {
					for(int z = 1; z <= s; ++z) {
						Combo newComb = new Combo(x,y,z);
						Combination comb1 = new Combination(x, y, 0);
						if(mini_combinations.get(comb1) < k) {
							Combination comb2 = new Combination(x, z, 5);
							if(mini_combinations.get(comb2) < k) {
								Combination comb3 = new Combination(y, z, 10);
								if(mini_combinations.get(comb3) < k) {
									combinations.add(newComb);
									mini_combinations.put(comb1, mini_combinations.get(comb1) + 1);
									mini_combinations.put(comb2, mini_combinations.get(comb2) + 1);
									mini_combinations.put(comb3, mini_combinations.get(comb3) + 1);
								}
							}
						}
					}
				}
			}

			System.out.printf("Case #%d: %d\n", t + 1, combinations.size());
			for(Combo c : combinations) System.out.println(c);
		}
	}

	static class Combo {

		int j, p, s;

		public Combo(int j, int p, int s){
			this.j = j;
			this.p = p;
			this.s = s;
		}

		@Override
		public String toString() { return j + " " + p + " " + s; }
	}

	static class JSPComparator implements Comparator<Combo> {
		public int compare(Combo c1, Combo c2) {
			if(c1.j == c2.j && c1.p == c2.p && c1.s == c2.s) return 0;
			return -1;
		}
	}

	static class Combination {

		int x, y, combNum;

		public Combination(int x, int y, int combNum){
			this.x = x;
			this.y = y;
			this.combNum = combNum;
		}

		@Override
		public boolean equals(Object o){
			Combination comb = (Combination)o;
			return x == comb.x && y == comb.y && combNum == comb.combNum;
		}

		@Override
		public int hashCode()
		{
		    return String.format("%d %d %d", x, y, combNum).hashCode();
		}
	}

}