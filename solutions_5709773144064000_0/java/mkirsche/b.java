import java.util.*;
public class b {
public static void main(String[] args)
{
	Scanner input = new Scanner(System.in);
	int T = input.nextInt();
	for(int t = 0; t<T; t++)
	{
		System.out.printf("Case #%d: ", t+1);
		double c = input.nextDouble(), f = input.nextDouble(), x = input.nextDouble();
		double res = 1e18;
		for(int iter = 0; iter <= 20001; iter++) res = Math.min(res, time(c, f, x, iter));
		System.out.println(res);
	}
}
static double time(double c, double f, double x, int purchase)
{
	if(purchase < 0) return -1e18;
	double cps = 2;
	if(x < c) return x/2;
	double res = 0;
	for(int i = 0; i<purchase; i++)
	{
		res += c/cps;
		cps += f;
	}
	return res + x/cps;
}
}
