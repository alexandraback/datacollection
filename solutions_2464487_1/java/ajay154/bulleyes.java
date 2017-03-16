import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.*;


public class bulleyes {

	private static final BigInteger two = new BigInteger("2");
	private static final BigInteger Eight = new BigInteger("8");

	/**
	 * @param args
	 * @throws IOException 
	 */
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int tests;
		Long r,t;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String str1 = br.readLine();
		tests = Integer.parseInt(str1);
		for(int i=1;i<=tests;i++)
		{
			String[] st = br.readLine().split(" ");
			r = Long.valueOf(st[0]);
			t = Long.valueOf(st[1]);
			BigInteger r1=new BigInteger(st[0]);
			BigInteger t1=new BigInteger(st[1]);
			BigInteger temp=r1.multiply(two);
			temp=temp.subtract(BigInteger.ONE);
			BigInteger temp1=temp.multiply(temp);
			temp1=temp1.add(Eight.multiply(t1));
			BigDecimal t2=new BigDecimal(temp1);
			BigDecimal t3=sqrt(t2,1);
			temp1=t3.toBigInteger();
			temp1=temp1.subtract(temp);
			temp1=temp1.divide(new BigInteger("4"));
			System.out.println("Case #"+i+": "+temp1);
			
		}
	}
	public static BigDecimal sqrt(BigDecimal in, int scale){
	    BigDecimal sqrt = new BigDecimal(1);
	    sqrt.setScale(scale + 3, RoundingMode.FLOOR);
	    BigDecimal store = new BigDecimal(in.toString());
	    boolean first = true;
	    do{
	        if (!first){
	            store = new BigDecimal(sqrt.toString());
	        }
	        else first = false;
	        store.setScale(scale + 3, RoundingMode.FLOOR);
	        sqrt = in.divide(store, scale + 3, RoundingMode.FLOOR).add(store).divide(
	                BigDecimal.valueOf(2), scale + 3, RoundingMode.FLOOR);
	    }while (!store.equals(sqrt));
	    return sqrt.setScale(scale, RoundingMode.FLOOR);
	}

}
