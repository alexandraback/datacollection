import java.math.BigInteger;
import java.util.Scanner;


public class C {
	static Scanner scan;
	
	public static void main(String[] args) {
//System.out.println(sqrtCeiling(new BigInteger("11")).toString());
//System.out.println(genNextPalin("2"));
		scan = new Scanner(System.in);
		int testCases = scan.nextInt();
		int n = 0;
		
		while(testCases>0){
			testCases--;
			n++;
			int count = 0;
			
			BigInteger A = new BigInteger(scan.next());
			BigInteger B = new BigInteger(scan.next());
			
			BigInteger start = sqrtCeiling(A);
			BigInteger finish = sqrtFloor(B);
			
			//if start is not palindrome generate next smallest palindrome 
			//continue generating all palindrome until finish
			//count all palindrome that its square is also palindrome
			BigInteger current;
			if(!isPalindrome(start.toString()))
				current = new BigInteger(genNextPalin(start.toString()));	
			else
				current = start.abs();
//int d = 0;
			while(current.compareTo(finish)!=1){
				//d++;
				if(isPalindrome(current.pow(2).toString()))
						count++;
				
				current = new BigInteger(genNextPalin(current.toString()));
				
				//if(d%1000000 == 0)
				//	System.out.println("counting: "+d);
			}
			
			System.out.println("Case #"+n+": "+count);
			

		}
	}
	
	public static String genNextPalin(String base){
		//check if it is 1 digit
		if(base.length()==1){
			if(Integer.parseInt(base)==9)
				return "11";
			else
				return (Integer.parseInt(base)+1)+"";
		}
		boolean check = true;
		//check if it is all 9s
		for(char a: base.toCharArray()){
			if(a!='9')
				check = false;
		}
		if(check){
			String num = "1";
			for(int i=0; i<base.length()-1; i++)
				num+="0";
			num+="1";
			return num;
		}
		
		boolean isBasePalin = isPalindrome(base);
		int mid = base.length()/2;
		if(isBasePalin){
			//if base is palin and it is odd increase mid and return
			if(base.length()%2==1){
				BigInteger leftHalf = new BigInteger(base.substring(0,mid+1));
				String newLeftHalf = leftHalf.add(BigInteger.ONE).toString();
				String newPalin = genPalin2(newLeftHalf.substring(0,mid),newLeftHalf.charAt(mid));
				return newPalin;
			}
			else{
				BigInteger leftHalf = new BigInteger(base.substring(0,mid));
				String newLeftHalf = leftHalf.add(BigInteger.ONE).toString();
				String newPalin = genPalin(newLeftHalf.substring(0,mid));
				return newPalin;
			}
		}
		else{
			if(base.length()%2==1){
				BigInteger leftHalf = new BigInteger(base.substring(0,mid));
				BigInteger rightHalf = new BigInteger(reverse(base.substring(mid+1,base.length())));
				
				//check if leftHalf is greater than right half
				if(leftHalf.compareTo(rightHalf)==1){
					String newPalin = genPalin2(base.substring(0,mid),base.charAt(mid));
					return newPalin;
				}
				else{
					BigInteger leftHalfMid = new BigInteger(base.substring(0,mid+1));
					String newLeftHalfMid = leftHalfMid.add(BigInteger.ONE).toString();
					String newPalin = genPalin2(newLeftHalfMid.substring(0,mid),newLeftHalfMid.charAt(mid));
					return newPalin;
				}
			}
			else{
				BigInteger leftHalf = new BigInteger(base.substring(0,mid));
				BigInteger rightHalf = new BigInteger(reverse(base.substring(mid,base.length())));
				
				//check if leftHalf is greater than right half
				if(leftHalf.compareTo(rightHalf)==1){
					return genPalin(base.substring(0,mid));
				}
				else{
					BigInteger leftHalfMid = new BigInteger(base.substring(0,mid));
					String newLeftHalfMid = leftHalfMid.add(BigInteger.ONE).toString();	
					return genPalin(newLeftHalfMid);
				}
			}
		}
	}
	
	public static String genPalin(String base){
		return base + new StringBuffer(base).reverse().toString();
	}
	public static String genPalin2(String base, char middle){
		return base + middle +new StringBuffer(base).reverse().toString();
	}
	
	public static String reverse(String in){
		return new StringBuffer(in).reverse().toString();
	}
	
	static boolean isPalindrome(String str) {    
	    int n = str.length();
	    for( int i = 0; i < n/2; i++ )
	        if (str.charAt(i) != str.charAt(n-i-1)) 
	        	return false;
	    return true;    
	}
	
	public static BigInteger sqrtFloor(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    return y;
	} // end bigIntSqRootFloor
	
	public static BigInteger sqrtCeiling(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x.equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
	        return x;
	    } // end if
	    BigInteger two = BigInteger.valueOf(2L);
	    BigInteger y;
	    // starting with y = x / 2 avoids magnitude issues with x squared
	    for (y = x.divide(two);
	            y.compareTo(x.divide(y)) > 0;
	            y = ((x.divide(y)).add(y)).divide(two));
	    if (x.compareTo(y.multiply(y)) == 0) {
	        return y;
	    } else {
	        return y.add(BigInteger.ONE);
	    }
	} // end bigIntSqRootCeil


}
