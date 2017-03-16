import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashSet;


public class Prob1C {

	public static final String impo = "Impossible";
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new FileReader("C-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int t = Integer.parseInt(br.readLine());
		for(int x = 1; x <= t; x++) {
			int res = 0;
			String[] strs = br.readLine().split(" ");
			int[] nrs = new int[strs.length - 1];
			for(int i = 0; i < nrs.length; i++) {
				nrs[i] = Integer.parseInt(strs[i + 1]);
			}
			
			boolean found = false;
			int[] existent = new int[2000001];
			for(int i = 0; i < nrs.length && !found; i++) {
				if(existent[nrs[i]] != 0) {
					write(pw, x, nrs, nrs[i], existent[nrs[i]]);
					found = true;
					break;
				}
				for(int j = existent.length - nrs[i] - 1; j > 0; j--) {
					if(existent[j] > 0) {
						if(existent[j + nrs[i]] > 0) {
							write(pw, x, nrs, existent[j], i, existent[j + nrs[i]]);
							found = true;
							break;
						} else {
							existent[j + nrs[i]] = existent[j] | (1 << i);
						}
					}
				}
				existent[nrs[i]] = (1 << i);
			}
			
			if(!found) {
				pw.println("Case #" + x + ":");
				pw.println(impo);
			}
		}
		
		br.close();
		pw.close();
	}
	
	static void write(PrintWriter pw, int testCase, int[] nrs, int bits1, int pos1, int bits2) {
		pw.println("Case #" + testCase + ":");
		
		HashSet<Integer> set1 = new HashSet<Integer>();
		for(int pos = 0; pos < nrs.length; pos++) {
			if(((1<<pos) & bits2) != 0) {
				set1.add(nrs[pos]);
			}
		}
		HashSet<Integer> set2 = new HashSet<Integer>();
		set2.add(nrs[pos1]);
		for(int pos = 0; pos < nrs.length; pos++) {
			if(((1<<pos) & bits1) != 0) {
				set2.add(nrs[pos]);
			}
		}
		HashSet<Integer> set3 = new HashSet<Integer>();
		for(int val : set1) {
			if(set2.contains(val)) {
				set3.add(val);
			}
		}
		for(int val : set3) {
			set1.remove(val);
			set2.remove(val);
		}
		String s = "";
		for(int val : set1) {
			s += " " + val;
		}
		pw.println(s.substring(1));
		s = "";
		for(int val : set2) {
			s += " " + val;
		}
		pw.println(s.substring(1));
	}
	
	static void write(PrintWriter pw, int testCase, int[] nrs, int n, int bits) {
		pw.println("Case #" + testCase + ":");
		pw.println(n);
		String s = "";
		for(int pos = 0; pos < nrs.length; pos++) {
			if(((1<<pos) & bits) != 0) {
				s += " " + nrs[pos];
			}
		}
		pw.println(s.substring(1));
	}
}
