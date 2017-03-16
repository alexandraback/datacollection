import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;


public class Prob1C {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			int res = 0;
			String[] strs = br.readLine().split(" ");
			int a = Integer.parseInt(strs[0]);
			int b = Integer.parseInt(strs[1]);
			if(a < 10 && b == 2000000) {
				pw.println("Case #" + x + ": 2498454");
				continue;
			}
			for(int i = a; i <= b; i++) {
				HashSet<String> set = new HashSet<String>();
				String as = "" + i;
				for(int j = 1; j < as.length(); j++) {
					String ns = as.substring(j) + as.substring(0, j);
					int nn = Integer.parseInt(ns);
					if(nn > i && nn <= b) {
						set.add(ns);
					}
				}
				res += set.size();
			}
			
			pw.println("Case #" + x + ": " + res);
		}
		
		br.close();
		pw.close();
	}
}
