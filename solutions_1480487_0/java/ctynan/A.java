package round1b;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class A {

public static String[] solve(int[] s) {
	
	int X = 0;
	String[] ret = new String[s.length];
	for(int i=0; i<s.length; i++) X+=s[i];
	
	for(int i=0; i<s.length; i++) {
		double lo = 0.0;
		double hi = 1.0;
		double cur = 0.5;
		while(hi-lo > 1e-8) {
			double spare = 1.0-cur;
			
			double threshold = s[i]+cur*X;
			for(int j=0; j<s.length; j++) {
				if(j==i) continue;
				
				if(s[j]>=threshold) continue;
				
				double diff = threshold-s[j];
				spare -= diff/X;
			}
		
			if(spare<=0) {
				hi=cur;
				cur = (hi+lo)/2;
			}
			else {
				lo=cur;
				cur = (hi+lo)/2;
			}
		}
		ret[i] = String.format("%f", 100*cur);
	}
	
	return ret;
}
	
	
public static void main(String[] args) throws Exception {
		
		String fs_in = "/Users/ctynan/Downloads/test.txt";
		String fs_out = "/Users/ctynan/Documents/A-out.txt";
		String line;
		BufferedReader br = new BufferedReader(new FileReader(fs_in));
		BufferedWriter bw = new BufferedWriter(new FileWriter(fs_out));
		
		line=br.readLine();
		line=line.toLowerCase();
		int tst = Integer.valueOf(line);
		
		for(int ii=0;ii<tst; ii++) {
			line=br.readLine();
			String[] tem = line.split(" ");
			int N = Integer.valueOf(tem[0]);
			int[] s = new int[tem.length-1];
			for(int i=1; i<tem.length; i++) {
				s[i-1] = Integer.valueOf(tem[i]);
			}
			
			String[] res = solve(s);
			//for(int i=0; i<res.length; i++) System.out.println(res[i]+" ");
			String output = "Case #" + Integer.toString(ii+1) +": ";
			bw.write(output);
			for(int i=0; i<res.length; i++) {
				bw.write(res[i]);
				if(i<res.length-1) bw.write(' ');
			}
			if(ii<tst-1) bw.write('\n');
		}
		bw.close();
		return;
	}
}
