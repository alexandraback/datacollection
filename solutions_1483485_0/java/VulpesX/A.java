import java.util.*;

public class A
{
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);

	  //String map = "abcdefghijklmnopqrstuvwxyz";
		String map = "yhesocvxduiglbkrztnwjpfmaq";

		int T = Integer.parseInt(scan.nextLine());
		for(int ca=1;ca <= T;ca++)
		{
			String str = scan.nextLine();
			System.out.print("Case #" + ca + ": ");

			for(int i=0;i < str.length();i++)
			{
				char c = str.charAt(i);
				if(c == ' ') System.out.print(" ");
				else System.out.print(map.charAt(c-'a'));
			}
			System.out.println();
		}
	}
}