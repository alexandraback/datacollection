import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class D {

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new File("D.out"));
		int T = in.nextInt();
		for(int t = 1; t<=T; t++){
		int K = in.nextInt();
		int C = in.nextInt();
		int S = in.nextInt();
		out.printf("Case #%d:",t);
		for(int i = 1; i <= S; i++){
			out.print(" "+i);
		}
		out.println();
		}
		out.close();
	}

}
