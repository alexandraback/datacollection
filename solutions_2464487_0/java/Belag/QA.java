import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class QA {

	public static void main(String[] Args) throws IOException {
		Scanner sc = new Scanner(new FileReader("A-small.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
		int caseCnt = sc.nextInt();
		sc.nextLine();
		for (int caseNum = 1; caseNum <= caseCnt; caseNum++) {
			System.out.println(caseNum);

			long r = sc.nextLong();
			long t = sc.nextLong();

			
			double delta = (double) (3+2*r) * (double) (3+2*r) -8* (double) (2*r+1-t);
			
			double sqrtDelta = Math.sqrt(delta);
			
			int ans = (int) Math.floor((-(double)(3+2*r) + sqrtDelta)/4)+1;
//			BigInteger delta = BigInteger.valueOf(
//					t)
//					.add(BigInteger.valueOf(r).multiply(BigInteger
//							.valueOf(r)));

			pw.println("Case #" + caseNum + ": " + ans);
		}

		pw.flush();
		pw.close();
		sc.close();
	}
	
	
	
	
}
