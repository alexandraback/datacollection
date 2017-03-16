import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter(new File("ALarge.out"));
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int caseOn = 1; caseOn <= cases; caseOn++) {
			System.out.printf("On case %d\n",caseOn);
			int n = in.nextInt();
			int sum = 0;
			int[] points = new int[n];
			for(int i = 0; i < n; i++) {
				points[i]=in.nextInt();
				sum+=points[i];
			}
			out.printf("Case #%d: ",caseOn);
			for(int i = 0; i < n; i++) {
				double l = 0, h = 100;
				while(Math.abs(l-h) > 1e-9) {
					double m = (l+h)/2;
//					System.out.printf("Checking %.2f for %d yields score %.2f\n",m,i,points[i] + (sum*m)/100.0);
					if(isEnough(points[i] + (sum*m)/100.0, i, m, points, sum)) {
						h=m;
					} else {
						l=m;
					}
				}
				out.printf("%.5f ",(l+h)/2);
			}
			out.println();
		}
		out.close();
	}
	
	public static boolean isEnough(double score, int pos, double percent, int[] scores, int sum) {
		double percentUsed = percent;
		for(int i = 0; i < scores.length; i++) {
			if(i==pos)
				continue;
			if(scores[i]>score)
				continue;
			double l = 0, h = 100;
			while(Math.abs(l-h)>1e-9) {
				double m = (l+h)/2;
				double thisscore = (m * sum)/100.0 + scores[i];
				if(thisscore > score) {
					h=m;
				} else {
					l=m;
				}
			}
//			System.out.printf("Minimum percent needed to beat %.2f is %.2f for %d with score %d\n",(l+h)/2,score,i,scores[i]);
			percentUsed+=(l+h)/2;
		}
		return percentUsed > 100;
	}
}
