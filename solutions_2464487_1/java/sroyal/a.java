import java.util.*;
import java.math.*;
public class a {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			long curr = br.nextLong();
			BigInteger have = BigInteger.valueOf(br.nextLong());
			long count = 0;
			curr++;
			BigInteger two = new BigInteger("2");
			if(curr % 2 == 0){
				long low = 1;
				long high = 707106781;
				while(high-low > 1){
					long mid = (low+high)/2;
					BigInteger sum = BigInteger.valueOf(-mid);
					long th = curr +(mid-1)*2;
					BigInteger other = BigInteger.valueOf(th/2);
					sum = sum.add(two.multiply(other.multiply(other.add(BigInteger.ONE))));
					BigInteger temp2 = BigInteger.valueOf(curr-2);
					temp2 = temp2.divide(two);
					sum = sum.subtract(two.multiply(temp2).multiply(temp2).add(BigInteger.ONE));
					if(sum.compareTo(have) > 0){
						high = mid;
					}
					else{
						low = mid;
					}
				}
				System.out.println("Case #"+c+": "+low);
			}
			else{
				long low = 1;
				long high = 707106781;
				while(high-low > 1){
					long mid = (low+high)/2;
					BigInteger sum = BigInteger.valueOf(-mid);
					long th = curr +(mid-1)*2;
					BigInteger other = BigInteger.valueOf(th/2);
					sum = sum.add(two.multiply(other.multiply(other.add(BigInteger.ONE))));
					BigInteger temp2 = BigInteger.valueOf(curr-2);
					temp2 = temp2.divide(two);
					sum = sum.subtract(two.multiply(temp2).multiply(temp2).add(BigInteger.ONE));
					if(sum.compareTo(have) > 0){
						high = mid;
					}
					else{
						low = mid;
					}
				}
				System.out.println("Case #"+c+": "+low);
			}
		}
	}
}

