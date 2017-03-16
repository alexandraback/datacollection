import java.util.*;

public class codeJam3BEasy
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		
		for(int testNo = 1; testNo <= testCase; testNo++)
		{
			int x = sc.nextInt();
			int currX = 0;
			String path = "";
			int jump = 1;
			if(x < 0)
			{
				while(currX - jump > x)
				{
					path+= "W";
					currX -= jump;
					jump++;
				}
				if(Math.abs(x-currX) > Math.abs(x-(currX-jump)))
				{
					path+= "W";
					currX -= jump;
					jump++;
					while(currX != x)
					{
						path+="W";
						currX -= jump;
						jump++;
						path+="E";
						currX += jump;
						jump++;
					}
				}
				else
				{
					while(currX != x)
					{
						path+="E";
						currX += jump;
						jump++;
						path+="W";
						currX -= jump;
						jump++;
					}
				}
				
			}
			else
			{
				while(currX + jump < x)
				{
					path+= "E";
					currX += jump;
					jump++;
				}
				if(Math.abs(x-currX) > Math.abs(x-(currX+jump)))
				{
					path+= "E";
					currX += jump;
					jump++;
					while(currX != x)
					{
						path+="E";
						currX += jump;
						jump++;
						path+="W";
						currX -= jump;
						jump++;
					}
				}
				else
				{
					while(currX != x)
					{
						path+="W";
						currX -= jump;
						jump++;
						path+="E";
						currX += jump;
						jump++;
					}
				}
			}
			
			
			int y = sc.nextInt();
			int currY = 0;
			if(Math.abs(y) < jump)
			{
				currY += jump;
				path += "N";
				jump++;
			}
			while(currY != y)
			{
				path += "N";
				currY += jump;
				jump++;
				if(currY == y)
					break;
				path+= "S";
				currY -= jump;
				jump++;
			}
			System.out.printf("Case #%d: %s\n", testNo, path);
		}
	}
}