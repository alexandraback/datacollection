import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class A1 {
	static int t;
	static BufferedWriter writer = null;

	static StringBuilder sb = new StringBuilder();
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static String str;

	public static void solve() throws IOException
	{
		int arr[] = new int[27];
		for(int i = 0 ; i < str.length() ; i++)
		{
			arr[str.charAt(i) - 'a']++;
		}

		StringBuilder num = new StringBuilder();
		boolean can = false;
		for(int i = 0 ; i <= 9 ; i++)
		{

			can = false;
			if(i == 0)
			{
				if(arr['z'-'a'] > 0 && arr['e'-'a'] > 0 && arr['r'-'a'] >0 && arr['o'-'a'] > 0)
				{
					arr['z'-'a']--;
					arr['e'-'a']--;
					arr['r'-'a']--;
					arr['o'-'a']--;
					can = true;
					num.append("0");
				}

			}


			if(i == 1)
			{
				if(arr['o'-'a'] > 0 && arr['n'-'a'] > 0 && arr['e'-'a'] >0)
				{

					arr['o'-'a']--;
					arr['n'-'a']--;
					arr['e'-'a']--;

					can = true;
					num.append("1");
				}

			}




			if(i == 2)
			{
				if(arr['t'-'a'] > 0 && arr['w'-'a'] > 0 && arr['o'-'a'] >0)
				{

					arr['t'-'a']--;
					arr['w'-'a']--;
					arr['o'-'a']--;
					can = true;
					num.append("2");
				}

			}


			if(i == 3)
			{
				if(arr['t'-'a'] > 0 && arr['h'-'a'] > 0 && arr['r'-'a'] >0 && arr['e'-'a'] > 1)
				{
					arr['t'-'a']--;
					arr['h'-'a']--;
					arr['r'-'a']--;
					arr['e'-'a']--;
					arr['e'-'a']--;
					can = true;
					num.append("3");
				}

			}



			if(i == 4)
			{
				if(arr['f'-'a'] > 0 && arr['o'-'a'] > 0 && arr['u'-'a'] >0 && arr['r'-'a'] > 0)
				{
					arr['f'-'a']--;
					arr['o'-'a']--;
					arr['u'-'a']--;
					arr['r'-'a']--;
					can = true;
					num.append("4");
				}

			}

			if(i == 5)
			{
				if(arr['f'-'a'] > 0 && arr['i'-'a'] > 0 && arr['v'-'a'] >0 && arr['e'-'a'] > 0)
				{
					arr['f'-'a']--;
					arr['i'-'a']--;
					arr['v'-'a']--;
					arr['e'-'a']--;

					can = true;
					num.append("5");
				}

			}


			if(i == 6)
			{
				if(arr['s'-'a'] > 0 && arr['i'-'a'] > 0 && arr['x'-'a'] >0)
				{
					arr['s'-'a']--;
					arr['i'-'a']--;
					arr['x'-'a']--;
					can = true;
					num.append("6");
				}

			}

			if(i == 7)
			{
				if(arr['s'-'a'] > 0 && arr['e'-'a'] > 1 && arr['v'-'a'] > 0  && arr['n'-'a'] > 0)
				{
					arr['s'-'a']--;
					arr['e'-'a']--;
					arr['v'-'a']--;
					arr['e'-'a']--;
					arr['n'-'a']--;
					can = true;
					num.append("7");
				}

			}

			if(i == 8)
			{
				if(arr['e'-'a'] > 0 && arr['i'-'a'] > 0 && arr['g'-'a'] > 0  && arr['h'-'a'] > 0 && arr['t'-'a'] > 0)
				{

					arr['e'-'a']--;
					arr['i'-'a']--;
					arr['g'-'a']--;
					arr['h'-'a']--;
					arr['t'-'a']--;
					can = true;
					num.append("8");
				}

			}

			if(i == 9)
			{
				if(arr['n'-'a'] > 1 && arr['i'-'a'] > 0 && arr['e'-'a'] > 0)
				{
					arr['n'-'a']--;
					arr['i'-'a']--;
					arr['n'-'a']--;
					arr['e'-'a']--;


					can = true;
					num.append("9");
				}

			}




			if(can) --i;
		}
		writer.write(num.toString()+"\n");
	}
	public static void main(String[]args)throws Throwable
	{
		int t;
		t = new Integer(br.readLine());
		int tc = 1;
		File file = new File("example.txt");
		writer = new BufferedWriter(new FileWriter(file));

		while( t-- > 0)
		{
			str = br.readLine();
			str = str.toLowerCase();
			writer.write("Case #"+tc+": ");

			solve();
			tc++;
		}

		writer.flush();
	}
}
