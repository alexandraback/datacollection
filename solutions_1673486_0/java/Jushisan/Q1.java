package Round1A;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Q1 {
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		String output = "./resultQ1.txt";
		BufferedWriter writer = new BufferedWriter(new FileWriter(output));
		
		int T = in.nextInt();
		for (int numCase = 1; numCase <= T; numCase++) {
			int A = in.nextInt();
			int B = in.nextInt();
			
			double[] p = new double[A];
			for (int i = 0; i < A; i++)
				p[i] = in.nextDouble();
			
			ArrayList<Double> avg = new ArrayList<Double>();
			double[] pUpto = new double[A];
			for (int i = 0; i < A; i++)
				pUpto[i] = (i == 0) ? p[i] : pUpto[i-1]*p[i];
			
			// keep typing
			String toPrint = "Case #" + numCase + ":";
			for (int nKeyBack = 0; nKeyBack < A; nKeyBack++) {								
				// how much it costs if it's correct.
				double correctCost = nKeyBack*2 + (B - A) + 1.0;
				// how much it costs if it's incorrect.
				double inCorrectCost = correctCost + B + 1.0;
				double correctUptoNow = pUpto[A - nKeyBack - 1];
				double incorrect = 1 - correctUptoNow;
				double avgCost = 0.0;
				avgCost = incorrect*inCorrectCost + correctUptoNow*correctCost;
				avg.add(avgCost);
			}
			// cost if restart immediately
			avg.add(2.0 + B);
			DecimalFormat decim = new DecimalFormat("0.0000000");
			toPrint += " " + decim.format(Collections.min(avg)) + "\r\n";
			System.out.println(toPrint);
			writer.write(toPrint);
		}
		writer.flush();
		writer.close();
	}
}
