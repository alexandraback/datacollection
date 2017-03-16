package gcj2014r1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class TheBoredTravelingSalesman {
	public static void main(String[] args) throws Exception {
		String fileName = args[0];
		TheBoredTravelingSalesman obj = new TheBoredTravelingSalesman();
		obj.solve(fileName);
	}

	int N = 0;
	int M = 0;
	String[] zip = null;
	int[][] flight = null;
	boolean[] out = null;
	int start = 0;
	String min = "";

	public void solve(String fileName) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader(fileName));
		BufferedWriter bw = new BufferedWriter(
				new FileWriter(fileName + ".out"));

		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
			String str = br.readLine();
			StringTokenizer token = new StringTokenizer(str, " ");
			N = Integer.parseInt(token.nextToken());
			M = Integer.parseInt(token.nextToken());

			zip = new String[N + 1];
			for (int j = 1; j <= N; j++) {
				zip[j] = br.readLine();
			}
			flight = new int[M * 2][2];
			for (int j = 0; j < M * 2;) {
				str = br.readLine();
				token = new StringTokenizer(str, " ");
				flight[j][0] = Integer.parseInt(token.nextToken());
				flight[j][1] = Integer.parseInt(token.nextToken());
				j++;
				flight[j][0] = flight[j - 1][1];
				flight[j][1] = flight[j - 1][0];
				j++;
			}
			min = "A";
			for (int j = 1; j <= N; j++) {
				out = new boolean[N + 1];
				ArrayList<Integer> travel = new ArrayList<Integer>();
				start = j;
				rec(j, travel, zip[j]);
			}

			bw.write("Case #" + (i + 1) + ": " + min);
			bw.write("\r\n");
		}
		bw.close();
		br.close();
	}

	private void rec(int cur, ArrayList<Integer> travel, String str) {
		if (str.compareTo(min) > 0) {
			return;
		} else if (str.length() == 5 * N) {
			if (str.compareTo(min) < 0) {
				min = str;
			}
			return;
		}
		String min = "AAAAA";
		int minidx = -1;
		int retidx = -1;
		for (int i = 0; i < M * 2; i++) {
			if (flight[i][0] == cur) {
				if (out[flight[i][1]] == false && flight[i][1] != start) {
					if (zip[flight[i][1]].compareTo(min) < 0) {
						minidx = i;
						min = zip[flight[i][1]];
					}
				} else if (out[flight[i][1]] == false && flight[i][1] == start) {
					if (travel.size() != 1) {
						retidx = i;
					}
				}
			}
		}
		// min
		if (minidx != -1) {
			out[flight[minidx][1]] = true;
			travel.add(cur);
			rec(flight[minidx][1], travel, str + zip[flight[minidx][1]]);
			out[flight[minidx][1]] = false;
			travel.remove(travel.size() - 1);
		}

		// start
		if (retidx != -1) {
			out[flight[retidx][1]] = true;
			travel.add(cur);
			rec(flight[retidx][1], travel, str);
			out[flight[retidx][1]] = false;
			travel.remove(travel.size() - 1);
		}

		// back
		if (travel.size() > 0) {
			int tmp = travel.get(travel.size() - 1);
			travel.remove(travel.size() - 1);
			rec(tmp, travel, str);
			travel.add(tmp);
		}
	}
}
