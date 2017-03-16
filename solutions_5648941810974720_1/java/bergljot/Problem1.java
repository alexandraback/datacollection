package round1B;

import java.util.Scanner;

public class Problem1 {
	
	public static String remove(String text, String remove)
	{
		String result = "";
		for (int i = 0; i < text.length(); i++)
		{
			String thisChar = "" + text.charAt(i);
			if (remove.contains(thisChar))
			{
				int index = remove.indexOf(thisChar);
				remove = remove.substring(0, index) + remove.substring(index + 1, remove.length());
			}
			else
			{
				result += text.charAt(i);
			}
				
		}
		return result;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		in.nextLine();
		for(int i = 0; i < cases; i++)
		{
			// code here
			String text = in.nextLine();
			int[] digits = new int[10];
			
			// digits with unique letters
			while(text.contains("X"))
			{
				digits[6] += 1;
				text = remove(text, "SIX");
			}
			while(text.contains("W"))
			{
				digits[2] += 1;
				text = remove(text, "TWO");
			}
			while(text.contains("Z"))
			{
				digits[0] += 1;
				text = remove(text, "ZERO");
			}
			while(text.contains("G"))
			{
				digits[8] += 1;
				text = remove(text, "EIGHT");
			}
			// digits with unique letters now
			while(text.contains("S"))
			{
				digits[7] += 1;
				text = remove(text, "SEVEN");
			}
			while(text.contains("H"))
			{
				digits[3] += 1;
				text = remove(text, "THREE");
			}
			while(text.contains("R"))
			{
				digits[4] += 1;
				text = remove(text, "FOUR");
			}
			while(text.contains("O"))
			{
				digits[1] += 1;
				text = remove(text, "ONE");
			}
			while(text.contains("F"))
			{
				digits[5] += 1;
				text = remove(text, "FIVE");
			}
			while(text.contains("N"))
			{
				digits[9] += 1;
				text = remove(text, "NINE");
			}
			String phone = "";
			for (int k = 0; k < 10; k++)
			{
				while(digits[k] > 0)
				{
					phone += k;
					digits[k] -= 1;
				}
			}
			System.out.println("Case #" + (i + 1) + ": " + phone);

		}
		in.close();
	}
}
