import java.io.*;
import java.util.*;


public class DeceitfulWar {
	public static int war(double[] nnaomi, double[] kken){
		TreeSet<Double> naomi = new TreeSet<Double>();
		TreeSet<Double> ken = new TreeSet<Double>();
		for(int i=0; i<nnaomi.length; i++){
			naomi.add(nnaomi[i]);
			ken.add(kken[i]);
		}
		int wins = 0;
		for(double n : naomi){
			Double k = ken.ceiling(n);
			if(k == null){
				wins += 1;
				Double rem = ken.first();
				ken.remove(rem);
			} else {
				ken.remove(k);
			}
		}
		return wins;
	}

	public static int deceit(double[] nnaomi, double[] kken){
		TreeSet<Double> naomi = new TreeSet<Double>();
		TreeSet<Double> ken = new TreeSet<Double>();
		for(int i=0; i<nnaomi.length; i++){
			naomi.add(nnaomi[i]);
			ken.add(kken[i]);
		}
		int wins = 0;
		for(double n : naomi){
			double k = ken.first();
			if(k < n){
				wins += 1;
				ken.remove(k);
			}else{
				double rem = ken.last();
				ken.remove(rem);
			}
		}
		return wins;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintStream ps = new PrintStream(new BufferedOutputStream(System.out));
		int cases = Integer.valueOf(br.readLine());
		for(int ctr=0; ctr<cases; ctr++){
			int n = Integer.valueOf(br.readLine());
			double[] naomi = new double[n];
			double[] ken = new double[n];
			String[] ss = br.readLine().split("\\s+");
			for(int i=0; i<n; i++){
				naomi[i] = Double.valueOf(ss[i]);
			}
			ss = br.readLine().split("\\s+");
			for(int i=0; i<n; i++){
				ken[i] = Double.valueOf(ss[i]);
			}
			int w = war(naomi, ken);
			int d = deceit(naomi, ken);
			ps.printf("Case #%d: %d %d\n", ctr+1, d, w);
		}
		ps.flush();
	}
}
