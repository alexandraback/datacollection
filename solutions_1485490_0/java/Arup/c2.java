import java.util.*;

class pair {

	public long quantity;
	public int type;

	public pair(long q) {
		quantity = q;
		type = 0;
	}

	public pair(long q, int t) {
		quantity = q;
		type = t;
	}

	public void addQ(long val) {
		quantity += val;
	}

	public void setT(int t) {
		type = t;
	}

	public String toString() {
		return "Q: "+quantity+" T: "+type;
	}
}

public class c2 {

	final public static boolean DEBUG = false;

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int N = stdin.nextInt();
			pair[] boxes = new pair[N];
			int M = stdin.nextInt();
			pair[] candy = new pair[M];

			for (int i=0; i<N; i++) {
				long q = stdin.nextLong();
				int t = stdin.nextInt();
				boxes[i] = new pair(q,t);
			}

			for (int i=0; i<M; i++) {
				long q = stdin.nextLong();
				int t = stdin.nextInt();
				candy[i] = (new pair(q,t));
			}



			long ans = solve(boxes, 0, candy, 0);

			System.out.println("Case #"+loop+": "+ans);

		}
	}

	public static long solve(pair[] newbox, int i, pair[] newcandy, int j) {

		if (i == newbox.length || j == newcandy.length)
			return 0;

		else if (newbox[i].type == newcandy[j].type && newbox[i].type != 0) {

			if (newbox[i].quantity < newcandy[j].quantity) {
				long temp = Math.min(newbox[i].quantity, newcandy[j].quantity);
				newcandy[j].quantity -= newbox[i].quantity;
				long retval = temp + solve(newbox, i+1, newcandy, j);
				newcandy[j].quantity += newbox[i].quantity;
				return retval;
			}
			else if (newbox[i].quantity > newcandy[j].quantity) {
				long temp = Math.min(newbox[i].quantity, newcandy[j].quantity);
				newbox[i].quantity -= newcandy[j].quantity;
				//System.out.println("In this case, quan is now "+newbox[i].quantity);
				long retval = temp + solve(newbox, i, newcandy, j+1);
				newbox[i].quantity += newcandy[j].quantity;
				return retval;
			}
			else {
				return newbox[i].quantity + solve(newbox, i+1, newcandy, j+1);
			}
		}
		else {
			return Math.max(solve(newbox,i+1, newcandy, j), solve(newbox, i,newcandy,j+1));
		}

	}
}