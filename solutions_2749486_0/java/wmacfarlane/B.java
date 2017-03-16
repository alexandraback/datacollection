import java.io.*;

class B
{
	public static void main ( String [] args ) throws Exception
	{
		BufferedReader br = new BufferedReader(new FileReader("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));

		int numTests = Integer.parseInt(br.readLine());
		for(int test = 1; test <= numTests; test++)
		{
			StringBuilder sb = new StringBuilder("");
			String[] reg = br.readLine().split(" ");
			int x = Integer.parseInt(reg[0]);
			int y = Integer.parseInt(reg[1]);
			
			int xLoc = 0;
			int yLoc = 0;
			int jInc = 1;
			while(xLoc != x)
			{
				if(xLoc < x) //target is east
				{
					if(jInc + xLoc < x) //just jump east
					{
						xLoc += jInc;
						sb.append("E");
						jInc++;
					}
					else
					{
						xLoc++;
						sb.append("WE");
						jInc += 2;
					}
				}
				else //target is west
				{
					if(xLoc - jInc > x) //just jump west
					{
						xLoc -= jInc;
						sb.append("W");
						jInc++;
					}
					else
					{
						xLoc--;
						sb.append("EW");
						jInc += 2;
					}
				}
			}
			
			while(yLoc != y)
			{
				if(yLoc < y) //target is north
				{
					if(jInc + yLoc < y) //just jump north
					{
						yLoc += jInc;
						sb.append("N");
						jInc++;
					}
					else
					{
						yLoc++;
						sb.append("SN");
						jInc += 2;
					}
				}
				else //target is south
				{
					if(yLoc - jInc > y) //just jump south
					{
						yLoc -= jInc;
						sb.append("S");
						jInc++;
					}
					else
					{
						yLoc--;
						sb.append("NS");
						jInc += 2;
					}
				}
			}
			
			
			
			
			
			
			out.println("Case #" + test + ": " + sb);

		}
		br.close();
		out.close();
	}
}