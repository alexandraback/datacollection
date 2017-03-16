import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Scanner;


public class Fractiles {
	public static void main(String[] args) throws IOException{
		Scanner kb = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("fractiles.out"));
		//PrintStream out = System.out;
		int cases = kb.nextInt();
		for(int n=0; n < cases; n++) {
			out.print("Case #" + (n + 1) + ":");
			
			long k = kb.nextLong(), c = kb.nextLong(), s = kb.nextLong();
			long[] powers = new long[(int) c];
			powers[0] = 1;
			for (int i=1; i < c; i++)
				powers[i] = k * powers[i-1];
			
			if (c * s < k)
				out.print("IMPOSSIBLE");
			else {
				long i=0;
				while (i < k) {
					long num = 1;
					for (int j=0; j < c && i < k; j++) {
						num += i * powers[j];
						i++;
					}
					out.print(" " + num);
				}
			}
			out.println();
		}
		out.close();
	}
}
