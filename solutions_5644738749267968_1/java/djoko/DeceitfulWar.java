import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;


public class DeceitfulWar {
	int n;
	
	public void process() {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		
		for (int i = 0; i < t; i++) {
			int num = sc.nextInt();
			double naomi[] = new double[num];
			for (int j = 0; j < num; j++) {
				naomi[j] = sc.nextDouble();
			}
			double ken[] = new double[num];
			for (int j = 0; j < num; j++) {
				ken[j] = sc.nextDouble();
			}
			
			Arrays.sort(naomi);
			Arrays.sort(ken);
			int deceitful = playDeceitful(naomi, ken);
			int war = playWar(naomi, ken);
			System.out.println("Case #" + (i + 1) + ": " + deceitful + " " + war);
		}
	}
	
	private int playDeceitful(double[] naomi, double[] ken) {
		n = naomi.length;
		graph = new boolean[n][n];
		for (int i = 0; i < naomi.length; i++) {
			for (int j = 0; j < ken.length; j++) {
				if (naomi[i] > ken[j])
					graph[i][j] = true;
			}
		}
		return maximumMatching();
	}
	
	private int playWar(double[] naomi, double[] ken) {
		int winCount = 0;
		double kenc[] = new double[ken.length];
		boolean kenWins = false;
		System.arraycopy(ken, 0, kenc, 0, ken.length);
		for (int i = 0; i < naomi.length; i++) {
			kenWins = false;
			for (int j = 0; j < kenc.length; j++) {
				if (kenc[j] > naomi[i]) {
					kenWins = true;
					kenc[j] = -1;
					break;
				}
			}
			if (!kenWins) {
				for (int j = 0; j < kenc.length; j++) {
					if (kenc[j] >= 0) {
						kenc[j] = -1;
						break;
					}
				}
				winCount++;
			}
		}
		return winCount;
	}
	
	public static void main(String args[]) {
		DeceitfulWar dw = new DeceitfulWar();
		dw.process();
	}
	
	boolean[][] graph;
	boolean seen[];
	int matchL[];   //What left vertex i is matched to (or -1 if unmatched)
	int matchR[];   //What right vertex j is matched to (or -1 if unmatched)
	 
    int maximumMatching() {
        //Read input and populate graph[][]
    	//Set m to be the size of L, n to be the size of R
    	matchL = new int[n];
    	matchR = new int[n];
    	seen = new boolean[n];
        Arrays.fill(matchL, -1);
        Arrays.fill(matchR, -1);
 
        int count = 0;
        for (int i = 0; i < n; i++) {
            Arrays.fill(seen, false);
            if (bpm(i)) count++;
        }
        return count;
    }
 
    boolean bpm(int u) {
        //try to match with all vertices on right side
	    for (int v = 0; v < n; v++) {
	        if (!graph[u][v] || seen[v]) continue;
	        seen[v] = true;
	        //match u and v, if v is unassigned, or if v's match on the left side can be reassigned to another right vertex
	        if (matchR[v] == -1 || bpm(matchR[v])) {
	            matchL[u] = v;
	            matchR[v] = u;
	            return true;
	        }
	    }
	    return false;
	}
}
