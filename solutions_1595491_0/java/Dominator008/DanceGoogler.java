import java.util.*;

public class DanceGoogler {

    public static void main(String[] args) {
        DanceGoogler d = new DanceGoogler();
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            System.out.printf("Case #%d: %d\n", i+1, d.solve(in));
        }
    }
    
    private int solve(Scanner in) {
	int N = in.nextInt();
	int S = in.nextInt();
	int p = in.nextInt();
	int[] scores = new int[N];
	for (int i = 0; i < N; i++) scores[i] = in.nextInt();
	int count = 0;
	for (int i = 0; i < scores.length; i++) {
	    if (scores[i] < p) continue;
	    double diff = p - (scores[i] - p) / 2.0;
	    if (diff > 2.0) continue;
	    if (diff > 1.0) {
		if (S > 0) {
		    S--;
		    count++;
		}
		else continue;
	    }
	    else count++;
	}
	return count;
    }

}