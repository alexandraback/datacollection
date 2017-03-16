import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

public class ProblemB {
	
	static  class State implements Comparable<State> {
		int stat;
		int step;
		@Override
		public int compareTo(State arg0) {
			return step - arg0.step;
		}
		
		State(int s, int st) {
			stat = s;
			step = st;
		}
	}
	
	
	static int[] p3;
	
	public static int solve(int[] a, int[] b) {
		int N = a.length;
		p3 = new int[N];
		p3[0] = 1;
		for (int i = 1 ; i < N ; i++) {
			p3[i] = p3[i-1] * 3;
		}
		
		Queue<State> q = new PriorityQueue<State>(1000000);
		q.add(new State(0, 0));
		
		int[] dp = new int[180000];
		Arrays.fill(dp, 1000);
		dp[0] = 0;
		
		
		while (q.size() >= 1) {
			State s = q.poll();
			int[] state = new int[N];
			int ss = s.stat;
			int stars = 0;
			for (int i = 0 ; i < N ; i++) {
				state[i] = ss % 3;
				stars += state[i];
				ss /= 3;
			}
			if (stars == N * 2) {
				return s.step;
			}
			
			
			for (int n = 0 ; n < N ; n++) {
				if (state[n] == 2) {
					continue;
				}
				int canget = 0;
				if (stars >= b[n]) {
					canget = 2;
				} else if (stars >= a[n]) {
					canget = 1;
				}
				if (canget == 0 || state[n] >= canget) {
					continue;
				}
				int nextstep = s.step + 1;
				int nextstat = s.stat + (canget - state[n]) * p3[n];
				if (dp[nextstat] > nextstep) {
					dp[nextstat] = nextstep;
					q.add(new State(nextstat, nextstep));
				}
			}
		}
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader s = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.valueOf(s.readLine());
		for (int t = 1 ; t <= T ; t++) {
			int N = Integer.valueOf(s.readLine());
			int[] a = new int[N];
			int[] b = new int[N];
			for (int i = 0 ; i < N ; i++) {
				String[] data = s.readLine().split(" ");
				a[i] = Integer.valueOf(data[0]);
				b[i] = Integer.valueOf(data[1]);
			}
			
			int step = solve(a, b);
			System.out.println("Case #" + t + ": " + ((step == -1) ? "Too Bad" : step));
		}
	}
}