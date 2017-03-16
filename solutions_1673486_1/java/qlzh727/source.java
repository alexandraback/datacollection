import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class PasswordProblem {

	public double solve(int a, int b, String pob){
		double re = 0.0;
		String[] split = pob.split("\\s");
		double[] pb = new double[a];
		for(int i =0; i < pb.length; i++){
			pb[i] = Double.parseDouble(split[i]);
		}
		
		double[] fib = new double[a];
		fib[0] = pb[0];
		for(int i = 1; i < a; i++)
			fib[i] = fib[i-1] * pb[i];
		
		//c1
//		double p1 = 1.0;
//		for(int i = 0; i < a; i++)
//			p1 *= pb[i];
		double p1 = fib[a-1];
		re = p1*(b-a +1) + (1.0 - p1)*(2*b -a +2);
		
		//c2
		for(int i = 1; i < a; i++){
//			double p2 = 1.0;
//			for(int j = 0; j < a-i; j++)
//				p2 *= pb[j];
			double p2 = fib[a-i-1];
			double exp = p2*(i+b-a+i+1) +(1.0 - p2) * (i+b-a+i+1+b+1);
			re = Math.min(re, exp);
		}
		
		//c3
		re = Math.min(b+2, re);
		
		return re;
		
	}
	
	
	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		
		PasswordProblem p = new PasswordProblem();
		
		File f = new File(args[0]);
		Scanner sc = new Scanner(f);
		int l = Integer.parseInt(sc.nextLine());
		for(int i = 1; i <= l ;i++){
			String[] line = sc.nextLine().split(" ");
			int a = Integer.parseInt(line[0]);
			int b = Integer.parseInt(line[1]);
			String pob = sc.nextLine();
			System.out.printf("Case #%d: %f\n", i, p.solve(a, b, pob));
		}
		
		
//		System.out.println(p.solve(2, 5, "0.6 0.6"));
//
//		System.out.println(p.solve(1, 20, "1"));
//		
//		System.out.println(p.solve(3, 4, "1 0.9 0.1"));
	}

}
