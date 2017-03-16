package round1a;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;

public class ProbA {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scanner = new Scanner(new FileInputStream(args[0]));
		PrintStream out = new PrintStream(args[1]);
		//PrintStream out = System.out;
		int numT = scanner.nextInt();
		for(int T=1; T<=numT; T++) {
			int r = scanner.nextInt();
			int t = scanner.nextInt();
			
			// Naive impl
			int numCircle = 0;
			while(t > 0) {
				int paintReq = (r+1) * (r+1) - (r * r);
				if(t >= paintReq) {
					t -= paintReq;
					numCircle++;
					r+=2;
				} else {
					break;
				}
			}
			out.format("Case #%d: %d\n", T, numCircle);
		}
		scanner.close();
		out.close();
	}

}
