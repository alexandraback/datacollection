import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P2CookieClickerAlpha
{
	private final double baseIncome = 2d;
	private final int id;
	private final double costCookieFarm;
	private final double farmIncome;
	private final double target;

	private double time;
	private double currentCookies;
	private double currentIncome;

	public P2CookieClickerAlpha(int id, double costCookieFarm, double farmIncome, double target)
	{
		this.id = id;
		this.costCookieFarm = costCookieFarm;
		this.farmIncome = farmIncome;
		this.target = target;
	}

	public void solve()
	{
		time = 0d;
		currentCookies = 0d;
		currentIncome = baseIncome;

		if(target <= costCookieFarm)
		{
			time = target / baseIncome;
		}
		else
		{
			while(currentCookies < target)
			{
				double deltaTime = (costCookieFarm - currentCookies) / currentIncome;
				time += deltaTime;
				currentCookies += deltaTime * currentIncome;
				if((target - currentCookies) / currentIncome > (target - (currentCookies - costCookieFarm)) / (currentIncome + farmIncome))
				{
					// buy farm
					currentCookies -= costCookieFarm;
					currentIncome += farmIncome;
				}
				else
				{
					time += (target - currentCookies) / currentIncome;
					currentCookies = target;
				}
			}
		}

		DecimalFormat decimalFormat = new DecimalFormat("0.0000000");
		System.out.println("Case #" + (id + 1) + ": " + decimalFormat.format(time));
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		int numberOfTestCases = in.nextInt();
		List<P2CookieClickerAlpha> problemList = new ArrayList<P2CookieClickerAlpha>();

		for(int i = 0; i < numberOfTestCases; i++)
		{
			double costCookieFarm = in.nextDouble();
			double farmIncome = in.nextDouble();
			double target = in.nextDouble();
			problemList.add(new P2CookieClickerAlpha(i, costCookieFarm, farmIncome, target));
		}

		for(P2CookieClickerAlpha problem : problemList)
		{
			problem.solve();
		}
	}
}
