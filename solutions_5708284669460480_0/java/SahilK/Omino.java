import java.util.Scanner;
import java.util.PriorityQueue;

public class Omino {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i=1;i<=T;i++) {
            int K = sc.nextInt();
            int L = sc.nextInt();
            int S = sc.nextInt();
			String dict = sc.next();
			String target =sc.next();
			int[] vals = new int[26];
			for (int j=0; j<K; j++) {
				vals[dict.charAt(j) - 'A'] += 1;
			}
			int prob = 1;
			for (int j=0; j<L; j++) {
				prob = prob * vals[target.charAt(j) - 'A'];
			}
			int myMax = 0;
			int step = L;
			for (int q = 0; q < L; q++) {
				if (target.startsWith(target.substring(q)))
					step = L - q;
			}
			myMax = 1 + ((S-L)/step);
			double expect = (double) prob * ((double) (S-L+1)) / ((double) Math.pow((double) K, (double) L));
			double soln = (double) myMax - expect;
            System.out.printf("Case #%d: %f", i, soln);
            System.out.println("");
        }
    }

}