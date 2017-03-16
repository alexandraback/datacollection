import java.io.File;
import java.io.PrintWriter;
import java.util.*;


public class Password {
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new File("A-large.in"));
		int num = scanner.nextInt();
		scanner.nextLine();
		PrintWriter writer = new PrintWriter(new File("Password.txt"));
		for(int a = 1;a<=num;a++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			double[] probs = new double[A];
			double[] cums = new double[A];
			double prob = 1;
			for(int i = 0;i<A;i++) {
				probs[i]=scanner.nextDouble();
				prob*=probs[i];
				cums[i]=prob;
			}
			double expected = Math.min(B+2,prob*(B-A+1) + (1-prob)*(B-A+1+B+1));
			for(int i = A-2;i>=0;i--) {
				expected=Math.min(cums[i]*(A-1-i+(B-1-i)+1) + (1-cums[i])*(A-1-i+(B-1-i)+1 + B+1),expected);
				//System.out.println((A-1-i+(B-1-i)+1) +" " + (1-cums[i])*(A-1-i+(B-1-i)+1 + B+1));
			}
			writer.println("Case #" + a + ": " + expected);
			System.out.println("Case #" + a + ": " + expected);
			writer.flush();
			
		}
		writer.close();
	}
}
