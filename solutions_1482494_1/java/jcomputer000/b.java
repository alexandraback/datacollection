import java.util.*;
import java.io.*;
public class b {
	class Pair implements Comparable<Pair> {
		int level;
		int cost;
		Pair(int l, int c) {
			level = l;
			cost = c;
		}
		public int compareTo(Pair p) {
			return cost - p.cost;
		}
	}
	b(Scanner in, PrintStream out) {
		int T = in.nextInt();
		for (int t=0; t<T; t++) {
			int N = in.nextInt();
			PriorityQueue<Pair> oneStar = new PriorityQueue<Pair>();
			PriorityQueue<Pair> oneStarB = new PriorityQueue<Pair>();
			PriorityQueue<Pair> twoStar = new PriorityQueue<Pair>();
			int[] twoStarCost = new int[N];
			int[] completed = new int[N];
			int done = 0;
			for (int i=0; i<N; i++) {
				oneStar.add(new Pair(i,in.nextInt()));
				int tmp = in.nextInt();
				twoStar.add(new Pair(i,tmp));
				twoStarCost[i] = tmp;
			}
			
			int curStars = 0;
			boolean fail = false;
			int turns = 0;
			while(done < N) {
				int changes = 0;
				while(!twoStar.isEmpty() && twoStar.peek().cost <= curStars) {
					int level = twoStar.poll().level;
//					System.out.println(level + " - 2");
					curStars += 2-completed[level];
					completed[level] = 2;
					done++;
					changes++;
					turns++;
				}
				while(!oneStar.isEmpty() && oneStar.peek().cost <= curStars) {
					int level = oneStar.poll().level;
					if (completed[level] < 2)
						oneStarB.add(new Pair(level,-twoStarCost[level]));
				}
				while(!oneStarB.isEmpty() && completed[oneStarB.peek().level] == 2)
					oneStarB.poll();
				if (!oneStarB.isEmpty()) {
					int level = oneStarB.poll().level;
//					System.out.println(level + " - 1");
					curStars += 1;
					completed[level] = 1;
					changes++;
					turns++;
				}
				if (changes == 0) {
					fail = true;
					break;
				}
			}
			out.printf("Case #%d: ",t+1);
			if (fail)
				out.println("Too Bad");
			else
				out.println(turns);
		}
	}
	public static void main(String[] args) throws Exception {
//		new b(new Scanner(System.in),new PrintStream(System.out));
		new b(new Scanner(new File("b.in")), new PrintStream(new FileOutputStream(new File("b.out"))));
	}
}
