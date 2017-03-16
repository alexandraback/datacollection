import java.io.*;
import java.util.*;

public class DeceitfulWar {
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream("src/D-large.in"))));

		String output = "";
		int t = sc.nextInt();
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			ArrayList<Double> naomi = new ArrayList<Double>();
			ArrayList<Double> ken = new ArrayList<Double>();
			for (int j = 0; j < n; j++) {
				naomi.add(sc.nextDouble());
			}
			for (int j = 0; j < n; j++) {
				ken.add(sc.nextDouble());
			}
			Collections.sort(naomi);
			Collections.sort(ken);
			ArrayList<Double> naomi2 = new ArrayList<Double>(naomi);
			ArrayList<Double> ken2 = new ArrayList<Double>(ken);
			int winsDecep = 0;
			int winsWar = 0;
			while (naomi.size() > 0) {
				if (naomi.get(0) > ken.get(0)) {
					winsDecep++;
					naomi.remove(0);
					ken.remove(0);
				} else {
					naomi.remove(0);
					ken.remove(ken.size()-1);
				}
			}
			while (naomi2.size() > 0) {
				double num = naomi2.remove(0);
				if (ken2.get(ken2.size()-1) > num) {
					for (double d : ken2) {
						if (d > num) {
							ken2.remove(d);
							break;
						}
					}
				} else {
					ken2.remove(0);
					winsWar++;
				}
			}
			output += "Case #" + i + ": " + winsDecep + " " + winsWar + "\n";
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(new FileOutputStream("src/D-large.out"), "utf-8"));
		bw.write(output);
		bw.close();
	}
}