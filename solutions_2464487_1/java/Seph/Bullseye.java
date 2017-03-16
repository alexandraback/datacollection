import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.math.BigDecimal;
import java.math.BigInteger;;

public class Bullseye {
	public static void main(String args[]) throws Exception {
		File file = new File("C:\\Users\\Seph\\Dropbox\\Google Code Jam\\input.txt");
		File out = new File("C:\\Users\\Seph\\Dropbox\\Google Code Jam\\out.txt");
		
		Scanner s = new Scanner(System.in);
		try {
			s = new Scanner(file);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		String output = "";
		
		int numCases = s.nextInt();
		for(int i=1; i<=numCases; i++) {
			long centerRadius = s.nextLong();
			long paintAmount = s.nextLong();
			
			output += "Case #"+i+": " + GetMaxRings2(centerRadius, paintAmount);
			
			if(i!=numCases)
				output+="\n";
		}
		
		FileWriter fw;
		try {
			fw = new FileWriter(out);
			fw.write(output);
			fw.close();
		} catch (IOException e) {
			e.printStackTrace();
		}		
	}
	
	
	public static long GetMaxRings2(long centerRadius, long paintAvailable) throws Exception {
		long initalRequirement = new BigInteger((centerRadius + 1)+"").pow(2).subtract(new BigInteger(centerRadius+"").pow(2)).longValue();
				
		long lowerBound = 1;
		long upperBound = paintAvailable/initalRequirement;
		
		while(upperBound>=lowerBound)
		{
			long midPoint = ((lowerBound+upperBound)/2);
			BigInteger paintRequired = GetPaintRequired(initalRequirement, midPoint);
			BigInteger nextPaintRequired = GetPaintRequired(initalRequirement, midPoint+1);
			
			int comparePaintRequired = paintRequired.compareTo(new BigInteger(paintAvailable+""));
			int compareNextPaintRequired = nextPaintRequired.compareTo(new BigInteger(paintAvailable+""));
			
			
			if((comparePaintRequired==-1 || comparePaintRequired==0) && (compareNextPaintRequired == 1))
				return midPoint;
			else if (comparePaintRequired == -1)
				lowerBound = midPoint + 1;
			else
				upperBound = midPoint -1;
		}
		
		throw new Exception("NOT FOUND!!");
		
	}
	
	/*
	 * 		if(paintRequired<=paintAvailable && nextPaintRequired > paintAvailable)
				return midPoint;
			else if (paintRequired<paintAvailable)
				lowerBound = midPoint + 1;
			else
				upperBound = midPoint -1;
	 */
	
	public static BigInteger GetPaintRequired(long initalRequirement, long numRings) {
		BigInteger initalRequirementBig = new BigInteger(initalRequirement+"");
		BigInteger numRingsBig = new BigInteger(numRings+"");
		
		BigInteger lastRing = initalRequirementBig.add((numRingsBig.subtract(new BigInteger(1+""))).multiply(new BigInteger(4+"")));
		BigInteger numTerms = ((lastRing.subtract(initalRequirementBig)).divide(new BigInteger(4+""))).add(new BigInteger(1+""));
		
		return ((initalRequirementBig.add(lastRing)).multiply(numTerms)).divide(new BigInteger(2+""));
		
	}
	/*
	public static BigInteger GetPaintRequired(long initalRequirement, long numRings) {
		BigInteger initalRequirementBig = new BigInteger(initalRequirement+"");
		BigInteger numRingsBig = new BigInteger(numRings+"");
		
		BigInteger lastRing = initalRequirementBig.add((numRingsBig.subtract(new BigInteger(1))).multiply(new BigInteger(4)));
		BigInteger numTerms = ((lastRing.subtract(val)initalRequirement)/4) + 1;
		
		return ((initalRequirement + lastRing) * numTerms)/2;
		
	}*/
	
	
	public static int GetMaxRings(long centerRadius, long paintRemaining)
	{
		int rings = 0;
		BigDecimal centerRadiusBigD = new BigDecimal(centerRadius);
		BigDecimal paintRemainingBigD = new BigDecimal(paintRemaining);
		
		BigDecimal ringOuterRadius = centerRadiusBigD.add(new BigDecimal(1));
		
		while(true)
		{
			BigDecimal paintRequired = GetRingArea(ringOuterRadius);
			if(paintRequired.compareTo(paintRemainingBigD)==-1 || paintRequired.compareTo(paintRemainingBigD)==0) {
				rings++;
				paintRemainingBigD = paintRemainingBigD.subtract(paintRequired);
			}
			else
			{
				break;
			}
			ringOuterRadius = ringOuterRadius.add(new BigDecimal(2));
		}
		
		return rings;
		
	}
	
	public static BigDecimal GetRingArea(BigDecimal outerRadius){
		BigDecimal outerCircleArea = (outerRadius.pow(2));
		BigDecimal innerCircleArea = (outerRadius.subtract(new BigDecimal(1))).pow(2);
		
		return (outerCircleArea.subtract(innerCircleArea));
	}
	
	public static BigDecimal GetPaintRequired(BigDecimal outerRadius) {
		BigDecimal ringArea = GetRingArea(outerRadius);
		
		return ringArea;
	}

}
