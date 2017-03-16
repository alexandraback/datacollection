import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class B {
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tc = 0; tc < T; tc++){
			final int tc_index = tc + 1;
			
			final double C = sc.nextDouble();
			final double F = sc.nextDouble();
			final double X = sc.nextDouble();
			
			double time = 0;
			double current_c = 2;
			
			while(true){
				final double buy_F = C / current_c;
				final double buy_F_then_buy_X = buy_F + X / (current_c + F);
				
				final double buy_X = X / current_c;
				
				if(buy_F_then_buy_X < buy_X){
					current_c += F;
					time += buy_F;
				}else{
					time += buy_X;
					break;
				}
				
			}
			
			
			System.out.printf("Case #%d: %.7f\n", tc_index, time);
		}
	}
	
}
