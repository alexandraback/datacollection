import java.util.*;
import java.text.*;

public class Lulz {
	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int t = 1; t <= T; t++) {
			int N = in.nextInt();
			double[] naomi = new double[N];
			double[] ken = new double[N];
			for(int i = 0; i < N; i++) {
				naomi[i] = in.nextDouble();
			}
			for(int i = 0; i < N; i++) {
				ken[i] = in.nextDouble();
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
			System.out.println("Case #" + t + ": "+ playDeceptiveWar(naomi, ken) + " " + playWar(naomi, ken));
		}
	}
	public static int playDeceptiveWar(double[] naomi, double[] ken) {
		int n = 0;
		int k = 0;
		int wins = 0;
		int delta = 0;
		for(int i = 0; i < 2 * naomi.length; i++) {
			if(k >= ken.length || (n < naomi.length && naomi[n] < ken[k])) {
				if(delta > 0) {
					wins++;
					delta--;
				}
				n++;
			} else {
				k++;
				delta++;
			}
		}
		return wins;
	}
	public static int playWar(double[] naomi, double[] ken) {
		LinkedList<Double> kenList = new LinkedList<Double>();
		for(double k : ken) {
			kenList.add(k);
		}
		int win = 0;
		for(int i = naomi.length - 1; i >= 0; i--) {
			double max = kenList.getLast();
			if(max > naomi[i]) {
				kenList.removeLast();
			} else {
				win++;
				kenList.removeFirst();
			}
		}
		return win;
	}
}