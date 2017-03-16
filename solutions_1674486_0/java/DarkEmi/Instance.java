
public class Instance 
{
	int 		nbClass;
	boolean[][] links;
	int[][]		nbPath;
	
	public Instance(int argNbClass, boolean[][] inheritanceLinks) 
	{
		nbClass = argNbClass;
		links = inheritanceLinks;
		
		nbPath = new int[nbClass][nbClass];
		for (int i = 0; i < nbClass; i++)
			for (int j = 0; j < nbClass; j++)
				nbPath[i][j] = 0;
	}
	
	public String solve()
	{
		for (int i = 0; i < nbClass; i++)
		{
			reccursive(i, i);
		}
		
		boolean diamond = false;
		for (int i = 0; i < nbClass; i++)
			for (int j = 0; j < nbClass; j++)
			{
				if (nbPath[i][j] > 1)
				{
					diamond = true;
				}
			}
	
		if (diamond == true)
			return ("Yes");
		else
			return ("No");
	}

	private void reccursive(int current, int root) 
	{
		for (int j = 0; j < nbClass; j++)
		{
			if (links[current][j] == true)
			{
				nbPath[root][j]++;
				reccursive(j, root);
			}
		}
	}
}
