import java.util.Arrays;
import java.util.Scanner;


class ProblemB {
	public static class Pair implements Comparable<Pair> {
		int cost, level;
		
		public Pair(int cost, int level) {
			this.cost = cost;
			this.level = level;
		}
		
		public int compareTo(Pair p) {
			return this.cost - p.cost;
		}
		
		public String toString() {
			return "cost = " + cost + "; level = " + level;
		}
	}
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int I = 1; I <= T; ++I) {
			int N = in.nextInt();
			Pair[] ones = new Pair[N], twos = new Pair[N];
			
			for (int i = 0; i < N; ++i) {
				ones[i] = (new Pair(in.nextInt(), i));
				twos[i] = (new Pair(in.nextInt(), i));
			}
			
			//Arrays.sort(ones);
			Arrays.sort(twos);
			
			int currStars = 0;
			int[] done = new int[N];
			int numDone = 0;
			boolean possible = true;
			int startOnes = N-1, startTwos = 0;
			int runs = 0;

			while (currStars < 2*N) {
				//Check all 2s
				for (int i = startTwos; i < N; ++i) {
					if (twos[i].cost <= currStars) {
						currStars += 2 - done[twos[i].level];
						done[twos[i].level] = 2;
						++numDone;
						++startTwos;
						++runs;
					}
					else {
						break;
					}
				}
				if (currStars == 2*N)
					break;
				
				int i;
				for (i = N-1; i >= 0; --i) {
					if (done[ones[twos[i].level].level] == 0 && ones[twos[i].level].cost <= currStars) {
						currStars++;
						++runs;
						done[ones[twos[i].level].level] = 1;
						break;
					}
				}
				if (i < 0) {
					possible = false;
					break;
				}
			}
			
			if (!possible) {
				System.out.printf("Case #%d: Too Bad\n", I);
			}
			else {
				System.out.printf("Case #%d: %d\n", I, runs);
			}
		}
	}
}
