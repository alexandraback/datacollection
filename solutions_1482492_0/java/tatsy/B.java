package round1c;

import java.util.Scanner;

public class B {
	public static void main(String args[]) {
		new B();
	}

	public B() {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();

		for(int c=1; c<=T; c++) {
			double D = scan.nextDouble();
			int N = scan.nextInt();
			int A = scan.nextInt();

			double[] t = new double[N];
			double[] x = new double[N];

			for(int i=0; i<N; i++) {
				t[i] = scan.nextDouble();
				x[i] = scan.nextDouble();
			}

			double[] v = new double[N-1];
			if(x[0] > D) {
				x[0] = D;
				t[0] = 0.0;
			}

			for(int i=0; i<N-1; i++) {
				v[i] = (x[i+1] - x[i]) / (t[i+1] - t[i]);
				if(x[i+1] > D) {
					x[i+1] = D;
					t[i+1] = t[i] + (D - x[i]) / v[i];
				}
			}

			double[] a = new double[A];
			for(int i=0; i<A; i++) {
				a[i] = scan.nextDouble();
			}

			System.out.printf("Case #%d:\n", c);
			for(int k=0; k<A; k++) {
				double[] pos = new double[N];
				double[] vel = new double[N];

				double it = t[0];
				double ix = 0.5 * a[k] * it * it;
				double iv = a[k] * it;
				pos[0] = ix <= x[0] ? ix : x[0];
				vel[0] = ix <= x[0] ? iv : v[0];

				for(int i=1; i<N; i++) {
					double ct = t[i] - t[i-1];
					double cx = pos[i-1] + vel[i-1] * ct + 0.5 * a[k] * ct * ct;
					double cv = vel[i-1] + a[k] * ct;

					double maxt = (-vel[i-1] + Math.sqrt(vel[i-1] * vel[i-1] + 2.0 * a[k] * (x[i] - x[i-1]))) / a[k];
					double maxv = vel[i-1] + a[k] * maxt;

					pos[i] = cx <= x[i] ? cx : x[i];
					if(i != N-1) vel[i] = cx <= x[i] ? cv : v[i];
					else vel[i] = cv;
					vel[i] = vel[i] > maxv ? maxv : vel[i];
				}

				double elapse = t[N-1];
				if(pos[N-1] < D) {
					double X = D - pos[N-1];
					double V = vel[N-1];
					elapse += (-V + Math.sqrt(V * V + 2.0 * a[k] * X)) / a[k];
				}
				System.out.println(elapse);
			}
		}
	}
}