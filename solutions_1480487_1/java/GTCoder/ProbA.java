import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;


public class ProbA {
	public static class Point implements Comparable<Point> {
		int index;
		int point;
		double votes = 0d;
		@Override
		public int compareTo(Point that) {
			return this.point < that.point ? -1 : this.point == that.point ? 0 : 1;
		}
	}
	
	public static void solve(Point[] points, int N) throws Exception {
		Arrays.sort(points);
		double average = 0d;
		for(int i = 0; i<N; i++) 
			average += points[i].point;

		double diff = 0;
		int i = 1;
		for(; i<N; i++) {
			if((diff + i*(points[i].point - points[i-1].point) ) > average ) {
				break;
			} else {
				diff += i* (points[i].point - points[i-1].point);
			}
		}
		double total = 0;
		for(int j = 0; j<i; j++) total += points[j].point;
		total += average;
		double distr = total / i;
		for(int j=0; j<i; j++) {
			points[j].votes = ((distr-points[j].point)/average) * 100;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));
		String line = in.readLine();
		int T = Integer.parseInt(line);
		for (int i = 1; i <= T; i++) {
			line = in.readLine();
			String[] comps = line.split("\\s+");
			int N = Integer.parseInt(comps[0]);
			Point[] points = new Point[N];
			Point[] toBeSorted = new Point[N];
			for(int j=0; j<N; j++) {
				Point p = new Point();
				p.point = Integer.parseInt(comps[j+1]);
				points[j] = p;
				toBeSorted[j] = p;
			}

			out.print("Case #" + i + ": ");
			solve(toBeSorted, N);
			for(int j = 0; j<N-1; j++) {
				out.print(points[j].votes + " ");
			}
			out.println(points[N-1].votes);

		}

		out.flush();
		in.close();
		out.close();
	}
}
