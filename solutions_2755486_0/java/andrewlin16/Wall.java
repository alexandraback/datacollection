import java.util.*;

public class Wall {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		
		for (int t = 1; t <= T; t++) {
			int N = in.nextInt();
			
			Queue<Attack> pq = new PriorityQueue<Attack>();
			
			for (int k = 0; k < N; k++) {
				int d = in.nextInt();
				int n = in.nextInt();
				int w = in.nextInt();
				int e = in.nextInt();
				int s = in.nextInt();
				int dd = in.nextInt();
				int dp = in.nextInt();
				int ds = in.nextInt();
				
				for (int D = 0; D < n; D++) {
					Interval i = new Interval(w, e, s);
					Attack a = new Attack(d + D * dd, i);
					pq.add(a);
					
					w = w + dp;
					e = e + dp;
					s = s + ds;
				}
			}
			
			List<Interval> wall = new ArrayList<Interval>();
			
			int succeed = 0;
			
			while (!pq.isEmpty()) {
				int day = pq.peek().d;
				
				List<Interval> oldWall = new ArrayList<Interval>(wall);
				//System.out.println("Wall: " + oldWall);
				
				while (!pq.isEmpty() && pq.peek().d == day) {
					Attack a = pq.remove();
					//System.out.println("\t" + a);
					
					boolean success = false;
					
					for (int x = a.i.l; !success && x <= a.i.r; x++) {
						if (canAtk(new LinkedList<Interval>(oldWall), a.i.l, a.i.r, a.i.s)) {
							success = true;
						}
					}
					
					if (success) {
						succeed++;
						//System.out.println("\tattack was success");
						
						wall.add(new Interval(a.i.l, a.i.r, a.i.s));
					}
				}
			}
			
			System.out.printf("Case #%d: %d\n", t, succeed);
		}
	}
	
	public static boolean canAtk(List<Interval> wall, int l, int r, int s) {
		if (wall.isEmpty()) {	// no more walls, can attack
			return true;
		}
		
		Interval i = wall.get(0);
		wall.remove(0);
		
		if (s > i.s) {	// wall is not even strong enough, check rest
			return canAtk(wall, l, r, s);
		}
		
		if (l < i.l) {
			if (r <= i.l) {					// attack, (_), wall
				return canAtk(wall, l, r, s);
			} if (r <= i.r) {				// attack, isect, (wall)
				return canAtk(wall, l, i.l, s);
			} else {					// attack, isect, attack
				List<Interval> copy = new LinkedList<Interval>(wall);
				return canAtk(wall, l, i.l, s) || canAtk(copy, i.r, r, s);
			}
		} else if (l < i.r) {
			if (r <= i.r) {				// (wall), isect, (wall)
				return false;	// wall blocks it
			} else {					// (wall), isect, attack
				return canAtk(wall, i.r, r, s);
			}
		} else {						// wall, (_), attack
			return canAtk(wall, l, r, s);
		}
	}
}

class Attack implements Comparable<Attack> {
	int d;
	Interval i;
	
	public Attack(int a, Interval b) {
		d = a;
		i = b;
	}
	
	public int compareTo(Attack o) {
		return d - o.d;
	}
	
	public String toString() {
		return String.format("Day %d: %s", d, i.toString());
	}
}

class Interval implements Comparable<Interval> {
	int l, r, s;
	
	public Interval(int a, int b, int c) {
		l = a;
		r = b;
		s = c;
	}
	
	public int compareTo(Interval o) {
		return o.l - l;
	}
	
	public String toString() {
		return String.format("[%d, %d] at %d", l, r, s);
	}
}
