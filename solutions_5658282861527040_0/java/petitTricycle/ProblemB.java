import java.io.IOException;
import java.io.PrintWriter;

public class ProblemB {

	public static int getNextInt() throws IOException {
		int current = 0, res = 0;
		while (current < 48 || current > 57)
			current = System.in.read();
		;
		while (current >= 48 && current <= 57) {
			res = (current - 48) + res * 10;
			current = System.in.read();
		}
		return res;
	}

	public static void main(String[] args) throws IOException {
		int cases = getNextInt();
		PrintWriter PW = new PrintWriter(System.out);
		String cas = "Case #";
		String dot = ": ";
		int A,B,K;
		int res;
		
		for (int c = 1; c <= cases; c++) {
			A=getNextInt();
			B=getNextInt();
			K=getNextInt();
			res = 0;
			for(int i = 0;i<A;i++)
				for(int j = 0;j<B;j++)
					if((i&j)<K)
						res++;
					
			PW.print(cas);
			PW.print(c);
			PW.print(dot);
			PW.println(res);
		}
		PW.close();
	}
}
