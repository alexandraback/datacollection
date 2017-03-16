import java.util.*;

public class Password {
	
	
	public static double solvei(int i, int a, int b, double[] p){
		double probok = 1.0;
		for(int j = 0; j<(a-i); j++){
			probok*=p[j];
		}
		int total = b-a+(2*i)+1;
		double ok = probok*total;
		ok+=(1-probok)*(total+b+1);
		return ok;
	}
	
	public static double solve(int a, int b, double[] p){
		int ra = b+2;
		int cont = a+b+1;
		int min = (ra<cont)? ra: cont;
		double mind = (double)min;
		double probok = 1; 
		for(int i = 0; i<a; i++){
			probok*=p[i];
		}
		double ok = (b-a+1)*probok;
		double notok = (b+b-a+2)*(1-probok);
		
		double total  =ok+notok;
		double res = (mind<total)? mind : total;
		
		for(int i= 1; i<a; i++){
			double resi = solvei(i, a,b, p);
			if(resi < res)
				res = resi;
		}
		return res;
	} 
	
	public static void main(String args[]){
	
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		
		for(int i = 1; i<=T; i++){
			int a = s.nextInt();
			int b = s.nextInt();
			double p[] = new double[a];
			for(int j  =0;j<a; j++){
				p[j] = s.nextDouble();
			}
			double res = solve(a, b, p);
			System.out.println("Case #"+i+": "+res);
		}

	}
}