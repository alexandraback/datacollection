import java.util.*;
import java.io.*;
import java.math.BigInteger;

public class Bullseye {
	public static long getNumber(BigInteger r, BigInteger t) {
		BigInteger res;
		BigInteger b = (new BigInteger("4")).add(r.multiply(new BigInteger("4")));
		BigInteger a = b.multiply(b).subtract((new BigInteger("4").multiply((new BigInteger("12")).multiply(r).add(new BigInteger("3")).subtract(t.multiply(new BigInteger("8"))))));
		res = sqrt(a);
		res = res.subtract(b);
		res = res.divide(new BigInteger("2"));
		long re = res.longValue();
		return (long)(re-1)/4+1; 
	}
	
	public static BigInteger sqrt(BigInteger n) {
	  	BigInteger a = BigInteger.ONE;
	  	BigInteger b = new BigInteger(n.shiftRight(5).add(new BigInteger("8")).toString());
	  	while(b.compareTo(a) >= 0) {
	    	BigInteger mid = new BigInteger(a.add(b).shiftRight(1).toString());
	    	if(mid.multiply(mid).compareTo(n) > 0) b = mid.subtract(BigInteger.ONE);
	    	else a = mid.add(BigInteger.ONE);
	  	}
	  	return a.subtract(BigInteger.ONE);
	}
	
	public static void main(String[] args) {
		//System.out.println(getNumber(new BigInteger("10000000000000000"),new BigInteger("1000000000000000000")));
		File file = new File("A-large (1).in");
		BufferedReader reader = null;
		
		try{
			reader = new BufferedReader(new FileReader(file));	
			String line1 = reader.readLine();
			int size = Integer.parseInt(line1);
			for(int i=0; i<size; i++){
				String[] t = reader.readLine().split(" ");
				System.out.println("Case #"+(i+1)+": "+getNumber(new BigInteger(t[0]), new BigInteger(t[1])));
			}
		} catch (FileNotFoundException e){
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (reader != null) {
					reader.close();
				}
			} catch (IOException e){
				e.printStackTrace();
			}
		}
	}	
}
