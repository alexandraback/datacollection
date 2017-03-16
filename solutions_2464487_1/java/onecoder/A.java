import java.math.BigInteger;
import java.util.Scanner;


public class A {

	private static void solve() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int test =  1 ; test <= T; test++){
			long r = sc.nextLong();
			long t = sc.nextLong();
			long tt = t;
			long ans = 0;
			while(true){
				long s = (r+1)*(r+1) - (r)*r;
				if(tt>=s)ans++;else break;		
				tt-=s;
				r=r+2;
			}
			System.out.println("Case #"+test+": "+ans);
		}
		
	}
	
	private static void solveBig() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int test =  1 ; test <= T; test++){
			long r = sc.nextLong();
			long t = sc.nextLong();
			long tt = t;
			long ans = 1;
			r=2*r+1;
			long st = 1;long end = Integer.MAX_VALUE -1;long m = st;
			while(true){
				m = (st+end)/2;
				BigInteger eq = BigInteger.valueOf(m).multiply(BigInteger.valueOf(r)).add(BigInteger.valueOf(2*m).multiply(BigInteger.valueOf(m-1)));
				BigInteger eq1 = BigInteger.valueOf(m+1).multiply(BigInteger.valueOf(r)).add(BigInteger.valueOf(2*(m+1)).multiply(BigInteger.valueOf(m)));
			
				
					if(eq.compareTo(BigInteger.valueOf(t))<=0 && eq1.compareTo(BigInteger.valueOf(t))>0){
					break;
					}
					else if(eq.compareTo(BigInteger.valueOf(t))<=0){
						st = m+1;
				}else end  = m-1;

			}
			

			System.out.println("Case #"+test+": "+m);
		}
		
	}
	
	public static void main(String[] args) {
		solveBig();
	}
	
}
