package pancakes;

import java.util.Scanner;

public class Main {
	
	static int flipsNeeded(String pancakes, char type)
	{
		if (pancakes.length() == 1)
		{
			if (pancakes.charAt(0) == type) return 0;
			else return 1;
		}
		int currentIndex = pancakes.length() - 1;
		while (pancakes.charAt(currentIndex) == type)
		{
			currentIndex--;
			if (currentIndex < 0) return 0;
		}
		// currentIndex points to the last minus
		while (pancakes.charAt(currentIndex) != type)
		{
			currentIndex--;
			if (currentIndex < 0) return 1;
		}
		// want to change the section in front of currentIndex to minuses, then flip all minuses
		if (type == '+') return 1 + flipsNeeded(pancakes.substring(0, currentIndex + 1), '-');
		else return 1 + flipsNeeded(pancakes.substring(0, currentIndex + 1), '+');
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		in.nextLine();
		for(int i = 0; i < cases; i++)
		{
			String pancakes = in.nextLine();
			System.out.println("Case #" + (i + 1) + ": " + flipsNeeded(pancakes,'+'));
		}
		in.close();
	}
}
