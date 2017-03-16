import java.util.ArrayList;
import java.util.Collection;
import java.util.Scanner;


public class C {

	static Scanner in = new Scanner(System.in);

	int N = in.nextInt();
	int[] x = new int[N];
	
	Collection<Integer> as = new ArrayList<Integer>();
	Collection<Integer> bs = new ArrayList<Integer>();
	
	boolean solve(int i, int A, int B) {
		if (i==N) {
			if (A==B && A>0) {
				return true;
			} else {
				return false;
			}
		}
		if (solve(i+1, A, B)) {
			return true;
		} else {
			if (solve(i+1, A+x[i], B)) {
				as.add(x[i]);
				return true;
			} else {
				if (solve(i+1, A, B+x[i])) {
					bs.add(x[i]);
					return true;
				} else {
					return false;
				}
			}
		}
	}
	
	void print(Collection<Integer> as) {
		boolean first = true;
		for (int i:as) {
			if (first) {
				first = false;
			} else {
				System.out.print(" ");
			}
			System.out.print(i);
		}
		System.out.println();
	}
	
	void solve() {
		int S = 0;
		for (int i=0; i<N; ++i) {
			x[i] = in.nextInt();
			S += x[i];
		}
		if (solve(0, 0, 0)) {
			print(as);
			print(bs);
		} else {
			System.out.println("Impossible");
		}
	}
	
	
	public static void main(String[] args) {
		int T = in.nextInt();
		for (int i=1; i<=T; ++i) {
			System.out.println("Case #" + i + ":");
			new C().solve();
		}

	}

}
