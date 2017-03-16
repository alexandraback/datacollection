import java.util.*;
import java.io.*;

public class tt {	
	public static void main(String[] args) throws Exception {
		InputStream is = null;
		OutputStream os = null;
		try {
			is = new FileInputStream("c:/users/user/desktop/input.txt");
			os = new FileOutputStream("c:/users/user/desktop/output.txt");
			
	        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
	        PrintWriter writer = new PrintWriter(os);
	        int cnt = Integer.parseInt(reader.readLine());
	        for (int i=0;i<cnt;++i) {
	        	//String[] lines = new String[4];
	        	//for (int j=0;j<4;++j)lines[j]=reader.readLine();
	        	String[] eles = reader.readLine().split(" ");
	        	String[] eles2 = reader.readLine().split(" ");
	        	int[] vals = new int[eles2.length];
	        	for (int j=0;j<eles2.length;++j) {
	        		vals[j] = Integer.parseInt(eles2[j]);	        		
	        	}
	        	writer.println("Case #" + (i+1) + ": " + 
	        			new tt().solve(Integer.parseInt(eles[0]), Integer.parseInt(eles[1]), vals));
	        }
	        writer.flush();
		} finally {
			if (is != null)is.close();
			if (os != null)os.close();
		}
	}
	
	int[] vals;
	int engery, gain, n;
	//boolean[] used;
	int[] maxEnter, minLeave;
	long res;
	void doIt(int from, int end) {
		if (from >= end)return;
		int pos = from;
		long tv = vals[pos];
		// find the max
		for (int i=from; i<end; ++i) {
			if (vals[i] > tv) {
				tv = vals[i];
				pos = i;
			}
		}
		int uv = Math.min(maxEnter[pos], maxEnter[pos] + gain - minLeave[pos]);
		res += tv * uv;
		
		int tt = uv + minLeave[pos] - gain;//maxEnter[pos];
		int tp = pos - 1;
		while (tp >= from && tt> gain) {
			minLeave[tp] = Math.max(minLeave[tp], tt);
			tt-=gain;
			--tp;
		}
		tp = pos + 1;
		tt = gain + maxEnter[pos] - uv;
		while (tp< end && tt<engery) {
			maxEnter[tp] = Math.min(maxEnter[tp], tt);
			tt+=gain;
			++tp;
		}		
		
		doIt(from, pos);
		doIt(pos+1, end);
	}
	
	String solve(int energy, int gain, int[] vals) {
		this.vals = vals;
		this.engery = energy; 
		this.gain = gain;
		n = vals.length;
		maxEnter = new int[n];
		minLeave = new int[n];
		//used = new boolean[n];
		for (int i=0;i<n;++i){
			maxEnter[i] = energy;
			minLeave[i] = gain;
		} 
		
		res = 0;
		doIt(0, n);
		return "" + res;
	}
	
}