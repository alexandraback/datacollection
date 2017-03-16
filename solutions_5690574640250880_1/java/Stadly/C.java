import java.util.Scanner;

public class C {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int cases = sc.nextInt();
		for(int q = 1; q <= cases; ++q) {
			int r = sc.nextInt();
			int c = sc.nextInt();
			int m = sc.nextInt();
			
			boolean inv = false;
			if(c < r) {
				inv = true;
				int temp = r;
				r = c;
				c = temp;
			}
			
			boolean[][] t = new boolean[r][c];
			boolean ok = true;
			boolean done = false;
			if(m == 0) {
				for(int i = 0; i < r; ++i)
					for(int j = 0; j < c; ++j)
						t[i][j] = true;
				done = true;
			}
			if(!done && r*c-m == 1) {
				t[0][0] = true;
				done = true;
			}
			if(!done && r == 1) {
				for(int i = 0; i < c-m; ++i)
					t[0][i] = true;
				done = true;
			}
			if(!done && (r*c-m == 2 || r*c-m == 3 || r*c-m == 5 || r*c-m == 7 || (r == 2 && (r*c-m)%2 == 1))) {
				ok = false;
				done = true;
			}
			if(!done) {
				int down = 0;
				int right = 0;
				int empty = 0;
				while(empty+m < r*c && r*c-(empty+m) != 3 && down < r) {
					t[down][right] = true;
					t[down][right+1] = true;
					empty += 2;
					++down;
				}
				down = 0;
				right += 2;
				while(empty+m < r*c) {
					if(down == r-1 && r*c-(empty+m) == 2) {
						down = 0;
						++right;
					}
					t[down][right] = true;
					++empty;
					++down;
					if(down%r == 0) {
						down = 0;
						++right;
					}
				}
			}

			System.out.println("Case #"+q+":");
			if(!ok)
				System.out.println("Impossible");
			else {
				System.out.print('c');
				for(int i = 1; i < c*r; ++i) {
					if((inv?i%r:i%c) == 0)
						System.out.println();
					System.out.print(t[inv?i%r:i/c][inv?i/r:i%c] ? '.' : '*');
				}
				System.out.println();
			}
		}
	}
}
