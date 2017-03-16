import java.io.*;
import java.util.*;
class Source1 
{
	public static void main(String[] args) throws IOException 
	{
		String s,word,buffer;
		String[][] board;

		FileReader input = new FileReader("B-small.in");
		Scanner in = new Scanner(input);
		File file = new File("B-small.out");
		BufferedWriter out = new BufferedWriter(new FileWriter(file));

		s = in.nextLine();
		int count= Integer.parseInt(s);

		int i=1;
		 while (in.hasNext())
		{

			 out.write("Case #"+(i++)+": ");
			
				if(in.hasNext())s = in.nextLine();

				out.write(flippancake(s));
				out.newLine();

		}


		 out.close();
	}
	
	public static String flippancake(String line)
	{
		int count=0;

		int state=1; // 0 -,1 +

			for (int i=0;i<line.length();i++ )
			{
					
					if(line.charAt(i)=='-' && state==1)
					{
						if(i==0) count++;
						else count+=2;
						state=0;
					}
					else if(line.charAt(i)=='+')
					{
						state=1;
					}
			}
		
		return count+"";
	}



}
