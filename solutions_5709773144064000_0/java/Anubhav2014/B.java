package qualification2014;

import java.text.DecimalFormat;
import java.util.Scanner;

public class B {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		double C,F,X;
		for (int i = 1; i <=T ; i++) {
			C = Double.parseDouble(sc.next());
			F = Double.parseDouble(sc.next());
			X = Double.parseDouble(sc.next());

			int maxFarmBuld =(int) (X/C);
			double cookiesRequired = X;
			double minTime = 11000000;
			double timeFarm =0;
			/*timeFarm+=(X)/2;
			minTime = Math.min(minTime, timeFarm);
			*///double timeNoFarm = X/rate;
			for (int n = 0; n <= maxFarmBuld; n++) {
				 timeFarm =0;
				double rate = 2;
				
				for (int j = 0; j <=n ; j++) {
					if(j!=0)
						{
						timeFarm += C/rate;
						rate +=F;
						if(j==n)
							timeFarm+=(X/*-(j*C)*/)/rate;
						}
					else
						if(n==0)
						timeFarm+=(X-(j*C))/rate;
					
				}
				
				minTime = Math.min(minTime, timeFarm);
			}
			DecimalFormat df = new DecimalFormat();
		    df.setMinimumFractionDigits(7);
		    df.setMaximumFractionDigits(7);
			System.out.println("Case #"+i+": "+df.format(Math.round(minTime*10000000)/10000000D));
			
				
			
			
		}
		

	}

}
