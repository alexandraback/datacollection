package codejam2016;

import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;

public class rq_c {
	
	static BigInteger[][] pow;
	static int N;
	static BigInteger char2val (char[] in, int base) {
		BigInteger r = pow[base][N-1].add(BigInteger.ONE);
		for (int i=0;i<in.length;i++) {
			if (in[i]=='1')
				r= r.add(pow[base][N-i-2]);
		}
		return r;
	}
	static void nextv (char[] in) {
		for (int i=in.length-1;i>=0;i--) {
			if (in[i]=='1') in[i]='0';
			else {
				in[i]='1';
				break;
			}
		}
	}
	static String char2out (char[] in) {
		String r = String.format("1%s11%s1", String.valueOf(in), String.valueOf(in));
		return r;
	}
	static public void main(String[] args) throws Exception{
		pow = new BigInteger[11][32];
		for (int i=2;i<11;i++) {
			for (int j=0;j<32;j++) {
				if (j==0) pow[i][j]=BigInteger.valueOf(1);
				else {
					pow[i][j] = pow[i][j-1].multiply(BigInteger.valueOf(i));
				}
			}
		}
		
		char[] x = new char[14];
		Arrays.fill(x, '0');
		N=16;
		PrintWriter pw = new PrintWriter("d:/out");
		pw.println("Case #1:");
		for (int i=0;i<500;i++) {
			StringBuilder sb = new StringBuilder(char2out(x));
			for (int base=2;base<=10;base++) {
				sb.append(" ");
				sb.append(char2val(x, base).toString());
			}
			pw.println(sb.toString());
			nextv(x);
		}
		pw.close();
	}
}
