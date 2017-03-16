import java.awt.Point;
import java.util.*;

public class Recycle {

    public static void main(String[] args) {
        Recycle r = new Recycle();
        Scanner in = new Scanner(System.in);
        int cases = in.nextInt();
        for (int i = 0; i < cases; i++) {
            System.out.printf("Case #%d: %d\n", i+1, r.solve(in));
        }
    }
    
    private int solve(Scanner in) {
	HashSet<Point> used = new HashSet<Point>();
	int A = in.nextInt();
	int B = in.nextInt();
	int count = 0;
	for (int i = A; i <= B; i++) {
	    String s = Integer.toString(i);
	    for (int k = 1; k < s.length(); k++) {
		String front = s.substring(0, k);
		String sub = s.substring(k);
		String reconstr = sub + front;
		if (reconstr.startsWith("0") || reconstr.equals(s)) continue;
		int reconstructed = Integer.parseInt(reconstr);
		if (reconstructed >= i) continue;
		if (used.contains(new Point(i, reconstructed))) continue;
		if (A <= reconstructed && reconstructed <= B) {
		    used.add(new Point(i, reconstructed));
		    count++;
		}
	    }
	}
	return count;
    }

}