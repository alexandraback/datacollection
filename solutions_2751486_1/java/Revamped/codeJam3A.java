import java.util.*;

public class codeJam3A
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		ArrayList<Character> vowels = new ArrayList<Character>();
		vowels.add('a');
		vowels.add('e');
		vowels.add('i');
		vowels.add('o');
		vowels.add('u');
		
		for(int testNo = 1; testNo <= testCase; testNo++)
		{
			String name = sc.next().toLowerCase();
			int n = sc.nextInt();
			int counter = 0;
			
			
			int from = 0;
			long subCount = 0;
			for(int i = 0; i < name.length(); i++)
			{
				if(vowels.indexOf(name.charAt(i)) < 0)
				{
					counter++;
					if(counter >= n)
					{
						subCount += (((i-(n-1)) - from) + 1)* (name.length() - i);
						from = (i-(n-1)) + 1;
					}
				}
				else
				{
					counter = 0;
				}
			}
			
			System.out.printf("Case #%d: %d\n", testNo, subCount);
		}
	}
}