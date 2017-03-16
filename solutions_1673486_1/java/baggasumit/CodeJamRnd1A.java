import java.io.*;
import java.util.*;

public class CodeJamRnd1A {
	public static void main(String[] args) throws IOException {
		int i, j, k;
		long startTime = System.currentTimeMillis();
		File inFile = new File("A-large.in"); // File to read from
		File outFile = new File("Rnd1A-large.out");

		BufferedReader reader = new BufferedReader(new FileReader(inFile));
		BufferedWriter writer = new BufferedWriter(new FileWriter(outFile));

		String line = null;
		line = reader.readLine();
		int cases = Integer.parseInt(line);
		int counter = 1;
		

		while ((line = reader.readLine()) != null) {
			float keystr = Float.MAX_VALUE;
			int A, B;			
			String[] node = line.split(" ");
			A = Integer.parseInt(node[0]);
			B = Integer.parseInt(node[1]);
			float[] p = new float[A];
			line = reader.readLine();
			String[] node2 = line.split(" ");
			float pAllRight = 1;
			float[] pMaster = new float[A];
			for(k = 0; k < A; k++) {
				p[k] = Float.parseFloat(node2[k]);
				pAllRight *= p[k];
				pMaster[k] = pAllRight;
 				//System.out.println(p[k]);
			}
			// If I keep typing
			
			// Prob that i got all right
			int strokesWhenRight = B - A + 1;
			int strokesWhenWrong = 2*B - A + 2;
			keystr = pAllRight*strokesWhenRight + (1 - pAllRight)*strokesWhenWrong;
		
			// If I press Enter right away
			keystr = Math.min(keystr, B+2);
					
			// If I backspace
			for(k = 1; k < A; k++) {
				float keys = pMaster[A-k-1] * (B - A + 2*k + 1) + (1 - pMaster[A-k-1])*(2*B - A + 2*k + 2);
				keystr = Math.min(keystr, keys);
			}
			
			// If I rub all
			keystr = Math.min(keystr, A+B+1);
		
			
			//System.out.println(keystr);
			
			writer.write("Case #"+counter+": "+keystr);
			writer.newLine();
			counter++;
		}		
		writer.close();
		long endTime = System.currentTimeMillis();
		long totalTime = endTime - startTime;
		System.out.println("Total Time: " + totalTime);
	}
}
