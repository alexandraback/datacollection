import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class CoinJam {
	
	static BigInteger ZERO = new BigInteger("0");
	static BigInteger ONE = new BigInteger("1");

	
	public static void main(String[] args) throws FileNotFoundException {
		int T,N,J;
		File file = new File("D:\\C-large.in");
		PrintWriter writer = new PrintWriter("D:\\C-large.out");
		Scanner sc = new Scanner(file);
		T = sc.nextInt();
		for (int i=1;i<=T;i++) {
			writer.println("Case #"+i+":");
			N = sc.nextInt();
			J = sc.nextInt();
			int n = (1<<((N/2)-1))+1;
			int dig[] = new int[N/2];
			for (int j=0;j<J;j++) {
				int val = n+2*j;
				for (int k=0;k<N/2;k++) {
					dig[N/2-1-k] = val%2;
					val /= 2;
				}
				for (int k=0;k<N/2;k++) 
					writer.print(dig[k]);
				for (int k=0;k<N/2;k++) 
					writer.print(dig[k]);
				for (int k=2;k<=10;k++) {
					BigInteger res = ZERO;
					for (int l=0;l<N/2;l++) {
						res = res.multiply(BigInteger.valueOf(k));
						if (dig[l]==1) res = res.add(ONE);
					}
					writer.print(" "+res);
				}
				writer.println();
			}
		}
		writer.close();
		sc.close();
	}
}
