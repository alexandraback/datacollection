import java.math.BigInteger;
import java.util.Scanner;


public class Bull {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int cases = sc.nextInt();
		
		for(int c = 0; c<cases; c++){
			long r = sc.nextLong();
			long t = sc.nextLong();
			
			BigInteger R = new BigInteger(""+r);
			BigInteger T = new BigInteger(""+t);
			BigInteger TWO = new BigInteger(2+"");
			BigInteger left = BigInteger.ZERO;
			BigInteger right = new BigInteger(""+707106790);
			BigInteger mid = right.subtract(left).divide(new BigInteger(2+""));
			
			while(right!=left){
				
				BigInteger act = (mid.add(BigInteger.ONE)).multiply(TWO.multiply(mid).add(TWO.multiply(R)).add(BigInteger.ONE));
				
				if(act.compareTo(T)<0){
					left  = mid;
					mid = right.add(left).divide(TWO);
				} else if (act.compareTo(T)>0){
					right = mid;
					mid = right.add(left).divide(TWO);		
				} else {
					break;
				}

				if(mid.compareTo(left)==0 || mid.compareTo(right)==0)break;
			}
					
			System.out.printf("Case #%d: %d\n",(c+1),mid.add(BigInteger.ONE));
		}

	}

}
