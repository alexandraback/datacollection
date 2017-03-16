package QualificationRound;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class P3Dijkstra {
	static boolean f1, f2;
	
	public static char multi(char c1, char c2)
	{
		f1 = f1 == f2;
		if(c1 == '1')
			return c2;
		if(c2 == '1')
			return c1;
		if(c1 == c2)
		{
			f1 = !f1;
			return '1';
		}
		f1 = f1 == ((c1 - 'i' + 3 - (c2 - 'i')) % 3 == 2);
		return (char) ('i' + (3 - (c1 - 'i') - (c2 - 'i')));
	}
	
	public static boolean isMinusOne(char part, boolean partF, int X)
	{
		if(part == '1')
			return !partF && (X % 2 == 1);
		else
			return X % 4 == 2;
	}
	public static boolean ijk(String str, int X)
	{
		char part = '1';
		boolean partF;
		f1 = true;
		f2 = true;
		for(int i = 0; i < str.length(); i++)
			part = multi(part, str.charAt(i));
		partF = f1;
		if(!isMinusOne(part, partF, X))
			return false;
		
		//find i
		f1 = true; f2 = true;
		char findi = '1';
		int i1 = 0, i2 = 0, k1 = 0, k2 = 0;
l1:		for(i1 = 0; i1 < 4; i1++)
		{
			for(i2 = 0; i2 < str.length(); i2++)
			{
				findi = multi(findi, str.charAt(i2));
				if(findi == 'i' && f1)
					break l1;
			}
		}
		//find k
		f1 = true; f2 = true;
		char findk = '1';
l2:		for(k1 = 0; k1 < 4; k1++)
		{
			for(k2 = 0; k2 < str.length(); k2++)
			{
				findk = multi(str.charAt(str.length() - 1 - k2), findk);
				f2 = f1;
				f1 = true;
				if(findk == 'k' && f2)
					break l2;
			}
		}
		
		if(i2 >= str.length() || k2 >= str.length())
			return false;
		
		return ((i1 + k1) * str.length() + i2 + 2 + k2 < str.length() * X);
	}
	
	public static boolean ijk2(String str, int X)
	{
		String s = "";
		for(int i = 0; i < X; i++)
			s += str;
		
		char c1 = '1';
		f1 = true; f2 = true;
		for(int i = 0; i < s.length(); i++)
		{
			f2 = true;
			c1 = multi(c1, s.charAt(i));
			if(f1 && c1 == 'i')
			{
				
			}
		}
		return false;
	}
	public static void main(String[] args) {


		BigInteger X8 = BigInteger.valueOf(8);
		File fin = new File("src/QualificationRound/C-large.in");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/QualificationRound/C-large.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				int L = scan.nextInt();
				long XX = scan.nextLong();
				
				int X = (int) (XX % 8);
				if(XX > 8)
					X += 8;
				String str = scan.next();
				output.println("Case #" + (i + 1) + ": " + (ijk(str, X) ? "YES" : "NO") );
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}					

	}
}
