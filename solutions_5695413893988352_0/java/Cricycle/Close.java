import java.util.*;

public class Close
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int caseNum = 1; caseNum <= t; ++caseNum)
		{
			String coders = in.next();
			String jammers = in.next();
			String[] results = solve(coders, jammers);
			System.out.printf("Case #%d: %s %s\n", caseNum, results[0].substring(0), results[1].substring(0));
		}
	}
	
	public static String[] solve(String coders, String jammers)
	{
		String[][] pairs = new String[3][];
		String[][] temp = new String[3][];
		int CODERWIN = 0;
		int TIE = 1;
		int JAMMERWIN = 2;
		
		int CODERSCORE = 0;
		int JAMMERSCORE = 1;
		
		pairs[TIE] = new String[2];
		Arrays.fill(pairs[TIE], "");
		
		for (int i = 0; i < coders.length(); ++i)
		{
			char coderCharTrue = coders.charAt(i);
			char jammerCharTrue = jammers.charAt(i);
			// this needs to be a loop over all combos?
			for (int coderVal = 0; coderVal <= 9; ++coderVal) {
			for (int jammerVal = 0; jammerVal <= 9; ++jammerVal) {
				char coderChar = (char)('0' + coderVal);
				char jammerChar = (char)('0' + jammerVal);
				
				// check if valid choices
				if (coderChar != coderCharTrue && coderCharTrue != '?') continue;
				if (jammerChar != jammerCharTrue && jammerCharTrue != '?') continue;
				
				if (coderChar > jammerChar)
				{
					// CODERWIN scenario
					if (pairs[TIE] != null)
					{
						String[] prev = temp[CODERWIN];
						temp[CODERWIN] = new String[2];
						temp[CODERWIN][CODERSCORE] = pairs[TIE][CODERSCORE] + coderChar;
						temp[CODERWIN][JAMMERSCORE] = pairs[TIE][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[CODERWIN], CODERSCORE))
						{
							temp[CODERWIN] = prev;
						}
					}
					else if (pairs[CODERWIN] != null)
					{
						String[] prev = temp[CODERWIN];
						temp[CODERWIN] = new String[2];
						temp[CODERWIN][CODERSCORE] = pairs[CODERWIN][CODERSCORE] + coderChar;
						temp[CODERWIN][JAMMERSCORE] = pairs[CODERWIN][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[CODERWIN], CODERSCORE))
						{
							temp[CODERWIN] = prev;
						}
					}
					
					// TIE scenario (there is none in this case)
					
					// JAMMERWIN scenario
					if (pairs[JAMMERWIN] != null)
					{
						String[] prev = temp[JAMMERWIN];
						temp[JAMMERWIN] = new String[2];
						temp[JAMMERWIN][CODERSCORE] = pairs[JAMMERWIN][CODERSCORE] + coderChar;
						temp[JAMMERWIN][JAMMERSCORE] = pairs[JAMMERWIN][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[JAMMERWIN], JAMMERSCORE))
						{
							temp[JAMMERWIN] = prev;
						}
					}
				}
				else if (coderChar == jammerChar)
				{
					// CODERWIN scenario
					if (pairs[CODERWIN] != null)
					{
						String[] prev = temp[CODERWIN];
						temp[CODERWIN] = new String[2];
						temp[CODERWIN][CODERSCORE] = pairs[CODERWIN][CODERSCORE] + coderChar;
						temp[CODERWIN][JAMMERSCORE] = pairs[CODERWIN][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[CODERWIN], CODERSCORE))
						{
							temp[CODERWIN] = prev;
						}
					}
					
					// TIE scenario
					if (pairs[TIE] != null)
					{
						String[] prev = temp[TIE];
						temp[TIE] = new String[2];
						temp[TIE][CODERSCORE] = pairs[TIE][CODERSCORE] + coderChar;
						temp[TIE][JAMMERSCORE] = pairs[TIE][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[TIE], CODERSCORE))
						{
							temp[TIE] = prev;
						}
					}
					
					// JAMMERWIN scenario
					if (pairs[JAMMERWIN] != null)
					{
						String[] prev = temp[JAMMERWIN];
						temp[JAMMERWIN] = new String[2];
						temp[JAMMERWIN][CODERSCORE] = pairs[JAMMERWIN][CODERSCORE] + coderChar;
						temp[JAMMERWIN][JAMMERSCORE] = pairs[JAMMERWIN][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[JAMMERWIN], JAMMERSCORE))
						{
							temp[JAMMERWIN] = prev;
						}
					}
				}
				else // jammerChar > coderChar
				{
					// JAMMERWIN scenario
					if (pairs[TIE] != null)
					{
						String[] prev = temp[JAMMERWIN];
						temp[JAMMERWIN] = new String[2];
						temp[JAMMERWIN][CODERSCORE] = pairs[TIE][CODERSCORE] + coderChar;
						temp[JAMMERWIN][JAMMERSCORE] = pairs[TIE][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[JAMMERWIN], JAMMERSCORE))
						{
							temp[JAMMERWIN] = prev;
						}
					}
					else if (pairs[JAMMERWIN] != null)
					{
						String[] prev = temp[JAMMERWIN];
						temp[JAMMERWIN] = new String[2];
						temp[JAMMERWIN][CODERSCORE] = pairs[JAMMERWIN][CODERSCORE] + coderChar;
						temp[JAMMERWIN][JAMMERSCORE] = pairs[JAMMERWIN][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[JAMMERWIN], JAMMERSCORE))
						{
							temp[JAMMERWIN] = prev;
						}
					}
					
					// TIE scenario (there is none in this case)
					
					// CODERWIN scenario
					if (pairs[CODERWIN] != null)
					{
						String[] prev = temp[CODERWIN];
						temp[CODERWIN] = new String[2];
						temp[CODERWIN][CODERSCORE] = pairs[CODERWIN][CODERSCORE] + coderChar;
						temp[CODERWIN][JAMMERSCORE] = pairs[CODERWIN][JAMMERSCORE] + jammerChar;
						if (!shouldUpdate(prev, temp[CODERWIN], CODERSCORE))
						{
							temp[CODERWIN] = prev;
						}
					}
				}
			}
			}
			
			pairs[CODERWIN] = temp[CODERWIN];
			pairs[TIE] = temp[TIE];
			pairs[JAMMERWIN] = temp[JAMMERWIN];
			/*
			System.out.println(Arrays.toString(pairs[CODERWIN]));
			System.out.println(Arrays.toString(pairs[TIE]));
			System.out.println(Arrays.toString(pairs[JAMMERWIN]));
			System.out.println("-------------------------");
			*/
			temp = new String[3][];
		}
		
		String[] results = new String[2];
		if (pairs[TIE] != null)
		{
			results = pairs[TIE];
		}
		else if (pairs[CODERWIN] == null)
		{
			results = pairs[JAMMERWIN];
		}
		else if (pairs[JAMMERWIN] == null)
		{
			results = pairs[CODERWIN];
		}
		else
		{
			long coderDiff = Long.parseLong(pairs[CODERWIN][CODERSCORE]) - Long.parseLong(pairs[CODERWIN][JAMMERSCORE]);
			long jammerDiff = Long.parseLong(pairs[JAMMERWIN][JAMMERSCORE]) - Long.parseLong(pairs[JAMMERWIN][CODERSCORE]);
			if (coderDiff < jammerDiff)
				results = pairs[CODERWIN];
			else if (jammerDiff < coderDiff)
				results = pairs[JAMMERWIN];
			else
			{
				long coderWinScore = Long.parseLong(pairs[CODERWIN][CODERSCORE]);
				long coderLoseScore = Long.parseLong(pairs[JAMMERWIN][CODERSCORE]);
				if (coderWinScore <= coderLoseScore)
					results = pairs[CODERWIN];
				else if (coderLoseScore < coderWinScore)
					results = pairs[JAMMERWIN];
			}
		}
		
		return results;
	}
	
	public static boolean shouldUpdate(String[] current, String[] next, int windex)
	{
		//System.out.println(Arrays.toString(current));
		//System.out.println(Arrays.toString(next));
		//System.out.printf("Windex=%d\n", windex);
		boolean result = false;
		while (true)
		{
			if (current == null)
			{
				result = true;
				break;
			}
			long curDiff = Long.parseLong(current[windex]) - Long.parseLong(current[1 - windex]);
			long nextDiff = Long.parseLong(next[windex]) - Long.parseLong(next[1 - windex]);
			if (curDiff < nextDiff)
			{
				result = false;
				break;
			}
			if (nextDiff < curDiff)
			{
				result = true;
				break;
			}
			
			long curVal = Long.parseLong(current[0]);
			long nextVal = Long.parseLong(next[0]);
			if (curVal <= nextVal)
			{
				result = false;
				break;
			}
			
			result = true;
			break;
		}
		
		//System.out.printf("Result = %s\n", result);
		return result;
	}
}