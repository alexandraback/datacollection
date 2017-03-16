import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;


public class B {

	static PrintStream out;
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(args[0]));
	 	out = new PrintStream(args[0] + ".out");
	 	
	 	int T = Integer.parseInt(in.readLine());
	 	
	 	for (int t = 1; t <= T; t++) {
	 		String[] next = in.readLine().split(" ");
	 		int X = Integer.parseInt(next[0]);
	 		int Y = Integer.parseInt(next[1]);
	 		
	 		Point target = new Point(X,Y);
	 		
	 		Map<Point,String> pointsReached = new HashMap<Point,String>();
	 		pointsReached.put(new Point(0,0),"");
	 		for (int i = 1; i <= 500; i++) {
	 			Map<Point,String> nextMap = new HashMap<Point,String>();
	 			for (Map.Entry<Point, String> entry : pointsReached.entrySet()) {
	 				nextMap.putAll(getNext(entry.getKey(), entry.getValue(), i));
	 			}
	 			pointsReached = nextMap;
	 			if (pointsReached.containsKey(target)) {
	 				print(t,pointsReached.get(target));
	 				break;
	 			}
	 		}
	 			
	 		
	 	}
	}
	
	private static void print(int t, String val) {
		out.println(String.format("Case #%d: %s", t, val));
	}
	
	public static Map<Point,String> getNext(Point p, String path, int n) {
		Map<Point,String> next = new HashMap<Point,String>();
		next.put(new Point(p.x, p.y + n), path + "N");
		next.put(new Point(p.x, p.y - n), path + "S");
		next.put(new Point(p.x + n, p.y), path + "E");
		next.put(new Point(p.x - n, p.y), path + "W");
		return next;
	}
	
	
}
class Point {
	int x;
	int y;
	
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
	
	public boolean equals(Object o) {
		if (!(o instanceof Point)) {
			return false;
		}
		Point other = (Point)o;
		return (other.x == this.x && other.y == this.y);
	}
	
	public int hashCode() {
		return 1000 * x + y;
	}
}
