import java.util.*;
public class codejam {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();
		int i;
		for(i=1;i<=t;i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			double[] p=new double[a];
			int j;
			for(j=0;j<a;j++) {
				p[j]=sc.nextDouble();
			}
			
			double ans=b+2;
			int k;
			for(j=0;j<a;j++) {
				double ok=1.0;
				for(k=0;k<a-j;k++) {
					ok*=p[k];
				}
				double temp=2*j+b-a+1+(b+1)*(1-ok);
				if(temp<ans) {
					ans=temp;
				}
			}
			
			System.out.println("Case #"+i+": "+ans);
		}
		
		
	}

}
