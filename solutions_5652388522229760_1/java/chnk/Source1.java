import java.io.*;
import java.util.*;
class Source1 
{
	public static void main(String[] args) throws IOException 
	{
		String s,word,buffer;
		String[][] board;

		FileReader input = new FileReader("A-large.in");
		Scanner in = new Scanner(input);
		File file = new File("A-large.out");
		BufferedWriter out = new BufferedWriter(new FileWriter(file));

		s = in.nextLine();
		int count= Integer.parseInt(s);

		int i=1;
		 while (in.hasNext())
		{

			 out.write("Case #"+(i++)+": ");

			
				if(in.hasNext())s = in. nextLine();

				out.write(lastnumber(Integer.parseInt(s)));
				out.newLine();

		}


		 out.close();
	}
	
	public static String lastnumber(int N)
	{
		int[] list = {1,1,1,1,1,1,1,1,1,1};
		int staticN=N;
		if (N==0)
		{
			return "INSOMNIA";
		}
		
		int sumlist=10;
		while (sumlist!=0)
		{
			int temp=N;
			while(temp>0)
			{
				int digit=temp%10;
				temp=temp/10;
				list[digit]=0;
			}

			N+=staticN;

			sumlist=0;
			for(int i=0;i<list.length;i++)
				sumlist+=list[i];
		}
		

		return (N-staticN)+"";
	}


}
