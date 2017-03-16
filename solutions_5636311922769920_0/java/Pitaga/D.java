import java.util.*;
import java.io.*;

public class D {
	
	public static void main(String[] args) throws IOException {
		
		
		Scanner qwe = new Scanner(new File("D.in"));
		PrintWriter out = new PrintWriter("D.out");
				
		int T = qwe.nextInt();
		
		for(int cse = 1; cse <= T; cse++){
			
			int K = qwe.nextInt();
			int C = qwe.nextInt();
			int S = qwe.nextInt();
			
			out.print("Case #"+cse+":");
			for(int i =1; i <=K; i++) out.print(" "+i);
			out.println();
			
		}
		
		
		out.close();
		qwe.close();
	}

}
