import java.util.*;

public class A {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int t=0; t<cases; t++) {
			String[] line = in.nextLine().split("/");
			long[] pq = new long[2];
			pq[0] = Long.parseLong(line[0]);
			pq[1] = Long.parseLong(line[1]);
			int count = 0;
			int countM = 0;
			boolean done = false;
			if (!divisible(pq[1])) {
				countM = 41;
			}
			while (pq[0] != pq[1] && countM < 41) {
				if (divisible(pq[0]) && divisible(pq[1])) {
					pq[0] = pq[0] / 2;
					pq[1] = pq[1] / 2;
				}
				if (pq[0] * 2 <= pq[1]) {
					pq[0] = pq[0] * 2;
				}
				else {
					if (!done) {
						count++;
					}
					done = true;
					pq[0] = pq[0] * 2 - pq[1];
				}
				if (!done) {
					count++;
				}
				countM++;
			}
			if (countM < 41) {
				System.out.println("Case #" + (t+1) + ": " + count);
			}
			else {
				System.out.println("Case #" + (t+1) + ": impossible");
			}
		}
	}
	
	private static boolean divisible(long x) {
		if ((x/2)*2 == x) {
			return true;
		}
		else {
			return false;
		}
	}

}
