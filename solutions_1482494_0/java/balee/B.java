import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

// Kingdom Rush
// http://code.google.com/codejam/contest/1645485/dashboard#s=p1

public class B {

	static class X implements Comparable<X> {
		int a;
		int b;
		int c;
		@Override
		public int compareTo(X o) {
			if ( a != o.a )
				return a - o.a;
			return b - o.b;
		}
	}
	
	private static String process(Scanner in) {
		int N = in.nextInt();
		ArrayList<X> arr = new ArrayList<X>();
		for(int i = 0; i < N; i++) {
			X x = new X();
			x.a = in.nextInt();
			x.b = in.nextInt();
			x.c = 0;
			arr.add(x);
		}
		Collections.sort(arr);
/*		for (X x : arr) 
			System.out.println(x.a + " " + x.b);
			*/
		int stars = 0;
		int steps = 0;
		boolean change = false;
		while(arr.size() > 0) {
			change = false;
			for (X x : arr) {
				if ( x.b <= stars ) {
					stars += 2 - x.c;
					steps++;
					change = true;
					arr.remove(x);
					break;
				}
			}
			if ( ! change ) {
				Collections.sort(arr);
				for (X x : arr) {
					if ( x.a <= stars ) {
						stars++;
						steps++;
						change = true;
						break;
					}
				}
			}
			if ( ! change && arr.size() > 0 )
				return "Too Bad";
		}
		return Integer.toString(steps);
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
