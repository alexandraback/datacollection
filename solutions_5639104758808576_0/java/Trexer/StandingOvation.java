package standingOvation;

public class StandingOvation
{

	public static void main(String[] args)
	{
		String[][] data = loader.Loader.load(1, "B:/Users/Sam/Documents/CodeJam/Qualification/StandingOvation/A-small-attempt1.in");
		for(int i=0; i<data.length; i++)
		{
			System.out.println("Case #" + (i+1) + ": " + friendsNeeded(data[i]));
		}
	}
	
	private static int friendsNeeded(String[] data)
	{
		String[] audience = data[1].split("");
		int required = 0, maxRequired = 0;
		for(int i=0; i<audience.length; i++)
		{
			required -= Integer.parseInt(audience[i]);
			required++;
			if (maxRequired<required) maxRequired = required;
		}
		return maxRequired;
	}
	
}