import java.util.Scanner;

public class B {
	public static void main(String args[]) {
		new B();
	}

	public B() {
		Scanner in = new Scanner(System.in);

		int T = in.nextInt();
		for(int t=1; t<=T; t++) {
			int N = in.nextInt();
			int S = in.nextInt();
			int p = in.nextInt();

			int y = 0;
			for(int n=0; n<N; n++) {
				int ti = in.nextInt();

				int r = ti - p;
				if(r < 0) continue;

				int a = r / 2;
				int b = r - a;

				int da = a - p;
				int db = b - p;
				int d = Math.min(da, db);
				if(d == -2) {
					if(S > 0) S--;
					else continue;
				}

				if(d >= -2) y++;
			}
			System.out.printf("Case #%d: %d\n", t, y);
		}
	}
}