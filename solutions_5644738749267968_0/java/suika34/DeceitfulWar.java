import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;


public class DeceitfulWar {

	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String line = br.readLine();
			int T = Integer.parseInt(line);

			for (int i=1; i<=T; i++) {
				int N = Integer.parseInt(br.readLine());
				
				LinkedList<Double> naomi = new LinkedList<Double>();
				line = br.readLine();
				String[] array = line.split(" ");
				for (String str : array) {
					naomi.add(Double.valueOf(str));
				}

				LinkedList<Double> ken = new LinkedList<Double>();
				line = br.readLine();
				array = line.split(" ");
				for (String str : array) {
					ken.add(Double.valueOf(str));
				}
				
				String result = solve(N, naomi, ken);

				System.out.println("Case #"+i+": "+result);
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	
	private static String solve(int N, LinkedList<Double> naomi, LinkedList<Double> ken) {
		Collections.sort(naomi);
		Collections.sort(ken);
		
		//System.out.println(naomi);
		//System.out.println(ken);
		
		List<Double> naomi_d = new LinkedList<Double>(naomi);
		List<Double> ken_d = new LinkedList<Double>(ken);
		
		//DeceitfulWar
		Collections.sort(naomi_d);
		Collections.sort(ken_d);
		
		int deceitflWarScore = 0;
		int numBattle = 0;
		while (numBattle < N) {
			double minKen = ken_d.get(0);
			int numLose = 0;
			for (double t : naomi_d) {
				if (t < minKen) {
					numLose += 1;
				} else {
					break;
				}
			}
			naomi_d = naomi_d.subList(numLose, naomi_d.size());
			ken_d = ken_d.subList(0, ken_d.size() - numLose);
			numBattle += numLose;

			while (numBattle < N && naomi_d.get(0) > ken_d.get(0)) {
				numBattle += 1;
				deceitflWarScore += 1;
				naomi_d.remove(0);
				ken_d.remove(0);
			}
		}
		
		
		//war
		int warScore = 0;
		for (int i=0; i<N; i++) {
			double n = naomi.poll();
			double k = ken.peek();
			for (double t : ken) {
				if (t > n) {
					k = t;
					break;
				}
			}
			ken.remove(k);
			//System.out.println(n+" "+k);
			if (n>k) {
				warScore += 1;
			}
		}
		//System.out.println(warScore);
		
		return deceitflWarScore+" "+warScore;
	}
}
