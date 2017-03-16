import java.io.*;
import java.util.*;

class war {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("war.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("war.out")));
		int T = Integer.parseInt(br.readLine());
		for (int i = 0; i < T; i++) {
		    int N = Integer.parseInt(br.readLine());
			ArrayList<Double> naomi = new ArrayList<Double>();
			ArrayList<Double> ken = new ArrayList<Double>();
			ArrayList<Double> naomi2 = new ArrayList<Double>();
			ArrayList<Double> ken2 = new ArrayList<Double>();
		    StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
			    double cur = Double.parseDouble(st.nextToken());
			    naomi.add(cur);
			    naomi2.add(cur);
			}
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
			    double cur = Double.parseDouble(st.nextToken());
			    ken.add(cur);
			    ken2.add(cur);
			}
			Collections.sort(naomi);
			Collections.sort(ken);
			Collections.sort(naomi2);
			Collections.sort(ken2);
			String answer = Integer.toString(deceitfulwar(naomi,ken,N)) + " " + Integer.toString(war(naomi2,ken2,N));
			out.println("Case #" + (i+1) + ": " + answer);
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
	public static int war(ArrayList<Double> naomi, ArrayList<Double> ken, int N) {
	    int score = 0;
	    for (int i = 0; i < N; i++) {
	        double compare = naomi.get(naomi.size()-1);
	        if (ken.get(ken.size() - 1) < compare) {
	            score++;
	            naomi.remove(naomi.size()-1);
	            ken.remove(0);
	        }
	        else {
                for (int j = ken.size() - 1; j >= 0; j--) {
                    if (j != 0 && ken.get(j) > compare && ken.get(j-1) < compare) break;
                }
                naomi.remove(naomi.size()-1);
                ken.remove(ken.size()-1);
	        }
	    }
	    return score;
	}
	public static int deceitfulwar(ArrayList<Double> naomi, ArrayList<Double> ken, int N) {
	    int score = 0;
	    for (int i = 0; i < N; i++) {
	        double compare = naomi.get(0);
	        if (ken.get(0) < compare) {
	            score++;
	            naomi.remove(0);
	            ken.remove(0);
	        }
	        else {
	            naomi.remove(0);
	            ken.remove(ken.size()-1);
	        }
	    }
	    return score;
	}
}

