import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.Scanner;


public class CODE_JAM {
	public static BigInteger isqrt (BigInteger  n ){  BigInteger p,r;
	   r = n; // initial guess

	   do{

	      p = r;
	      r = r.add(n.divide(r)).divide(BigInteger.valueOf(2)); // integer division!

	   }while(r.compareTo(p)==-1);
	   //while( r.longValue() < p.longValue() );
	   return p;
	}
	public static BigInteger ptb2( long a,  long b,  long c){
		
		 BigInteger delta=BigInteger.valueOf(b).multiply(BigInteger.valueOf(b)).subtract(BigInteger.valueOf(a).multiply(BigInteger.valueOf(c)).multiply(BigInteger.valueOf(4)));
		return (BigInteger.valueOf(-1*b).add(isqrt(delta))).divide(BigInteger.valueOf(2*a));
	}
	public static void main(String [] args) throws IOException{
		long  T;
		long  r, t;
		long  sum;
		BigInteger rs;
		Scanner inp=new Scanner(new File("in.txt"));
		File file = new File("out.txt");
		FileWriter fw = new FileWriter(file.getAbsoluteFile());
		BufferedWriter bw = new BufferedWriter(fw);
		T=inp.nextLong();
		for(int count=1;count<=T;count++){
			r=inp.nextLong();
			t=inp.nextLong();
			//sum=0;rs=1;
//			sum=rs*(2*r-1+2*rs);
//			while(sum<=t){
//				rs++;
//				sum=rs*(2*r-1+2*rs);
//			}
			rs=ptb2(2, 2*r-1, t*-1);
			
			String rsu="Case #"+count+": "+rs+"\n";
			bw.write(rsu);
		}
		bw.close();
	}
}
