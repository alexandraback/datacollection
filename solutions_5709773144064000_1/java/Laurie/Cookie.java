import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class Cookie {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner (new File("bigc.in"));
		int cases = in.nextInt();
		
		for (int caseNo = 1; caseNo <= cases; caseNo++)
		{
		   System.out.print("Case #" + caseNo + ": ");
		   solve (in);   
		}

	}

	private static void solve(Scanner in) {
		double farmCost = in.nextDouble();
		double farmIncrease = in.nextDouble();
		double goal = in.nextDouble();
		
		double rate = 2.0;
		double totalTime = 0.0;
		
		while (true) {
			double timeToGoal = goal/rate;
			double timeToNextFarm = farmCost/rate;
			
			if (timeToGoal < timeToNextFarm)  {
				totalTime += timeToGoal;
				System.out.println (totalTime);
				return;
			}
			
			double timeWithNewFarm = timeToNextFarm + goal/(rate + farmIncrease);
			
			if (timeToGoal < timeWithNewFarm ) {
				totalTime += timeToGoal;
				System.out.println (totalTime);
				return;
			}
			
			//  Let's buy that new farm
			rate += farmIncrease;
			totalTime += timeToNextFarm;				
		}
	}
}
