import java.io.ObjectInputStream.GetField;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;


public class Kingdom {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		Reader reader = new Reader();
		ArrayList<String> input = reader.LinesReader();
		ArrayList<String> output = new ArrayList<String>();
		
		long nbCases = reader.nbCases;
		int currentLine = 0;
		for (int i = 0; i < nbCases; i++)
		{
			int nbLevel = Integer.valueOf(input.get(currentLine));
			currentLine++;
			
			ArrayList<Level> levels = new ArrayList<Level>();
			
			for (int j = 0; j < nbLevel; j++)
			{
				String[] line = input.get(currentLine).split(" ");
				currentLine++;
				
				Level l = new Level();
				l.oneStarDiff = Integer.valueOf(line[0]);
				l.twoStarDiff = Integer.valueOf(line[1]);
				levels.add(l);
			}
			String toto = getOutputStringForSingleCase(nbLevel, levels);
			System.out.println("out => " + toto);
			output.add(toto);
		}
		reader.output(output);
	}

	public static String getOutputStringForSingleCase(int nbLevel, ArrayList<Level> levels)
	{
		System.out.println("case : ");
		for (Level l : levels)
		{
			System.out.println(l.oneStarDiff + " - " + l.twoStarDiff);
		}
		
		// les plus dur à la fin de l'arrayList
		Collections.sort(levels, new Comparator<Level>()
			{
			//Returns a negative integer, zero, or a positive integer 
			// as the first argument is less than, equal to, or greater 
			// than the second.
			    public int compare(Level l1, Level l2)
			    {
			        if (l1.twoStarDiff < l2.twoStarDiff)
			        	return -1;
			        if (l1.twoStarDiff == l2.twoStarDiff)
			        	return 0;

			        // else..
			        return 1;
			    }
			});
			
		// pas encore fait de level !
		long nbStar = 0;
		
		
		
		// so nice programming, lol
		long nbTry = 0;
		while (true)
		{
			boolean doneAlevel = false;
			// est ce qu'on peut faire un lvl 2 ? (les plus facile au début)
			Level tested = levels.get(0);
			if (nbStar >= levels.get(0).twoStarDiff)
			{
				if (tested.doneOnce == true)
				{
					nbStar++;
				}
				else
					nbStar = nbStar + 2;
				
				// fait en lvl 2 : on l'enlève de la liste
				levels.remove(0);
				doneAlevel = true;
			}
			else // can we do a level 1 diff ?
			{
				int hardestDoable = -1;
				int index = -1;
				for (int i = 0; i < levels.size(); i++)
				{
					Level l = levels.get(i);
					if (l.doneOnce == false)
					{
						if (nbStar >= l.oneStarDiff)
						{
							if (l.twoStarDiff > hardestDoable)
							{
								index = i;
								hardestDoable = l.twoStarDiff;
							}
						}
					}
				}
				if (index != -1) // we found the "good level"
				{
					nbStar++;
					levels.get(index).doneOnce = true;
					doneAlevel = true;
				}
			}
			if (doneAlevel == false) // can not do
				return "Too Bad";
			nbTry++;
			if (levels.size() == 0)
				return String.valueOf(nbTry);
		}
	}
}