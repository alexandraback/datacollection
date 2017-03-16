import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;


public class CJ2016C {
	
	static String convertBase(String num, int b1, int b2){
		return Long.toString(Long.parseLong(num, b1), b2);
	}
	
	public static BigInteger bigIntSqRootFloor(BigInteger x)
	        throws IllegalArgumentException {
	    if (x.compareTo(BigInteger.ZERO) < 0) {
	        throw new IllegalArgumentException("Negative argument.");
	    }
	    // square roots of 0 and 1 are trivial and
	    // y == 0 will cause a divide-by-zero exception
	    if (x .equals(BigInteger.ZERO) || x.equals(BigInteger.ONE)) {
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

	public static void main(String[] args) throws FileNotFoundException {
		Scanner scan = new Scanner(System.in);
		//Scanner scan = new Scanner(new File("CJ2016C.in"));
		int t,n,j,cnt,divs,lastDiv = 1;
		String str;
		BigInteger num,sqrt;
		BigInteger arr[] = new BigInteger[11];
		boolean ok;
		t = scan.nextInt();
		for(int t2 = 1; t2 <= t; t2++){
			System.out.printf("Case #%d:\n",t2);
			n = scan.nextInt();
			j = scan.nextInt();
			cnt = 0;
			str = "";
			for(int i = 0; i < n-2; i++) str += '0';
			//System.out.println(str);
			str = '1' + str + '1';
			//str = "010101";
			while (cnt < j){
				ok = true;
				//System.out.println(str);
				//System.out.println(str);
				for(int b = 2; b <= 10 & ok; b++){
					//System.out.println(b);
					num = new BigInteger(str,b);
					//System.out.println(num);
					//System.out.printf("b:%d num:%d\n",b,num);
					divs = 0;
					sqrt = bigIntSqRootFloor(num);
					sqrt = bigIntSqRootFloor(sqrt);
					if (num.isProbablePrime(1)){
						ok = false;
						break;
					}
					for(BigInteger i = new BigInteger("2"); i.compareTo(sqrt) <= 0; i = i.add(BigInteger.ONE)){
						//System.out.println("i: " + i + " num: " + num);
						if (num.remainder(i).compareTo(BigInteger.ZERO) == 0){ 
							divs++;
							arr[b] = i;
							break;
						}
					}
					if (divs == 0){
						ok = false;
					}
				}
				
				if (ok){
					System.out.print(str);
					for(int i = 2; i <= 10; i++) System.out.printf(" %d",arr[i]);
					System.out.println();
					cnt++;
				}
				
				num = new BigInteger(str,2);
				num = num.add(BigInteger.ONE);
				str = num.toString(2);
				while (str.charAt(str.length()-1) == '0'){
					num = new BigInteger(str,2);
					num = num.add(BigInteger.ONE);
					str = num.toString(2);
				}
				
			}
		}
		

	}

}
