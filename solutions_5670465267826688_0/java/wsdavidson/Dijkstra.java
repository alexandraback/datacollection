import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;


public class Dijkstra
{
	private static int[][] QUATERNION = new int[][]
			{
		new int[] { 0, 0, 0, 0, 0 },
		new int[] { 0, 1, 2, 3, 4 },
		new int[] { 0, 2, 1, 4, 3 },
		new int[] { 0, 3, 4, 1, 2 },
		new int[] { 0, 4, 3, 2, 1 }
			};
	private static int[][] QUATERNION_PARITY = new int[][]
			{
		new int[] { 0, 0, 0, 0, 0 },
		new int[] { 0, 1, 1, 1, 1 },
		new int[] { 0, 1, -1, 1, -1 },
		new int[] { 0, 1, -1, -1, 1 },
		new int[] { 0, 1, 1, -1, -1 }
			};
	
	private static int[][] REVERSE_QUATERNION = new int[][]
			{
		new int[] { 0, 0, 0, 0, 0 },
		new int[] { 0, 1, 2, 3, 4 },
		new int[] { 0, 2, 1, 4, 3 },
		new int[] { 0, 3, 4, 1, 2 },
		new int[] { 0, 4, 3, 2, 1 }
			};
	private static int[][] REVERSE_QUATERNION_PARITY = new int[][]
			{
		new int[] { 0, 0, 0, 0, 0 },
		new int[] { 0, 1, 1, 1, 1 },
		new int[] { 0, -1, 1, -1, 1 },
		new int[] { 0, -1, 1, 1, -1 },
		new int[] { 0, -1, -1, 1, 1 }
			};
	
	public static void main(String[] args)
	{
		try
		{
			start();
		}
		catch (Exception e)
		{
			e.printStackTrace();
		}
	}
	
