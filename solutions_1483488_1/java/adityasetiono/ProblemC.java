import java.io.*;
import java.util.*;

public class ProblemC
{
	public static void main(String[] args)
	{
		String txtfile="C-large.in";
		try
		{
			Scanner scan = new Scanner(new FileInputStream(txtfile));
			FileWriter fstream = new FileWriter("C-large.out");
			BufferedWriter out = new BufferedWriter(fstream);
			int T = scan.nextInt();
			int y = 0,A,B,l,ban;
			String temp,sban;
			boolean copy;
			int[] z;
			for (int x=1;x<=T;x++)
			{
				A = scan.nextInt();
				B = scan.nextInt();
				y = 0;
				for (int i=A;i<B;i++)
				{
					temp = i + "";
					l = temp.length();
					z = new int[l];
					for (int j=0;j<l;j++) z[j] = 0;
					for (int j=1;j<l;j++)
					{
						sban = temp.substring(j) + "" + temp.substring(0,j);
						ban = Integer.parseInt(sban);
						copy = false;
						z[j] = ban;
						for (int k=0;k<j;k++) if (ban==z[k]) copy = true;
						if (ban>=A && ban<=B && ban>i && copy==false)
						{
							y++;
						}
					}
				}
				out.write("Case #" + x + ": " + y + "\n");
			}
			out.close();
		}
		catch (IOException ex)
		{
			System.out.println(ex);
			System.exit(1);
		}

	}
}