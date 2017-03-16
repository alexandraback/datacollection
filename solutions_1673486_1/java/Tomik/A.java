import java.math.BigDecimal;
import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			int A = sc.nextInt();
			int B = sc.nextInt();
			double[] p = new double[A];
			double pt = 1;
			BigDecimal ptd = BigDecimal.ONE;
			for (int j = 0; j < A; j++) {
				p[j] = sc.nextDouble();
				pt *= p[j];
				ptd = ptd.multiply(BigDecimal.valueOf(p[j]));
			}
			
			double opt = (B-A+1)*pt + (B-A+1+B+1)*(1-pt);
			double ra = B+2;
			opt = Math.min(opt, ra);
			
//			BigDecimal optd = ptd.multiply(BigDecimal.valueOf(B-A+1)).add( (BigDecimal.ONE.subtract(ptd).multiply(BigDecimal.valueOf(B-A+1+B+1))) );
//			int comp = optd.compareTo(BigDecimal.valueOf(B+2));
//			if(comp > 0)
//				optd = BigDecimal.valueOf(B+2);
			
			double pc = 1;
			BigDecimal pcd = BigDecimal.ONE;
			for (int j = 0; j < A; j++) {
				
				double ptmp = pc * (A-j+B+1-j) + (1-pc)*(A-j+B+1-j+B+1);
				opt = Math.min(opt, ptmp);
				pc *= p[j];
				
//				BigDecimal ptmpd = pcd.multiply(BigDecimal.valueOf(A-j+B+1-j)).add( (BigDecimal.ONE.subtract(ptd).multiply(BigDecimal.valueOf(A-j+B+1-j+B+1))) );
//				comp = optd.compareTo(ptmpd);
//				if(comp > 0)
//					optd = ptmpd;
//				pcd = pcd.multiply(BigDecimal.valueOf(p[j]));
			}
			
			System.out.println("Case #" + i + ": " + opt);//optd.toString());
		}
	}

}
