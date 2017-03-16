package round1a;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class ProblemA {

	ProblemA() throws IOException {
		
		Scanner reader = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int cases = reader.nextInt();
		
		for(int i = 1; i <= cases; i++) {
			
			int A = reader.nextInt(), B = reader.nextInt();
			double[] q = new double[A+1];
			double[] c = new double[A+1];
			c[0] = 1;
			for(int j = 0; j < A; j++) {
				double pj = reader.nextDouble();
				q[j] = c[j] * (1-pj);
				c[j+1] = c[j] * pj;
			}
			q[A] = c[A];
			
			double enter = B+2;
			double keep = q[A]*(B+1-A) + (1-q[A])*(2*B+2-A);
			double bestback = B*2+10;
			
			for(int j = 1; j < A; j++) {
				int left = A-j;
				int first = j+B-left+1;
				int second = first+B+1;
				double exp = first*c[left] + second*(1-c[left]);
				if(exp<bestback) bestback = exp;
			}
			
			double result = Math.min(enter, Math.min(keep,bestback));
			
			writer.write("Case #"+i+": "+result);
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		new ProblemA();
	}
}
