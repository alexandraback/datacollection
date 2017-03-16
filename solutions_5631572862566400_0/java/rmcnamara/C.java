import java.awt.Point;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class C {

	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream(new File("small_c.in")));
		System.setOut(new PrintStream(new File("small_c.out")));
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		for (int t = 1; t <= T; t++) {
			int N = scan.nextInt();
			int[] f = new int[N];
			Set<Integer>[] rev = (Set<Integer>[])new Set[N];
			for (int i = 0; i < rev.length; i++) {
				rev[i] = new HashSet<Integer>();
			}
			for (int i = 0; i < N; i++) {
				f[i] = scan.nextInt() - 1;
				rev[f[i]].add(i);
			}
			Set<Point> twocycles = new HashSet<Point>();
			for (int i = 0; i < N; i++) {
				if (f[f[i]] == i) {
					twocycles.add(new Point(Math.min(i, f[i]), Math.max(i, f[i])));
				}
			}
			int max = 0;
			for (Point p : twocycles) {
				Set<Integer> fronteir = new HashSet<>();
				fronteir.addAll(rev[p.x]);
				fronteir.remove(p.y);
				int len = 2;
				while (fronteir.size() > 0) {
					len++;
					Set<Integer> newFronteir = new HashSet<>();
					for (Integer x : fronteir) {
						newFronteir.addAll(rev[x]);
					}
					fronteir = newFronteir;
				}
				max += len;
				fronteir = new HashSet<>();
				fronteir.addAll(rev[p.y]);
				fronteir.remove(p.x);
				len = 0;
				while (fronteir.size() > 0) {
					len++;
					Set<Integer> newFronteir = new HashSet<>();
					for (Integer x : fronteir) {
						newFronteir.addAll(rev[x]);
					}
					fronteir = newFronteir;
				}
				max += len;
			}
			
			foo: for (int i = 0; i < N; i++) {
				Set<Integer> fronteir = new HashSet<>();
				Set<Integer> seen = new HashSet<>();
				seen.add(i);
				fronteir.add(i);
				int len = 0;
				while (fronteir.size() > 0){
					len++;
					Set<Integer> newFronteir = new HashSet<>();
					for (int x : fronteir) {
						if (f[x] == i) {
							max = Math.max(len, max);
							continue foo;
						}
						if (!seen.contains(f[x])) {
							seen.add(f[x]);
							newFronteir.add(f[x]);
						}

					}
					fronteir = newFronteir;
				}
			}
			System.out.println(String.format("Case #%s: %s", t, max));
		}
	}
}
