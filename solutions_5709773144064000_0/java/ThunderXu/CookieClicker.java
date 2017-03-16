import java.util.Scanner;


public class CookieClicker {

	public void solve()
	{
		Scanner sc = new Scanner(System.in);
		int numTest = sc.nextInt();
		for(int i=0;i<numTest;i++)
		{
			double totalTime = 0;
			double curSpeed = 2;
			double C = sc.nextDouble();
			double F = sc.nextDouble();
			double X = sc.nextDouble();
			while(X/curSpeed>(C/curSpeed+X/(curSpeed+F)))
			{
				totalTime += C/curSpeed;
				curSpeed+=F;
			}
			totalTime += X/curSpeed;
			System.out.printf("Case #%d: %f\n", i+1, totalTime);
		}
		sc.close();
	}
}
