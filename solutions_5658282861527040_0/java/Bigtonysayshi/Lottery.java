
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;

public class Lottery {

	public static int solveLottery(int[] row) {
		int cases = 0;
		int A = row[0];
		int B = row[1];
		int K = row[2];
		
		String bitsA = Integer.toBinaryString(A);
		String bitsB = Integer.toBinaryString(B);
		String bitsK = Integer.toBinaryString(K);
		
		for (int i=0; i<A; i++) {
			for (int j=0; j<B; j++) {
				int C = i & j;
				if (C < K) {
					cases++;
				}
			}
		} 
		
		
		return cases;
	}
	
	private static int leadingOneIndex(String bits) {
		for (int i=0; i<bits.length(); i++) {
			if (bits.charAt(i) == '1') {
				return i;
			}
		}
		return -1;
	}
	
	private static int median(int[] list) {
		int n = list.length;
		
		if (n % 2 == 0) {
			return (list[n/2] + list[n/2 - 1])/2;
		} 
		else {
			return list[(n-1)/2];
		}
	}
	
	
	public static void main(String args[] ) throws Exception {
		String filename = "B-small-attempt0.in";
		String outfilename = "B_small_out.txt";
		
    	BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = br.readLine();
		int numTests = Integer.valueOf(line);
		ArrayList<String> results = new ArrayList<String>();

		for (int i=0; i<numTests; i++) {
			line = br.readLine();
			String[] tokens = line.split(" ");
			
			int[] row = new int[3];
			for (int j=0; j<3; j++) {
				row[j] = Integer.valueOf(tokens[j]);
			}

			
			int cases = solveLottery(row);
			String output = "Case #" + (i+1) + ": " + cases;

			results.add(output);
			
		}
		
		br.close();
		
		Writer writer = null;
		try {
		    writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outfilename), "utf-8"));
		    for (String str : results) {
		    	writer.write(str+"\n");
		    }
		} catch (IOException ex) {
		  // report
		} finally {
		   try {writer.close();} catch (Exception ex) {}
		}
	}
}

