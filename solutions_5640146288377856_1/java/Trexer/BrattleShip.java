package uk.ac.cam.spt37.codeJam2015;

import java.util.Scanner;

public class BrattleShip
{

	public static void main(String[] args)
	{
		Scanner data = new Scanner(System.in);
		int cases = data.nextInt();
		for(int i=1; i<=cases; i++)
		{
			int result = solve(data.nextInt(), data.nextInt(), data.nextInt());
			System.out.println("Case #"+i+": "+result);
		}
		data.close();
	}
	
	private static int solve(int rows, int cols, int width)
	{
		int result = cols/width;
		result *= rows;
		if (cols%width == 0) result--;
		result += width;
		return result;
	}

}