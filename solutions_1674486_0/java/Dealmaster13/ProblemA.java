package googleCodeJam.round1.C;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class ProblemA {

	public static int globalPaths = 0;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			// Open the file that is the first 
			// command line parameter
			FileInputStream fstream = new FileInputStream("input.txt");
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			br.readLine();
			int counter = 1;
			//Read File Line By Line
			while ((strLine = br.readLine()) != null)   {
				// Print the content on the console
				System.out.print("Case #" + counter + ": ");

				int nodes = Integer.parseInt(strLine);

				ArrayList<ArrayList<Integer>> to = new ArrayList<ArrayList<Integer>>();

				for (int i = 0; i < nodes; i ++)
				{
					strLine = br.readLine();

					String values[] = strLine.split(" ");

					to.add(new ArrayList<Integer>());

					ArrayList<Integer> connections = to.get(i);

					for (int j = 0; j < Integer.parseInt(values[0]); j ++)
					{
						connections.add(Integer.parseInt(values[j+1]) - 1);
					}
				}

				boolean found = false;

				int nodeCounter = 0;

				while (!found && nodeCounter != nodes)
				{
					for (int i = 0; i < nodes; i ++)
					{
						if (i != nodeCounter)
						{
							int paths = findPaths(nodeCounter, to, i);
							
							if (paths >= 2)
							{
								found = true;
							}
							
							globalPaths = 0;
						}
					}
					
					nodeCounter ++;
				}

				if (found)
				{
					System.out.println("Yes");
				}
				else
				{
					System.out.println("No");
				}
				
				counter ++;
			}
			//Close the input stream
			in.close();
		}catch (IOException e){//Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

	public static int findPaths(int currentNode, ArrayList<ArrayList<Integer>> to, int goalNode)
	{
		if (globalPaths < 2)
		{
			if (currentNode == goalNode)
			{
				return 1;
			}
			else
			{
				ArrayList<Integer> connections = to.get(currentNode);

				int count = 0;

				for (int i = 0; i < connections.size(); i ++)
				{
					if (globalPaths < 2)
					{
						count += findPaths(connections.get(i), to, goalNode);
					}

					globalPaths = count;
				}

				return count;
			}
		}
		else
		{
			return globalPaths;
		}
	}

}
