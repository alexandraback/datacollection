package be.filip.gcj2016;

public class CountingResult {

	private final boolean success;
	private final long largestNumber;
	
	private CountingResult(boolean success, long largestNumber) {
		super();
		this.success = success;
		this.largestNumber = largestNumber;
	}
	
	public static CountingResult createSuccesful(long largestNumber)
	{
		return new CountingResult(true, largestNumber);
	}
	
	public static CountingResult createFailed(long largestNumber)
	{
		return new CountingResult(false, largestNumber);
	}
	
	public boolean isSuccesfull()
	{
		return success;
	}
	
	public long getLargestNumber()
	{
		return largestNumber;
	}
	
	
}
