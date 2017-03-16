import java.util.*;

public class P4DeceitfulWar
{
	private final int id;
	private final Double[] naomisBlocks;
	private final Double[] kensBlocks;

	private List<Double> naomisBlocksList;
	private List<Double> kensBlocksList;

	public P4DeceitfulWar(int id, Double[] naomisBlocks, Double[] kensBlocks)
	{
		this.id = id;
		this.naomisBlocks = naomisBlocks;
		this.kensBlocks = kensBlocks;
	}

	public void solve()
	{
		int pointsNewStrategy = playNewStrategy();
		int pointsOldStrategy = playOldStrategy();

		System.out.println("Case #" + (id + 1) + ": " + pointsNewStrategy + " " + pointsOldStrategy);
	}

	private int playNewStrategy()
	{
		naomisBlocksList = new ArrayList<Double>(naomisBlocks.length);
		kensBlocksList = new ArrayList<Double>(kensBlocks.length);

		for(int i = 0; i < naomisBlocks.length; i++)
		{
			naomisBlocksList.add(naomisBlocks[i]);
		}

		for(int i = 0; i < kensBlocks.length; i++)
		{
			kensBlocksList.add(kensBlocks[i]);
		}

		Collections.sort(naomisBlocksList);
		Collections.sort(kensBlocksList);

		int pointsNaomi = 0;
		int pointsKen = 0;
		int cheated = 0;

		boolean hasMoreBlocks = true;
		boolean doneCheating = false;

		while(hasMoreBlocks)
		{
			if(!doneCheating)
			{
				// play with cheats
				Double fakeNaomisBlock = null;
				Double naomisBlockToBeRemoved = null;
				for(Double naomisBlock : naomisBlocksList)
				{
					if(naomisBlock > kensBlocksList.get(0))
					{
						cheated++;
						fakeNaomisBlock = 1d - cheated * Double.MIN_VALUE;
						naomisBlockToBeRemoved = naomisBlock;
						break;
					}
				}

				if(fakeNaomisBlock != null)
				{
					naomisBlocksList.remove(naomisBlockToBeRemoved);
					playKen(fakeNaomisBlock);
					pointsNaomi++;
				}
				else
				{
					doneCheating = true;
				}
			}

			if(doneCheating)
			{
				// play old strategy (no more cheating possible)
				Double naomisBlock = naomisBlocksList.remove(0);

				// ken uses his strategy
				if(!playKen(naomisBlock))
					pointsNaomi++;

			}

			hasMoreBlocks = !naomisBlocksList.isEmpty();
		}

		return pointsNaomi;
	}

	private int playOldStrategy()
	{
		naomisBlocksList = new ArrayList<Double>(naomisBlocks.length);
		kensBlocksList = new ArrayList<Double>(kensBlocks.length);

		for(int i = 0; i < naomisBlocks.length; i++)
		{
			naomisBlocksList.add(naomisBlocks[i]);
		}

		for(int i = 0; i < kensBlocks.length; i++)
		{
			kensBlocksList.add(kensBlocks[i]);
		}

		Collections.sort(naomisBlocksList);
		Collections.sort(kensBlocksList);

		int pointsNaomi = 0;
		boolean hasMoreBlocks = true;

		while(hasMoreBlocks)
		{
			// naomi choses next block (no particular strategy)
			Double naomisBlock = naomisBlocksList.remove(0);

			// ken uses his strategy
			if(!playKen(naomisBlock))
				pointsNaomi++;

			hasMoreBlocks = !naomisBlocksList.isEmpty();
		}

		return pointsNaomi;
	}

	private boolean playKen(Double naomisBlock)
	{
		boolean kenWins = false;
		if(kensBlocksList.get(kensBlocksList.size() - 1) > naomisBlock)
		{
			// ken can win this round -> take least element > naomisBlock
			Double kensBlockToBeRemoved = null;
			for(Double kensBlock : kensBlocksList)
			{
				if(kensBlock > naomisBlock)
				{
					kensBlockToBeRemoved = kensBlock;
					kenWins = true;
					break;
				}
			}
			kensBlocksList.remove(kensBlockToBeRemoved);
			//System.out.println("Naomi:" + naomisBlock + " Ken:" + kensBlockToBeRemoved);
		}
		else
		{
			// ken can't win this round - take least element in list
			//System.out.println("Naomi:" + naomisBlock + " Ken:" + kensBlocksList.remove(0));
			kensBlocksList.remove(0);
			kenWins = false;
		}
		return kenWins;
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		int numberOfTestCases = in.nextInt();
		List<P4DeceitfulWar> problemList = new ArrayList<P4DeceitfulWar>();

		for(int i = 0; i < numberOfTestCases; i++)
		{
			int numberOfBlocks = in.nextInt();

			Double[] naomisBlocks = new Double[numberOfBlocks];
			Double[] kensBlocks = new Double[numberOfBlocks];

			for(int j = 0; j < numberOfBlocks; j++)
			{
				naomisBlocks[j] = in.nextDouble();
			}

			for(int j = 0; j < numberOfBlocks; j++)
			{
				kensBlocks[j] = in.nextDouble();
			}

			problemList.add(new P4DeceitfulWar(i, naomisBlocks, kensBlocks));
		}

		for(P4DeceitfulWar problem : problemList)
		{
			problem.solve();
		}
	}
}
