package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Task2 {
	
	private static boolean matchesExpression(String expression, int number)
	{
		while (!expression.isEmpty())
		{
			char currentChar = expression.charAt(expression.length() - 1);
			if ((currentChar != '?') && ((number % 10) + '0' != currentChar))
				return false;
			
			number /= 10;
			expression = expression.substring(0, expression.length() - 1);
		}
		
		return true;
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2016/data/Round1B/B-small-attempt1.in");
		PrintStream out = new PrintStream(new FileOutputStream("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2016/data/Round1B/B-small-attempt1.out"));
		System.setOut(out);
		
		Scanner sc = new Scanner(file);
		int T = sc.nextInt();
		for (int i = 0; i < T; ++i)
		{
			String C = sc.next();
			String J = sc.next();
			int lead = 0;
			String cResult = "";
			String jResult = "";
			
			for (int j = 0; j < C.length(); ++j)
			{
				char cChar = C.charAt(j);
				char jChar = J.charAt(j);
				if (cChar == '?')
				{
					if (jChar == '?')
					{
						if (lead == 0)
						{
							cResult = cResult + "0";
							jResult = jResult + "0";
						}
						else if (lead == 1)
						{
							cResult = cResult + "0";
							jResult = jResult + "9";
						}
						else if (lead == 2)
						{
							cResult = cResult + "9";
							jResult = jResult + "0";							
						}
					}
					else
					{
						if (lead == 0)
						{
							cResult = cResult + jChar;
							jResult = jResult + jChar;
						}
						else if (lead == 1)
						{
							cResult = cResult + "0";
							jResult = jResult + jChar;
						}
						else if (lead == 2)
						{
							cResult = cResult + "9";
							jResult = jResult + jChar;							
						}
					}
				}
				else
				{
					if (jChar == '?')
					{
						if (lead == 0)
						{
							cResult = cResult + cChar;
							jResult = jResult + cChar;
						}
						else if (lead == 1)
						{
							cResult = cResult + cChar;
							jResult = jResult + "9";
						}
						else if (lead == 2)
						{
							cResult = cResult + cChar;
							jResult = jResult + "0";							
						}
					}
					else
					{
						cResult = cResult + cChar;
						jResult = jResult + jChar;

						if (lead == 0)
						{
							if (cChar > jChar)
								lead = 1;
							else if (cChar < jChar)
								lead = 2;
						}
					}
				}
			}
			
			int maxChecked = 10;
			if (C.length() == 2)
				maxChecked = 100;
			else if (C.length() == 3)
				maxChecked = 1000;
			
			int minDifference = maxChecked;
			String cTrue = "";
			String jTrue = "";
			
			for (int cCheck = 0; cCheck < maxChecked; ++cCheck)
			{
				if (!matchesExpression(C, cCheck))
					continue;
				
				
				for (int jCheck = 0; jCheck < maxChecked; ++jCheck)
				{
					if (!matchesExpression(J, jCheck))
						continue;
					
					if (Math.abs(cCheck - jCheck) < minDifference)
					{
						minDifference = Math.abs(cCheck - jCheck);
						cTrue = String.valueOf(cCheck);
						jTrue = String.valueOf(jCheck);
					}
					
					if (minDifference == 0)
						break;
				}
				
				if (minDifference == 0)
					break;
			}
			
			while (cTrue.length() != cResult.length())
				cTrue = "0"+cTrue;
			while (jTrue.length() != jResult.length())
				jTrue = "0"+jTrue;
			
			System.out.println(String.format("Case #%d: %s %s", i+1, cTrue, jTrue));
			/*
			System.out.print(String.format("Case #%d: %s %s from %s %s", i+1, cResult, jResult, C, J));
			if (cTrue.equals(cResult) && jTrue.equals(jResult))
				System.out.println();
			else
				System.out.println(String.format("- but actually %s %s", cTrue, jTrue));
				*/
		}	
		
		sc.close();
	}
}