import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.StringReader;
import java.util.HashSet;
import java.util.Set;


public class Kingdom {

	
	public static void main(String [] args) throws NumberFormatException, IOException
	{

		//BufferedReader in = new BufferedReader(new FileReader("src/kingdom.input"));
		BufferedReader in = new BufferedReader(new StringReader(args[0]));
		int rows = Integer.parseInt(in.readLine());
		for ( int i = 1; i <= rows; i++)
		{
			String line = in.readLine();
			String[] vals = line.split(" ");
			int levelCount = Integer.parseInt(vals[0]);
			int [][] levels = new int[levelCount][2];
			boolean [][] earned = new boolean[levelCount][2];
			
			for ( int j = 0; j < levelCount; j++)
			{
				line = in.readLine();
				vals = line.split(" ");
				levels[j][0]=Integer.parseInt(vals[0]);
				levels[j][1]=Integer.parseInt(vals[1]);
				earned[j][1]=false;
			}
			
			int starCount = 0;
			int levelsCompleted = 0;
			
			while ( starCount < levelCount * 2 )
			{
				boolean levelFound = false;
				for ( int j = 0; j < levelCount; j++ )
				{
					if (earned[j][1]==false && levels[j][1]<=starCount)
					{
						earned[j][1]=true;
						if ( earned[j][0]==true)
						{
							levelsCompleted++;
							starCount++;
							//System.out.println("Turn " + levelsCompleted + ": Earned 1 more star on Level " + j);
						}
						else
						{
							levelsCompleted++;
							earned[j][0]=true;
							starCount+=2;
							//System.out.println("Turn " + levelsCompleted + ": Earned 2 stars on Level " + j);
						}						
						levelFound=true;
						break;
					}
				}
				if ( levelFound )
				{
					continue;
				}
				int highest = 0;
				int index = 0;
				for ( int j = 0; j < levelCount; j++ )
				{
					if (earned[j][0]==false && levels[j][0]<=starCount && levels[j][1]>=highest)
					{
						index=j;
						highest=levels[j][1];
						levelFound=true;
					}
				}
				if ( !levelFound )
				{
					break;
				}
				else
				{
					//System.out.println("Turn " + levelsCompleted + ": Earned 1 star on Level " + index);
					earned[index][0]=true;
					starCount++;						
					levelsCompleted++;
				}
			}
			
			if ( starCount < levelCount * 2 )
			{
				System.out.println("Case #"+i+": " + "Too Bad");
			}
			else
			{
				System.out.println("Case #"+i+": " + levelsCompleted);
			}
			
			
		}
	}
	
	
}
