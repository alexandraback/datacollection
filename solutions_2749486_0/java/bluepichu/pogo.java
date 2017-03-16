//Program by Matthew Savage
//With help from the TJHSST SCT Grader Example Class

import java.io.*;
import java.util.*;
import java.awt.Point;

public class pogo{
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("pogo.out")));
		
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= testCases; t++){
			pw.print("Case #" + t + ": ");
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			
			HashMap oldPoints = new HashMap<Point, String>();
			oldPoints.put(new Point(0, 0), "");
			HashMap newPoints = new HashMap<Point, String>();
			Point target = new Point(x, y);
			
			for(int i = 1; i <= 500; i++){
				for(Point p : (Set<Point>)(oldPoints.keySet())){
					newPoints.put(new Point(p.x, p.y+i), oldPoints.get(p) + "N");
					newPoints.put(new Point(p.x, p.y-i), oldPoints.get(p) + "S");
					newPoints.put(new Point(p.x+i, p.y), oldPoints.get(p) + "E");
					newPoints.put(new Point(p.x-i, p.y), oldPoints.get(p) + "W");
				}
				
				if(newPoints.keySet().contains(target)){
					break;
				}
				
				oldPoints = newPoints;
				newPoints = new HashMap<Point, String>();
			}
			
			pw.println(newPoints.get(target));
		}
		
		br.close();
		pw.close();
	}
}