package codejam.round1B;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.LineNumberReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Tide {
	static class Edge implements Comparable<Edge> {
		Room goTo;
		double minTime;
		
		@Override
		public int compareTo(Edge o) {
			if (minTime < o.minTime)
				return -1;
			if (minTime > o.minTime)
				return 1;
			return 0;
		}
	}
	
	static class Room {
		int x, y;
		int floor, ceil;
		Double enterable;
		Double minTime;
		boolean initiallyReachable;
		Edge[] edges;
	}
	
	Room[][] rooms;
	int h;
	int w;
	int[][] floors;
	int[][] ceils;
	boolean[][] enterable;
	int initialLevel;
	
	public Tide(int width, int height, int[][] floors, int[][] ceils, int initialLevel) {
		this.rooms = new Room[width][height];
		for (int x = 0; x < width; x++) {
			for (int y = 0; y < height; y++) {
				Room r = new Room();
				r.x = x;
				r.y = y;
				r.floor = floors[x][y];
				r.ceil = ceils[x][y];
				
				if (r.ceil - r.floor < 50) {
					r.enterable = null;
				} else {
					if (r.ceil - 50 >= initialLevel) {
						r.enterable = 0.0;
					} else {
						r.enterable = (initialLevel - r.ceil + 50) / 10.0;
					}
				}
				
				rooms[x][y] = r;
			}
		}
		
		this.h = height;
		this.w = width;
		this.initialLevel = initialLevel;
	}
	
	public double compute() {
		edges();
		ArrayList<Room> initial = initialReachability();
		
		if (rooms[w - 1][h - 1].initiallyReachable)
			return 0.0;
		
		findMinTime(initial);
		
		return rooms[w - 1][h - 1].minTime;
	}
	
	void findMinTime(ArrayList<Room> initial) {
		PriorityQueue<Edge> q = new PriorityQueue<Tide.Edge>(initial.size() * 2);
		for (Room r : initial) {
			Edge e = new Edge();
			e.goTo = r;
			e.minTime = 0;
			q.add(e);
		}
		
		while (!q.isEmpty()) {
			Edge walk = q.remove();
			Room curr = walk.goTo;
			if (curr.minTime != null && curr.minTime <= walk.minTime)
				continue;
			
			curr.minTime = walk.minTime;
			for (Edge e : curr.edges) {
				double t = minTime(curr, e.goTo);
				if (e.goTo.minTime != null && e.goTo.minTime <= t)
					continue;
				
				Edge newWalk = new Edge();
				newWalk.goTo = e.goTo;
				newWalk.minTime = t;
				q.add(newWalk);
			}
		}
	}
	
	double minTime(Room from, Room to) {
		double earliestStart = Math.max(from.minTime, to.enterable);
		double waterLevelAtStart = initialLevel - earliestStart * 10.0 - from.floor;
		double fastTimeLeft = (waterLevelAtStart - 20) / 10.0;
		
		if (fastTimeLeft >= 0)
			return earliestStart + 1;
		return earliestStart + 10;
	}
	
	static final int[][] d = {
		{ -1,  0 },
		{  1,  0 },
		{  0,  1 },
		{  0, -1 }
	};
	
	private void edges() {
		ArrayList<Edge> edges = new ArrayList<Edge>();
		
		for (int x = 0; x < w; x++) {
			for (int y = 0; y < h; y++) {
				edges.clear();
				
				Room curr = rooms[x][y];
				for (int[] o : d) {
					int ox = x + o[0];
					int oy = y + o[1];
					if (ox < 0 || oy < 0 || ox >= w || oy >= h)
						continue;
					
					Room next = rooms[ox][oy];
					if (next.enterable == null)
						continue;
					
					if (next.ceil < curr.floor + 50)
						continue;
					if (next.floor > curr.ceil - 50)
						continue;
					
					Edge e = new Edge();
					e.goTo = next;
					edges.add(e);
				}
				
				curr.edges = edges.toArray(new Edge[edges.size()]);
			}
		}
	}
	
	private ArrayList<Room> initialReachability() {
		ArrayList<Room> allReachable = new ArrayList<Tide.Room>();
		
		ArrayDeque<Room> q = new ArrayDeque<Room>();
		q.add(rooms[0][0]);
		while (!q.isEmpty()) {
			Room r = q.removeFirst();
			if (r.initiallyReachable)
				continue;
			allReachable.add(r);
			r.initiallyReachable = true;
			for (Edge e : r.edges) {
				Double en = e.goTo.enterable;
				if (en != null && en == 0.0)
					q.add(e.goTo);
			}
		}
		
		return allReachable;
	}
	
	public static void main(String[] args) throws IOException {
		File f = new File("/home/mitja/cj/B");
		for (File input : f.listFiles()) {
			if (input.isFile() && input.getName().endsWith(".in")) {
				File output = new File(f, input.getName() + ".out");
				
				FileWriter out = new FileWriter(output);
				
				int[][] lines = readInts(input);
				
				int nCases = lines[0][0];
				int line = 1;
				for (int c = 1; c <= nCases; c++) {
					int[] r = lines[line++];
					int initialLevel = r[0];
					int w = r[1];
					int h = r[2];
					
					int[][] floors = new int[w][];
					int[][] ceils = new int[w][];
					System.arraycopy(lines, line, ceils, 0, w);
					line += w;
					System.arraycopy(lines, line, floors, 0, w);
					line += w;
					
					out.append("Case #" + c + ": " + new Tide(w, h, floors, ceils, initialLevel).compute() + "\n");
				}
				
				out.close();
			}
		}
	}

	private static int[][] readInts(File input) throws IOException {
		ArrayList<int[]> out = new ArrayList<int[]>();
		
		LineNumberReader lnr = new LineNumberReader(new FileReader(input));
		
		String l;
		while ((l = lnr.readLine()) != null) {
			String[] parts = l.trim().split(" ");
			
			int[] i = new int[parts.length];
			for (int a = 0; a < parts.length; a++)
				i[a] = Integer.parseInt(parts[a]);
			
			out.add(i);
		}
		
		return out.toArray(new int[out.size()][]);
	}
}
