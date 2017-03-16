import java.util.ArrayList;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int cases = input.nextInt();
		for(int c = 1; c <= cases; c++)
		{
			int J = input.nextInt();
			int P = input.nextInt();
			int S = input.nextInt();
			int K = input.nextInt();
			
			ArrayList<int[]> combos = new ArrayList<int[]>();
			for(int j = 1; j <= J; j++)
			{
				for(int p = 1; p <= P; p++)
				{
					for(int s = 1; s <= S; s++)
					{
						int[] temp = new int[3];
						temp[0] = j;
						temp[1] = p;
						temp[2] = s;
						boolean usable = true;
						int jpr = 1;
						int jsr = 1;
						int psr = 1;
						for(int a = 0; a < combos.size(); a++)
						{
							int[] b = combos.get(a);
							if(temp[0] == b[0] && temp[1] == b[1])
								jpr++;
							if(temp[0] == b[0] && temp[2] == b[2])
								jsr++;
							if(temp[1] == b[1] && temp[2] == b[2])
								psr++;
							if(jpr > K || jsr > K || psr > K)
							{
								usable = false;
								break;
							}
						}
						if(usable)
						{
							combos.add(temp);
						}
					}
				}
			}
			System.out.println("Case #" + c + ": " + combos.size());
			for(int iter = 0; iter < combos.size(); iter++)
			{
				int[] temp = combos.get(iter);
				System.out.println(temp[0] + " " + temp[1] + " " + temp[2]);
			}
		}
	}

}
