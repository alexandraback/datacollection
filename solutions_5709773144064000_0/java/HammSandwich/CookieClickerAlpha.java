import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.RoundingMode;


public class CookieClickerAlpha {
	//an attempt in Java because I need an external view of my code from before or I'll never see the problem with it
	
	private static final String BASE = "B-small-attempt3";
	private static final String IN_FILE = "C:\\Users\\Peter\\Downloads\\" + BASE + ".in";
	private static final String OUT_FILE = "C:\\Users\\Peter\\Desktop\\" + BASE + "java.out";
	
	public static void main(String[] args){
		File in = new File(IN_FILE);
		BufferedReader f;
		
		File out = new File(OUT_FILE);

		try {
			f = new BufferedReader(new FileReader(in));
			if (!out.exists()) {
				out.createNewFile();
			}
			FileWriter fw = new FileWriter(out.getAbsoluteFile());
			BufferedWriter o = new BufferedWriter(fw);

		
			int n = Integer.parseInt(f.readLine());
			for(int i = 0 ; i < n ; i++){
				output(i+1, process(f.readLine()), o);
			}
			o.flush();
			o.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 

	}

	private static void output(int c, String result, BufferedWriter o) throws IOException {
		System.out.println("Case #" + c + ": " + result);
		o.write("Case #" + c + ": " + result + "\n");
	}

	private static String process(String string) {
		String[] cfx = string.split(" ");
		
		BigDecimal farmCost = new BigDecimal(cfx[0]);
		BigDecimal farmProduction = new BigDecimal(cfx[1]);
		BigDecimal goal = new BigDecimal(cfx[2]);
		BigDecimal numFarmsBought = new BigDecimal(0);

		BigDecimal bestTimeSoFar = secondsUntil(goal, farmProduction, numFarmsBought);//slowest time with zero farms
		BigDecimal secondsSpentOnFarms = new BigDecimal(0);
		while(bestTimeSoFar.compareTo(totalTimeWithOneMoreFarm(farmCost, goal, farmProduction, numFarmsBought, secondsSpentOnFarms)) > 0){
			bestTimeSoFar = totalTimeWithOneMoreFarm(farmCost, goal, farmProduction, numFarmsBought, secondsSpentOnFarms);
			secondsSpentOnFarms = secondsSpentOnFarms.add(secondsUntil(farmCost, farmProduction, numFarmsBought));
			numFarmsBought = numFarmsBought.add(increment);
			//loop exits when one more farm will cost more time than just running until we hit our goal
		}
		return bestTimeSoFar.setScale(7, RoundingMode.HALF_UP).toPlainString();
		
	}
		
	private static BigDecimal totalTimeWithOneMoreFarm(BigDecimal farmCost, BigDecimal goal,
			BigDecimal farmProduction, BigDecimal numFarmsBought, BigDecimal secondsSpentOnFarms) {
		return secondsSpentOnFarms.add(//time we've already spent on farms
				secondsUntil(farmCost, farmProduction, numFarmsBought)).add( //time we will spend on the next farm
				secondsUntil(goal, farmProduction, numFarmsBought.add(increment))); //time we will spend on the goal with that next farm
	}

	private static BigDecimal secondsUntil(BigDecimal goal, BigDecimal farmProduction, BigDecimal numFarms){
		return goal.divide( productionRate(farmProduction, numFarms), 50, RoundingMode.HALF_UP );
	}
	private static BigDecimal increment = new BigDecimal(1);
	private static BigDecimal baseRate = new BigDecimal(2);
	private static BigDecimal productionRate(BigDecimal farmProduction, BigDecimal numFarms){
		return (farmProduction.multiply( numFarms).add(baseRate));
	}
}
