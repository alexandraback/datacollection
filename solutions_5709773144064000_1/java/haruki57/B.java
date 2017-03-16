package temp;

import java.util.Scanner;

public class B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n = sc.nextInt();
		for(int nn = 1;nn<=n;nn++){
			double ans = Double.MAX_VALUE;
			C c = new C();
			c.C=sc.nextDouble();
			c.F=sc.nextDouble();
			c.X=sc.nextDouble();
			for(int i = 0;;i++){
				c.set(i);
//				c.output();
//				System.out.println(c.calc());
				if(ans < c.calc()){
					break;
				}
				ans =c.calc();

				c.fi();
				
			}
			
			System.out.println("Case #"+nn+": "+ans);
		}
	}
/*
	1 500 4 02000
	1 30.50000 3.14159 1999.19990
 */
	static class C{
		double t=0;
		double F=0,X=0,C=0;
		double x=0;
		double katamuki=2;
		double y0=0;
		double calc=0;
		void set(int a){
			katamuki = 2 + a * F;
			y0 = -(x * katamuki);
		}
		double calc(){
			
			return (X - y0) / katamuki;
		}
		void fi(){
			x += C / katamuki;
		}
		void output(){
			System.out.println("y = "+katamuki+"*t" + " - " +y0+" "+x);
		}
	}
}
