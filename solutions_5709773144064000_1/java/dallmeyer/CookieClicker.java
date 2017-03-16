import java.util.Scanner;


public class CookieClicker {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		int T = in.nextInt();
		for (int t = 1; t <= T; t++)
		{
			runMe(in, t);
		}
	}
	
	private static void runMe(Scanner in, int t)
	{
		double 	C = in.nextDouble(),
				F = in.nextDouble(),
				X = in.nextDouble();
		
		double rate = 2.0;
		double time1 = 0;
		double first = X / rate;
		double time2 = C / rate;
		double next = time2 + X / (rate + F);
		
		while (next <= first)
		{
			time1 = time2;
			first = next;
			rate += F;
			time2 += C / rate;
			next = time2 + X / (rate + F);
		}
		
		time1 += X / rate;
		System.out.println("Case #" + t + ": " + time1);
	}

}
