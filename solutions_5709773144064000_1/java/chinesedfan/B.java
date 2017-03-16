import java.text.DecimalFormat;
import java.util.*;

public class B {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.0000000");
		int total = s.nextInt();
		int current = 1;
		while (current <= total) {
			double C = s.nextDouble();
			double F = s.nextDouble();
			double X = s.nextDouble();
			
			double cookie = 0;
			double rate = 2;
			double time = 0;
			while (cookie < X) {
				double wait = (cookie >= C) ? 0 : (C-cookie)/rate;
				double time1 = wait + (X - (cookie+wait*rate-C))/(rate+F);
				double time2 = (X-cookie)/rate;
				if (time1 < time2) {
					// buy a new one
					cookie = (cookie+wait*rate-C);
					rate += F;
					time += wait;
				} else {
					// just wait
					time += time2;
					break;
				}
			}
			
			System.out.println("Case #" + (current++) +": " + df.format(time));
		}
	}
}
