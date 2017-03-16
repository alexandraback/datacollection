import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class deceitful_war {

	public static void main(String[] args) throws Exception {
		//BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
		PrintWriter pw = new PrintWriter("D-large.out", "UTF-8");
		
		int t = Integer.parseInt(br.readLine());
		
		for (int test = 0; test < t; test++) {
			pw.print("Case #" + (test + 1) + ": ");
			
			int n = Integer.parseInt(br.readLine());
			
			List<Double> naomi = new ArrayList<Double>();
			List<Double> ken = new ArrayList<Double>();
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for (int i = 0; i < n; i++) {
				naomi.add(Double.parseDouble(st.nextToken()));
			}
			
			st = new StringTokenizer(br.readLine());
			
			for (int i = 0; i < n; i++) {
				ken.add(Double.parseDouble(st.nextToken()));
			}
			
			Collections.sort(naomi);
			Collections.sort(ken);
			
			List<Double> naomi2 = new ArrayList<Double>(naomi);
			List<Double> ken2 = new ArrayList<Double>(ken);
			
			int npoints = 0;
			
			while (!naomi.isEmpty()) {
				if (naomi.get(naomi.size() - 1) > ken.get(ken.size() - 1)) {
					naomi.remove(naomi.size() - 1);
					npoints++;
				} else {
					naomi.remove(0);
				}
				ken.remove(ken.size() - 1);
			}
			
			pw.print(npoints + " ");
			npoints = 0;
			
			while (!naomi2.isEmpty()) {
				double nchoose = naomi2.get(naomi2.size() - 1);
				if (nchoose > ken2.get(ken2.size() - 1)) {
					npoints++;
					ken2.remove(0);
				} else {
					for (int i = 0; i < ken2.size(); i++) {
						if (ken2.get(i) > nchoose) {
							ken2.remove(i);
							break;
						}
					}
				}
				naomi2.remove(naomi2.size() - 1);
			}
			
			pw.println(npoints);
		}
		
		br.close();
		pw.close();
	}
}