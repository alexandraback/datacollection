import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class D {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for(int q = 1; q <= t; ++q) {
			ArrayList<Double> naomi = new ArrayList();
			ArrayList<Double> ken = new ArrayList();
			int n = sc.nextInt();
			for(int i = 0; i < n; ++i)
				naomi.add(sc.nextDouble());
			for(int i = 0; i < n; ++i)
				ken.add(sc.nextDouble());
			Collections.sort(naomi, Collections.reverseOrder());
			Collections.sort(ken, Collections.reverseOrder());
			
			int fst = solve(ken, naomi);
			int snd = solve(naomi, ken);

			System.out.println("Case #"+q+": "+fst+" "+(n-snd));
		}
	}
	
	static int solve(ArrayList<Double> fst, ArrayList<Double> snd) {
		int points = 0;
		int pos = 0;
		for(double a : fst) {
			if(snd.get(pos) > a) {
				++pos;
				++points;
			}
		}
		return points;
	}
}