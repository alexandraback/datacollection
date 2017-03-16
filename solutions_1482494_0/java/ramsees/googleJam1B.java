import java.io.*;
public class googleJam1B {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		BufferedReader reader = null;
		PrintWriter writer = null;
		try{
			reader = new BufferedReader(new FileReader("B-small-attempt5.in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter("BSmall5.out")));
			int numInput = Integer.parseInt(reader.readLine());
			System.out.println("ok");
			for(int i = 0; i < numInput; i++)
			{
				System.out.println(i);
				int numLevels = Integer.parseInt(reader.readLine());
				System.out.println(i);
				int aLevel[] = new int[numLevels];
				int bLevel[] = new int[numLevels];
				for(int j = 0; j < numLevels; j++)
				{
					String temp = reader.readLine();
					System.out.println(i);
					int index = temp.indexOf(" ");
					aLevel[j] = Integer.parseInt(temp.substring(0,index));
					temp = temp.substring(index+1);
					bLevel[j] = Integer.parseInt(temp);
				}
				boolean finished = false;
				boolean didLevel;
				int currentStars = 0;
				int levelsPlayed = 0;
				while(!finished)
				{
					didLevel = false;
					for(int k = 0; k < numLevels; k++)
					{
						if(bLevel[k] != -1 && bLevel[k] <=currentStars)
						{
							if(aLevel[k] != -1)
							{
								currentStars++;
								aLevel[k] = -1;
							}
							currentStars++;
							levelsPlayed++;
							bLevel[k] = -1;
							didLevel = true;
						}
					}
					if(!didLevel)
					{
						int maxDoable = -1;
						int doIndex = -1;
						for(int k = 0; k < numLevels; k++)
						{
							if(aLevel[k]<=currentStars&&bLevel[k]>maxDoable&&aLevel[k] != -1)
							{
								System.out.println(bLevel[k] + " " + k);
								maxDoable = bLevel[k];
								doIndex = k;
							}
						}
						if(maxDoable!=-1)
						{
							System.out.println(maxDoable);
							aLevel[doIndex] = -1;
							currentStars++;
							levelsPlayed++;
						}
						else
							finished = true;
					}
				}
				if(currentStars == 2*numLevels)
					writer.print("Case #" + (i+1) + ": " + levelsPlayed + "\n");
				else
					writer.print("Case #" + (i+1) + ": " + "Too Bad" + "\n");
			}
			writer.close();
			System.out.println("done");
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

	}

}
