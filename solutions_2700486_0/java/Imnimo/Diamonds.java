import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;


public class Diamonds {
	static ArrayList<DiamondField> all = new ArrayList<DiamondField>();
	public static void main(String[] args) {
		try {
			Scanner s = new Scanner(new File("B-small.in"));
			int numCases = Integer.parseInt(s.nextLine());
			for(int c = 1;c<=numCases;c++) {
				String problem = s.nextLine();
				String[] items = problem.split(" ");
				int numDrops = Integer.parseInt(items[0]);
				int x = Integer.parseInt(items[1]);
				int y = Integer.parseInt(items[2]);
				
				all = new ArrayList<DiamondField>();
				ArrayList<DiamondField> current = new ArrayList<DiamondField>();
				current.add(new DiamondField());
				for(int i = 0;i<numDrops;i++) {
					//System.out.println("DROP # " + i + " SIZE " + current.size());
					all = new ArrayList<DiamondField>();
					for(DiamondField p : current) {
						drop2(0,40,p);
					}
					current = all;
					
				}
				
				double count = 0;
				double total = 0;
				Point test = new Point(x,y);
				for(DiamondField p : current) {
					if(p.points.contains(test)) {
						count+=p.prob;
					}
					total+=p.prob;
				}
				System.out.println("Case #" + c + ": " + count/total);
				//System.out.println(count + " / " + total + " from " + current.size());
				
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	public static void drop2(int x, int y, DiamondField points) {
		
		
		//System.out.println("AT " + x  + ", " + y + " WITH PROB " + points.prob);
		
		//hit ground
		if(y==0) {
			//System.out.println("Hit Ground");
			DiamondField temp = new DiamondField();
			
			temp.points.addAll(points.points);
			temp.points.add(new Point(x,y));
			temp.prob = points.prob;
			
			all.add(temp);
			return;
		}
		Point belowLeft = new Point(x-1,y-1);
		Point belowRight = new Point(x+1,y-1);
		
		
		//hit edge of diamond left, right is open
		if(points.points.contains(belowLeft) && !points.points.contains(belowRight)) {
			//System.out.println("SLIDE RIGHT");
			drop2(x+1,y-1,points);
			return;
		}
	
		
		
		//hit edge of diamond right, left is open
		
		else if(points.points.contains(belowRight) && !points.points.contains(belowLeft)) {
			//System.out.println("SLIDE LEFT");
			drop2(x-1,y-1,points);
			return;
		}
		
		//hit both left and right
		else if(points.points.contains(belowRight) && points.points.contains(belowLeft)) {
			//System.out.println("TRAPPED");
			DiamondField temp = new DiamondField();
			temp.points.addAll(points.points);
			temp.points.add(new Point(x,y));
			temp.prob = points.prob;
			all.add(temp);
			return;
		}
		
		//hit tip of diamond two below, both left and right are open
		Point below = new Point();
		below.x = x;
		below.y = y-2;
		if(points.points.contains(below)) {
		//	System.out.println("HIT BELOW");
			DiamondField temp = new DiamondField();
			temp.points.addAll(points.points);
			temp.prob = points.prob/2;
			drop2(x-1,y-1,temp);
			drop2(x+1,y-1,temp);
			return;
		}
		
		drop2(x,y-1,points);
		
	}
}
class DiamondField {
	TreeSet<Point> points;
	double prob;
	public DiamondField() {
		points = new TreeSet<Point>();
		prob = 1;
	}
}
	
class Point implements Comparable<Point>{
	int x, y;
	public Point(){}
	public Point(int a, int b) {
		x = a;
		y = b;
	}
	public boolean equals(Object o) {
		if(o instanceof Point) {
			Point p = (Point)o;
			return x == p.x && y == p.y;
		}
		return false;
	}
	@Override
	public int compareTo(Point arg0) {
		if(y>arg0.y) {
			return 1;
		}
		if(y<arg0.y) {
			return -1;
		}
		if(x>arg0.x) {
			return 1;
		}
		if(x<arg0.x) {
			return -1;
		}
		return 0;
	}
	public int hashCode() {
		return x + 31*y*(y+1);
	}
}
