import java.util.Scanner;


public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(System.in);
		int t = cin.nextInt();
		int k = 0;
		while(t>0){
			t--;
			k++;
			int a = cin.nextInt();
			int b = cin.nextInt();
			double []p = new double[a+1];
			double []q = new double[a+1];
			double []r = new double[a+1];
			for(int i = 0 ; i < a ; i++){
				p[i] = cin.nextDouble();
				if(i>0)q[i] = p[i]*q[i-1];else q[i] = p[i];
				if(i>0)r[i] = q[i-1]*(1-p[i])+r[i-1]; else r[i] = 1-p[i];
			}			
			double ans = 2+b;
			for(int i = 0 ; i < a ; i++){
				double tans = q[i]*(1+b-a+2*(a-i-1))+r[i]*(1+b-a+2*(a-i-1)+b+1);
//				System.out.println(i+" "+q[i]+" "+(1+b-a+2*(a-i-1)));
//				System.out.println(r[i]+" "+(1+b-a+2*(a-i-1)+b+1));
				if(tans<ans) ans = tans;
			}
			System.out.printf("Case #%d: %.6f\n",k,ans);
		}
	}

}
