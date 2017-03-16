import java.io.IOException;


public class C extends CodeJammer {

	@Override
	public void process() throws IOException {
		// TODO Auto-generated method stub
		output(""); //Always begins with a blank line
		int R = reader.getInt();
		int C = reader.getInt();
		int M = reader.getInt();
		
		if (M == R*C-1) { //easy special case
			System.out.print("c");
			for (int r=0; r<R;r++) {
				for (int c=0; c<C && (r>0 || c<C-1); c++) {
					System.out.print("*");
				}
				System.out.println();
			}
			return;
		}
		
		int  b = R*C-M; //number of blank squares
		
		if (R==1 || C==1) { //A silly edge case
			System.out.print("c");
			int counter = 1;
			for (int r=0; r<R;r++) {
				for (int c=0; c<C && (r>0 || c<C-1); c++) {
					if (counter < b) {
						System.out.print(".");
						counter++;
					} else {
						System.out.print("*");
					}
				}
				System.out.println();
			}
			return;
		}
		
		if (b==2 || b==3 || b==5 || b==7 || ((R==2 || C==2) && (b%2) == 1)) { //The losing cases
			System.out.println("Impossible");
			return;
		}
		
		//Now I know it is possible. Time to determine the grid.
		boolean[][] mined = new boolean[R][C];
		for (int r=0; r<R; r++) for (int c=0;c<C;c++) mined[r][c] = true;
		int A,B; //Tells how far down and to the right the "hook" of blanks goes
		if (C == 2) {
			A = 1;
			B = (b-2)/2;
		} else if (R == 2) {
			A = (b-2)/2;
			B = 1;
		} else if (b<=6) { //Both dimensions are at least 3
			if (b==4) {
				A = 1;
				B = 1;
			} else {
				A = 2;
				B = 1;
			}
		} else { //Here both dimensions are at least 3
			A = B = 2;
			while ((A+1)*(B+1) < b && A <= C-2) A++;
			while ((A+1)*(B+1) < b && B <= R-2) B++;
		}
		int left = (b - 2*A -2*B);
		for (int c=0; c<A+1; c++) {
			mined[0][c] = false;
			mined[1][c] = false;
		}
		for (int r=0; r<B+1; r++) {
			mined[r][0] = false;
			mined[r][1] = false;
		}
		for (int r=2; r<=B; r++) {
			for (int c=2; c<=A; c++) {
				if (left > 0) {
					mined[r][c] = false;
					left--;
				}
			}
		}
		
		for (int r=0; r<R; r++) {
			for (int c=0; c<C; c++) {
				if (mined[r][c]) System.out.print("*");
				else {
					if (r == 0 && c == 0) System.out.print("c");
					else System.out.print(".");
				}
			}
			System.out.println();
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		C c = new C();
		c.run(args);
	}

}
