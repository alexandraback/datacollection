package roundC;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;

class Point {
	int x, y, step;
	String path;

	public Point(int x, int y, String path, int step) {
		this.x = x;
		this.y = y;
		this.path = path;
		this.step = step;
	}

	@Override
	public String toString() {
		return path;
	}
}

public class B {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("cb.in"),
				1024 * 1024 * 2);
		BufferedWriter bw = new BufferedWriter(new FileWriter("cb.out"),
				1024 * 1024 * 2);

		int t = Integer.parseInt(br.readLine());
		int count = 1;
		StringBuilder sb = new StringBuilder();

		HashMap<String, Point> hash = new HashMap<String, Point>();
		LinkedList<Point> q = new LinkedList<Point>();
		Point root = new Point(0, 0, "", 0);
		q.add(root);
		hash.put("0_0", root);

		int limit = 100;

		while (!q.isEmpty()) {
			Point p = q.poll();
			int step = p.step + 1;
			if (p.x + step <= limit) {
				String coord = (p.x + step) + "_" + p.y;
				if (!hash.containsKey(coord)) {
					Point np = new Point(p.x + step, p.y, p.path + "E", step);
					q.add(np);
					hash.put(coord, np);
				}
			}
			if (p.x - step >= -limit) {
				String coord = (p.x - step) + "_" + p.y;
				if (!hash.containsKey(coord)) {
					Point np = new Point(p.x - step, p.y, p.path + "W", step);
					q.add(np);
					hash.put(coord, np);
				}
			}
			if (p.y - step >= -limit) {
				String coord = (p.x) + "_" + (p.y - step);
				if (!hash.containsKey(coord)) {
					Point np = new Point(p.x, p.y - step, p.path + "S", step);
					q.add(np);
					hash.put(coord, np);
				}
			}
			if (p.y + step <= limit) {
				String coord = (p.x) + "_" + (p.y + step);
				if (!hash.containsKey(coord)) {
					Point np = new Point(p.x, p.y + step, p.path + "N", step);
					q.add(np);
					hash.put(coord, np);
				}
			}
		}

		// System.out.println("end");
		String line;
		while (count <= t) {
			line = br.readLine();

			int index = line.indexOf(' ');
			int x = Integer.parseInt(line.substring(0, index));
			int y = Integer.parseInt(line.substring(index + 1));
			sb.append("Case #" + count + ": " + hash.get(x + "_" + y) + "\n");

			count++;
		}
		bw.write(sb.toString());
		System.out.println(sb.toString());
		bw.close();
		br.close();
	}

	public static int[] readArrayLine(String line, int n) {
		int[] ret = new int[n];
		int start = 0;
		int end = line.indexOf(' ', start);
		for (int i = 0; i < n; i++) {
			if (end > 0)
				ret[i] = Integer.parseInt(line.substring(start, end));
			else
				ret[i] = Integer.parseInt(line.substring(start));
			start = end + 1;
			end = line.indexOf(' ', start);
		}
		return ret;
	}
}
