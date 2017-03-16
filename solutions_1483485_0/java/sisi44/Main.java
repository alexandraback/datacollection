import java.util.*;

public class Main{
	static char change(char a)
	{
		char res =  'a';
		switch(a)
		{
		case ' ':res = ' '; break;
		case 'a':res = 'y';break;
		case 'b':res = 'h';break;
		case 'c':res = 'e';break;
		case 'd':res = 's';break;
		case 'e':res = 'o';break;
		case 'f':res = 'c';break;
		case 'g':res = 'v';break;
		case 'h':res = 'x';break;
		case 'i':res = 'd';break;
		case 'j':res = 'u';break;
		case 'k':res = 'i';break;
		case 'l':res = 'g';break;
		case 'm':res = 'l';break;
		case 'n':res = 'b';break;
		case 'o':res = 'k';break;
		case 'p':res = 'r';break;
		case 'q':res = 'z';break;
		case 'r':res = 't';break;
		case 's':res = 'n';break;
		case 't':res = 'w';break;
		case 'u':res = 'j';break;
		case 'v':res = 'p';break;
		case 'w':res = 'f';break;
		case 'x':res = 'm';break;
		case 'y':res = 'a';break;
		case 'z':res = 'q';break;
			
			
		}
		return res;
	}
	public static void main(String args[])
	{
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		in.nextLine();
		for(int i = 1; i<= T; i++)
		{
			String s = in.nextLine();
			System.out.print("Case #"+i+": ");
			for(int j = 0; j<s.length();j++)
			{
				System.out.print(change(s.charAt(j)));
			}
			System.out.println();
		}
		
		//System.out.println();
	}
}