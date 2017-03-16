import java.util.*;


public class Program {
	
	private static int scoreW(ArrayList<Double> wn, ArrayList<Double> wk) {
		ArrayList<Double> n = (ArrayList<Double>) wn.clone();
		ArrayList<Double> k = (ArrayList<Double>) wk.clone();
		
		int score = 0;
		
		while (! n.isEmpty()) {
			double dn = n.remove(n.size()-1);
			if (k.get(k.size()-1) > dn) {
				k.remove(k.size()-1);				
			} else {
				k.remove(0);
				score++;
			}
		}
		
		return score;
	}

	private static int scoreD(ArrayList<Double> wn, ArrayList<Double> wk) {
		ArrayList<Double> n = (ArrayList<Double>) wn.clone();
		ArrayList<Double> k = (ArrayList<Double>) wk.clone();

		int score = 0;
		
		while (! n.isEmpty()) {
			double dn = n.remove(0);
			double dk = k.get(0);			
			if (dn < dk) {
				k.remove(k.size()-1);				
			} else {
				k.remove(0);
				score++;
			}
		}
		
		return score;
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

		int nCases = in.nextInt();
		in.nextLine();
		for (int caseNumber = 1; caseNumber <= nCases; caseNumber++) {
			int n = in.nextInt();
			in.nextLine();
			
			ArrayList<Double> wn = new ArrayList<>();
			ArrayList<Double> wk = new ArrayList<>();
			
			String[] line = in.nextLine().split(" ");
			for (int i = 0; i < n; i++) {
				wn.add(Double.parseDouble(line[i]));
			}			
			Collections.sort(wn);
			
			line = in.nextLine().split(" ");
			for (int i = 0; i < n; i++) {
				wk.add(Double.parseDouble(line[i]));
			}
			Collections.sort(wk);
			
			System.out.print("Case #");
			System.out.print(caseNumber);
			System.out.print(": ");
			System.out.print(scoreD(wn, wk));
			System.out.print(" ");
			System.out.println(scoreW(wn, wk));
			
		}
	}

}
