import java.text.DecimalFormat;
import java.util.*;

public class D {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.0000000");
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			int N = s.nextInt();
			Vector<Double> v1 = new Vector<Double>();
			Vector<Double> v2 = new Vector<Double>();
			
			for (int i = 0; i < N; i++) v1.add(s.nextDouble());
			for (int i = 0; i < N; i++) v2.add(s.nextDouble());
			
			Collections.sort(v1);
			Collections.sort(v2);
						
			System.out.println("Case #" + (current++) +": "
					+ getCheat(v1, v2) + " " + getFair(v1, v2));			
		}
	}
	
	public static int getCheat(Vector<Double> v1, Vector<Double> v2) {
		int score = 0;
		int pos2 = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (v1.elementAt(i) > v2.elementAt(pos2)) {
				// treat as heavier than player 2's max block
				score++;
				pos2++;
			} else {
				// no way to win, but force player 2 to use the max
			}
		}
		return score;
	}
	
	public static int getFair(Vector<Double> v1, Vector<Double> v2) {
		int score = 0;
		int pos2 = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (v2.elementAt(pos2) > v1.elementAt(i)) {
				// player 2 wins directly
			} else {
				while(v2.elementAt(pos2) < v1.elementAt(i)) {
					pos2++; // try to find one to win
					if (pos2 == v2.size()) return v1.size()-i; // including the current, player 1 will always win
				}
			}
			pos2++; // prepare next
			if (pos2 == v2.size()) return v1.size()-(i+1); // player 1's remaining will always win
		}
		return score;
	}
}
