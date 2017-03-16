package round1B;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class BSlow {

	public static void main(String[] args) {
		Scanner in;
		PrintWriter out;
		try {
			in = new Scanner(new File("B-small-attempt1.in"));
			out = new PrintWriter("b1.out");
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			System.exit(1);
			return;
		}
		
		int numCases = in.nextInt();
		
		for (int t = 1; t <= numCases; t++){
			
			int A = in.nextInt();
			int B = in.nextInt();
			int K = in.nextInt();
			int count = 0;
			for (int a = 0; a < A; a++){
				for (int b = 0; b < B; b++){
					if ((a&b) < K) count++;
				}
			}
			
			out.println("Case #" + t + ": " + count);
					
			
			
			
		}
		
		in.close();
		out.close();
		
	}

	
}
