import java.util.*;

public class Round1AA {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		sc.useLocale(Locale.US);
		
		int z = sc.nextInt();
		
		for(int i=0; i<z; i++){
			int a = sc.nextInt();
			int b = sc.nextInt();
			
			double[] p = new double[a+1];
			
			p[0] = 1.0;
			
			for(int j=1; j<=a; j++){
				p[j] = p[j-1]*sc.nextDouble();
			}
			
			double min = b+2;
			
			for(int j=0; j<=a; j++){
				double test = (b-a+1+2*j)*p[a-j] + (2*(b+j+1)-a)*(1.0-p[a-j]);
				
				if(test < min){
					min = test;
				}
			}
			
			System.out.printf("Case #%d: %.6f\n", (i+1), min);
		}
	}
}
