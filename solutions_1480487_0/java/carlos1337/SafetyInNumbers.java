package B;

import java.io.File;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.text.NumberFormat;
import java.util.Arrays;
import java.util.Scanner;

public class SafetyInNumbers {

	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new File("A-small.out"));
		int t = sc.nextInt();				
		for (int i = 1; i <= t; i++) {
			int n = sc.nextInt();
			int[] scores = new int[n];
			int sum = 0;
			int max = -1;
			for (int j = 0; j < scores.length; j++) {
				scores[j] = sc.nextInt();
				sum+=scores[j];
				max = Math.max(max,scores[j]);
			}			
			
			
			double[] added = new double[n];
			double total=0;
			for (int j = 0; j < scores.length; j++) {
				added[j] = max-scores[j];
				total+=added[j];
			}
			for (int j = 0; j < added.length; j++) {
				added[j] += (sum-total)/n;
			}
			NumberFormat nf = DecimalFormat.getInstance();
			
			nf.setMinimumFractionDigits(6);
			nf.setMaximumFractionDigits(6);
			String resp = "Case #"+i+": ";
			for (int j = 0; j < added.length; j++) {
				resp+=nf.format(Math.max(100*added[j]/(sum==0?1:sum),0))+" ";
			}
			//System.out.println(min);
			//System.out.println(sum);
			//System.out.println(Arrays.toString(scores));
			//System.out.println(Arrays.toString(reqs));
			pw.println(resp.trim().replace(",", "."));					
		}
		pw.close();
	}
	
}
