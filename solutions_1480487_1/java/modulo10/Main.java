
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;


public class Main {
	public static void main(String[] args) {
		InputStream in = System.in;
		PrintStream out = System.out;
		if (args.length > 0) {
			try {
				in = new FileInputStream(args[0]);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}
		Scanner scanner = new Scanner(in);
		int cases = scanner.nextInt();
		for (int i = 1; i <= cases; ++i) {
			int nc = scanner.nextInt();
			int sum = 0;
			Points[] order = new Points[nc];
			
			for (int j = 0; j < order.length; ++j) {
				int k = scanner.nextInt();
				sum += k;
				Points p =new Points();
				p.index = j;
				p.points = k;
				p.add = 0;
				order[j] = p;
			}
			
			Arrays.sort(order, new Comparator<Points>() {

				@Override
				public int compare(Points o1, Points o2) {
					return o1.points - o2.points;
				}
			});
			
			int points = sum;
			int j = 0;
			for (j = find(order); points >= j; j = find(order)) {
				for (int k = 0; k < j; k++) {
					order[k].add+=1;
					points--;
				}
			}
			if (points > 0) {
				for (int k = 0; k < j; k++) {
					order[k].add+=((double)points)/j;
				}
			}
			
			Arrays.sort(order, new Comparator<Points>() {

				@Override
				public int compare(Points o1, Points o2) {
					return o1.index - o2.index;
				}
			});
			
			out.format("Case #%d:",i);
			for (Points points2 : order) {
				out.print(' ');
				out.print(100*points2.add/sum);
			}
			out.println();
		}
	}
	
	private static int find(Points[] p) {
		int r = 1;
		Points v;
		int s;
		if (p.length == 0) {
			return 0;
		}
		v = p[0];
		s = v.points + (int)(v.add+0.5);
		for (r = 1; r < p.length; ++r) {
			v=p[r];
			int t = v.points + (int)(v.add+0.5);
			if (t != s) {
				break;
			}
		}
		return r;
	}
	
	private static class Points {
		public int index;
		public int points;
		public double add;
	}
}
