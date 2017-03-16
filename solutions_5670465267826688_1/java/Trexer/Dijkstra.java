package dijkstra;

import java.util.Random;

public class Dijkstra
{

	private static final int[][] product =
		{
			{1,2,3,4},
			{2,-1,4,-3},
			{3,-4,-1,2},
			{4,3,-2,-1}
		};
	
	public static void main(String[] args)
	{
		String[][] data = loader.Loader.load(2, "/home/sam/Documents/CodeJam/Qualification/Dijkstra/C-large.in");
/*		String[][] data = new String[200][2];
		Random gen = new Random();
		for(int i=0; i<data.length; i+=2)
		{
			int l = gen.nextInt(10000);
			long x = 10000000000000000L/l;
			data[i][0] = new Integer(l).toString();
			data[i][1] = new Long(x).toString();
			data[i+1][0] = ranGen.Generator.stringGen(l, "ijk");
		}
*/		for(int i=0; i<data.length; i+=2)
		{
			long repetitions = Long.parseLong(data[i][1]);
			boolean ijk = multiply(repetitions, data[i+1][0]);
			System.out.println("Case #" + (i/2+1) + ": " + (ijk ? "YES" : "NO"));
		}
	}
	
	public static boolean multiply(long repetitions, String string)
	{
		int[] stringAsInts = new int[string.length()];
		for(int i=0; i<string.length(); i++)
		{
			switch(string.charAt(i))
			{
				case 'i':
					stringAsInts[i] = 2;
					break;
				case 'j':
					stringAsInts[i] = 3;
					break;
				case 'k':
					stringAsInts[i] = 4;
					break;
				default:
					stringAsInts[i] = 1;
			}
		}
		int currentResult = 1, singleResult = 1;
		boolean iHit = false, jHit = false, kHit = false;
		for(int currentChar : stringAsInts)
		{
			singleResult = ((singleResult > 0) ? 1 : -1) * product[Math.abs(singleResult)-1][currentChar-1];
		}
		int countLimiter = 0;
		while(countLimiter < 4 && repetitions > 0 && !(iHit && jHit && kHit))
		{
			repetitions--;
			countLimiter++;
			for(int currentChar : stringAsInts)
			{
				currentResult = ((currentResult > 0) ? 1 : -1) * product[Math.abs(currentResult)-1][currentChar-1];
				switch(currentResult)
				{
					case 2:
						if(!iHit)
						{
							iHit = true;
							currentResult = 1;
							countLimiter = 0;
						}
						break;
					case 3:
						if(iHit && !jHit)
						{
							jHit = true;
							currentResult = 1;
							countLimiter = 0;
						}
						break;
					case 4:
						if(jHit && !kHit)
						{
							kHit = true;
							currentResult = 1;
							countLimiter = 0;
						}
						break;
					default:
				}
			}
		}
		repetitions = repetitions % 4;
		for(int i=0; i<repetitions; i++)
		{
			currentResult = (((currentResult > 0) == (singleResult > 0)) ? 1 : -1) * product[Math.abs(currentResult)-1][Math.abs(singleResult)-1];
		}
		return iHit && jHit && kHit && currentResult == 1;
	}
	
}