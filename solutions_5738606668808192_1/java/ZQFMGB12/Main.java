package codejam16qualp3;

import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;

public class Main {

	public static final int LIM = 1000;
	public static final int N = 32;
	public static final int J = 500;
	static int cnt = 0;
	
	static BigInteger prime(BigInteger n){
		if (n.compareTo(BigInteger.ONE) == -1) return new BigInteger("-1");
		if (n.compareTo(new BigInteger("3")) == -1) return new BigInteger("-1");
		if (n.mod(new BigInteger("2")).equals(BigInteger.ZERO)) return new BigInteger("2");
		if (n.mod(new BigInteger("3")).equals(BigInteger.ZERO)) return new BigInteger("3");
		int cnt = 0;
		for (BigInteger i = new BigInteger("5"); i.multiply(i).compareTo(n) <= 0; i = i.add(new BigInteger("6"))){
			if (cnt >= LIM) break;
			cnt++;
			if (n.mod(i).equals(BigInteger.ZERO)) return i;
			if (n.mod(i.add(new BigInteger("2"))).equals(BigInteger.ZERO)) return i.add(new BigInteger("2"));
		}
		return new BigInteger("-1");
	}
	
	static BigInteger toBase10(long n, int base){
		BigInteger num = new BigInteger("0");
		int p = 0;
		while(n > 0){
			if (n%2 == 1){
				BigInteger i = new BigInteger(Integer.toString(base));
				i = i.pow(p);
				num = num.add(i);
			}		
			p++;
			n >>= 1;
		}
		return num;
	}
	
	//hey, I'm actually using java for once
	public static void main(String[] args) throws Exception{
		PrintWriter out = new PrintWriter(new File("data.out"));
		out.printf("Case #1:\n");
		ArrayList<BigInteger> list = new ArrayList<BigInteger>();
		for (long i = 1L<<(N-1); i <= 1L<<N; i++){
			if (i%2 == 0) continue;
			//System.out.println(i);
			boolean flag = true;
			list.clear();
			for (int j = 2; j <= 10; j++){
				BigInteger num = toBase10(i,j);
				BigInteger p = prime(num);
				if (p.equals(new BigInteger("-1"))){
					flag = false;
					break;
				}
				list.add(p);
			}
			if (flag){
				BigInteger n = new BigInteger(Long.toString(i));
				out.print(n.toString(2));
				System.out.println(n.toString(2));
				for (BigInteger num : list){
					out.print(" " + num.toString());
				}
				out.print("\n");
				cnt++;
			}
			if (cnt >= J) break;
		}
		out.flush();
		out.close();
	}
	
}
