import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;

/**
 * @author Admin
 */
public class Gcj1_4 {
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("D-large.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output4.txt"));

		int nrT = Integer.parseInt(br.readLine());
		for(int t = 1; t <= nrT; t++) {
			String[] vals = br.readLine().split(" ");
			int x = Integer.parseInt(vals[0]);
			int r = Integer.parseInt(vals[1]);
			int c = Integer.parseInt(vals[2]);
			
			if(x == 1) {
				pw.println("Case #" + t + ": GABRIEL");
				continue;
			}
			if(x == 2) {
				if((r*c) % 2 == 0) {
					pw.println("Case #" + t + ": GABRIEL");
				} else {
					pw.println("Case #" + t + ": RICHARD"); 
				}
				continue;
			}
			if(x == 3) {
				if(r == 1 || c == 1 || (r * c) % 3 != 0) {
					pw.println("Case #" + t + ": RICHARD");
				} else {
					pw.println("Case #" + t + ": GABRIEL");
				}
				continue;
			}
			if(x == 4) {
				if(r <= 2 || c <= 2 || (r * c) % 4 != 0) {
					pw.println("Case #" + t + ": RICHARD");
				} else {
					pw.println("Case #" + t + ": GABRIEL");
				}
				continue;
			}
			if(x >= 7) {
				pw.println("Case #" + t + ": RICHARD");
				continue;
			}
			if(x == 5) {
				if(r <= 2 || c <= 2 || (r * c) % 5 != 0) {
					pw.println("Case #" + t + ": RICHARD");
				} else if(r * c == 15) {
					pw.println("Case #" + t + ": RICHARD");
				} else {
					pw.println("Case #" + t + ": GABRIEL");
				}
				continue;
			}
			if(x == 6) {
				if(r <= 3 || c <= 3 || (r * c) % 6 != 0 || Math.max(r, c) < 6) {
					pw.println("Case #" + t + ": RICHARD");
				} else {
					pw.println("Case #" + t + ": GABRIEL");
				}
				continue;
			}
		}
		
		br.close();
		pw.close();
		System.out.println("done!");
	}
}
