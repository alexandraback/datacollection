package round1C;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

public class ProblemB {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("round1C/B-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new File("round1C/out.txt"));

		int T = sc.nextInt();
		sc.nextLine();

		for (int tc = 1; tc <= T; tc++) {

			int targetX = sc.nextInt();
			int targetY = sc.nextInt();


			printSolution(out, tc, naive(targetX,targetY));
		}
		out.close();
		sc.close();
	}

	public static String naive(int targetX, int targetY) {
		String path = "";
		int x = 0; 
		int y = 0;
		int jump = 1;
		if (y != targetY) {
			boolean north = y > 0;
			// get y
			while (y != targetY) {
				if (north) {
					y += jump;
					path += "N";
				} else {
					y -= jump;
					path += "S";
				}
				jump++;
				north = !north;
			}
			if (x == targetX)
				return path;
		}
		boolean east = targetX > 0;
		while (Math.abs(x) < Math.abs(targetX)) {
			if (east) {
				x += jump;
				path += "E";
			} else {
				x -= jump;
				path += "W";
			}
			jump++;
		}
		if (targetX == x)
			return path;
		if (east) {
			x += jump;
			path += "E";
		} else {
			x -= jump;
			path += "W";
		}
		jump++;
		east = !east;
		while (x != targetX) {
			if (east) {
				x += jump;
				path += "E";
			} else {
				x -= jump;
				path += "W";
			}
			jump++;
			east = !east;
		}
		if (path.length() > 500)
			System.out.println("TOO LONG "+path.length());
		return path;
	}
	public static String bfs(int targetX, int targetY) {
		LinkedList<Node>  open = new LinkedList<Node>();
		LinkedList<Node>  closed = new LinkedList<Node>();
		open.add(new Node(0,0,1,""));
		while (!open.isEmpty()) {
			Node current = open.remove();
			if (current.x == targetX && current.y == targetY) 
				return current.path;
			Iterator<Node> it = closed.iterator();
			boolean ok = true;
			while(it.hasNext() && ok) {
				Node test = it.next();
				if (test.x == current.x && test.y == current.y)
					ok = false;
			}
			if (ok) {
				//System.out.println(current.path);
				closed.add(current);
				Node north = new Node(current.x,current.y+current.jump,current.jump+1,current.path+"N");
				Node south = new Node(current.x,current.y-current.jump,current.jump+1,current.path+"S");
				Node east = new Node(current.x+current.jump,current.y,current.jump+1,current.path+"E");
				Node west = new Node(current.x-current.jump,current.y,current.jump+1,current.path+"W");
				open.add(north);
				open.add(south);
				open.add(east);
				open.add(west);
			}
		}
		return "NOT FOUND";
	}
	public static String search(int n, int x, int y, String path, int targetX, int targetY) {
		System.out.println(x+" "+y);
		if (x == targetX && y == targetY)
			return path;
		else if (n == 0) 
			return "";
		else {
			String v = search(n-1,x+n,y,path+"N",targetX,targetY);
			if (v.length() > 0)
				return v;
			v = search(n-1,x-n,y,path+"S",targetX,targetY);
			if (v.length() > 0)
				return v;
			v = search(n-1,x,y+n,path+"W",targetX,targetY);
			if (v.length() > 0)
				return v;
			v = search(n-1,x,y-n,path+"E",targetX,targetY);
			if (v.length() > 0)
				return v;
		}
		return "";

	}
	public static void printSolution(PrintWriter out, int tc, String soln) {
		out.println("Case #"+tc+": "+soln);
		out.flush();
		System.out.println("Case #"+tc+": "+soln);

	}
}
class Node {
	int x = 0;
	int y = 0;
	String path = "";
	int jump = 0;
	public Node(int x, int y, int jump,String path) {
		this.x = x;
		this.y = y;
		this.jump = jump;
		this.path = path;
	}
}