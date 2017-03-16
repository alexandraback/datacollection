import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class fractal {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		int T = scan.nextInt();
		PrintWriter out = new PrintWriter(new File("fractal.out"));
		
		for(int t=1;t<=T;t++){
			int K = scan.nextInt();scan.nextInt();scan.nextInt();
			out.print("Case #"+t+": ");
			for(int i=1;i<=K;i++)out.print(i+" ");
			out.println();
		}
		out.close();
	}
}
