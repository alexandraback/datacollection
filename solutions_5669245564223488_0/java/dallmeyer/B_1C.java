import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;


public class B_1C {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int tc = in.nextInt();
		
		mainloop: for (int caseno = 1; caseno <= tc; caseno++)
		{
			int n = in.nextInt();
			String[] trains = new String[n];
			boolean impossible = false;
			HashMap<Character,String> 	startsWith = new HashMap<Character,String>(),
										endsWith = new HashMap<Character,String>();
			HashMap<Character,ArrayList<String>> isAll = new HashMap<Character,ArrayList<String>>();
			for (int i = 0; i < n; i++)
			{
				String s = in.next();
				int a = s.lastIndexOf(s.charAt(0)),
					b = s.indexOf(s.charAt(s.length()-1));
				if (s.charAt(0) != s.charAt(s.length()-1) && b - a != 1)
				{
					impossible = true;
				}
				else
				{
					if (s.charAt(0) == s.charAt(s.length()-1))
					{
						if (isAll.containsKey(s.charAt(0)))
						{
							isAll.get(s.charAt(0)).add(s);
						}
						else
						{
							ArrayList<String> temp = new ArrayList<String>();
							temp.add(s);
							isAll.put(s.charAt(0), temp);
						}
					}
					else
					{
						if (startsWith.containsKey(s.charAt(0)))
						{
							impossible = true;
						}
						else
						{
							startsWith.put(s.charAt(0),s);
						}
						if (endsWith.containsKey(s.charAt(s.length()-1)))
						{
							impossible = true;
						}
						else
						{
							endsWith.put(s.charAt(s.length()-1), s);
						}
					}
				}
				trains[i] = s;
			}
			
			if (impossible)
			{
				System.out.println("Case #" + caseno + ": 0");
				continue mainloop;
			}
			
			ArrayList<String> starts = new ArrayList<String>();
			ArrayList<ArrayList<String>> allStarts = new ArrayList<ArrayList<String>>();
			
			for (Character c : startsWith.keySet())
			{
				if (!endsWith.containsKey(c) && !isAll.containsKey(c))
				{
					starts.add(startsWith.get(c));
				}
			}
			for (Character c : isAll.keySet())
			{
				if (!startsWith.containsKey(c) && !endsWith.containsKey(c))
				{
					allStarts.add(isAll.get(c));
				}
			}
			
			BigInteger count = BigInteger.valueOf(starts.size() + allStarts.size());
			for (String s : starts)
			{
				String x = s;
				while (true)
				{
					char end = x.charAt(x.length()-1);
					if (isAll.containsKey(end))
					{
						count =  count.multiply(factorial(isAll.get(end).size())).mod(BigInteger.valueOf(1000000007));
					}
					if (startsWith.containsKey(end))
					{
						x = startsWith.get(end);
					}
					else
					{
						break;
					}
				}
			}
			for (ArrayList<String> als : allStarts)
			{
				char c = als.get(0).charAt(0);
				count =  count.multiply(factorial(als.size()).mod(BigInteger.valueOf(1000000007)));
				if (startsWith.containsKey(c))
				{
					String x = startsWith.get(c);
					while (true)
					{
						char end = x.charAt(x.length()-1);
						if (isAll.containsKey(end))
						{
							count =  count.multiply(factorial(isAll.get(end).size())).mod(BigInteger.valueOf(1000000007));
						}
						if (startsWith.containsKey(end))
						{
							x = startsWith.get(end);
						}
						else
						{
							break;
						}
					}
				}
			}
			
			System.out.println("Case #" + caseno + ": " + count);
		}
	}

	private static BigInteger factorial(int x)
	{
		BigInteger y = BigInteger.ONE;
		for (int i = 2; i <= x; i++)
		{
			y = y.multiply(BigInteger.valueOf(i));
		}
		return y;
	}
	
}
