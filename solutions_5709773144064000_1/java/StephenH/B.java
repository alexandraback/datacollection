import java.util.*;

public class B
{


	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());
		double c, f, x;
		double r;
		double time;

		while(test <= cases)
		{
			time = 0;
			r = 2;

			c = sc.nextDouble();
			f = sc.nextDouble();
			x = sc.nextDouble();

			while((x / r) - (x / (r + f)) >= c / r)
			{
				time += c / r;
				r += f;
			}

			time += x / r;

			System.out.println("Case #" + test + ": " + time);

			test++;
		}
	}
}