import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;


public class HikingDeer {
	HikingDeer(Scanner in, PrintWriter out){
		int tests = in.nextInt();
		for(int t = 1; t<=tests; t++){
			int n = in.nextInt();
			ArrayList<Hiker> ary = new ArrayList<>();
			for(int i = 0; i<n; i++){
				int d = in.nextInt();
				int h = in.nextInt();
				int m = in.nextInt();
				for(int j = 0; j<h; j++)
					ary.add(new Hiker(d, m+j));
			}
			Collections.sort(ary);
			
			int min = 0;
			Hiker cur = null;
			for(Hiker h: ary){
				if(cur == null)
					cur = h;
				else{
					if(cur.rev*(360L-cur.start) < h.rev*(360L-h.start+360))
						continue;
					if(h.rev < cur.rev){
						min++;
						cur = h;
					}
				}
			}
			
//			int min = ary.size();
//			if(ary.size()==1)
//				min = 0;
//			else{
//				Hiker h1 = ary.get(0);
//				Hiker h2 = ary.get(1);
//				if(h1.rev*(360L-h1.start) < h2.rev*(360L-h2.start+360))
//			}
			out.printf("Case #%d: %d\n", t, min);
		}
		out.close();
	}
	class Hiker implements Comparable<Hiker> {
		int rev, start;
		Hiker(int s, int r){
			start = s;
			rev = r;
		}
		@Override
		public int compareTo(Hiker o) {
			if(start != o.start)
				return Integer.compare(start, o.start);
			return -Integer.compare(rev, o.rev);
		}
	}
	public static void main(String[] args) throws FileNotFoundException {
		String name = "C-small-1-attempt1";
//		new HikingDeer(new Scanner(System.in), new PrintWriter(System.out));
		new HikingDeer(new Scanner(new File(name+".in")), new PrintWriter(new File(name+".out")));
	}
}
