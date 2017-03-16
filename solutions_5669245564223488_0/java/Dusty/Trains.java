import java.io.*;

public class Trains
{
	public static void main(String[] args) throws Exception
	{
		PrintWriter writer = new PrintWriter("output.txt","UTF-8");
		BufferedReader br = new BufferedReader(new FileReader("input.txt"));
		int t= Integer.parseInt(br.readLine());
		for(int x = 0;x<t;x++)
		{
			int n = Integer.parseInt(br.readLine());
			String[] thingies = br.readLine().split(" ");

			//check if possible
			//ALL the combos
			int count = allcombos("",thingies);
			String temp = "";


			String out = "Case #"+(x+1)+": "+count;
			writer.println(out);
			System.out.println(x);
		}
		writer.close();
	}

	static boolean checkifok(String tbc)
	{
		char[] alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
		boolean[] checks = new boolean[26];
		for(int x = 0;x<26;x++)
			checks[x] = false;
		char prev = ' ';
		for(int x = 0;x<tbc.length();x++)
		{
			for(int y = 0;y<26;y++)
			{
				if(alpha[y]==tbc.charAt(x))
				{
					if(alpha[y]!=prev)
					{
						if(checks[y]==true)
							return false;
						else
						{
							checks[y]=true;
							prev = alpha[y];
						}
					}
					break;
				}
			}	
		}
		return true;
	}

	static int allcombos(String in, String[] strin)
	{
		if(strin.length == 1)
		{
			String submit = in+strin[0];
			if(checkifok(submit))
			{
				return 1;
			}
			return 0;
		}
		else
		{
			String[]  temp = new String[strin.length-1];
			int sum = 0;
			for(int x = 0;x<strin.length;x++)
			{
				int ins = 0;
				for(int y = 0;y<strin.length;y++)
				{
					if(y!=x)
					{
						temp[ins]=strin[y];
						ins++;
					}
				}
				String submit = in+strin[x];
				sum += allcombos(submit,temp);
			}
			return sum;
		}
	}


}