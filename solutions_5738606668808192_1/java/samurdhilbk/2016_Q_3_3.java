import java.io.*;
import java.util.*;
import java.math.*;
import java.lang.*;

class Main{

	 private static final Random rnd = new Random();

	public static long lastTime;

	public static void main(String[] args) throws Exception{

	  long limit=(long)(Math.pow(2.0,32.0)-1.0);

	  //System.out.println(isPrime(BigInteger.valueOf(143)));

	  System.out.println("Case #1:");

	  int count=0;

	  for(long i=(long)(Math.pow(2.0,31.0)+1.0);i<=limit;i+=2){
	    boolean found=true;
	    long n=i;
	    char c[]=new char[32];
	    for(int j=0;j<32;j++){
	      if((n & (1<<j)) != 0) c[31-j]='1';
	      else c[31-j]='0'; 
	    }
	    String s=new String(c);
	    //System.out.println(s);
	    BigInteger vec[]=new BigInteger[11];
	    for(int j=0;j<11;j++) vec[j]=BigInteger.ZERO;
	    for(int j=2;j<=10;j++){
	      BigInteger u=new BigInteger(s,j);
	      if(u.mod(BigInteger.valueOf(2)).compareTo(BigInteger.ZERO)==0){
	        vec[j]=BigInteger.valueOf(2);
	      }
	      else{
	        if(miller_rabin(u)){
	        	found=false;
	          	break;
	        }
	        else{
	        	lastTime=System.currentTimeMillis();
	        	BigInteger ret=BigInteger.ZERO;
	        	try{
	        	  ret=rhoFactor(u,BigInteger.ONE);
	        	}
	        	catch(Exception e){
	        		found=false;
	          		break;
	        	}
	        	vec[j]=ret;
	        }
	      }
	    }
	    if(!found) continue;
	    count++;
	    System.out.print(s+" ");
	    for(int j=2;j<=10;j++) System.out.print(vec[j]+" ");
	    System.out.println();
	    if(count==500) break;
	  } 
	}

	public static BigInteger isPrime(BigInteger p){
		if(p.compareTo(BigInteger.valueOf(2))==-1) return BigInteger.ZERO;
		for (BigInteger i = BigInteger.valueOf(2);i.multiply(i).compareTo(p)<=0;i = i.add(BigInteger.ONE)) {
        	if(p.mod(i).compareTo(BigInteger.ZERO)==0) return i;
    	}
    	return BigInteger.ZERO;
	}

	private static boolean miller_rabin_pass(BigInteger a, BigInteger n) {
	    BigInteger n_minus_one = n.subtract(BigInteger.ONE);
	    BigInteger d = n_minus_one;
		int s = d.getLowestSetBit();
		d = d.shiftRight(s);
	    BigInteger a_to_power = a.modPow(d, n);
	    if (a_to_power.equals(BigInteger.ONE)) return true;
	    for (int i = 0; i < s-1; i++) {
	        if (a_to_power.equals(n_minus_one)) return true;
	        a_to_power = a_to_power.multiply(a_to_power).mod(n);
	    }
	    if (a_to_power.equals(n_minus_one)) return true;
	    return false;
	}

	public static boolean miller_rabin(BigInteger n) {
	    for (int repeat = 0; repeat < 20; repeat++) {
	        BigInteger a;
	        do {
	            a = new BigInteger(n.bitLength(), rnd);
	        } while (a.equals(BigInteger.ZERO));
	        if (!miller_rabin_pass(a, n)) {
	            return false;
	        }
	    }
	    return true;
	}

	private static BigInteger rhoFactor(BigInteger n, BigInteger c) throws Exception{
		long currentTime=System.currentTimeMillis();
		if((currentTime-lastTime)>=1000) throw new Exception();
		BigInteger t = BigInteger.valueOf(2);
		BigInteger h = BigInteger.valueOf(2);
		BigInteger d = BigInteger.ONE;
		while (d.equals(BigInteger.ONE)){
			t = t.multiply(t).add(c).mod(n);
			h = h.multiply(h).add(c).mod(n);
			h = h.multiply(h).add(c).mod(n);
			d = t.subtract(h).gcd(n);
		}
		if (d.equals(n)) /* cycle */{
			return rhoFactor(n, c.add(BigInteger.ONE));
		}
		else {
			return d;
		}
	}
}


	

