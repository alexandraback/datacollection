import java.io.*;
import java.util.*;

public class ProblemA
{
	public static void main(String[] args)
	{
		String txtfile="A-small-attempt2.in";
		try
		{
			Scanner scan = new Scanner(new FileInputStream(txtfile));
			FileWriter fstream = new FileWriter("A-small-attempt2.out");
			BufferedWriter out = new BufferedWriter(fstream);
			int T = scan.nextInt();
			scan.nextLine();
			String G,output="";
			int temp;

			char[] map = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b',
						'k','r','z','t','n','w','j','p','f','m','a','q'};

			for (int X=1;X<=T;X++)
			{
				G = scan.nextLine();
				output="";
				for (int i=0;i<G.length();i++)
				{
					temp = (int) G.charAt(i);
					temp -= 97;
					if (temp<0)
						output+=" ";
					else
						output += map[temp];
				}
				out.write("Case #" + X + ": " + output + "\n");
			}
			out.close();
		}
		catch (Exception ex)
		{
			System.out.println(ex);
			System.exit(1);
		}

	}
}