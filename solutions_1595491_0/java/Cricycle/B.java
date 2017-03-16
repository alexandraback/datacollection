import java.util.*;

public class B {
	public static void main(String[] args) {
		B b = new B();
		b.solve();
	}
	
	public void solve() {
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int ii = 1; ii <= t; ++ii) {
			int num = in.nextInt();
			int surprising = in.nextInt();
			int points = in.nextInt();
			int[][] bests = new int[num][2]; //[i][0] best, not surprising.  [i][1], best, surprising
			for(int i = 0; i < num; ++i) {
				int score = in.nextInt();
				if(score <= 1) {
					bests[i][0] = score;
					bests[i][1] = score;
				}
				else if(score % 3 == 0) {
					bests[i][0] = score/3;
					bests[i][1] = bests[i][0] + 1;
				} else if(score % 3 == 1) {
					bests[i][0] = score/3 + 1;
					bests[i][1] = bests[i][0];
				} else {
					bests[i][0] = score/3 + 1;
					bests[i][1] = bests[i][0] + 1;
				}
				//System.out.printf("With a total of %d, best non: %d, best with: %d\n", score, bests[i][0], bests[i][1]);
			}
			int total = 0;
			for(int i = 0; i < num; ++i) { //check all not suprising stuffs
				if(bests[i][0] >= points) {
					++total;
					bests[i][1] = -1;
				}
			}
			for(int i = 0; i < num && surprising > 0; ++i) {
				if(bests[i][1] >= points) {
					++total;
					--surprising;
				}
			}
			System.out.printf("Case #%d: %d\n", ii, total);
		}
	}
}