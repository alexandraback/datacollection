import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.LinkedList;


public class Prob1B {

	static int[] dx = new int[] {0, 1, 0, -1};
	static int[] dy = new int[] {1, 0, -1, 0};
	
	static int n = 0, m = 0;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			String[] strs = br.readLine().split(" ");
			int h = Integer.parseInt(strs[0]);
			n = Integer.parseInt(strs[1]);
			m = Integer.parseInt(strs[2]);

			int[][] ceilings = new int[n][m];
			int[][] floors = new int[n][m];
			for(int i = 0; i < n; i++) {
				strs = br.readLine().split(" ");
				for(int j = 0; j < strs.length; j++) {
					ceilings[i][j] = Integer.parseInt(strs[j]);
				}
			}
			
			for(int i = 0; i < n; i++) {
				strs = br.readLine().split(" ");
				for(int j = 0; j < strs.length; j++) {
					floors[i][j] = Integer.parseInt(strs[j]);
				}
			}
			
			boolean[][] possible = new boolean[n][m];
			possible[0][0] = true;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			while(q.size() > 0) {
				int val = q.removeFirst();
				int vx = val / m;
				int vy = val % m;
				for(int i = 0; i < dx.length; i++) {
					if(isIn(vx + dx[i], vy + dy[i]) && !possible[vx + dx[i]][vy + dy[i]]) {
						if(h + 50 <= ceilings[vx + dx[i]][vy + dy[i]] &&
								floors[vx][vy] + 50 <= ceilings[vx + dx[i]][vy + dy[i]] &&
										floors[vx + dx[i]][vy + dy[i]] + 50 <= ceilings[vx][vy] &&
										floors[vx + dx[i]][vy + dy[i]] + 50 <= ceilings[vx + dx[i]][vy + dy[i]]) {
							possible[vx + dx[i]][vy + dy[i]] = true;
							q.add((vx + dx[i]) * m + vy + dy[i]);
						}
					}
				}
			}
			
			double[][] minDists = new double[n][m];
			double[][] minTime = new double[n][m];
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < m; j++) {
					if(possible[i][j]) {
						minDists[i][j] = 0;
						minTime[i][j] = 0;
						q.add(i * m + j);
					} else {
						minDists[i][j] = Double.MAX_VALUE;
						minTime[i][j] = Double.MAX_VALUE;
					}
				}
			}
			while(q.size() > 0) {
				int val = q.removeFirst();
				int vx = val / m;
				int vy = val % m;
				for(int i = 0; i < dx.length; i++) {
					if(!isIn(vx + dx[i], vy + dy[i]) || possible[vx + dx[i]][vy + dy[i]]) {
						continue;
					}
					if(floors[vx][vy] + 50 <= ceilings[vx + dx[i]][vy + dy[i]] &&
							floors[vx + dx[i]][vy + dy[i]] + 50 <= ceilings[vx][vy] &&
						 floors[vx + dx[i]][vy + dy[i]] + 50 <= ceilings[vx + dx[i]][vy + dy[i]]) {
						double nh = h - minTime[vx][vy] * 10;
						double newTime = minTime[vx][vy];
						if(nh + 50 > ceilings[vx + dx[i]][vy + dy[i]]) {
							newTime += (double)(nh + 50 - ceilings[vx + dx[i]][vy + dy[i]]) / 10.0;
							nh = h - newTime * 10;
						}
						if(nh - 20 >= floors[vx][vy]) {
							newTime += 1.0;
							if(newTime < minTime[vx + dx[i]][vy + dy[i]]) {
								minTime[vx + dx[i]][vy + dy[i]] = newTime;
								q.add((vx + dx[i]) * m + vy + dy[i]);
							}
						} else {
							newTime += 10.0;
							if(newTime < minTime[vx + dx[i]][vy + dy[i]]) {
								minTime[vx + dx[i]][vy + dy[i]] = newTime;
								q.add((vx + dx[i]) * m + vy + dy[i]);
							}
						}
					}
				}
			}
			
			pw.println("Case #" + x + ": " + minTime[n - 1][m - 1]);
		}
		
		br.close();
		pw.close();
	}
	
	static boolean isIn(int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < m;
	}
}
