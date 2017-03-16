import java.util.*;
public class C {
	static int height[] = new int[10000];
	
	static int getHeight(int pos) { return height[pos+5000]; }
	static void resetHeight() { for(int i = -1000; i <= 1000; ++i) resetHeight(i); }
	static void resetHeight(int pos) { height[pos+5000] = 0; }
	static void growHeight(int pos, int v) { height[pos+5000] = Math.max(height[pos+5000], v); }
	static void growHeight(int l, int r, int v) { for(int i = l; i <= r; ++i) growHeight(i, v); }
	static int getMinHeight(int l, int r) { int lo = getHeight(l); for(int i = l; i <= r; ++i) lo = Math.min(lo, getHeight(i)); return lo; }

	static Scanner in;
	
	static int attack(int day, ArrayList<Attack> attacks) {
		int sum = 0;
		for(int i = 0;i < attacks.size(); ++i) if(((Attack)attacks.get(i)).day == day) {
			if(getMinHeight(2*((Attack)attacks.get(i)).l, 2*((Attack)attacks.get(i)).r) < ((Attack)attacks.get(i)).s) {
				++sum;
			}
		}
		for(int i = 0;i < attacks.size(); ++i) if(((Attack)attacks.get(i)).day == day) {
			growHeight(2*((Attack)attacks.get(i)).l, 2*((Attack)attacks.get(i)).r, ((Attack)attacks.get(i)).s);
		}
		return sum;
	}
	
	static void testcase(int t) {
		int N = in.nextInt();
		ArrayList<Attack> attacks = new ArrayList<Attack>();
		for(int i = 0;i < N; ++i) {
			int d = in.nextInt(), n = in.nextInt(), w = in.nextInt(), e = in.nextInt();
			int s = in.nextInt(), delta_d = in.nextInt(), delta_p = in.nextInt(), delta_s = in.nextInt();
			for(int j = 0;j < n; ++j) {
				Attack a = new Attack(); a.l = w; a.r = e; a.s = s; a.day = d;
				attacks.add(a);
				d += delta_d; s += delta_s;
				w += delta_p; e += delta_p;
			}
		}
		resetHeight();
		Collections.sort(attacks);
		int sum = 0;
		for(int i = 0;i < attacks.size(); ++i) {
			sum += attack(((Attack)attacks.get(i)).day, attacks);
		}
		System.out.println("Case #"+t+": "+sum);
	}
	
	public static void main(String[] args) {
		in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t = 1; t <= T; ++t) testcase(t);
	}
}

class Attack implements Comparable<Attack> {
	int l, r, s;//left, right, strength
	int day;
	public int compareTo(Attack o) {
		return this.day - o.day;
	}
}