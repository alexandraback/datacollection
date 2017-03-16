import java.util.*;
import java.io.*;
import java.math.BigInteger;
public class CoinJam {
	static PrintWriter w; static final long L = 101;
	public static void main(String...thegame)throws Exception{
		w = new PrintWriter("coinjam.txt", "UTF-8");
		Scanner seer = new Scanner(System.in);
		int T = seer.nextInt(); int count = 0;
		for(int t = 0; t < T; t++){
			w.print(String.format("Case #%d:\n", t+1));
			int N = seer.nextInt();
			int J = seer.nextInt();
			long max = (long) Math.pow(2, N) - 1;
			for(long i = (long) Math.pow(2, N-1) + 1; i <= max; i+=2){
				String n = Long.toBinaryString(i);
				long[] divs = new long[11];
				for(int r = 2; r <= 10; r++){
					BigInteger big = new BigInteger(n, r);
					for(long d = 2; d <= L; d++){
						if(big.mod(BigInteger.valueOf(d)).equals(BigInteger.ZERO)) {
							divs[r] = d; break;
						}
					}
				}
				boolean ver = true;
				for(int r = 2; r <= 10; r++) if(divs[r] == 0) ver = false;
				if(!ver) continue;
				StringBuilder sb = new StringBuilder();
				sb.append(n+" ");
				for(int r = 2; r <= 10; r++) sb.append(divs[r]+" ");
				w.println(sb.toString().trim());
				count++; if(count == J) break;
			}
		}
		w.close();
	}
}
