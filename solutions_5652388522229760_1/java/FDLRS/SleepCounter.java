package be.filip.gcj2016;

public class SleepCounter {

	public static CountingResult startFrom(long startNumber, int maxTries)
	{
		int tryCounter = 0;
		long tempNumber = startNumber;
		
		DigitCollection combinedDC = DigitCollection.createEmpty();
		
		while(tryCounter < maxTries)
		{
			DigitCollection tempDC = DigitCollection.createFromNumber(tempNumber);
			combinedDC = combinedDC.combine(tempDC);
			
			if(combinedDC.isFull())
			{
				return CountingResult.createSuccesful(tempNumber);
			}
			
			try{
				tempNumber = Math.addExact(tempNumber, startNumber);
			}
			catch(ArithmeticException e)
			{
				return CountingResult.createFailed(tempNumber);
			}
			
			tryCounter++;
		}
		
		return CountingResult.createFailed(tempNumber);
	}
	
}
