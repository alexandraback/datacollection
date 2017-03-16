import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class FallingDiamonds {

	public static class Point {
		int x;
		int y;

		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "[x=" + x + ", y=" + y + "]";
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj) return true;
			if (obj == null) return false;
			if (getClass() != obj.getClass()) return false;
			Point other = (Point) obj;
			if (x != other.x) return false;
			if (y != other.y) return false;
			return true;
		}
	}
	
	private List<List<Boolean>> leftRight = new ArrayList<List<Boolean>>();

	private double getProbability(int diamonds, int x, int y) {
		if (x == 0 && y == 0) return 1;
		Point target = new Point(x, y);

		List<Point> points = new ArrayList<Point>();
		if (diamonds >= 15) {
			for (int i = 5; i >= 1; i--) {
				for (int j = -i + 1; j < i; j += 2) {
					points.add(new Point(j, 5 - i));
				}
			}
			for (int i = 0; i < points.size(); i++) {
				if (target.equals(points.get(i))) return 1;
			}

			if (diamonds == 15) return 0;
			diamonds -= 15;
			rec(new ArrayList<Boolean>(), diamonds, 5);
			
			List<List<Point>> seqs = new ArrayList<List<Point>>();
			
			for (int i = 0; i < leftRight.size(); i++) {
				List<Point> ps = new ArrayList<FallingDiamonds.Point>();
				Point left = null;
				Point right = null;
				List<Boolean> lr = leftRight.get(i);
				for (int j = 0; j < lr.size(); j++) {
					if (lr.get(j)) {
						if (left == null) {
							left = new Point(-6, 0);
						} else {
							left = new Point(left.x + 1, left.y + 1);
						}
						ps.add(left);
					} else {
						if (right == null) {
							right = new Point(6, 0);
						} else {
							right = new Point(right.x - 1, right.y + 1);
						}
						ps.add(right);
					}
				}
				seqs.add(ps);
			}
			
//			for (int i = 0; i < seqs.size(); i++) {
//				for (int j = i + 1; j < seqs.size(); j++) {
//					if (seqs.get(i).containsAll(seqs.get(j))) {
//						seqs.remove(j);
//						j--;
//					}
//				}
//			}
			
			int tempIn = 0;
			for (int i = 0; i < seqs.size(); i++) {
				if (seqs.get(i).contains(target)) tempIn++;
			}
			
			return (double) tempIn / (double) seqs.size();
		} else if (diamonds >= 6) {

			for (int i = 3; i >= 1; i--) {
				for (int j = -i + 1; j < i; j += 2) {
					points.add(new Point(j, 3 - i));
				}
			}
			for (int i = 0; i < points.size(); i++) {
				if (target.equals(points.get(i))) return 1;
			}

			if (diamonds == 6) return 0;
			diamonds -= 6;
			rec(new ArrayList<Boolean>(), diamonds, 4);
			
			List<List<Point>> seqs = new ArrayList<List<Point>>();
			
			for (int i = 0; i < leftRight.size(); i++) {
				List<Point> ps = new ArrayList<FallingDiamonds.Point>();
				Point left = null;
				Point right = null;
				List<Boolean> lr = leftRight.get(i);
				for (int j = 0; j < lr.size(); j++) {
					if (lr.get(j)) {
						if (left == null) {
							left = new Point(-4, 0);
						} else {
							left = new Point(left.x + 1, left.y + 1);
						}
						ps.add(left);
					} else {
						if (right == null) {
							right = new Point(4, 0);
						} else {
							right = new Point(right.x - 1, right.y + 1);
						}
						ps.add(right);
					}
				}
				seqs.add(ps);
			}
			
//			for (int i = 0; i < seqs.size(); i++) {
//				for (int j = i + 1; j < seqs.size(); j++) {
//					if (seqs.get(i).containsAll(seqs.get(j))) {
//						seqs.remove(j);
//						j--;
//					}
//				}
//			}
			
			int tempIn = 0;
			for (int i = 0; i < seqs.size(); i++) {
				if (seqs.get(i).contains(target)) tempIn++;
			}
			
			return (double) tempIn / (double) seqs.size();
			
		} else if (diamonds >= 1) {
			
			points.add(new Point(0, 0));
			for (int i = 0; i < points.size(); i++) {
				if (target.equals(points.get(i))) return 1;
			}

			if (diamonds == 1) return 0;
			diamonds -= 1;
			rec(new ArrayList<Boolean>(), diamonds, 2);
			
			List<List<Point>> seqs = new ArrayList<List<Point>>();
			
			for (int i = 0; i < leftRight.size(); i++) {
				List<Point> ps = new ArrayList<FallingDiamonds.Point>();
				Point left = null;
				Point right = null;
				List<Boolean> lr = leftRight.get(i);
				for (int j = 0; j < lr.size(); j++) {
					if (lr.get(j)) {
						if (left == null) {
							left = new Point(-2, 0);
						} else {
							left = new Point(left.x + 1, left.y + 1);
						}
						ps.add(left);
					} else {
						if (right == null) {
							right = new Point(2, 0);
						} else {
							right = new Point(right.x - 1, right.y + 1);
						}
						ps.add(right);
					}
				}
				seqs.add(ps);
			}
			
//			for (int i = 0; i < seqs.size(); i++) {
//				for (int j = i + 1; j < seqs.size(); j++) {
//					if (seqs.get(i).containsAll(seqs.get(j))) {
//						seqs.remove(j);
//						j--;
//					}
//				}
//			}
			
			int tempIn = 0;
			for (int i = 0; i < seqs.size(); i++) {
				if (seqs.get(i).contains(target)) tempIn++;
			}
			
			return (double) tempIn / (double) seqs.size();
		}
		
		return 0;
	}

	void rec(List<Boolean> list, int diamonds, int constraint) {
		if (diamonds == 0) {
			leftRight.add(new ArrayList<Boolean>(list));
			return;
		}
		
		int lefts = 0;
		int rights = 0;
		for (int i = 0; i < list.size(); i++) {
			if (list.get(i)) {
				lefts++;
			} else {
				rights++;
			}
		}
		if (lefts < constraint) {
			list.add(true);
			rec(list, diamonds - 1, constraint);
			list.remove(list.size() - 1);
		}
		
		if (rights < constraint) {
			list.add(false);
			rec(list, diamonds - 1, constraint);
			list.remove(list.size() - 1);
		}
	}

	public static final String INPUT_FILE_PATH = "C://DiskD//CodeJamInput.txt";
	public static final String OUTPUT_FILE_PATH = "C://DiskD//CodeJamOutput.txt";

	public static void main(String[] args) {
		Scanner in = null;
		PrintWriter writer = null;
		try {
			System.out.println("start");

			in = new Scanner(new File(INPUT_FILE_PATH));
			writer = new PrintWriter(new FileWriter(OUTPUT_FILE_PATH));
			int testCount = in.nextInt();

			for (int i = 0; i < testCount; i++) {
				int diamonds = in.nextInt();
				int x = in.nextInt();
				int y = in.nextInt();

				System.out.println(i);
				writer.println("Case #" + (i + 1) + ": " + new FallingDiamonds().getProbability(diamonds, x, y));
			}
			writer.flush();

			System.out.println("end");
		} catch (IOException ex) {
			ex.printStackTrace();
		} finally {
			if (in != null) in.close();
			if (writer != null) writer.close();
		}
	}

}
