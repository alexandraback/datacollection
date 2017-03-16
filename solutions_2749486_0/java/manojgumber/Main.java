import java.util.Scanner;

public class Main {

	static char[] out;

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int nCases = s.nextInt();
		for (int i = 0; i < nCases; i++) {
			int X = s.nextInt();
			int Y = s.nextInt();
			int step = 1;
			out = new char[2000];
			int nsteps = 0;
			while (X != 0) {
				if (step <= Math.abs(X)) {
					if (X > 0) {
						X -= step;
						out[nsteps++] = 'E';
					} else {
						X += step;
						out[nsteps++] = 'W';
					}
					step++;
				} else {
					int rest = Math.abs(X);
					char step1;
					char step2;
					if (X > 0) {
						step1 = 'W';
						step2 = 'E';
					} else {
						step1 = 'E';
						step2 = 'W';
					}
					for (int j = 0; j < rest; j++) {
						out[nsteps++] = step1;
						out[nsteps++] = step2;
						step++;
						step++;
					}
					X=0;
				}
			}
			while (Y != 0) {
				if (step <= Math.abs(Y)) {
					if (Y > 0) {
						Y -= step;
						out[nsteps++] = 'N';
					} else {
						Y += step;
						out[nsteps++] = 'S';
					}
					step++;
				} else {
					int rest = Math.abs(Y);
					char step1;
					char step2;
					if (Y > 0) {
						step1 = 'S';
						step2 = 'N';
					} else {
						step1 = 'N';
						step2 = 'S';
					}
					for (int j = 0; j < rest; j++) {
						out[nsteps++] = step1;
						out[nsteps++] = step2;
						step++;
						step++;
					}
					Y=0;
				}

			}
			String path = new String(out, 0, nsteps);
			System.out.format("Case #%d: %s\n", i+1,path);
		}
	}

}

