package round1A;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.StringTokenizer;

public class Main {
	private static final String TASKNAME = "input";
	
	private class Car {
		public boolean left;
		public final int speed;
		public double pos;
		
		public Car(boolean left, int speed, double pos) {
			this.left = left;
			this.speed = speed;
			this.pos = pos;
		}
		
		public String toString() {
			String res;
			if (left) {
				res = "L";
			} else {
				res = "R";
			}
			return res + " " + speed + " " + pos;
		}
	}

	private void solve() throws IOException {
		int tests = nextInt();
		for (int t = 1; t <= tests; t++) {
			int n = nextInt();
			Car[] c = new Car[n];
			for (int i = 0; i < n; i++) {
				char w = nextToken().charAt(0);
				boolean left = false;
				if (w == 'L') {
					left = true;
				}
				c[i] = new Car(left, nextInt(), nextInt());
			}
			
			double first = -1;
			double Time = 0;
			int k = 0;
			
			while (true) {
				int a = -1;
				int b = -1;
				double min = 1e18;
				
				for (int i = 0; i < n; i++) {
					for (int j = i + 1; j < n; j++) {
						if (c[i].left == c[j].left && (
								c[i].pos < c[j].pos && c[i].speed > c[j].speed ||
								c[j].pos < c[i].pos && c[j].speed > c[i].speed)) {
							double time = (Math.abs(c[i].pos - c[j].pos) - 5) / Math.abs(c[i].speed - c[j].speed);
							if (time < min) {
								min = time;
								a = i;
								b = j;
							}
						}
					}
				}
				
				if (a == -1) {
					break;
				}
				
				Time += min;
				for (int i = 0; i < n; i++) {
					c[i].pos += c[i].speed * min;
				}
				if (possible(a, c)) {
					c[a].left = !c[a].left;
				} else if (possible(b, c)) {
					c[b].left = !c[b].left;
				} else {
					first = Time;
					break;
				}
				
				k++;
				if (k == n * n) {
					first = Time;
					break;
				}
			}
			
			print("Case #" + t + ": ");
			if (first < 0) {
				println("Possible");
			} else {
				println(first);
			}
		}
	}
	
	private static final double ESP = 1e-9;
	private boolean possible(int p, Car[] c) {
		boolean f = !c[p].left;
		
		for (Car car: c) {
			if (car.left == f) {
				if (Math.abs(c[p].pos - car.pos) + ESP < 5) {
					return false;
				}
			}
		}
		
		return true;
	}

	private String nextToken() throws IOException {
		while (tokenizer == null || !tokenizer.hasMoreTokens()) {
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	private int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	private double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	private long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private void print(Object o) {
		writer.print(o);
	}

	private void println(Object o) {
		writer.println(o);
	}

	private void printf(String format, Object... o) {
		writer.printf(format, o);
	}

	public static void main(String[] args) {
		long time = System.currentTimeMillis();
		Locale.setDefault(Locale.US);
		new Main().run();
		System.err.printf("%.3f\n", 1e-3 * (System.currentTimeMillis() - time));
	}

	BufferedReader reader;
	StringTokenizer tokenizer;
	PrintWriter writer;

	private void run() {
		try {
			reader = new BufferedReader(new InputStreamReader(System.in));
			writer = new PrintWriter(System.out);
			reader = new BufferedReader(new FileReader(TASKNAME + ".in"));
			writer = new PrintWriter(TASKNAME + ".out");
			solve();
			reader.close();
			writer.close();
		} catch (IOException e) {
			e.printStackTrace();
			System.exit(13);
		}
	}
}