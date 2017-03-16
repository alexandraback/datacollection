import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;


public class Main {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter out = new PrintWriter(new File("output.txt"));
		
		int tn = in.nextInt();
		for(int ti=1;ti<=tn;++ti){
			long r = in.nextLong();
			long t = in.nextLong();
			
			/*
			 * ll res = sqrt((double)t);
			while(f(res,r)>t) --res;
			while(f(res+1,r)<=t) ++res;
			
			
			cout<<"Case #"<<ti<<": ";
			cout<<res<<' '<<f(res,r);
			cout<<endl;
			 */
			
			/*long res = (long)Math.sqrt((double)t/r);
			while(res*res<=t) ++res;
			--res;
			
			while(f(res,r).compareTo(T)>0) --res;
			while(f(res+1,r).compareTo(T)<=0) ++res;*/
			
			BigInteger lk=BigInteger.ZERO;
			BigInteger rk=BigInteger.valueOf(Long.MAX_VALUE);
			BigInteger T = BigInteger.valueOf(t);
			BigInteger R = BigInteger.valueOf(r);
			
			while(lk.compareTo(rk)<0){
				BigInteger m = (lk.add(rk)).shiftRight(1);
				BigInteger ff = f(m, R);
				if(ff.compareTo(T)<=0){
					lk = m.add(BigInteger.ONE);
				}else rk = m;;
			}
			
			BigInteger res = lk.subtract(BigInteger.ONE);
			
			out.println(String.format("Case #%d: ", ti)+res);
		}
		
		
		out.close();
		
	}
	
	
	static BigInteger f(BigInteger K, BigInteger R){
		//return (4*r+2 + 4*(k-1))/2*k;
		//(2*r-1 + 2*k)*k;
		return R.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE).add(K.multiply(BigInteger.valueOf(2))).multiply(K);
	}

}
