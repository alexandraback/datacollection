
import java.util.Scanner;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		sc.nextLine();
		for(int testNum = 1; testNum <= tests; testNum++)
		{
			String s = sc.next().trim();
			String currWord = s.substring(0,1);
			
			for(int i = 1; i < s.length(); i++)
			{
				String nextWord1 = currWord + s.substring(i, i + 1);
				String nextWord2 = s.substring(i, i + 1) + currWord;
				//System.out.println(nextWord1);
				//System.out.println(nextWord2);
				int compare = nextWord1.toString().compareTo(nextWord2.toString());
				if(compare < 0)
				{
					currWord = nextWord2;
				}
				else
				{
					currWord = nextWord1;
				}
			}
			System.out.println("Case #" + testNum + ": " + currWord.toString());
		}
		
		sc.close();
	}
}
