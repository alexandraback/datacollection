import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = sc.nextInt();
		int n;
		int games = 0, stars = 0, goal = 0, nextStars = 0;
		int[][] starReqs;
		boolean[][] won;
		int c;

		while(test <= cases)
		{
			games = 0;
			stars = 0;

			n = sc.nextInt();

			goal = 2 * n;
			starReqs = new int[n][2];
			won = new boolean[n][2];

			for(c = 0; c < n; c++)
			{
				starReqs[c][0] = sc.nextInt();
				starReqs[c][1] = sc.nextInt();
				Arrays.fill(won[c], false);
			}

			nextStars = -1;

			while(stars < goal && (nextStars = playMax(starReqs, won, stars)) != 0)
			{
				stars += nextStars;
				games++;
			}

			System.out.print("Case #" + test + ": ");

			if(stars == goal)
				System.out.println(games);
			else System.out.println("Too Bad");

			test++;
		}
	}

	public static int playMax(int[][] starReqs, boolean[][] won, int stars)
	{
		int r = 0, c = 1;
		int maxC = 0, maxR = 0, maxReq = 0;

		for(c = 1; c >= 0; c--)
		{
			maxC = -1;
			maxR = -1;
			maxReq = -1;

			for(r = 0; r < starReqs.length; r++)
			{
				if(!won[r][c] && starReqs[r][c] <= stars)
				{
					if(c == 1)
					{
						if(!won[r][c - 1])
						{
							won[r][c - 1] = true;
							won[r][c] = true;
							return 2;
						}
						else
						{
							maxC = c;
							maxR = r;
						}
					}
					else
					{
						if(starReqs[r][c + 1] > maxReq)
						{
							maxR = r;
							maxC = c;
							maxReq = starReqs[r][c + 1];
						}
					}
				}
			}

			if(maxC != -1 && maxR != -1)
			{
				won[maxR][maxC] = true;
				return 1;
			}
		}

		return 0;
	}
}