package b;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class B
{

	public B()
	{
		try {
			Scanner s = new Scanner(System.in);//new File("/home/kulcyk/workspace/GCJ/bsmall.txt"));
			int t = s.nextInt();
			BufferedWriter bf = new BufferedWriter(new FileWriter(new File("/home/kulcyk/workspace/GCJ/bout")));

			for(int i = 0; i< t; i++)
			{
				int n = s.nextInt();
				int[] o = new int[n];
				int[] two = new int[n];
				int[] g = new int[n];

				for(int j = 0; j < n; j++)
				{
					o[j] = s.nextInt();
					two[j] = s.nextInt();
				}

				int star = 0;
				int numplayed = 0;


				while(true)
				{
					boolean foundTwo = false;
					boolean foundOne = false;
					int oneIndex = -1;
					int maxtwo = -1;

					for(int j =0; j < n; j++)
					{
						if(g[j]<2 && star>=two[j])
						{
							foundTwo = true;
							numplayed++;
							star+=2-g[j];
							g[j]=2;

							System.out.println("using: "+j);
							break;
						}
						else if (g[j]<1 && star>=o[j] && two[j]>maxtwo)
						{
							maxtwo = two[j];
							oneIndex = j;
							foundOne = true;
							System.out.println("pot use: "+j);
						}
					}
					if(!foundTwo && foundOne)
					{
						star++;
						numplayed++;
						g[oneIndex]=1;
						System.out.println("def use: "+oneIndex);
					}
					else if (!foundTwo)
					{
						break;
					}
					
					System.out.println("part star: "+star);

					if(star==n*2)
						break;
				}
				System.out.println("Star: "+star);
				
				if(star==n*2)
					bf.append("Case #"+(i+1)+": "+numplayed+"\n");
				else
					bf.append("Case #"+(i+1)+": Too Bad\n");
			}

			bf.flush();
			bf.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args)
	{
		new B();

		System.out.println("Done!");
	}

}