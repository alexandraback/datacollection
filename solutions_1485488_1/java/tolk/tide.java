import java.io.*;
import java.util.*;

class tide implements Comparator {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("tide.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("tide.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int water = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int[][] floor = new int[N][M];
			int[][] ceiling = new int[N][M];
			for (int j = 0; j < N; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < M; k++) {
					ceiling[j][k] = Integer.parseInt(st.nextToken());
				}
			}
			for (int j = 0; j < N; j++) {
				st = new StringTokenizer(br.readLine());
				for (int k = 0; k < M; k++) {
					floor[j][k] = Integer.parseInt(st.nextToken());
				}
			}
			ArrayList reachable = reachable(water, N, M, floor, ceiling);
			double answer = dijkstra(water, N, M, floor, ceiling, reachable);
			out.println("Case #" + (i+1) + ": " + answer);
			out.flush();
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
	public tide() {
	}
	public int compare(Object o1, Object o2) {
		int answer = 0;
		double[] a1 = (double[])o1;
		double[] a2 = (double[])o2;
		if (a1[2] > a2[2]) {
		  answer = 1;
		} else if (a1[2] == a2[2]) {
		  answer = 0;
		} else {
		  answer = -1;
		}
		return answer;
	}
	public static ArrayList reachable(int water, int N, int M, int[][] floor, int[][] ceiling) {
		Queue q = new LinkedList();
		int[] start = new int[2];
		start[0] = 0;
		start[1] = 0;
		q.add(start);
		ArrayList reachable = new ArrayList();
		boolean[][] visited = new boolean[N][M];
		while (q.size() != 0) {
			int[] current = (int[])q.poll();
			reachable.add(current);
			if (!visited[current[0]][current[1]]) {
				visited[current[0]][current[1]] = true;
				//north
				if (current[0] > 0) {
					if (Math.max(Math.max(water, floor[current[0] - 1][current[1]]), floor[current[0]][current[1]]) <= ceiling[current[0] - 1][current[1]] - 50 && floor[current[0] - 1][current[1]] <= ceiling[current[0]][current[1]] - 50 && !visited[current[0] - 1][current[1]]) {
						int[] next = new int[2];
						next[0] = current[0] - 1;
						next[1] = current[1];
						q.add(next);
					}
				}
				//east
				if (current[1] < M-1) {
					if (Math.max(Math.max(water, floor[current[0]][current[1] + 1]), floor[current[0]][current[1]]) <= ceiling[current[0]][current[1] + 1] - 50 && floor[current[0]][current[1] + 1] <= ceiling[current[0]][current[1]] - 50 && !visited[current[0]][current[1] + 1]) {
						int[] next = new int[2];
						next[0] = current[0];
						next[1] = current[1] + 1;
						q.add(next);
					}
				}
				//south
				if (current[0] < N-1) {
					if (Math.max(Math.max(water, floor[current[0] + 1][current[1]]), floor[current[0]][current[1]]) <= ceiling[current[0] + 1][current[1]] - 50 && floor[current[0] + 1][current[1]] <= ceiling[current[0]][current[1]] - 50 && !visited[current[0] + 1][current[1]]) {
						int[] next = new int[2];
						next[0] = current[0] + 1;
						next[1] = current[1];
						q.add(next);
					}
				}
				//west
				if (current[1] > 0) {
					if (Math.max(Math.max(water, floor[current[0]][current[1] - 1]), floor[current[0]][current[1]]) <= ceiling[current[0]][current[1] - 1] - 50 && floor[current[0]][current[1] - 1] <= ceiling[current[0]][current[1]] - 50 && !visited[current[0]][current[1] - 1]) {
						int[] next = new int[2];
						next[0] = current[0];
						next[1] = current[1] - 1;
						q.add(next);
					}
				}
			}
		}
		return reachable;
	}
	public static double dijkstra(int water, int N, int M, int[][] floor, int[][] ceiling, ArrayList reachable) {
		double min = Double.POSITIVE_INFINITY;
		for (int i = 0; i < reachable.size(); i++) {
			int[] current = (int[])reachable.get(i);
			if (current[0] == N-1 && current[1] == M-1) {
				return 0;
			}
		}
		for (int i = 0; i < reachable.size(); i++) {
			int[] current = (int[])reachable.get(i);
			tide t = new tide();
			PriorityQueue q = new PriorityQueue(10, t);
			double[] first = new double[3];
			first[0] = (double)current[0];
			first[1] = (double)current[1];
			first[2] = 0;
			q.add(first);
			boolean[][] visited = new boolean[N][M];
			while(q.size() != 0) {
				double[] curtest = (double[])q.poll();
				double curtime = curtest[2];
				int[] curtestint = new int[2];
				curtestint[0] = (int)curtest[0];
				curtestint[1] = (int)curtest[1];
				if ((int)curtest[0] == N-1 && (int)curtest[1] == M-1) {
					min = Math.min(min, curtest[2]);
					break;
				}
				if (!visited[(int)curtest[0]][(int)curtest[1]]) {
					visited[(int)curtest[0]][(int)curtest[1]] = true;
					//north
					if (curtest[0] > 0) {
						if (Math.max(floor[curtestint[0] - 1][curtestint[1]], floor[curtestint[0]][curtestint[1]]) <= ceiling[curtestint[0] - 1][curtestint[1]] - 50 && floor[curtestint[0] - 1][curtestint[1]] <= ceiling[curtestint[0]][curtestint[1]] - 50 && !visited[curtestint[0] - 1][curtestint[1]]) {
							double[] next = new double[3];
							next[0] = curtest[0] - 1;
							next[1] = curtest[1];
							double safetime = Math.max(0, 1/(double)10*(50-(double)ceiling[curtestint[0] - 1][curtestint[1]] - 10*curtime + (double)water));
							if ((double)water - 10*safetime - 10*curtime >= floor[curtestint[0]][curtestint[1]] + 20) {
								next[2] = curtime + safetime + 1;
							} else {
								next[2] = curtime + safetime + 10;
							}
							q.add(next);
						}
					}
					//south
					if (curtest[0] < N-1) {
						if (Math.max(floor[curtestint[0] + 1][curtestint[1]], floor[curtestint[0]][curtestint[1]]) <= ceiling[curtestint[0] + 1][curtestint[1]] - 50 && floor[curtestint[0] + 1][curtestint[1]] <= ceiling[curtestint[0]][curtestint[1]] - 50 && !visited[curtestint[0] + 1][curtestint[1]]) {
							double[] next = new double[3];
							next[0] = curtest[0] + 1;
							next[1] = curtest[1];
							double safetime = Math.max(0, 1/(double)10*(50-(double)ceiling[curtestint[0] + 1][curtestint[1]] - 10*curtime + (double)water));
							if ((double)water - 10*safetime - 10*curtime >= floor[curtestint[0]][curtestint[1]] + 20) {
								next[2] = curtime + safetime + 1;
							} else {
								next[2] = curtime + safetime + 10;
							}
							q.add(next);
						}
					}
					//west
					if (curtest[1] > 0) {
						if (Math.max(floor[curtestint[0]][curtestint[1] - 1], floor[curtestint[0]][curtestint[1]]) <= ceiling[curtestint[0]][curtestint[1] - 1] - 50 && floor[curtestint[0]][curtestint[1] - 1] <= ceiling[curtestint[0]][curtestint[1]] - 50 && !visited[curtestint[0]][curtestint[1] - 1]) {
							double[] next = new double[3];
							next[0] = curtest[0];
							next[1] = curtest[1] - 1;
							double safetime = Math.max(0, 1/(double)10*(50-(double)ceiling[curtestint[0]][curtestint[1] - 1] - 10*curtime + (double)water));
							if ((double)water - 10*safetime - 10*curtime >= floor[curtestint[0]][curtestint[1]] + 20) {
								next[2] = curtime + safetime + 1;
							} else {
								next[2] = curtime + safetime + 10;
							}
							q.add(next);
						}
					}
					//east
					if (curtest[1] < M-1) {
						if (Math.max(floor[curtestint[0]][curtestint[1] + 1], floor[curtestint[0]][curtestint[1]]) <= ceiling[curtestint[0]][curtestint[1] + 1] - 50 && floor[curtestint[0]][curtestint[1] + 1] <= ceiling[curtestint[0]][curtestint[1]] - 50 && !visited[curtestint[0]][curtestint[1] + 1]) {
							double[] next = new double[3];
							next[0] = curtest[0];
							next[1] = curtest[1] + 1;
							double safetime = Math.max(0, 1/(double)10*(50-(double)ceiling[curtestint[0]][curtestint[1] + 1] - 10*curtime + (double)water));
							if ((double)water - 10*safetime - 10*curtime >= floor[curtestint[0]][curtestint[1]] + 20) {
								next[2] = curtime + safetime + 1;
							} else {
								next[2] = curtime + safetime + 10;
							}
							q.add(next);
						}
					}
				}
			}
		}
		return min;
	}
}

