import java.math.BigInteger;
import java.util.Scanner;


public class Jam2016_QD {
	public void print(BigInteger[] d) {
		
		for(int i=0; i<(d.length-1); ++i) {
			BigInteger b = d[i];
			
			System.out.print(b + " ");
		}
		System.out.print(d[d.length - 1]);		
		System.out.println();
	}
	
	public int nextIdx(int cur, int max) {
		return (cur + 1) % max;
	}
	
	public BigInteger[] solve(int k, int c, int s) {
		int loop = (k + c - 1)/c;
		BigInteger[] ret = new BigInteger[loop];
		
		//	impossible check
		if(s < loop)
			return null;
		
		//	make index
		BigInteger one = new BigInteger("1");
		int bidx = 0;
		int lidx = 0;
		for(int i=0; i<k;){
			BigInteger idx = new BigInteger("0");
			for(int j=0; j<c; ++j, ++i, ++bidx) {
				idx = idx.multiply(new BigInteger(Integer.toString(k))).add(new BigInteger(Integer.toString(bidx%k)));
			}
			
			ret[lidx++] = idx.add(one);
		}
		
		return ret;
	}
	
	public static void main(String[] args) {
		Scanner	scanIn	= new Scanner(System.in);
		
		int T	= scanIn.nextInt();
		
		for(int i=0; i<T; ++i) {
			Jam2016_QD	inst	= new Jam2016_QD();
			int		k		= scanIn.nextInt();
			int		c		= scanIn.nextInt();
			int		s		= scanIn.nextInt();
			
			BigInteger[] ret = inst.solve(k, c, s);
			
			if(ret == null)
				System.out.println("Case #" + (i+1) + ": " + "IMPOSSIBLE");
			else {
				System.out.print("Case #" + (i+1) + ": ");
				inst.print(ret);
			}
		}
		
		scanIn.close();
	}
}