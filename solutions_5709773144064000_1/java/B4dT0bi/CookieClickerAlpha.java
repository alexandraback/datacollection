import java.io.BufferedReader;
import java.io.FileReader;
import java.text.DecimalFormat;

public class CookieClickerAlpha
{

	public static void main(String[] args)
	{
//		 solve(1,30,1,2);
//		 solve(2,30,2,100);
//		 solve(3,30.50000, 3.14159, 1999.19990);
//		 solve(4,500.0, 4.0, 2000.0);
//		 solve(5,5.0, 4.0, 200.0);
//		 solve(6,1.0, 1.0, 100000.0);
//		solve (1, 41,1,1290);
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			int anzTC = Integer.parseInt(br.readLine());
			for (int tc = 0; tc < anzTC; tc++)
			{
				String[] tmp = br.readLine().split(" ");
				solve(tc + 1, Double.parseDouble(tmp[0]), Double.parseDouble(tmp[1]), Double.parseDouble(tmp[2]));
			}
			br.close();
		}
		catch (Exception ex)
		{

		}
	}

	private static final double defaultcookiesPerSecond = 2;
	private static final DecimalFormat DECIMAL_FORMAT = new DecimalFormat("0.0000000");

	private static void solve(int tc, double costOfCookieFarm, double additionalCookiesPerFarm, double target)
	{
		double result = calc(defaultcookiesPerSecond, 0, target / defaultcookiesPerSecond, costOfCookieFarm, additionalCookiesPerFarm, target);
		System.out.println("Case #" + tc + ": " + DECIMAL_FORMAT.format(result).replace(',', '.'));
	}

	// private static double calc( double crrCookiesPerSecond,
	// double crrTime,
	// double lastTime,
	// double costOfCookieFarm,
	// double additionalCookiesPerFarm,
	// double target)
	// {
	// double newCookiesPerSecond = crrCookiesPerSecond +
	// additionalCookiesPerFarm;
	// double newTime = crrTime + (costOfCookieFarm / crrCookiesPerSecond);
	// double newLastTime = newTime + (target / newCookiesPerSecond);
	// if (newLastTime > lastTime) return lastTime;
	// return calc(newCookiesPerSecond, newTime, newLastTime, costOfCookieFarm,
	// additionalCookiesPerFarm, target);
	// }
	private static double calc(	double crrCookiesPerSecond,
								double crrTime,
								double lastTime,
								double costOfCookieFarm,
								double additionalCookiesPerFarm,
								double target)
	{
		double currentTime = crrTime;
		double currentcookiesPerSecond = crrCookiesPerSecond;
		double lastDuration = lastTime;

		boolean targetreached = false;
		while (!targetreached)
		{
			double timeWithCurrentCookies = currentTime + target / currentcookiesPerSecond;
//			int anzCF = (int) (currentcookiesPerSecond / costOfCookieFarm);
//			if (anzCF <= 0) anzCF = 1;
			int anzCF = 1;
			double timeWithNewCookies = currentTime + ((costOfCookieFarm * anzCF) / currentcookiesPerSecond) + target
					/ (currentcookiesPerSecond + (additionalCookiesPerFarm * anzCF));
			if (timeWithCurrentCookies < timeWithNewCookies)
			{
				if (lastDuration < timeWithCurrentCookies)
				{
					return lastDuration;
				}
				return timeWithCurrentCookies;
			}
			else
			{
				if (lastDuration < timeWithNewCookies)
				{
					return lastDuration;
				}
				lastDuration = timeWithNewCookies;
				currentTime += (costOfCookieFarm * anzCF) / currentcookiesPerSecond;
				currentcookiesPerSecond += additionalCookiesPerFarm * anzCF;
			}
		}
		return 0;
	}
}
