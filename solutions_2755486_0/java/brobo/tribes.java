import java.util.*;
import java.io.*;
import java.util.regex.*;

public class tribes {
	public static void main(String[] args) throws Exception {
		Scanner input = new Scanner(new File("input/tribes-small.in"));
		PrintWriter out = new PrintWriter(new File("output/tribes-small.out"));
		int sets = input.nextInt();
		input.nextLine();
		primary: for (int onSet = 1; onSet <= sets; onSet++) {
			System.out.printf("%d of %d%n", onSet, sets);
			out.printf("Case #%d: ", onSet);
			Queue<Tribe> tribes = new PriorityQueue<Tribe>();
			int n = input.nextInt();
			int minWait = Integer.MAX_VALUE;
			for (int i=0; i<n; i++) {
				Tribe cur = new Tribe(input.nextInt(), input.nextInt(), input.nextInt(), input.nextInt(), input.nextInt(),input.nextInt(), input.nextInt(), input.nextInt(), i);
				tribes.add(cur);
			}
			Map<Long, Long> wall = new HashMap<Long, Long>();
			Set<Long> gaps = new HashSet<Long>();
			
			int tot =0;
			while (!tribes.isEmpty()) {
				Map<Long, Long> attacks = new HashMap<Long, Long>();
				int day = tribes.peek().nextAttack;
				//System.out.println("Day " + day);
				Iterator<Tribe> it = tribes.iterator();
				while (it.hasNext()) {
					Tribe cur = it.next();
					//System.out.println(cur.strength);
					if (cur.nextAttack > day) break;
					boolean won = false;
					//System.out.println("Tribe attacking");
					for (long i=cur.west*2; i<=cur.east*2; i++) {
						if (!wall.containsKey(i) || wall.get(i) < cur.strength){
							if (!won) {
								//System.out.println(cur + " won on day " + day + " at " + i + " wall at " + (wall.containsKey(i) ? wall.get(i) : 0));
								won=true;
							}
							if (!attacks.containsKey(i) || attacks.get(i) < cur.strength) {
								//System.out.println("Need to fix wall at " + i);
								attacks.put((long)i, (long)cur.strength);
							}
						}
					}
					if (won) tot++;
					cur.at();
					if (cur.attacksLeft == 0) it.remove();
				}
				for (Map.Entry<Long, Long> entry : attacks.entrySet()) {
					//System.out.println("Updating wall");
					wall.put(entry.getKey(), entry.getValue());
				}
				//System.out.println(wall);
			}
			out.println(tot);
		}
		out.close();
	}
	
	public static class Tribe implements Comparable<Tribe> {
		int nextAttack, attacksLeft, west, east, strength, time, move, strMod, i;
		public Tribe(int a, int n,int w,int e,int s,int t,int m,int str,int i) {
			nextAttack = a;
			attacksLeft = n;
			west= w;
			east =e;
			strength=s;
			time=t;
			move=m;
			strMod=str;
			this.i =i;
		}
		
		public int at() {
			nextAttack += time;
			attacksLeft -= 1;
			int res = strength;
			strength += strMod;
			west += move;
			east += move;
			return res;
		}
		
		public int compareTo(Tribe other) {
			return nextAttack - other.nextAttack;
		}
		public String toString() {return "" + i;}
	}
}