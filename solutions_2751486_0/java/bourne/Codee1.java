import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;


public class Codee1 {
	static Map<Character, Boolean> mp = new HashMap<Character, Boolean>();
	public static void main(String[] args) throws IOException {
		String inp = "E:\\CodeJam\\A-small-attempt0.in";
		String otp = "opt2.txt";
		mp.put('a', Boolean.TRUE);
		mp.put('e', Boolean.TRUE);
		mp.put('i', Boolean.TRUE);
		mp.put('o', Boolean.TRUE);
		mp.put('u', Boolean.TRUE);
		BufferedReader read = new BufferedReader(new FileReader(new File(inp)));
		BufferedWriter write = new BufferedWriter(new FileWriter(new File(otp)));
		int t = Integer.parseInt(read.readLine());
		for(int i=0; i<t; i++) {
			String[] v1 = read.readLine().split(" ");
			String s = v1[0];
			write.write("Case #"+(i+1)+": " +solve(s, Integer.parseInt(v1[1])) + "\n");
		}
		write.flush();
		write.close();
	}
	
	public static long solve(String s1, int n) {
		boolean[] a = new boolean[s1.length()];
		for(int i=0; i<a.length; i++) {
			if(!mp.containsKey(s1.charAt(i))) {
				a[i] = true;
			}
		}
		int c = 0;
		for(int i=0; i<s1.length(); i++) {
			int maxCon = 0;
			if(a[i]) {
				maxCon = 1;
			}
			int ind = s1.length();
			int j;
			for(j=i+1; j<s1.length(); j++) {
				if(maxCon == n) {
					ind = j-1;
					break;
				} else {
					if(a[j-1] && a[j]) {
						maxCon++;
					} else if(a[j]){
						maxCon = 1;
					} else {
						maxCon = 0;
					}
				}
			}
			if(j==s1.length() && maxCon == n) {
				ind = j-1;
			}
			if(maxCon == n) {
				c += s1.length() - ind;
			}
		}
		return c;
	}
}
