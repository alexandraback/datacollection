import java.util.*;

public class TopicSmall
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int caseNum = 1; caseNum <= t; ++caseNum)
		{
			int numTopics = in.nextInt();
			String[][] topics = new String[numTopics][2];
			for (int i = 0; i < numTopics; ++i)
			{
				topics[i][0] = in.next();
				topics[i][1] = in.next();
			}
			
			// try to determine least number of real people
			int least = numTopics;
			for (int bitMask = 1; bitMask < (1 << numTopics); ++bitMask)
			{
				// suppose bits in bitmask are real people.  is this a valid scenario?
				HashSet<String> firstTopic = new HashSet<String>(numTopics * 10);
				HashSet<String> secondTopic = new HashSet<String>(numTopics * 10);
				int count = 0;
				boolean possible = true;
				for (int i = 0, bit = 1; i < numTopics; ++i, bit <<= 1)
				{
					// real
					if ( (bit & bitMask) != 0)
					{
						firstTopic.add(topics[i][0]);
						secondTopic.add(topics[i][1]);
						++count;
					}
				}
				
				for (int i = 0, bit = 1; i < numTopics; ++i, bit <<= 1)
				{
					// fake
					if ( (bit & bitMask) == 0)
					{
						possible &= firstTopic.contains(topics[i][0]);
						possible &= secondTopic.contains(topics[i][1]);
					}
					
					if (!possible)
						break;
				}
				
				if (possible)
					least = Math.min(least, count);
			}
			
			System.out.printf("Case #%d: %d\n", caseNum, numTopics - least);
		}
	}
}