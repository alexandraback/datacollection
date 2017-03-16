import java.awt.geom.Point2D;
import java.io.*;
import java.util.*;
import java.text.*;

public class Main implements Runnable{

	/**
	 * @param args
	 */
	private StringTokenizer stReader;
	private BufferedReader bufReader;
	private PrintWriter out;
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		(new Main()).run();
	}

	@Override
	public void run(){
		// TODO Auto-generated method stub
		try {
			bufReader = new BufferedReader(new FileReader("input.txt"));
		} catch (FileNotFoundException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		try {
			out = new PrintWriter(new FileWriter("output.txt"));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		stReader = null;
		Solves();
		out.flush();
	}
	public String ReadLine() {
		String result = null;

		try {
			result = bufReader.readLine();
		} catch (IOException e) {
		}
		return result;
	}
	public String NextString(){
		if (stReader == null || !stReader.hasMoreTokens()){
			stReader = new StringTokenizer(ReadLine(),"\n\r ");
		}
		return stReader.nextToken();
	}
	public int NextInt(){
		return Integer.parseInt(NextString());
	}
	public long NextLong(){
		return Long.parseLong(NextString());
	}
	public double NextDouble(){
		return Double.parseDouble(NextString());
	}
	void Solves(){
		int n = NextInt();
		for(int i =0; i < n; i++){
			out.print("Case #"  +(i + 1) + ": ");
			Solve();
			out.println();
		}
		out.flush();
	}
	/*String PrePath(Point finalPoint){
		String result = "";
		boolean isXstep = true;
		int step = 0;
		while(true){
			
			if (Math.abs(startPoint.X - finalPoint.X) < step
					&& Math.abs(startPoint.Y - finalPoint.Y) < step)
				break;
			
					
		}
	}*/
	Point startPoint;
	void Solve(){
		Point finalPoint = new Point(NextInt(),NextInt(),0,"");
		startPoint = new Point(0,0,0,"");
		//String prePath = PrePath(finalPoint);
		LinkedList<Point> list = new LinkedList<Point>();
		list.add(startPoint);
		Point result = null;
		HashSet<Point> was = new HashSet<Point>();
		was.add(startPoint);
		while(list.size() > 0){
			Point work = list.removeFirst();
			int step = work.step + 1;
			//Point north = new Point(work.X,work.Y + step,step,work.path + "N");
			//Point south = new Point(work.X,work.Y - step,step,work.path + "S");
			Point west = new Point(work.X - step,work.Y ,step,work.path + "W");
			Point east = new Point(work.X + step,work.Y ,step,work.path + "E");
			/*if (finalPoint.compare(north) == 0) {
				result = north;
				break;
			}
			if (finalPoint.compare(south) == 0){
				result = south;
				break;
			}*/
			if (finalPoint.compareX(west) == 0){
				result = west;
				break;
			}
			if (finalPoint.compareX(east) == 0){
				result = east;
				break;
			}
			
			//int curDistanceX = Math.abs(finalPoint.X - work.X);
			//int curDistanceY = Math.abs(finalPoint.Y - work.Y);
			boolean N = false,S = false,W = false,E = false;
			
			//int distanceN = Math.abs(finalPoint.Y - north.Y);
			//int distanceS = Math.abs(finalPoint.Y - south.Y);
			//int distanceW = Math.abs(finalPoint.X - west.X);
			//int distanceE = Math.abs(finalPoint.X - east.X);
			
			//if (distanceN < curDistanceY || work.step > curDistanceY) N = true;
			//if (distanceS < curDistanceY || work.step > curDistanceY) S = true;
			//if (distanceW < curDistanceX || work.step > curDistanceX) W = true;
			//if (distanceE < curDistanceX || work.step > curDistanceX) E = true;
			
			/*if (north.step < 502 && !was.contains(north) && N) {
				was.add(north);
				list.addLast(north);
			}
			if (south.step < 502 && !was.contains(south) && S) {
					was.add(south);
					list.addLast(south);
			}
			*/
			if (west.step < 502 && !was.contains(west)) {
				was.add(west);
				list.addLast(west);
			}
			if (east.step < 502 && !was.contains(east)) {
				was.add(east);
				list.addLast(east);
			}
			
		}
		list.clear();
		list.add(result);
		while(list.size() > 0){
			Point work = list.removeFirst();
			int step = work.step + 1;
			Point north = new Point(work.X,work.Y + step,step,work.path + "N");
			Point south = new Point(work.X,work.Y - step,step,work.path + "S");
			//Point west = new Point(work.X - step,work.Y ,step,work.path + "W");
			//Point east = new Point(work.X + step,work.Y ,step,work.path + "E");
			if (finalPoint.compareY(north) == 0) {
				result = north;
				break;
			}
			if (finalPoint.compareY(south) == 0){
				result = south;
				break;
			}
			
			
			
			if (north.step < 502 && !was.contains(north)) {
				was.add(north);
				list.addLast(north);
			}
			if (south.step < 502 && !was.contains(south)) {
					was.add(south);
					list.addLast(south);
			}
			
		}
		out.print(result.path);
		
	}
	
	class Point implements Comparable<Point>{
		int X,Y;
		String path;
		int step;
		Point(int X,int Y,int step,String path){
			this.X = X;
			this.Y = Y;
			this.path = path;
			this.step = step;
		}

		public int compareX(Point arg0){
			//if (Math.abs(this.X) == Math.abs(arg0.X) && Math.abs(this.Y) == Math.abs(arg0.Y)) return 0;
			if (this.X == arg0.X) return 0;
			return -1;
		}
		public int compareY(Point arg0){
			//if (Math.abs(this.X) == Math.abs(arg0.X) && Math.abs(this.Y) == Math.abs(arg0.Y)) return 0;
			if (this.Y == arg0.Y) return 0;
			return -1;
		}
		@Override
		public int compareTo(Point arg0) {
			if (this.X != arg0.X) return this.X - arg0.X;
			if (this.Y != arg0.Y) return this.Y - arg0.Y;
			if (this.step != arg0.step) return this.step - arg0.step;
			return 0;
		}
	}
}
