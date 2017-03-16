import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.math.BigInteger;
import java.util.Scanner;

public class D {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("D-large.in"));
//		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter("D-out-large.txt", "UTF-8");
		while(sc.hasNext()) {
			int T = sc.nextInt();
			for(int i = 1; i <= T; i++) {
				int K = sc.nextInt();
				int C = sc.nextInt();
				int S = sc.nextInt();
				if(S < Math.ceil((double)K / C)) {
					System.out.println("Case #" + i + ": IMPOSSIBLE");
					pw.println("Case #" + i + ": IMPOSSIBLE");	
					continue;
				}
				System.out.print("Case #" + i + ":");
				pw.print("Case #" + i + ":");
				long a = 0;
				for(int j = 0; j < K; j++) {
					a*=K;
					a+=j;
					if(j%C==C-1) {
						System.out.print(" " + (a+1));
						pw.print(" " + (a+1));
						a = 0;
					}
				}
				if((K-1)%C!=C-1) {
					System.out.print(" " + (a+1));
					pw.print(" " + (a+1));
					a = 0;
				}
				System.out.println();
				pw.println();
			}
			pw.close();
		}
	}
}
