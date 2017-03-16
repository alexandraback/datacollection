import java.io.*;
import java.util.*;

public class Main implements Runnable {

	public void _main() throws IOException {
		int nTests = nextInt();
		for (int test = 1; test <= nTests; test++) {
			out.println("Case #" + test + ": " + solve());
		}
	}

	private int solve() throws IOException {
		int numTribes = nextInt();
		List<Event> events = new ArrayList<Event>();
		for (int i = 0; i < numTribes; i++) {
			int d = nextInt();
			int n = nextInt();
			int w = nextInt();
			int e = nextInt();
			int s = nextInt();
			int deltaD = nextInt();
			int deltaP = nextInt();
			int deltaS = nextInt();
			for (int j = 0; j < n; j++) {
				Event ev = new Event();
				ev.time = d;
				ev.l = w;
				ev.r = e - 1;
				ev.strength = s;
				events.add(ev);
				d += deltaD;
				w += deltaP;
				e += deltaP;
				s += deltaS;
			}
		}
		Collections.sort(events);
		return dummy(events);
	}

	private int dummy(List<Event> events) {
		Map<Integer, Integer> wall = new HashMap<Integer, Integer>();
		int res = 0;
		int i = 0;
		while (i < events.size()) {
			int j = i;
			while (j < events.size() && events.get(i).time == events.get(j).time) {
				++j;
			}
			--j;

			for (int k = i; k <= j; k++) {
				Event e = events.get(k);
				for (int z = e.l; z <= e.r; z++) {
					Integer level = wall.get(z);
					if (level == null) {
						level = 0;
					}
					if (level < e.strength) {
						++res;
						break;
					}
				}
			}
			
			for (int k = i; k <= j; k++) {
				Event e = events.get(k);
				for (int z = e.l; z <= e.r; z++) {
					Integer level = wall.get(z);
					if (level == null) {
						level = 0;
					}
					if (level < e.strength) {
						level = e.strength;
					}
					wall.put(z, level);
				}
			}
			i = j + 1;
		}
		return res;
	}

	class Event implements Comparable<Event> {
		int time;
		int strength;
		int l, r;
		
		public int compareTo(Event o) {
			if (time != o.time) return time - o.time;
			if (strength != o.strength) return strength - o.strength;
			if (l != o.l) return l - o.l;
			if (r != o.r) return r - o.r;
			return 0;
		}
	}


	private BufferedReader in;
	private PrintWriter out;
	private StringTokenizer st;

	private String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String rl = in.readLine();
			if (rl == null)
				return null;
			st = new StringTokenizer(rl);
		}
		return st.nextToken();
	}

	private int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(next());
	}

	private double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.UK);
		new Thread(new Main()).start();
	}

	public void run() {
		try {
			in = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			in = new BufferedReader(new FileReader("C-small-attempt0.in"));
			out = new PrintWriter(new FileWriter("C-small-attempt0.out"));

			_main();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(202);
		}
	}

}
