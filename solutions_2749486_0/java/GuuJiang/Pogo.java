import java.awt.Point;
import java.io.File;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Pogo {
	
	private Scanner cin;
	private PrintStream cout;
	/**
	 * @param args
	 * @throws Exception 
	 */
	public static void main(String[] args) throws Exception {
		new Pogo().solve();
	}

	public void solve() throws Exception {
		/*
		cin = new Scanner(System.in);
		cout = System.out;
		/*/
		cin = new Scanner(new File("B-small-attempt1.in"));
		cout = new PrintStream("B-small-attempt1.out");
		//*/
		int no = cin.nextInt();
		for (int i = 1; i <= no; ++i) {
			cout.printf("Case #%d: %s\n", i, solveCase(i));
		}
	}
	
	private String solveCase(int no) throws Exception {
		MyPoint target = new MyPoint(cin.nextInt(), cin.nextInt());
		Set<MyPoint> prev = new HashSet<>();
		Set<MyPoint> next = new HashSet<>();
		Set<MyPoint> temp;
		char[] dirs = {'N', 'S', 'E', 'W'};
		prev.add(new MyPoint(0, 0));
		int step = 1;
		while (true) {
			for (MyPoint pt : prev) {
				for (char dir : dirs) {
					MyPoint t = new MyPoint(pt, step, dir);
					if (t.equals(target)) {
						return t.path;
					}
					next.add(t);
				}
			}
			temp = prev;
			prev = next;
			next = temp;
			next.clear();
			++step;
		}
	}
}

class MyPoint extends Point {
	String path = "";

	public MyPoint(int x, int y) {
		super(x, y);		
	}
	
	public MyPoint(MyPoint p, int step, char dir) {
		super(p.x, p.y);
		path = p.path + dir;
		switch (dir) {
		case 'N':
			y += step;
			break;
		case 'S':
			y -= step;
			break;
		case 'E':
			x += step;
			break;
		case 'W':
			x -= step;
			break;
		}
	}
}
