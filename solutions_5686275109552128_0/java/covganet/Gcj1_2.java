import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;

/**
 * @author Admin
 * 2 * 3 * 5 * 7 * 11 * 13 * 17 * 19 = 9699690
 */
public class Gcj1_2 {
	static int[] nrs = null;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt2.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output2.txt"));

		int nrT = Integer.parseInt(br.readLine());
		for(int t = 1; t <= nrT; t++) {
			int d = Integer.parseInt(br.readLine());
			String[] vals = br.readLine().split(" ");
			
			nrs = new int[d];
			for(int i = 0; i < nrs.length; i++) {
	      nrs[i] = Integer.parseInt(vals[i]);
      }
			Arrays.sort(nrs);
			int res = nrs[nrs.length - 1];
			for(int max = 1; max < res; max++) {
				int newRes = max;
				for(int j = nrs.length - 1; j >= 0; j--) {
					newRes += ((nrs[j] + max - 1) / max) - 1;
					if(newRes >= res) {
						break;
					}
				}
				if(newRes < res) {
					res = newRes;
				}
			}
			
			pw.println("Case #" + t + ": " + res);
			pw.flush();
		}
		
		br.close();
		pw.close();
		System.out.println("done!");
	}
}
