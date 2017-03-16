import java.util.*;

public class C
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int test = 1, cases = Integer.parseInt(sc.nextLine());

		int length;
		long mult;
		String line;

		int[][] subex;
		int full;
		int front, back, mid, mid1, mid2, midBlock;

		int cut1, cut2;
		long reps;
		boolean found;

		int i, j, k;

		while(test <= cases)
		{
			length = sc.nextInt();
			mult = sc.nextLong();

			line = sc.next();

			subex = new int[length][length];

			for(i = 0; i < length; i++)
			{
				switch(line.charAt(i))
				{
					case '1': subex[i][i] = 1; break;
					case 'i': subex[i][i] = 2; break;
					case 'j': subex[i][i] = 3; break;
					case 'k': subex[i][i] = 4; break;
					default: System.out.println("Invalid quaternion input");
				}

				for(j = 0; j < i; j++)
				{
					subex[j][i] = prod(subex[j][i - 1], subex[i][i]);
				}
			}

			full = subex[0][length - 1];

			found = false;

			for(cut1 = 0; cut1 < length && !found; cut1++)
			{
				for(cut2 = 0; cut2 < length && !found; cut2++)
				{
					reps = 0;

					if(cut1 == 0)
						front = 1;
					else front = subex[0][cut1 - 1];

					for(k = 1; front != 2 && k < 4; k++)
					{
						front = prod(full, front);
						reps++;
					}

					if(front == 2)
					{
						if(cut2 <= cut1)
						{
							reps++;

							mid1 = subex[cut1][length - 1];

							if(cut2 == 0)
								mid2 = 1;
							else mid2 = subex[0][cut2 - 1];

							mid = prod(mid1, mid2);

							midBlock = 1;

							for(k = 1; mid != 3 && k < 4; k++)
							{
								midBlock = prod(midBlock, full);
								mid = prod(prod(mid1, midBlock), mid2);
								reps++;
							}
						}
						else
						{
							mid1 = subex[cut2][length - 1];
							mid2 = subex[0][cut2 - 1];

							mid = subex[cut1][cut2 - 1];

							midBlock = prod(mid1, mid2);

							for(k = 1; mid != 3 && k < 4; k++)
							{
								mid = prod(mid, midBlock);
								reps++;
							}
						}

						if(mid == 3)
						{
							back = subex[cut2][length - 1];

							for(k = 1; back != 4 && k < 4; k++)
							{
								back = prod(back, full);
								reps++;
							}

							if(back == 4 && reps <= mult - 1 && (mult - reps - 1) % 4 == 0)
								found = true;
						}
					}
				}
			}

			System.out.print("Case #" + test + ": ");

			if(found)
				System.out.println("YES");
			else System.out.println("NO");

			test++;
		}
	}

	public static int prod(int a, int b)
	{
		int sa = a > 0 ? 1 : -1;
		int sb = b > 0 ? 1 : -1;

		a = a * sa;
		b = b * sb;

		switch(a)
		{
			case 1: return sa * sb * b;
			case 2: switch(b)
				{
					case 1: return sa * sb * 2;
					case 2: return sa * sb * -1;
					case 3: return sa * sb * 4;
					case 4: return sa * sb * -3;
					default: System.out.println("Invalid quaternion");
				}
			case 3: switch(b)
				{
					case 1: return sa * sb * 3;
					case 2: return sa * sb * -4;
					case 3: return sa * sb * -1;
					case 4: return sa * sb * 2;
					default: System.out.println("Invalid quaternion");
				}
			case 4: switch(b)
				{
					case 1: return sa * sb * 4;
					case 2: return sa * sb * 3;
					case 3: return sa * sb * -2;
					case 4: return sa * sb * -1;
					default: System.out.println("Invalid quaternion");
				}
			default: System.out.println("Invalid quaternion");
		}

		return 0;
	}
}