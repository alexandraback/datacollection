import java.util.*;

class p2
{
	private static final double CLICK_PRODUCTIVITY = 2.0d;
	
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for(int i=0; i<testCases; i++){
			double C = sc.nextDouble();
			double F = sc.nextDouble();
			double X = sc.nextDouble();
			double res = calculateTime(C,F,X);
			System.out.print("Case #"+(i+1)+": ");
			System.out.format("%.7f%n", res);
		}
	}
	
	public static double calculateTime(double C, double F, double X){
		long farms;
		double formula = (X*F-CLICK_PRODUCTIVITY*C-C*F)/(C*F);
		if(formula<0){
			farms = 0;
		}
		else{
			farms = (long)Math.ceil(formula);
		}
		
		double totalTime = (X/(CLICK_PRODUCTIVITY+farms*F));
		for(long i=0; i<farms; i++){
			totalTime+=(C/(CLICK_PRODUCTIVITY+i*F));
		}
		return totalTime;
	}
}
