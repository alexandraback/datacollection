import java.io.BufferedReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;


public class CounterCulture {

	/**
	 * @param args
	 */
	public static long powerOf10(int n)
	{
		if(n == 0)
			return 1;
		else
			return 10 * powerOf10(n-1);
	}
	public static long numTimesToReachNDigits(int n)
	{
		if(n == 1)
			return 0;
		else if(n == 2)
			return 10;
		else
			return numTimesToReachNDigits(n-1) + 8 + 1 + powerOf10(n-2);
	}
	public static int charToDigit(char c)
	{
		return c - '0';
	}
	public static void main(String[] args) {
		try
		{
			BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
			int t = Integer.parseInt(f.readLine());
			FileWriter fout = new FileWriter("counterculture.out");
			for(int i = 1; i <= t; i++)
			{
				String s = f.readLine();
				int n = Integer.parseInt(s);
				if(n < 10)
				{
					System.out.println("Case #" + i + ": " + n);
					fout.write("Case #" + i + ": " + n + "\n");
				}
				else
				{
					long numbersToSay = numTimesToReachNDigits(s.length()) + 1;
					if(charToDigit(s.charAt(0)) == 1)
						numbersToSay += charToDigit(s.charAt(s.length()-1)) - 1;
					else if(charToDigit(s.charAt(s.length() - 1)) == 0)
					{
						numbersToSay += n - (powerOf10(s.length() - 1) + 1); 
					}
					else
					{
						numbersToSay += charToDigit(s.charAt(0)) + charToDigit(s.charAt(s.length()-1)) - 1;
					}
					if(s.length() % 2 == 0)
					{
						for(int j = 1; j < s.length()/2; j++)
						{
							if(charToDigit(s.charAt(j)) == 0)
								numbersToSay += powerOf10(j) * (charToDigit(s.charAt(s.length() - j - 1)));
							else
								numbersToSay += powerOf10(j) * (charToDigit(s.charAt(j)) + charToDigit(s.charAt(s.length() - j - 1)) + 1);
						}
						System.out.println("Case #" + i + ": " + numbersToSay);
						fout.write("Case #" + i + ": " + numbersToSay + "\n");
					}
					else
					{
						for(int j = 1; j < s.length()/2; j++)
						{
							if(charToDigit(s.charAt(j)) == 0)
								numbersToSay += powerOf10(j) * (charToDigit(s.charAt(s.length() - j - 1)));
							else
								numbersToSay += powerOf10(j) * (charToDigit(s.charAt(j)) + charToDigit(s.charAt(s.length() - j - 1)) + 1);
						}
						numbersToSay += powerOf10(s.length()/2) * charToDigit(s.charAt(s.length()/2));
						System.out.println("Case #" + i + ": " + numbersToSay);
						fout.write("Case #" + i + ": " + numbersToSay + "\n");
					}
				}
				//System.out.println("Case #" + i + ": " + minTime);
				//fout.write("Case #" + i + ": " + minTime + "\n");
			}
			f.close();
			fout.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}

	}

}
