import java.io.File;
import java.io.PrintWriter;
import java.util.LinkedList;
import java.util.Scanner;

public class Solution
{

	public static void main(String[] args) throws Exception
	{
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		s.nextLine();
		
		PrintWriter pW = new PrintWriter(new File("output.out"));
		for(int a = 0;a<N;a++)
		{
			String toUse = s.nextLine();
			int[] amount = new int[10];
			char[] temp = toUse.toCharArray();
			LinkedList<String> another = new LinkedList<String>();
			for(int c = 0;c<temp.length;c++)
			{
				another.add(temp[c]+"");
			}
			for(int i = 0;i<9;)
			{
				if(checkAndRemove(another,i))
				{
					amount[i]++;
				}
				else
				{
					i+=2;
				}
			}
			for(int i = 1;i<10;)
			{
				if(checkAndRemove(another,i))
				{
					amount[i]++;
				}
				else
				{
					i+=2;
				}
			}
			StringBuilder sB = new StringBuilder();
			for(int n = 0;n<10;n++)
			{
				for(int i = 0;i<amount[n];i++)
				{
					sB.append(n);
				}
			}
			pW.println("Case #"+(a+1)+": "+sB.toString());
		}
		pW.flush();
		pW.close();
	}
	
	public static boolean checkAndRemove(LinkedList<String> another, int index)
	{
		switch(index)
		{
		case 0:
			if(another.contains("Z"))
			{
				another.remove("Z");
				another.remove("E");
				another.remove("R");
				another.remove("O");
				return true;
			}
			break;
		case 1:
			if(another.contains("O"))
			{
				another.remove("O");
				another.remove("N");
				another.remove("E");
				return true;
			}
			break;
		case 2:
			if(another.contains("W"))
			{
				another.remove("T");
				another.remove("W");
				another.remove("O");
				return true;
			}
			break;
		case 3:
			if(another.contains("H"))
			{
				another.remove("T");
				another.remove("H");
				another.remove("R");
				another.remove("E");
				another.remove("E");
				return true;
			}
			break;
		case 4:
			if(another.contains("U"))
			{
				another.remove("F");
				another.remove("O");
				another.remove("U");
				another.remove("R");
				return true;
			}
			break;
		case 5:
			if(another.contains("F"))
			{
				another.remove("F");
				another.remove("I");
				another.remove("V");
				another.remove("E");
				return true;
			}
			break;
		case 6:
			if(another.contains("X"))
			{
				another.remove("S");
				another.remove("I");
				another.remove("X");
				return true;
			}
			break;
		case 7:
			if(another.contains("S"))
			{
				another.remove("S");
				another.remove("E");
				another.remove("V");
				another.remove("E");
				another.remove("N");
				return true;
			}
			break;
		case 8:
			if(another.contains("G"))
			{
				another.remove("E");
				another.remove("I");
				another.remove("G");
				another.remove("H");
				another.remove("T");
				return true;
			}
			break;
		case 9:
			if(another.contains("N"))
			{
				another.remove("N");
				another.remove("I");
				another.remove("N");
				another.remove("E");
				return true;
			}
			break;
		}
		return false;
	}
	
}