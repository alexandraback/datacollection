import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;

public class Main {
	

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File("C.in")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(new File("C.out"))));

		BigInteger[] prime = new BigInteger[10000];
		int[] p = new int[prime.length];
		loop1:for (int i = 3, c = 0; c < p.length; i+=2) {
			for (int j = 0; j < c; j++) {
				if (i % p[j] == 0) continue loop1; 
			}
			p[c++] = i;
		}
		for (int i = 0; i < prime.length; i++) prime[i] = BigInteger.valueOf(p[i]);
		
		int T = Integer.parseInt(br.readLine());
		for (int t = 0; t < T; t++) {
			String[] str = br.readLine().split(" ");
			int N = Integer.parseInt(str[0]);
			int J = Integer.parseInt(str[1]);
			pw.println("Case #"+(t+1)+": ");

			long n = ((long)1 << (N-1)) + 1;
			
			loop2:for (int i = 0; i < J;) {
				System.out.println();
				System.out.print(""+n+" "+Long.toBinaryString(n));
				String answer = Long.toBinaryString(n);
				loop3:for (int j = 2; j <= 10; j++) {
					BigInteger bi = new BigInteger(Long.toBinaryString(n), j);
					System.out.print(" "+bi);
					for (int k = 0; k < prime.length; k++) {
						if (bi.equals(prime[k])) {
							n += 2;
							continue loop2;
						}
						if (bi.mod(prime[k]).equals(BigInteger.ZERO)) {
							System.out.print(" "+p[k]);
							answer += " " + p[k];
							continue loop3;
						}
					}
					n += 2;
					continue loop2;
				}
				System.out.print(" ok");
				pw.println(answer);
				pw.flush();
				i++;
				n += 2;
			}
		}

		pw.close();
		br.close();
	}
	
}
