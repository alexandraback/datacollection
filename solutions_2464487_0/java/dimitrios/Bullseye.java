import java.math.*;

class Bullseye {

	public static void main(String[] args) {
		java.util.Scanner sc = new java.util.Scanner(System.in);
		int T = sc.nextInt();
		BigInteger ONE = new BigInteger("1");
		BigInteger TWO = new BigInteger("2");
		BigInteger THREE = new BigInteger("3");
		BigInteger FOUR = new BigInteger("4");
		BigInteger EIGHT = new BigInteger("8");
		for(int t=1; t<=T; t++) {
			BigInteger R = sc.nextBigInteger().multiply(TWO).subtract(ONE),		// 2R+1
				p = sc.nextBigInteger(),
				D = bigSqrt(R.pow(2).add(p.multiply(EIGHT))),
				n = R.negate().add(D.add(ONE)).divide(FOUR);
			/*System.out.println(R);
			System.out.println(R.pow(2).add(p.multiply(EIGHT)));
			System.out.println(D);
			System.out.println(n);*/
			while(n.multiply(n.multiply(TWO).add(R)).compareTo(p) > 0) {
				//System.out.println(n+": "+n.multiply(n.multiply(TWO).add(R)));
				n = n.subtract(ONE);
			}
			System.out.printf("Case #%d: %s\n", t, n.toString());
		}
	}

	private static BigInteger bigSqrt(BigInteger i) {
		int firsttime = 0;
        BigDecimal myNumber = new BigDecimal(i);
        BigDecimal g = new BigDecimal("1");
        BigDecimal my2 = new BigDecimal("2");
        BigDecimal epsilon = new BigDecimal("0.0000000001");

        BigDecimal nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);
       
        //Get the value of n/g
        BigDecimal nBygPlusg = nByg.add(g);
       
        //Get the value of "n/g + g
        BigDecimal nBygPlusgHalf =  nBygPlusg.divide(my2, 9, BigDecimal.ROUND_FLOOR);
       
        //Get the value of (n/g + g)/2
        BigDecimal  saveg = nBygPlusgHalf;
        firsttime = 99;
       
        do
        {
                g = nBygPlusgHalf;
                nByg = myNumber.divide(g, 9, BigDecimal.ROUND_FLOOR);
                nBygPlusg = nByg.add(g);
                nBygPlusgHalf =  nBygPlusg.divide(my2, 9, BigDecimal.ROUND_FLOOR);
                BigDecimal  savegdiff  = saveg.subtract(nBygPlusgHalf);
                   
                if (savegdiff.compareTo(epsilon) == -1 )
                {
                    firsttime = 0;
                }
                else
                {
                    saveg = nBygPlusgHalf;
                }
               
        } while (firsttime > 1);
        return saveg.toBigInteger();
	}

}