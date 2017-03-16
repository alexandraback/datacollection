
import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.FileWriter;
import java.io.BufferedWriter;

public class Kingdom
{
	public static void main(String[] args)
	{
		try
		{
			Scanner s = new Scanner(new File("kingdom.in"));
			BufferedWriter w = new BufferedWriter(new FileWriter(new File("kingdom.out")));
			int numCases = s.nextInt();
			s.nextLine();
		//	numCases = 1;
			
			for(int n = 1;n <= numCases; n++)
			{
				int N = s.nextInt();
				int[] oneStar = new int[N];
				int[] twoStar = new int[N];
				int[] state = new int[N]; //0 for not tried, 1 for completed lvl1, 2 for completed lvl2
				boolean canDoIt = true;
				for(int k = 0; k < N; k++)
				{
					oneStar[k] = s.nextInt();
					twoStar[k] = s.nextInt();
					state[k] = 0;
				}
				int count = 0; //levels completed
				int numStars = 0;
				do
				{
					//greedily choose any two Star he can do
					boolean doesTwoStar = false;
					for(int k = 0; k < N; k++)
					{
						if(state[k] != 2 && twoStar[k] <= numStars) //can complete twoStar for an undone level
						{
							doesTwoStar = true;
							numStars += (2 - state[k]);
							state[k] = 2; //completed
							count++; //does a level
	//						System.out.println("Choosing Two Star: " + k);
							break;
						}
					}
					if(doesTwoStar)
						continue;
						
					//else choose the one star with the hardest two star
					int index = -1;
					for(int k = 0; k < N; k++) //find the first undone lvl1 that he can do
					{
						if(state[k] == 0 && oneStar[k] <= numStars)
						{
							index = k;
							break;
						}
					}
			
					if(index == -1) //he cannot do any of the lvl1's
					{
						break;
					}
					
					for(int k = 0; k < N; k++) //find the optimal lvl1
					{
						if(state[k] == 0 && oneStar[k] <= numStars)
						{
							if(twoStar[k] > twoStar[index])
								index = k;
						}
					}
//					System.out.println("Choosing One Star: " + index);
					numStars++; //choose that lvl1
					state[index] = 1;
					count++;
					
				} while(true); //go until we can't do anymore
				
				for(int k = 0; k < N; k++) //check if we stopped because we won or because we are weak
					if(state[k] != 2)
						canDoIt = false;
				
				if(canDoIt)
					w.write("Case #" + n + ": " + count + "\n");
				else
					w.write("Case #" + n + ": Too Bad\n");
			}
			
			w.flush();
			w.close();
		}
		catch (IOException e)
		{
			e.printStackTrace();
		}
	}
	

}