import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;


public class Elf {

	public static void main(String[] args) throws Exception {
		BufferedReader bufferRead = new BufferedReader(new FileReader("A-small-attempt1.in"));
    	//BufferedReader bufferRead = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new FileWriter("A-small.out"));

		int caseCnt = Integer.parseInt(bufferRead.readLine());

		for(int l=0; l<caseCnt; l++) {
			String[] caseData = bufferRead.readLine().split("/");
			long P = Integer.parseInt(caseData[0]);
			long Q = Integer.parseInt(caseData[1]);

			out.println("Case #"+(l+1)+": "+checkElf(P, Q));
		}

		out.close();
        bufferRead.close();
	}

	public static String checkElf(long P, long Q) {
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
}
