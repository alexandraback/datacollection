import java.io.*;
import java.util.*;


public class Main extends Thread {
	
	Scanner in;
	static PrintWriter out;
	
	static final String path = "C:/gcj2013_r1/";
	static final String problem = "C-small";
	
	static int wallHeight[] = new int[2 * 676060 + 1];
	
	static class Tribe implements Comparable <Tribe> {
		int firstDay;
		int nAttacks;
		
		int westPos;
		int eastPos;
		
		int strength;
		
		int pauseDays;
		int movingVector;
		
		int deltaStrength;
		
		private int done;
		boolean lastSuccess;
		
		Tribe(Scanner in, int idx) {
			firstDay = in.nextInt();
			nAttacks = in.nextInt();
			
			westPos = in.nextInt();
			eastPos = in.nextInt();
			
			strength = in.nextInt();
			
			
			pauseDays = in.nextInt();
			
			movingVector = in.nextInt();
			
			deltaStrength = in.nextInt();
			done = 0;
			this.idx = idx;
		}
		int idx;
		
		boolean canAttack() {
			return done < nAttacks;
		}
		
		int getNextDay() {
			return firstDay + done * pauseDays;
		}
		
		boolean attack() {
			if (done != 0) {
				westPos += movingVector;
				eastPos += movingVector;
			}
			done++;
			
//			out.print("Attacking: idx =  " + idx + " " + westPos + ":" + eastPos + ", strength = " + strength + " day = " + (firstDay + (done-1) * pauseDays));
			for (int pos = westPos; pos < eastPos; pos++) {
				if (wallHeight[676060 + pos] < strength) {
					strength += deltaStrength;
					lastSuccess = true;
//					out.println(" ...succeeds"); out.flush();
					return true;
				}
			}
			
//			out.println(" ...fails"); out.flush();
			lastSuccess = false;
			strength -= deltaStrength;
			
			return false;
		}
		
		void buildWall() {
//			out.println("TRY");
			if (lastSuccess) {
				int oldStrength = strength - deltaStrength;
//				out.println("building: " + westPos + " " + eastPos + " , height " + oldStrength);
				for (int pos = westPos; pos < eastPos; pos++) {
					if (wallHeight[676060 + pos] < oldStrength) {
						wallHeight[676060 + pos] = oldStrength;
					}
				}
			}
		}
		
		@Override
		public int compareTo(Tribe second) {
			return this.getNextDay() - second.getNextDay();
		}
	}
	
	
	void solveOne(int test) {
		Arrays.fill(wallHeight, 0);
		int nSucceed = 0;
		
		int n = in.nextInt();

		PriorityQueue <Tribe> q = new PriorityQueue<Main.Tribe>();
		for (int i = 0; i < n; i++) {
			q.add(new Tribe(in, i + 1));
		}
		
		LinkedList <Tribe> oldDayRem = new LinkedList<Main.Tribe>();
		int prevDay = -1;
		while (!(q.isEmpty() && oldDayRem.isEmpty())) {
			Tribe first = q.poll();
			
			if (first == null || first.getNextDay() != prevDay) {
				boolean add = false;
				for (Tribe tr : oldDayRem) {
					tr.buildWall();
					if (tr.canAttack()) {
						q.add(tr);
						add = true;
					}
				}
				oldDayRem.clear();
				if (add) {
					if (first != null) {
						q.add(first);
					}
					continue;
				}
			}
			
			if (first == null) {
				continue;
			}
			int day = first.getNextDay();
			if (first.attack()) {
				nSucceed++;
			}
			
			oldDayRem.add(first);
			prevDay = day;
		}
		
		out.println("Case #" + test + ": " + nSucceed);
	}
	
	void solve() {
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			solveOne(i + 1);
		}
	}
	
	
	static void check(boolean e) {
		if (!e) {
			throw new Error();
		}
	}
	
	
	public void run() {
		try {
			in = new Scanner(new FileReader(path + problem + ".in"));
			out = new PrintWriter(new FileWriter(path + problem + ".out"));
		} catch (IOException e) {
			in = new Scanner(System.in);
			out = new PrintWriter(System.out);
		}
		
		try {
			solve();
		} finally {
			out.close();
		}
	}
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "GAVNO", 500000000).start();
	}
}