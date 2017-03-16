import java.io.*;
import java.util.*;

public class PasswordProblem {

	public static void main(String[] args) {
		Scanner sc = null;
		PrintWriter fout = null;
		int t = 0;

		try {
			sc = new Scanner(new File(args[0]));
			fout = new PrintWriter(new BufferedWriter(new FileWriter("result.txt")));
			t = sc.nextInt();
		} catch(Exception e) {
			System.out.println(e);
		}
		
		for( int i = 0; i < t; i++ ) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			double[] p = new double[a];
			
			for( int j = 0; j < a; j++ ) {
				p[j] = sc.nextDouble();
			}
			
			double minStroke = b + 2;
			double[] pPerfect = new double[a+1];
			pPerfect[0] = 1.;
			for( int j = 1; j <= a; j++ ) {
				pPerfect[j] = pPerfect[j-1] * p[j-1];
			}
						
			for( int numB = 0; numB <= a; numB++ ) {
				double tmpStroke = pPerfect[a-numB] * ( 2 * numB + b - a + 1 );
				tmpStroke += ( 1 - pPerfect[a-numB] ) * ( 2 * numB + b - a + 1 + b + 1 );
				minStroke = Math.min( tmpStroke, minStroke );
			}
			
			//System.out.println("Case #" + (i+1) + ": " + minStroke);
			fout.println("Case #" + (i+1) + ": " + minStroke);
		}

		fout.close();
		sc.close();
	}

}
