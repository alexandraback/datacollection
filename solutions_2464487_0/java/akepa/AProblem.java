import java.math.BigInteger;
import java.util.Scanner;


public class AProblem {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int testCases = sc.nextInt();

		for (int tcase = 1; tcase <= testCases; tcase++) {
			
			BigInteger r = sc.nextBigInteger(); // radio inicila
			BigInteger t = sc.nextBigInteger(); // milimetros iniciales
			BigInteger qcb = BigInteger.ZERO;
			BigInteger qca = BigInteger.ZERO;
			
			BigInteger cb = r.multiply(r);
			r = r.add(BigInteger.ONE);
			qcb = r.multiply(r);
			BigInteger cn = qcb.subtract(cb);
			
			int ncirculos = 0;
			
			while(t.compareTo(cn) >= 0){
				t = t.subtract(cn);//t - cn;
				r = r.add(BigInteger.ONE);
				qca = r.multiply(r);
				//System.out.println(qca);
				cb = qca.subtract(qcb);
				r = r.add(BigInteger.ONE);
				qcb = r.multiply(r);
				//System.out.println(qcb);
				cn = qcb.subtract(qca);
				ncirculos++;
			}
			
			System.out.println("Case #" + tcase + ": " + ncirculos);
		}

	}

}
