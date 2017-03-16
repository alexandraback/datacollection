import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Elf {

	public static void main(String[] args) throws Exception {
		BufferedReader bufferRead = new BufferedReader(new FileReader("A-large.in"));
    	//BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new FileWriter("A-large.out"));

		int caseCnt = Integer.parseInt(bufferRead.readLine());

		for(int l=0; l<caseCnt; l++) {
			String[] caseData = bufferRead.readLine().split("/");
			long P = Long.parseLong(caseData[0]);
			long Q = Long.parseLong(caseData[1]);

			out.println("Case #"+(l+1)+": "+checkElf(P, Q));
		}

		out.close();
        bufferRead.close();
	}

	public static String checkElf(long P, long Q) {
		long gcd = findGcd(P,Q);

		Q /= gcd;
		P /= gcd;

		long currQ = 1;
		while(currQ*2 <= Q) {
			currQ *= 2;
		}

		if(currQ < Q && currQ * 2 > Q)
			return "impossible";

		for(long i=1; i<=40; i++) {
			P *= 2;
			double currGen = (double)P / (double)Q;
			if(currGen >= 1.0)
				return Long.toString(i);
		}

		return "impossible";
	}

	public static long findGcd(long a, long b) {
		while(b > 0) {
			long temp = b;
			b = a % b;
			a = temp;
		}
		return a;
 	}
}
