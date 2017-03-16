import java.io.File;
import java.util.*;

public class D {
	
	public static void main(String[] args) throws Exception {
		int[] powers = new int[1048577];
		int ccccc = 0;
		for (int i = 1; i < powers.length; i = (i << 1)) {
			powers[i] = ccccc;
			ccccc++;
		}
		
		Scanner sc = new Scanner(new File("D2.in"));
		int tt = sc.nextInt();
		for (int csnum = 1; csnum <= tt; csnum++) {
			int n = sc.nextInt();
			double[] aa = new double[n];
			double[] bb = new double[n];
			TreeSet<Double> a = new TreeSet<Double>();
			TreeSet<Double> b = new TreeSet<Double>();
			
			for (int i = 0; i < n; i++) {
				aa[i] = sc.nextDouble();
				a.add(aa[i]);
			}
			Arrays.sort(aa);
			
			for (int i = 0; i < n; i++) {
				bb[i] = sc.nextDouble();
				b.add(bb[i]);
			}
			
			// fair case
			int s1 = 0;
			for (int i = 0; i < n; i++) {
				if (b.ceiling(aa[i]) == null) {
					b.remove(b.first());
					s1++;
				} else {
					b.remove(b.ceiling(aa[i]));
				}
			}
			
			for (int i = 0; i < n; i++) {
				b.add(bb[i]);
			}
			
			// unfair case
			int s2 = 0;
			for (int i = 0; i < n; i++) {
				if (a.first() < b.first()) {
					a.remove(a.first());
					b.remove(b.last());
				} else {
					a.remove(a.first());
					b.remove(b.first());
					s2++;
				}
			}
			
			System.out.println("Case #" + csnum + ": " + s2 + " " + s1);
		}
	}
}
