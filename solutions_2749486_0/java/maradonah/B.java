import java.io.*;
import java.util.*;

public class B {
	static int [] dx = {1, -1, 0, 0};
	static int [] dy = {0, 0, 1, -1};
	static char [] dir = {'E', 'W', 'N', 'S'};
	public static void main(String[] args) throws IOException {
		BufferedInputStream bis = new BufferedInputStream(new FileInputStream("B-small-attempt0.in"));
		BufferedReader br = new BufferedReader(new InputStreamReader(bis));
		PrintWriter out = new PrintWriter(new File("B-small-attempt0.out"));
		StringTokenizer st;
		int cases = Integer.parseInt(br.readLine().trim());
		for (int c = 1; c <= cases; c++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			State top = new State(0, 0, 0, "");
			out.println("Case #" + c + ": " + findSolution(top, X, Y));
		}
		out.close();
	}
	public static String findSolution(State t, int X, int Y) {
		LinkedList <State> q = new LinkedList<State>();
		q.add(t);
		HashSet <State> visited = new HashSet<State>();
		visited.add(t);
		while(!q.isEmpty()) {
			t = q.removeFirst();
			if(t.X == X && t.Y == Y) {
				return t.path;
			}
			for (int i = 0; i < dx.length; i++) {
				int nsteps = t.steps+1;
				State n = new State(nsteps, t.X+dx[i]*nsteps, t.Y+dy[i]*nsteps, t.path+dir [i]);
				if(!visited.contains(n)) {
					visited.add(n);
					q.add(n);
				}
			}
		}
		return "";
	}
}
class State {
	int steps;
	int X;
	int Y;
	String path;
	public State(int steps, int x, int y, String pa) {
		super();
		this.steps = steps;
		X = x;
		Y = y;
		path = pa;
	}
	public int hashCode() {
		return X*1000+Y+steps*1000000;
	}
	public boolean equals(Object o) {
		State other = (State)o;
		return other.steps == steps && X == other.X && Y == other.Y;
	}
	public String toString() {
		return "State [steps=" + steps + ", X=" + X + ", Y=" + Y + "]";
	}
	
}