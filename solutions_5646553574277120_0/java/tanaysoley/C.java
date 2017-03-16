import java.util.Scanner;

public class C {
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		int C, D, V, d[];
		boolean v[];
		boolean ind[];
		for (int I = 1; I <= T; I++) {
			C = in.nextInt();
			D = in.nextInt();
			V = in.nextInt();
			d = new int[D];
			v = new boolean[V + 1];
			// System.out.println("<<<<<<<<<<<" + C + " " + D + " " + V);
			for (int i = 0; i < D; i++) {
				d[i] = in.nextInt();
				// System.out.print(d[i]+" ");
			}
			// System.out.println();

			for (int i = 1; i <= D; i++) {
//				System.out.println(">>" + i);
				ind = new boolean[D];
				for (int j = 0; j < i; j++) {
					ind[ind.length - j - 1] = true;
				}

				while (ind != null) {
					int counter = 0;
					for (int j = 0; j < D; j++) {
						if (ind[j]) {
							counter = counter + d[j];
						}
					}
					try {
//						System.out.println("can make " + counter);
						v[counter] = true;
					} catch (Exception e) {

					}
					ind = next(ind);
				}
			}

			int result = 0;
			v[0] = true;
			for (int i = 1; i <= V; i++) {
				for (int j = 1; j <= V; j++) {
					if (!v[j]) {
//						System.out.print(j + ",");
					}
				}
//				System.out.println();
				if (!v[i]) {
//					System.out.println("adding " + i);
					result++;
					for (int j = 1; j <= V; j++) {
						if (v[j] && j + i < V) {
							if (!v[j + i]) {
//								System.out.println("now can make" + (i + j) + " " + i + "+" + j);
							}
//							System.out.println();
							v[j + i] = true;
						}
					}
					v[i]=true;
				}
			}

			System.out.println("Case #" + I + ": " + result);
		}
	}

	public static boolean[] next(boolean[] a) {
		for (int i = a.length - 1; i >= 0; i--) {
			if (i == 0) {
				return null;
			}
			if (a[i] && !a[i - 1]) {
				a[i] = false;
				a[i - 1] = true;
				int c = 0;
				for (int j = a.length - 1; j >= i; j--) {
					if (a[j]) {
						c++;
						a[j] = false;
					}

				}

				for (int j = a.length - 1; j >= a.length - c; j--) {
					a[j] = true;
				}
				break;
			}
		}
		boolean[] b = new boolean[a.length];
		for (int i = 0; i < a.length; i++) {
			b[i] = a[i];
		}
		return b;
	}
}