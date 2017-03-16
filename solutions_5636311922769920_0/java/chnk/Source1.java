import java.math.BigInteger;
import java.io.*;
import java.util.*;
class Source1 
{
	public static void main(String[] args) throws IOException 
	{
		String s,word,buffer;
		String[][] board;

		FileReader input = new FileReader("D-small.in");
		Scanner in = new Scanner(input);
		File file = new File("D-small.out");
		BufferedWriter out = new BufferedWriter(new FileWriter(file));

		s = in.nextLine();
		int count= Integer.parseInt(s);

		int i=1;
		 while (in.hasNext())
		{

			 out.write("Case #"+(i++)+":");

			 if(in.hasNext())s = in.nextLine();
			
			 String[] num = s.split(" ");
			 int K = Integer.parseInt(num[0]);
			 int C = Integer.parseInt(num[1]);
			 int S = Integer.parseInt(num[2]);

				out.write(getcleantile(K,C,S));
				out.newLine();

		}


		 out.close();
	}

	public static String getcleantile(int K,int C,int S)
	{
		// generate possible sequence
		//System.out.println(K+" "+C+" "+S);
		String result="";

		if(K==S)
		{

			if(C==1)
			{
				for (int i=1;i<=S;i++)
				{
					result+=" "+i; 
				}
			}
			else
			{
				if(K==1)
					result=" 1";
				else
					for (int i=2;i<=K;i++)
					{
						result+=" "+i; 
					}
			}
		}
		else
		{
			return result;
		}
		return result;
	}


}
