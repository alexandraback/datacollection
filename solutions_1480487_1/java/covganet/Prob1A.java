import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;


public class Prob1A {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			String s = br.readLine();
			String[] strs = s.split(" ");
			int n = strs.length - 1;
			double[] res = new double[n];
			
			double[] vals = new double[n];
			int sum = 0;
			for(int i = 0; i < vals.length; i++) {
				vals[i] = Integer.parseInt(strs[i + 1]);
				sum += vals[i];
			}
			
			double min = 0, max = sum;
			while(min + 1e-8 < max) {
				double med =  (min + max) / 2, tot = 0;
				boolean isOk = true;
				for(int i = 0; i < vals.length; i++) {
					if(vals[i] >= med) {
						continue;
					}
					tot += (med - vals[i]) / sum;
				}
				if(tot > 1) {
					max = med;
				} else {
					min = med;
				}
			}
			
			boolean[] established = new boolean[vals.length];
			double toDec = 0;
			for(int i = 0; i < vals.length; i++) {
				res[i] = 100.0 * (min - vals[i]) / (double)sum;
				if(res[i] < 0) {
					res[i] = 0;
				}
			}
			
			String sres = "";
			for(int i = 0; i < res.length; i++) {
				sres += " " + res[i];
			}
			pw.println("Case #" + x + ": " + sres.substring(1));
		}
		
		br.close();
		pw.close();
	}
}
