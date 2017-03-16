package ominousOmino;

public class OminousOmino
{

	public static void main(String[] args)
	{
		String[][] data = loader.Loader.load(1, "/home/sam/Documents/CodeJam/Qualification/OminousOmino/D-small-attempt0.in");
		for(int i=0; i<data.length; i++)
		{
			System.out.println("Case #" + (i+1) + ": " + winner(data[i]));
		}
	}
	
	private static String winner(String[] data)
	{
		int n = Integer.parseInt(data[0]);
		int x = Integer.parseInt(data[1]);
		int y = Integer.parseInt(data[2]);
		if(x > y)
		{
			int i = x; 
			x = y;
			y = i;
		}
		if(x * y % n != 0) return "RICHARD";
		String result = "RICHARD";
		switch (n)
		{
			case 1:
				result = "GABRIEL";
				break;
			case 2:
				if (y != 1) result = "GABRIEL";
				break;
			case 3:
				if (x >= 2 && y >= 3) result = "GABRIEL";
				break;
			case 4:
				if (x >= 3 && y >= 4) result = "GABRIEL";
				break;
			case 5:
				if (x >= 4 && y >= 5) result = "GABRIEL";
				break;
			case 6:
				if (x >= 4 && y >= 6) result = "GABRIEL";
				break;
			default:
		}
		return result;
	}
	
}