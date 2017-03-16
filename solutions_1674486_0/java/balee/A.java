import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

// Diamond Inheritance
// http://code.google.com/codejam/contest/1781488/dashboard#s=p0

public class A {

	private static String process(Scanner in) {
		int N = in.nextInt();
		ArrayList<TreeSet<Integer>> r = new ArrayList<TreeSet<Integer>>(); 
		ArrayList<HashMap<Integer, Integer>> reason = new ArrayList<HashMap<Integer, Integer>>(); 
		for(int i = 0; i < N; i++) {
			int m = in.nextInt();
			HashMap<Integer, Integer> ar = new HashMap<Integer, Integer>();
			reason.add(ar);
			TreeSet<Integer> a = new TreeSet<Integer>();
			r.add(a);
			for(int j = 0; j < m; j++) {
				int value = in.nextInt() - 1;
				a.add(value);
				ar.put(value, i);
			}
		}
		boolean change = true;
		while( change ) {
			change = false;
			for(int i = 0; i < N; i++) {
				TreeSet<Integer> a = r.get(i);
				HashMap<Integer, Integer> ar = reason.get(i);
				TreeSet<Integer> x = new TreeSet<Integer>();
				for (Integer ia : a) {
					TreeSet<Integer> b = r.get(ia);
					HashMap<Integer, Integer> iar = reason.get(ia);
					for (Integer ib : b) {
						if ( ! a.contains(ib) ) {
							x.add(ib);
							ar.put(ib, iar.get(ib));
							change = true;
						}
						else if ( ar.get(ib) != iar.get(ib) )
							return "Yes";
					}
				}
				a.addAll(x);
			}
		}
		return "No";
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
