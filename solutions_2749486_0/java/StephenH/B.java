import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		int x, y;

		int i;

		while(test <= cases)
		{
			x = sc.nextInt();
			y = sc.nextInt();

			System.out.print("Case #" + test + ": ");

			if(x < 0)
			{
				for(i = 0; i < -x; i++)
				{
					System.out.print("EW");
				}				
			}
			else
			{
				for(i = 0; i < x; i++)
				{
					System.out.print("WE");
				}
			}

			if(y < 0)
			{
				for(i = 0; i < -y; i++)
				{
					System.out.print("NS");
				}				
			}
			else
			{
				for(i = 0; i < y; i++)
				{
					System.out.print("SN");
				}
			}

			System.out.println();

			test++;
		}
	}
}