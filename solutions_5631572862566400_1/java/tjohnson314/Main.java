
import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashSet;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int testNum = 1; testNum <= tests; testNum++)
		{
			int n = sc.nextInt();
			int[] bff = new int[n];
			int[] countBff = new int[n];
			for(int i = 0; i < n; i++)
			{
				bff[i] = sc.nextInt() - 1; //Convert to 0-based
				countBff[bff[i]]++;
			}
			
			/*boolean allCycles = true;
			for(int i = 0; i < n; i++)
			{
				if(countBff[i] != 1)
					allCycles = false;
			}
			
			if(allCycles)
			{
				System.out.println("Case #" + testNum + ": " + n);
			}
			else
			{*/
			
			ArrayList<ArrayList<Integer>> chains = new ArrayList<ArrayList<Integer>>();
			ArrayList<ArrayList<Integer>> circles = new ArrayList<ArrayList<Integer>>();
			boolean[] inCircle = new boolean[n];
			for(int i = 0; i < n; i++)
				inCircle[i] = false;
			
			for(int i = 0; i < n; i++)
			{
				int[] place = new int[n];
				for(int j = 0; j < n; j++)
					place[j] = -1;
				
				ArrayList<Integer> newChain = new ArrayList<Integer>();
				int end = i;
				newChain.add(end);
				place[end] = 0;
				int currPlace = 1;
				while(place[bff[end]] == -1)
				{
					end = bff[end];
					newChain.add(end);
					place[end] = currPlace;
					currPlace++;
				}
				
				if(place[bff[end]] == currPlace - 2)
				{
					if(countBff[newChain.get(0)] == 0 || currPlace == 2)
					{
						//System.out.print("Chain: ");
						//for(int val : newChain)
							//System.out.print((val + 1) + " ");
						chains.add(newChain);
						//System.out.println();
					}
				}
				else if(place[bff[end]] == 0)
				{
					if(!inCircle[newChain.get(0)])
					{
						//System.out.print("Circle: ");
						for(int val : newChain)
						{
							inCircle[val] = true;
							//System.out.print((val + 1) + " ");
						}
						circles.add(newChain);
						//System.out.println();
					}
				}
			}
			
			//Now our strategy is either to pick the largest circle...
			ArrayList<Integer> bestCircle = new ArrayList<Integer>();
			for(ArrayList<Integer> circle : circles)
			{
				if(circle.size() > bestCircle.size())
					bestCircle = circle;
			}
			
			//Or to find some set of possibly overlapping chains. We can exclude all of
			//the kids contained in circles, since if we include one of them we have to
			//take the entire circle.
			ArrayList<ArrayList<Integer>> combinedChains = new ArrayList<ArrayList<Integer>>();
			boolean[] combined = new boolean[chains.size()];
			for(int i = 0; i < chains.size(); i++)
				combined[i] = false;
			
			for(int i = 0; i < chains.size(); i++)
			{
				ArrayList<Integer> chain1 = chains.get(i);
				int size1 = chain1.size();
				for(int j = i + 1; j < chains.size(); j++)
				{
					ArrayList<Integer> chain2 = chains.get(j);
					int size2 = chain2.size();
					
					if(chain1.get(size1 - 1) == chain2.get(size2 - 2)
							&& chain1.get(size1 - 2) == chain2.get(size2 - 1))
					{
						combined[i] = true;
						combined[j] = true;
						//System.out.println("Can combine chains " + i + " and " + j);
						ArrayList<Integer> combinedChain = new ArrayList<Integer>();
						for(int val: chain1)
							combinedChain.add(val);
						for(int k = 0; k < chain2.size() - 2; k++)
							combinedChain.add(chain2.get(k));
						combinedChains.add(combinedChain);
					}
				}
			}
			
			
			for(int i = 0; i < chains.size(); i++)
			{
				if(!combined[i])
					combinedChains.add(chains.get(i));
			}
			
			//System.out.println("Combined chains:");
			/*for(int i = 0; i < combinedChains.size(); i++)
			{
				for(int j = 0; j < combinedChains.get(i).size(); j++)
				{
					System.out.print((combinedChains.get(i).get(j) + 1) + " ");
				}
				System.out.println();
			}*/
			
			//Now partition combined chains into disjoint sets of chains,
			//which we know is possible because chains...
			boolean[] partitioned = new boolean[combinedChains.size()];
			for(int i = 0; i < combinedChains.size(); i++)
				partitioned[i] = false;
			ArrayList<ArrayList<Integer>> partition = new ArrayList<ArrayList<Integer>>();
			for(int i = 0; i < combinedChains.size(); i++)
			{
				if(!partitioned[i])
				{
					ArrayList<Integer> bestOfPartition = combinedChains.get(i);
					HashSet<Integer> newSet = new HashSet<Integer>();
					for(int val: combinedChains.get(i))
					{
						newSet.add(val);
					}
					
					for(int j = i + 1; j < combinedChains.size(); j++)
					{
						if(!partitioned[j])
						{
							boolean overlap = false;
							for(int k = 0; k < combinedChains.get(j).size(); k++)
							{
								if(newSet.contains(combinedChains.get(j).get(k)))
								{
									overlap = true;
									break;
								}
							}
							
							if(overlap)
							{
								partitioned[j] = true;
								if(combinedChains.get(j).size() > bestOfPartition.size())
									bestOfPartition = combinedChains.get(j);
							}
						}
					}
					partition.add(bestOfPartition);
				}
			}
			
			int maxSize = 0;
			for(int i = 0; i < partition.size(); i++)
				maxSize += partition.get(i).size();
			
			System.out.print("Case #" + testNum + ": ");
			if(maxSize > bestCircle.size())
			{
				System.out.println(maxSize);
				if(maxSize > n)
				{
					System.out.println("Error: Dumping input");
					for(int i = 0; i < n; i++)
						System.out.println(bff[i] + 1);
					
					System.out.println("Best:");
					for(ArrayList<Integer> chain : partition)
					{
						for(int val : chain)
						{
							System.out.println((val + 1) + " ");
						}
					}
				}
			}
			else
			{
				System.out.println(bestCircle.size());
				/*for(int val: bestCircle)
				{
					System.out.print((val + 1) + " ");
				}*/
			}
			//System.out.println();
		}
		
		sc.close();
	}
}
