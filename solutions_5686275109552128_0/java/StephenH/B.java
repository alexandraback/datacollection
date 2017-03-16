import java.util.*;

public class B
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());

		ArrayList<Integer> pancakes = new ArrayList<Integer>();

		int eaters;
		int special, loc, min;
		boolean reordering;

		int i;

		while(test <= cases)
		{
			eaters = sc.nextInt();

			pancakes.clear();

			for(i = 0; i < eaters; i++)
			{
				pancakes.add(sc.nextInt());
			}

			Collections.sort(pancakes);

			special = 0;

			min = pancakes.get(pancakes.size() - 1);

			while(pancakes.get(pancakes.size() - 1) > 1 && special < min)
			{
				loc = pancakes.size() - 1;
				pancakes.add(pancakes.get(loc) / 2);
				pancakes.set(loc, pancakes.get(loc) - (pancakes.get(loc) / 2));
				special++;

				Collections.sort(pancakes);

				min = Math.min(pancakes.get(pancakes.size() - 1) + special, min);
			}

			System.out.println("Case #" + test + ": " + min);

			test++;
		}
	}
}