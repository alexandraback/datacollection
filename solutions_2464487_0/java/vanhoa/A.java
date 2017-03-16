//S = pi r^2, in this problem S = r^2 
//first black ring: S1=(r+1)^2-r^2 = 2r+1
//second black ring: S2=2r+5
//k-th black ring: Sk = 2(r+2k)-3=2r+4k-3
//sum over k: 2kr-3k+2*k*(k+1) = t
//solve for k: (-2r+1+sqrt(4r^2-4r+1+8t))/4
import java.math.BigInteger;
import java.util.Scanner;

class A {
 	BigInteger TWO = BigInteger.ONE.add(BigInteger.ONE);
	BigInteger areaFor(BigInteger r, BigInteger n){
		return n.multiply(n.add(r).multiply(TWO).subtract(BigInteger.ONE));
	}
	public BigInteger findNoOfRings(BigInteger r, BigInteger t){
		BigInteger fr = BigInteger.ZERO, to = new BigInteger("999999999999999999999");
		//t=t.divide(BigInteger.TEN.multiply(BigInteger.TEN));
		while(fr.compareTo(to)<=0){
			BigInteger mi = fr.add(to).divide(TWO);
			if(areaFor(r,mi).compareTo(t)<=0) fr=mi.add(BigInteger.ONE);
			else to=mi.subtract(BigInteger.ONE);
		}
		return fr.subtract(BigInteger.ONE);
	}
	public void work(){
		Scanner sc = new Scanner(System.in);
		int nT = sc.nextInt();
		for(int T=1;T<=nT;T++){
			BigInteger r=sc.nextBigInteger();
			BigInteger t=sc.nextBigInteger();
			System.out.println("Case #"+T+": "+findNoOfRings(r,t));
		}
	}
	public static void main(String[] args) {
		new A().work();
	}
}