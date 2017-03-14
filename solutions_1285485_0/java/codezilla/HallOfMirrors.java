package codejam2012;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class HallOfMirrors {

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new BufferedReader(new FileReader(
				"A-large-practice.in.txt")));
		Output out = new Output("D.out");

		int T = scanner.nextInt();

		for (int t = 1; t <= T; t++) {

			int H = scanner.nextInt();
			int W = scanner.nextInt();
			int D = scanner.nextInt();
			scanner.nextLine();

			int x0 = 0;
			int y0 = 0;

			for (int i = 0; i < H; i++) {

				char[] arr = scanner.next().toCharArray();
				for (int j = 0; j < W; j++) {
					if (arr[j] == 'X') {
						x0 = j - 1;
						y0 = i - 1;
					}
				}
			}

			// flip board around
			List<Point> xList = new ArrayList<Point>();
			xList.add(new Point(x0, y0));
			int xMin = 0, xMax = W-2;
			int yMin = 0, yMax = H-2;
			while(xMax <= D){
				int size = xList.size();
				for(int i = 0; i < size; i ++){
					Point p = new Point(xList.get(i));
					p.x = 2 * xMax - p.x -1;
					xList.add(p);
				}
				xMax = (xMax - xMin) * 2;
			}
			
			while(-xMin <= D){
				int size = xList.size();
				for(int i = 0; i < size; i ++){
					Point p = new Point(xList.get(i));
					p.x = 2 * xMin - p.x -1;
					xList.add(p);
				}
				xMin = 2 * xMin - xMax;
			}

			while(yMax <= D){
				int size = xList.size();
				for(int i = 0; i < size; i ++){
					Point p = new Point(xList.get(i));
					p.y = 2 * yMax - p.y -1;
					xList.add(p);
				}
				yMax = (yMax - yMin) * 2;
			}
			
			while(-yMin <= D){
				int size = xList.size();
				for(int i = 0; i < size; i ++){
					Point p = new Point(xList.get(i));
					p.y = 2 * yMin - p.y -1;
					xList.add(p);
				}
				yMin = 2 * yMin - yMax;
			}
			
			//System.out.println(xList);
			
			List<Point> candidateList = new ArrayList<Point>();
			
			for(Point p : xList){
				if(p.x == x0 && p.y == y0){
					continue;
				}
				
				int xx = p.x - x0;
				int yy = p.y - y0;
				if(xx * xx + yy * yy <= D * D){
					candidateList.add(p);
				}
			}
			//System.out.println(candidateList);
			
			int count = candidateList.size();
			for(int i = 0; i < candidateList.size() - 1; i ++){
				
				Point p1 = candidateList.get(i);
				if(p1.disabled){
					continue;
				}
				
				for(int j = i + 1; j < candidateList.size(); j ++){
					Point p2 = candidateList.get(j);
					
					if(p2.disabled){
						continue;
					}
					
					if(sameLine(x0, p1.x, p2.x, y0, p1.y, p2.y)){
						count--;
						p2.disabled = true;
					}
				}
			}
			out.format("Case #%d: %d\n", t, count);
		}

		scanner.close();
		out.close();
	}
	
	private static boolean sameLine(int x0, int x1, int x2, int y0,
			int y1, int y2) {
		return (y1 - y0) * (x2 - x0) == (x1 - x0) * (y2 - y0) &&
				Math.signum(y2 - y0) == Math.signum(y1 - y0) &&
				Math.signum(x2 - x0) == Math.signum(x1 - x0);
	}
	
	static class Point{
		int x,y;
		boolean disabled = false;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public Point(Point p) {
			this.x = p.x;
			this.y = p.y;
		}
		
		public String toString(){
			return this.x + "," + this.y;
		}
	}

	static class Output {

		PrintWriter pw;

		public Output(String filename) throws IOException {
			pw = new PrintWriter(new BufferedWriter(new FileWriter(filename)));
		}

		public void print(String s) {
			pw.print(s);
			System.out.print(s);
		}

		public void println(String s) {
			pw.println(s);
			System.out.println(s);
		}

		public void format(String format, Object... args) {
			pw.format(format, args);
			System.out.format(format, args);
		}

		public void close() {
			pw.close();
		}
	}

}
