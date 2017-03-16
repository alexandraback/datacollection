package standingOvation;

public class StandingOvation
{

	public static void main(String[] args)
	{
		//String[][] data = loader.Loader.load(1, "B:/Users/Sam/Documents/CodeJam/Qualification/StandingOvation/A-small-attempt1.in");
		String[][] data = loader.Loader.load(1, "/home/sam/Documents/CodeJam/Qualification/StandingOvation/A-large.in");
		/*String[][] data = new String[100][2];
		for(int i=0; i<data.length; i++)
		{
			data[i][0] = "1000";
			data[i][1] = ranGen.Generator.stringGen(1001, "0123456789");
		}
		System.out.println("generated");*/
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