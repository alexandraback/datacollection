import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.math.BigInteger;


public class GoogleCodeJamBullsEye {
	public static void main(String args[]) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(
				new FileInputStream("/Users/ashwinjain/Desktop/bull_in_small.txt")));
		int cases = Integer.parseInt(br.readLine());
		
		for(int xx=0;xx<cases;xx++){
			String temp[] = br.readLine().split(" ");
			BigInteger t = new BigInteger(temp[1]);
			BigInteger r = new BigInteger(temp[0]);
			BigInteger a = BigInteger.ONE;
			BigInteger curr = a.multiply(
					a.multiply(new BigInteger("2"))
					.add(r.multiply(new BigInteger("2")))
					.subtract(BigInteger.ONE));
			//System.out.println("curr:"+curr);
			while(t.compareTo(curr) >= 0){
				a=a.add(BigInteger.ONE);
				curr = a.multiply(a.multiply(new BigInteger("2")).add(r.multiply(new BigInteger("2"))).subtract(BigInteger.ONE));
				//System.out.println("T: "+ t + "curr: "+curr);
			}
			
			System.out.printf("Case #%d: %s\n",(xx+1),a.subtract(BigInteger.ONE));
			//break;
		}
	}
}
