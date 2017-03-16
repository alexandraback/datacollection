package codejams;

import java.io.BufferedReader;
import java.io.PrintWriter;
import java.util.Collections;
import java.util.ArrayList;

public class War {
	
	public War() {
		
	}
	
	public void testCase(BufferedReader br, PrintWriter pw) {
		try {
			br.readLine(); // number of blocks
			
			ArrayList<Double> naomi = new ArrayList<Double>();
			String[] str = br.readLine().split(" ");
			for (String blk : str) naomi.add(Double.parseDouble(blk));
			Collections.sort(naomi);

			if (Main.debug) System.out.println(naomi);
			
			ArrayList<Double> ken = new ArrayList<Double>();
			str = br.readLine().split(" ");
			for (String blk : str) ken.add(Double.parseDouble(blk));
			Collections.sort(ken);
			
			if (Main.debug) System.out.println(ken);
			
			// DECEITFUL WAR
			int nh = 0;
			int kh = 0;
			int kt = ken.size() - 1;
			int c = 0;
			while (nh < naomi.size()) {
				//while ken still has trailing maxes
				while (nh < naomi.size() && ken.get(kt) > naomi.get(naomi.size()-1)) {
					nh++;
					kt--;
				}
				// while naomi still has leading mins
				while (nh < naomi.size() && naomi.get(nh) < ken.get(kh)) {
					nh++;
					kt--;
				}
				// while ken still has leading mins
				while (nh < naomi.size() && ken.get(kh) < naomi.get(nh)) {
					nh++;
					kh++;
					c++;
				}
			}
			if (Main.debug) System.out.println("Deceitful "+c);
			pw.print(c + " ");
			
			// HONORABLE WAR
			int nt = naomi.size() -1;
			kt = ken.size() - 1;
			c = 0;
			
			while (nt >= 0) {
				// while naomi still has trailing maxes increase counter, remove ken min
				while (nt >= 0 && naomi.get(nt) > ken.get(kt)) {
					nt--;
					c++;
				}
				// while ken still has trialing maxes, remove naomi's maxes
				while (nt >= 0 && ken.get(kt) > naomi.get(nt)) {
					kt--;
					nt--;
				}

			}
			if (Main.debug) System.out.println("Honorable "+c);

			pw.print(c);
		}
		catch (Exception e) {
			e.printStackTrace();
		}
	}
	
}