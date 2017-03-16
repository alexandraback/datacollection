import java.math.BigInteger;
import java.util.Scanner;

public class GCJ_Problem_A {

	
	public static void main(String args[]){
		int T;
		Scanner in = new Scanner(System.in);
		T = in.nextInt();
		
		for(int tt=1; tt<=T; tt++){
			BigInteger ans;
			BigInteger r, t;
			r = in.nextBigInteger();
			t = in.nextBigInteger();
			
			BigInteger left, right, mid, c, cc, two;
			two = new BigInteger("2");
			left = BigInteger.ZERO;
			right = t;
			
			while(true) {
                mid = left.add(right).divide(two);
			
                //c = 2mid*(mid+r-1)+mid;
                //cc  = 2*(mid+1)*((mid+1)+r-1)+(mid+1);
                c = mid.multiply((mid.add(r).subtract(BigInteger.ONE))).multiply(two).add(mid);
                BigInteger mm = mid.add(BigInteger.ONE);
                cc = mm.multiply((mm.add(r).subtract(BigInteger.ONE))).multiply(two).add(mm);
                
                if (c.compareTo(t)<=0 && cc.compareTo(t)>0) {ans = mid; break;}
                
                if (c.compareTo(t)>0) {
                          right = mid;
                } else {
                          left = mid;
                }
                
                //System.out.println("left : "+left+" right : "+right);
			}
			
			System.out.println("Case #"+tt+": "+ans);
		}
	}
}
