package R1B;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class C {

	static Scanner reader;
	static PrintWriter writer;
	
	public static void main(String[] args) throws IOException {
		reader = new Scanner(new FileReader("input"));
		writer = new PrintWriter(new FileWriter("output"));
		int nt = reader.nextInt();
		for(int tc = 1; tc <= nt; tc++) {
			solve(tc);
		}
		writer.close();
		reader.close();
	}

	static void solve(int tc) {
		int n = reader.nextInt();
		Group[] g = new Group[n];
		for(int i = 0; i < n; i++) {
			g[i] = new Group(reader.nextInt(), reader.nextInt(), reader.nextLong());
		}
		int ans = -1;
		int deg1 = 0, deg2 = 0;
		long time1 = 0, time2 = 0;
		if(n == 1 && g[0].nb == 1) {
			ans = g[0].deg == 0 ? 1 : 0;
			writer.printf("Case #%d: %d\n", tc, ans);
			return;
		} else if(n == 1 && g[0].nb == 2) {
			deg1 = deg2 = g[0].deg;
			time1 = g[0].time;
			time2 = g[0].time + 1;
		} else if(n == 2) {
			deg1 = g[0].deg;
			deg2 = g[1].deg;
			time1 = g[0].time;
			time2 = g[1].time;
		}
		
		
		if(deg1 > deg2) {
			long tmp = deg2;
			deg2 = deg1;
			deg1 = (int)tmp;
			tmp = time2;
			time2 = time1;
			time1 = tmp;
		}

		ans = getSol(deg1, deg2, time1, time2);
		
		writer.printf("Case #%d: %d\n", tc, ans);
	}
	
	static double eps = 0;
	
	static class Group {
		int deg, nb;
		long time;
		public Group(int deg, int nb, long time) {
			this.deg = deg;
			this.nb = nb;
			this.time = time;
		}
		public String toString() {
			return String.format("%d %d %d", deg, nb, time);
		}
	}
	
	static int getSol(int deg1, int deg2, long time1, long time2) {
		double speed1 = 360.0 / time1;
		double speed2 = 360.0 / time2;
		
		if(time1 == time2) return 0; // check
		
		if(time1 > time2) {
			double time2Reaches1 = (360.0 - deg2 + deg1) / (speed2 - speed1);
			double time1Finish   = (360.0 - deg1) / speed1;
			if(time1Finish < time2Reaches1 - eps) {
				return 0;
			}
			return 1;
		}
		
		if(time1 < time2) {
			double time1Meet2 = (deg2 - deg1) / (speed1 - speed2);
			double deg2AfterMeet = deg2 + speed2 * time1Meet2;
			if(deg2AfterMeet >= 360.0 + eps) {
				return 0;
			}
			double time2ToFinish = (360.0 - deg2AfterMeet) / speed2;
			if(time2ToFinish < time2 - eps) {
				return 0;
			}
			return 1;
		}
		
		return -1;
	}
	
	static int canDoOne(int deg1, int time1, int deg2, int time2) {
		// no one at the start
		if(deg1 != 0 && deg2 != 0) {
			if(time1 == time2) {
				return 0;
			}
			if(time1 < time2) {
				int degToGo1 = 360 - deg1;
				int degToGo2 = 360 - deg2 + deg1;
				
				double timeToReach = (degToGo2 * time2) / 360.0;
				double timeToFinish = (time1 * degToGo1) / 360.0;
				
				if(timeToFinish < timeToReach) {
					return 0;
				}
				
				if(timeToFinish == timeToReach) {
					return 1;
				}
				
				if(timeToFinish > timeToReach) {
					
					if(timeToFinish < timeToReach + time2) {
						return 1;
					}
					
				}
				return 2;
			}
			
			if(time1 > time2) {
				
				
				double timeToReach = ((deg2 - deg1) * time2) / 360.0;
				
				double deg = deg2 + (timeToReach * time2) / 360.0;
				
				if(deg >= 360) {
					return 0;
				}
				
				double degToGo = 360 - deg;
				double timeToFinish = (degToGo * time2) / 360.0;
				
				if(timeToFinish < time1) {
					return 1;
				}
				
				return 2;
			}
		}
		
		return 2;
	}
	
}
