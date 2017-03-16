package y2013.Round1C;

import static java.util.Arrays.deepToString;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

/**
 * 
 * @author PierreB 
 * Notes:
 * For the small dataset I just need to reach the required location.
 * For the big dataset I need the shortest path.
 * E.g. Graph Theory
 * E.g. Dijiskstra's Algorithm. / BFS
 * So what model to use?
 * Vertex = point in (x, y)
 * Edge = direction.
 * I want minimum number of edges.
 */
public class B {
	final String ROUND = "Round1C";
	final char [] direction = {'N', 'E', 'S', 'W'};
	
	private class Coord {
		int x, y;
		String path;
		int nextJump;
		public Coord(int x, int y, String path, int nextJump) {
			this.x = x;
			this.y = y;
			this.path = path;
			this.nextJump = nextJump;
		}
		
		public boolean equals(Object y) {
			Coord that = (Coord) y;
			if(this.y != that.y) {return false;}
			if(this.x != that.x) {return false;}
			if(this.nextJump != that.nextJump) {return false;}
			return true;
		}
		
		public boolean coordEquals(Coord that) {
			if(this.y != that.y) {return false;}
			if(this.x != that.x) {return false;}
			return true;
		}
		
		public int hashCode() {
			Integer xi = x;
			Integer yi = y;
			return xi.hashCode()*31 + yi.hashCode();
		}
		
		public String toString() {
			return "x: "+x+" ,y: "+y+" ,j:"+nextJump+" "+path;
		}
	}
	
	Coord end;
	int x, y;
	void read(Scanner sc) {
		x = sc.nextInt();
		y = sc.nextInt();
		end = new Coord(x, y, "", 0);
	}

	void solve() {
		Queue<Coord> q = new Queue<Coord>();
		HashSet<Coord> seen = new HashSet<Coord>();
		Coord nll = new Coord(0,0,"",1);
		q.enqueue(nll);
		
		while(!q.isEmpty()) {
			Coord temp = q.dequeue();
			if(seen.contains(temp)) {
				continue;
			}
			seen.add(temp);
			if(temp.coordEquals(end)) {
				System.out.println(temp.path);
				break;
			}
			q.enqueue(new Coord(temp.x+temp.nextJump,temp.y, temp.path + "E", temp.nextJump+1));
			q.enqueue(new Coord(temp.x, temp.y+temp.nextJump, temp.path + "N", temp.nextJump+1));
			q.enqueue(new Coord(temp.x-temp.nextJump, temp.y, temp.path + "W", temp.nextJump+1));
			q.enqueue(new Coord(temp.x, temp.y-temp.nextJump, temp.path + "S", temp.nextJump+1));
		}
	}

	// EXTRA METHODS

	void run() throws FileNotFoundException {
		Scanner sc = new Scanner(new File("y2013/" + ROUND + "/b.in"));
		int caseN = sc.nextInt();
		for (int caseID = 1; caseID <= caseN; caseID++) {
			read(sc);
			System.out.printf("Case #%d: ", caseID);
			solve();
			System.out.flush();
		}
	}

	void debug(Object... os) {
		System.err.println(deepToString(os));
	}

	public static void main(String[] args) {
		try {
			new B().run();
		} catch (FileNotFoundException e) {
			System.out.println(e.getMessage());
			System.out.println(System.getProperty("user.dir"));
		}
	}
}
