import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Problem1 {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = new Scanner(new File("input.txt"));
		PrintStream output = new PrintStream(new FileOutputStream(new File("output.txt")));
		
		int T = input.nextInt();
		input.nextLine();
		
		for(int i=1; i <= T; ++i) {
			Scanner line = new Scanner(input.nextLine());
			int A = line.nextInt();
			int B = line.nextInt();
			line = new Scanner(input.nextLine());
			double p[] = new double[A];
			for(int j =0; j <A; ++j) {
				p[j] = line.nextDouble();
			}
			
			/*System.out.printf("Case:%d, A:%d, B:%d p:", i,A,B);
			for(int j=0; j <A; ++j) {
				System.out.printf("%2f ", p[j]);
			}
			System.out.println("");
			*/
			
			ArrayList<Double> expect = new ArrayList<Double>();
			expect.add((B-A+1)*product(p,0) + (2*B-A+2) * (1-product(p,0)));
			expect.add((double) (B+2));
			
			for(int j=1; j <= A; ++j) {
				expect.add((B-A+2*j+1)*product(p,j) + (2*B-A+2*j+2) * (1-product(p,j)));
			}

			System.out.printf("Case #%d: %f\n",i,Collections.min(expect));
			output.printf("Case #%d: %f\n",i,Collections.min(expect));
		}
	}
	
	public static double product(double[] p, int j) {
		double prod = 1;
		for(int i =0; i < p.length - j; ++i) {
			prod *= p[i];
		}
		//System.out.printf("%f\n",prod);
		return prod;
	}
}
