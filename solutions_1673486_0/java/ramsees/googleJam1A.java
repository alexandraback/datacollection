import java.io.*;
public class googleJam1A {
	public static void main(String[] args)
	{
		BufferedReader reader = null;
		PrintWriter writer = null;
		try{
			reader = new BufferedReader(new FileReader("A-small-attempt5.in"));
			writer = new PrintWriter(new BufferedWriter(new FileWriter("ASmall6.out")));
			int numInput = Integer.parseInt(reader.readLine());
			for(int i = 0; i < numInput; i++)
			{
				System.out.println(numInput);
				String tempString = reader.readLine();
				int index = tempString.indexOf(" ");
				int numTyped = Integer.parseInt(tempString.substring(0,index));
				System.out.println(numTyped);
				tempString = tempString.substring(index+1);
				int numTotal = Integer.parseInt(tempString);
				System.out.println("ok");
				tempString = reader.readLine();
				double probs[] = new double[numTyped];
				for(int j = 0; j < numTyped; j++)
				{
					index = tempString.indexOf(" ");
					if(index == -1)
						probs[j] = Double.parseDouble(tempString);
					else
					{
						probs[j] = Double.parseDouble(tempString.substring(0,index));
						tempString = tempString.substring(index+1);
					}
				}
				double numBack[] = new double[numTyped];
				double probability = 1;
				for(int j = numTyped-1; j >= 0; j--)
				{
					probability = probability*(probs[numTyped-j-1]);
					System.out.println(probability);
					numBack[j] = 2*j + numTotal-numTyped + 1 + (1-probability)*(numTotal+1);
					System.out.println(numBack[j]);
				}
				System.out.println("no error");
				double numRestart = 1+numTotal+1;
				double max = numRestart;
				System.out.println(max);
				for(int j = 0; j < numTyped; j ++)
				{
					if(max>numBack[j])
						max = numBack[j];
					System.out.println(numBack[j]);
				}
				System.out.println(max);
				writer.print("Case #" + (i+1) + ": " + max + "\n");
				
			}
			writer.close();
		}
		catch(Exception e)
		{
			
		}
	}
	
}
