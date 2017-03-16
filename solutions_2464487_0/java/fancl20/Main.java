import java.util.*; 
import java.io.*; 
import java.math.*; 
 public class Main { 
     public static void main(String args[]) { 
    	 Scanner in = new Scanner(new BufferedInputStream(System.in));
    	 int ca = in.nextInt();
    	 for(int i = 0;i<ca;++i) {
    		 BigInteger rad = in.nextBigInteger();
    		 BigInteger t = in.nextBigInteger();
    		 BigInteger l = BigInteger.ZERO;
    		 BigInteger r = t;
    		 while(l.compareTo(r)!=0) {
    			 BigInteger m = l.add(r).divide(BigInteger.valueOf(2));
    			 BigInteger tmp1 = rad.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE).multiply(m); 
    			 BigInteger tmp2 = m.subtract(BigInteger.ONE).multiply(m).multiply(BigInteger.valueOf(2));
    			 if(tmp1.add(tmp2).compareTo(t)==-1) l = m.add(BigInteger.ONE);
    			 else r = m;
    		 }
    		 BigInteger tmp1 = rad.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE).multiply(l); 
    		 BigInteger tmp2 = l.subtract(BigInteger.ONE).multiply(l).multiply(BigInteger.valueOf(2));
    		 if(tmp1.add(tmp2).compareTo(t)==1) l = l.subtract(BigInteger.ONE);
    		 System.out.println("Case #"+(i+1)+": "+l.toString());
    	 }
     } 
 }