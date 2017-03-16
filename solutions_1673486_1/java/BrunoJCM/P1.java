import java.text.DecimalFormat;
import java.util.Scanner;


public class P1 {
	
	public static void main(String[] args) {
		
		DecimalFormat df = new DecimalFormat("#.000000");
		
		Scanner s = new Scanner(P1.class.getResourceAsStream("A-large.in"));
		
		double[] p = new double[100000];
		
		int nt = s.nextInt();
		s.nextLine();
		
		int teste = 1;
		while (nt-- > 0) {
			
			int d = s.nextInt();
			int n = s.nextInt();
			
			for (int i = 0; i < d; i++) {
				p[i] = s.nextDouble();
			}
			
			double resp = n +2;
			
			for (int nDeletados=0; nDeletados <= d; nDeletados++) {

				double pp = 1;
				for (int i = 0; i < d - nDeletados; i++) {
					pp *= p[i];
				}
				
				double pcert = pp * (n-d+1+nDeletados*2);
				//System.out.print(pcert);
				//System.out.print("+");
				double perra = (1-pp) * (n-d+1+nDeletados*2 + n + 1);
				//System.out.print(perra);
				double dele = pcert + perra;
				//System.out.println("=" + dele);
				
				if (dele < resp) resp = dele;
			}
			
			
			System.out.println("Case #" + teste + ": " + df.format(resp));
			
			teste++;
		}
		
	}

}
