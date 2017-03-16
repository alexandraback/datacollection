import java.util.*;

public class D
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());

		int blocks, R, C;

		int min;

		String winner;

		while(test <= cases)
		{
			blocks = sc.nextInt();
			R = sc.nextInt();
			C = sc.nextInt();

			if((R * C) % blocks != 0)
				winner = "RICHARD";
			else if(blocks >= 7)
				winner = "RICHARD";
			else if(blocks == 1)
				winner = "GABRIEL";
			else if(blocks == 2)
			{
				if(R >= 2 || C >= 2)
					winner = "GABRIEL";
				else winner = "RICHARD";
			}
			else if(blocks == 3)
			{
				if((R >= 2 && C >= 3) || (R >= 3 && C >= 2))
					winner = "GABRIEL";
				else winner = "RICHARD";
			}
			else // if(blocks >= 4)
			{
				if(blocks % 2 == 0)
					min = blocks - 1;
				else min = blocks;

				if((R >= min && C >= blocks) || (R >= blocks && C >= min))
					winner = "GABRIEL";
				else winner = "RICHARD";
			}

			System.out.println("Case #" + test + ": " + winner);

			test++;
		}
	}
}