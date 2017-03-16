import java.io.*;
public class googleJam1C {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		PrintWriter writer = null;
		BufferedReader reader = null;
		try{
			reader = new BufferedReader(new FileReader("C-small-attempt2.in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter("CSmall2.out")));
			int numInput = Integer.parseInt(reader.readLine());
			for(int i = 0; i < numInput; i++)
			{
				int numCars = Integer.parseInt(reader.readLine());
				double speeds[] = new double[numCars];
				double distances[] = new double[numCars];
				boolean left[] = new boolean[numCars];
				for(int j = 0; j < numCars; j++)
				{
					String temp = reader.readLine();
					int index = temp.indexOf(" ");
					if(temp.substring(0,index).equals("L"))
						left[j] = true;
					else
						left[j] = false;
					temp = temp.substring(index+1);
					index = temp.indexOf(" ");
					speeds[j] = Double.parseDouble(temp.substring(0,index));
					temp = temp.substring(index+1);
					distances[j] = Double.parseDouble(temp);
				}
				boolean collision = false;
				double count = 0;
				while (!collision&& count < 11000000)
				{
					for(int j = 0; j < numCars; j++)
					{
						distances[j] += speeds[j]/1000;
					}
					for(int j = 0; j < numCars; j++)
					{
						for(int k = 0; k < numCars; k++)
						{
							if(k!= j && Math.abs(distances[k]-distances[j]) <5)
							{
								if(left[j] == left[k])
								{
									left[j] = !left[j];
									boolean part1 = false;
									boolean part2 = false;
									for(int m = 0; m < numCars; m++)
									{
										if(m!=j&& m!=k && Math.abs(distances[k]-distances[m]) <5)
											part1 = true;
										if(m!=j&& m!=k && Math.abs(distances[j]-distances[m]) <5)
											part2 = true;
									}
									if(part1&&part2)
										collision = true;
								}
							}
						}
					}
					count++;
				}
				if(collision)
					writer.print("Case #" + (i+1) + ": " + (count-1)/1000 + "\n");
				else
					writer.print("Case #" + (i+1) + ": " + "Possible" + "\n");
			}
			writer.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}

	}

}
