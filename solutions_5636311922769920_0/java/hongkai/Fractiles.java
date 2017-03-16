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
			
			int k = kb.nextInt(), c = kb.nextInt(), s = kb.nextInt();
			for (int i=1; i <= k; i++) {
				out.print(" " + i);
			}
			out.println();
		}
		out.close();
	}
}
