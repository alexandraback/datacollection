import java.util.*;


public class DeceitfulWar {
	public void solve()
	{
		Scanner sc = new Scanner(System.in);
		int numTest = sc.nextInt();
		for(int i=0;i<numTest;i++)
		{
			Integer numBlocks = sc.nextInt();
			LinkedList<Double> NaomiBlocks = new LinkedList<Double>();
			LinkedList<Double> KenBlocks = new LinkedList<Double>();

			for(int z=0;z<numBlocks;z++)
			{
				NaomiBlocks.add(sc.nextDouble());
			}
			
			for(int z=0;z<numBlocks;z++)
			{
				KenBlocks.add(sc.nextDouble());
			}
			LinkedList<Double> DeceitfulNaomiBlocks = (LinkedList<Double>)NaomiBlocks.clone();
			LinkedList<Double> DeceitfulKenBlocks = (LinkedList<Double>)KenBlocks.clone();
			Collections.sort(KenBlocks);
			Integer scoreNaomi=0;
			Integer scoreKen=0;
			for(int z=0;z<numBlocks;z++)
			{
				Double valNaomi = NaomiBlocks.get(z);
				if(KenBlocks.get(KenBlocks.size()-1)<valNaomi)
				{
					scoreNaomi++;
					KenBlocks.remove(0);
				}
				else
				{
					scoreKen++;
					for(int y=0;y<KenBlocks.size();y++)
					{
						if(KenBlocks.get(y)>valNaomi)
						{
							KenBlocks.remove(y);
							break;
						}
					}
				}
			}
			Integer deceitfulScoreNaomi=0;
			Integer deceitfulScoreKen=0;
			Collections.sort(DeceitfulNaomiBlocks);
			Collections.sort(DeceitfulKenBlocks);
//			for(int z=0;z<numBlocks;z++)
//			{
//				Double valNaomi = DeceitfulNaomiBlocks.get(z);
//				if(DeceitfulKenBlocks.get(DeceitfulKenBlocks.size()-1)<valNaomi)
//				{
//					DeceitfulKenBlocks.remove(DeceitfulKenBlocks.size()-1);
//					deceitfulScoreNaomi++;
//				}
//				else
//				{
//					DeceitfulKenBlocks.remove(DeceitfulKenBlocks.size()-1);
//					deceitfulScoreKen++;
//				}
//			}
			Integer smallerIndex = 0;
			Integer largerIndex = numBlocks-1;
			while(smallerIndex<=largerIndex)
			{
				Double valNaomi = DeceitfulNaomiBlocks.get(largerIndex);
				if(DeceitfulKenBlocks.get(DeceitfulKenBlocks.size()-1)<valNaomi)
				{
					DeceitfulKenBlocks.remove(DeceitfulKenBlocks.size()-1);
					deceitfulScoreNaomi++;
					largerIndex--;
				}
				else
				{
					DeceitfulKenBlocks.remove(DeceitfulKenBlocks.size()-1);
					deceitfulScoreKen++;
					smallerIndex++;
				}
				
			}
			
//			for(int z=numBlocks-1;z>=0;z--)
//			{
//				Double valNaomi = DeceitfulNaomiBlocks.get(z);
//				if(DeceitfulKenBlocks.get(DeceitfulKenBlocks.size()-1)<valNaomi)
//				{
//					DeceitfulKenBlocks.remove(DeceitfulKenBlocks.size()-1);
//					deceitfulScoreNaomi++;
//				}
//				else
//				{
//					DeceitfulKenBlocks.remove(DeceitfulKenBlocks.size()-1);
//					deceitfulScoreKen++;
//				}
//			}
			System.out.printf("Case #%d: %d %d\n", i+1, deceitfulScoreNaomi, scoreNaomi);
		}
		
		sc.close();
	}
}
