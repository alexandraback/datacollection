import java.util.Scanner;


public class B {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for(int kases=1;kases<=T;kases++) {
	
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();
			double r = 2.0;
			double min = X/r;
			double t=0;
			int acc=0;
			while(true) {
				
				t+=C/r;
				r+=F;
				double attempt = t+(X/r);
				if(attempt>min)
					break;
				min=attempt;
				acc++;
			}
			System.out.print("Case #"+kases+": ");
			System.out.printf("%.7f\n",min);
			//System.err.println(acc+": "+r);
			/*
			frac C = new frac(in.next());
			frac F = new frac(in.next());
			frac X = new frac(in.next());
			frac r = new frac(2,1);
			frac min = X.div(r);
			frac t=new frac(0,1);
			int acc=0;
			while(true) {
				t=t.add(C.div(r));
				r=r.add(F);
				frac attempt = t.add(X.div(r));
				if(attempt.compareTo(min)>0)
					break;
				min=attempt;
				acc++;
			}
			System.out.print("Case #"+kases+": ");
			System.out.printf("%.7f\n",min.toDouble()); */
		}
	}
}



/*
double C = in.nextDouble();
double F = in.nextDouble();
double X = in.nextDouble();
double r = 2.0;
double min = X/r;
double t=0;
int acc=0;
while(true) {
	
	t+=C/r;
	r+=F;
	double attempt = t+(X/r);
	if(attempt>min)
		break;
	min=attempt;
	acc++;
}
System.out.print("Case #"+kases+": ");
System.out.printf("%.7f\n",min);
System.err.println(acc+": "+r);

Case #1: 0.6305771
*/