	private static void start() throws NumberFormatException, IOException
	{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < testCases; ++i)
		{
			String[] unparsed = reader.readLine().split(" ");
			int patternLength = Integer.parseInt(unparsed[0]);
			int patternCount = Integer.parseInt(unparsed[1]);
			
			String unparsedPattern = reader.readLine();
			
			int[] pattern = parsePattern(unparsedPattern);
			
			//System.out.println("pattern: " + Arrays.toString(pattern));
			
			boolean canDoIt = doTestCase(patternCount, pattern);
			String result = canDoIt ? "YES" : "NO";
			
			System.out.println("Case #" + (i+1) + ": " + result);
		}
	}
	
	private static int[] parsePattern(String unparsedPattern)
	{
		int[] pattern = new int[unparsedPattern.length()];
		for (int j = 0; j < pattern.length; ++j)
		{
			pattern[j] = ((int) unparsedPattern.charAt(j) - ((int) 'g'));
		}
		
		return pattern;
	}
	
	private static boolean doTestCase(int patternCount, int[] pattern)
	{
		if (pattern.length < 2) return false;
		
		if (patternCount > 20)
		{
			patternCount = 20 + (patternCount % 4);
		}
		
		int[] longPattern = new int[pattern.length*patternCount];
		for (int i = 0; i < patternCount; ++i)
		{
			System.arraycopy(pattern, 0, longPattern, i*pattern.length, pattern.length);
		}
		
		if (longPattern.length < 3) return false;
		
		//System.out.println("long pattern: " + Arrays.toString(longPattern));
		
		int patternTotalValue = parsePattern(pattern, 0, pattern.length);
		
		int baseCacheFirst = longPattern[0];
		int baseCacheMiddle = longPattern[1];
		int baseCacheLast = subtractFromStart(patternTotalValue, longPattern[0]);
		baseCacheLast = subtractFromStart(baseCacheLast, longPattern[1]);
		for (int i = 1; i < patternCount; ++i)
		{
			baseCacheLast = addToEnd(baseCacheLast, patternTotalValue);
		}
		
		int cacheFirst = baseCacheFirst;
		int cacheMiddle = baseCacheMiddle;
		int cacheLast = baseCacheLast;
		
		for (int cut1 = 1; cut1 <= longPattern.length - 2 && cut1 <= pattern.length*4+1; ++cut1)
		{
			if (cut1 > 1)
			{
				baseCacheLast = subtractFromStart(baseCacheLast, longPattern[cut1]);
				
				//System.out.println("Advancing cut1");
				cacheFirst = addToEnd(cacheFirst, longPattern[cut1-1]);
				cacheMiddle = longPattern[cut1];
				cacheLast = baseCacheLast;
			}
			
			/*
			int rawFirst = parsePattern(longPattern, 0, cut1);
			
			if (rawFirst != cacheFirst)
			{
				System.out.println("i's don't match!: " + rawFirst + ", " + cacheFirst);
				System.exit(1);
			}
			*/
			
			if (cacheFirst != 2) continue;
			
			for (int cut2 = cut1 + 1; (cut2 <= longPattern.length - 1) && (cut2-cut1 <= pattern.length*4+1); ++cut2)
			{
				if (cut2 > cut1 + 1)
				{
					//System.out.println("Advancing cut2");
					cacheMiddle = addToEnd(cacheMiddle, longPattern[cut2-1]);
					cacheLast = subtractFromStart(cacheLast, longPattern[cut2-1]);
				}
				
				//System.out.println("i: " + cacheFirst + ", j: " + cacheMiddle + ", k: " + cacheLast);
				
				if (cacheMiddle == 3 && cacheLast == 4)
				{
					return true;
				}
				
				/*
				int rawMiddle = parsePattern(longPattern, cut1, cut2);
				
				if (rawMiddle != cacheMiddle)
				{
					System.out.println("   pattern count: "  + patternCount + ", pattern length: " + pattern.length);
					System.out.println("   long pattern: " + Arrays.toString(longPattern));
					System.out.println("   i: " + cacheFirst + ", j: " + cacheMiddle + ", k: " + cacheLast);
					System.out.println("   raw_i: " + rawFirst + ", raw_j: " + rawMiddle + ", raw_k: unknown");
					System.out.println("   cut1: " + cut1 + ", cut2: " + cut2);
					System.exit(1);
				}
				
				if (cacheMiddle != 3) continue;
				
				int rawLast = parsePattern(longPattern, cut2, longPattern.length);
				
				if (rawLast != cacheLast)
				{
					System.out.println("   pattern count: "  + patternCount + ", pattern length: " + pattern.length);
					System.out.println("   long pattern: " + Arrays.toString(longPattern));
					System.out.println("   i: " + cacheFirst + ", j: " + cacheMiddle + ", k: " + cacheLast);
					System.out.println("   raw_i: " + rawFirst + ", raw_j: " + "XXX" + ", raw_k: " + rawLast);
					System.out.println("   cut1: " + cut1 + ", cut2: " + cut2);
					System.exit(1);
				}
				*/
			}
		}
		
		return false;
	}
	
	private static int parsePattern(int[] pattern, int start, int end)
	{
		int val = pattern[start];
		int parity = 1;
		for (int i = start+1; i < end; ++i)
		{
			int newval = QUATERNION[val][pattern[i]];
			parity = parity * QUATERNION_PARITY[val][pattern[i]];
			val = newval;
		}
		
		return val * parity;
	}
	
	private static int addToEnd(int val, int adding)
	{
		int valParity = val > 0 ? 1 : -1;
		int addingParity = adding > 0 ? 1 : -1;
		int parity = valParity * addingParity;
		parity *= QUATERNION_PARITY[Math.abs(val)][Math.abs(adding)];
		val = QUATERNION[Math.abs(val)][Math.abs(adding)];
		
		return val * parity;
	}
	
	private static int subtractFromStart(int val, int subtracting)
	{
		int parity = val > 0 ? 1 : -1;
		parity *= REVERSE_QUATERNION_PARITY[subtracting][Math.abs(val)];
		val = QUATERNION[subtracting][Math.abs(val)];
		
		return val * parity;
	}
}
