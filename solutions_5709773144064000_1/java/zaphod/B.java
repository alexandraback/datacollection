import java.io.*;
import java.util.Scanner;

public class B
{

	public static void main(String[] args) throws IOException
	{
		String fileName = "B-large";
		Scanner in = new Scanner(new File(fileName + ".in"));
		PrintWriter out = new PrintWriter(new FileWriter(fileName + ".out"));

		int noOfCases = in.nextInt();
		for (int caseNo = 1; caseNo <= noOfCases; caseNo++)
		{
			double C = in.nextDouble();
			double F = in.nextDouble();
			double X = in.nextDouble();

			double minTime = Double.MAX_VALUE;
			double upperLimit = Math.round(X/C);
		//	int lowerLimit = 0;
			int lowerLimit =Math.max(0, (int) upperLimit - 100000);
			for (int maxBuys = lowerLimit; maxBuys <= upperLimit; maxBuys++)
			{
			
				double rate = 2.0;
				double time = 0;
				for (int buy =0; buy < maxBuys; buy++)
				{
					double timeToBuy = C / rate;
					time += timeToBuy;
					rate += F;
					// System.out.println(timeToBuy);
				}
				// System.out.println(X/rate);
				time += X / rate;

			//	System.out.println(maxBuys + " " + time);
				if (time < minTime)
				{
				//	System.out.println(maxBuys + " " +limit +  " " + time);
					minTime = time;
				}
			}

			System.out.printf("Case #%d: %.7f%n", caseNo, minTime);
			out.printf("Case #%d: %.7f%n", caseNo, minTime);

		}
		in.close();
		out.close();

	}

}
