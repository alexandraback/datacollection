package codes;

import java.text.DecimalFormat;
import java.util.ArrayList;

public class CookieClickerAlpha {
	ArrayList<Double> buyingFarmTime;
	ArrayList<Double> buyingFactoryTime;
	
	double natrualIncreament = 2;
	
	double farmCost;
	double farmIncrement;
	double objective;
	
	
	String[][] result;
	
	public String[][] optimalBuyingTime (String[] inputData) {
		farmCost = Double.valueOf(inputData[0]);
		farmIncrement = Double.valueOf(inputData[1]);
		objective = Double.valueOf(inputData[2]);
		
		buyingFarmTime = new ArrayList<Double>();
		
		int farmCount = 0;
		double optimalTimeBuyingFactory = Double.MAX_VALUE;
		double buyingFarmsTime = 0;
		while (true) {
			double increment = natrualIncreament + farmIncrement * farmCount;
			double timeToBuyAFactory = (objective)/ increment + buyingFarmsTime;
			if (timeToBuyAFactory < optimalTimeBuyingFactory) {
				optimalTimeBuyingFactory = timeToBuyAFactory;
			}
			
//			buyingFactoryTime.add(timeToBuyAFactory);
			double previousBuyingFarmTime = 0;
			if (farmCount!=0) {
				 previousBuyingFarmTime = buyingFarmTime.get(farmCount-1);
			}
			
			double timeBuyingANewFarm = previousBuyingFarmTime + farmCost/increment;
			
			if (optimalTimeBuyingFactory < timeBuyingANewFarm) {
				break;
			}
			
			buyingFarmTime.add(timeBuyingANewFarm);
			farmCount++;
			buyingFarmsTime = timeBuyingANewFarm;
		}
		
		
		String str = String.format("%.7f", optimalTimeBuyingFactory).toString();
		result = new String[][]{{str}};
		
		return result;
	}
}
