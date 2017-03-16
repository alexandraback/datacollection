import java.util.*;

public class C
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = sc.nextInt();
		int a, b, curr, count;
		String aStr, bStr, num, shift;

		while(test <= cases)
		{
			count = 0;

			a = sc.nextInt();
			b = sc.nextInt();
			aStr = Integer.toString(a);
			bStr = Integer.toString(b);

			for(curr = a; curr <= b; curr++)
			{
				num = Integer.toString(curr);
				shift = nextShift(num);

				while(!num.equals(shift))
				{
					if(shift.charAt(0) != '0' && aStr.compareTo(shift) <= 0 && bStr.compareTo(shift) >= 0 && num.compareTo(shift) < 0)
						count++;

					shift = nextShift(shift);
				}
			}

			System.out.println("Case #" + test + ": " + count);

			test++;
		}
	}

	public static String nextShift(String s)
	{
		if(s.length() <= 1)
			return s;
		else return s.substring(1, s.length()) + s.substring(0, 1);
	}
}