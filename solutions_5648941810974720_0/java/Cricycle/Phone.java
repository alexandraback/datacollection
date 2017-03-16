import java.util.*;

public class Phone
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for (int caseNum = 1; caseNum <= t; ++caseNum)
		{
			char[] s = in.next().toCharArray();
			int[] counts = new int[26];
			for (char c : s)
			{
				counts[c - 'A']++;
			}
			
			ArrayList<Integer> list = new ArrayList<Integer>();
			
			int[] checkOrder = {0, 2, 4, 6, 8, 3, 1, 7, 5, 9};
			char[][] toCheck = 
			{
				{'Z', 'E', 'R', 'O'},
				{'W', 'T', 'O'},
				{'U', 'F', 'O', 'R'},
				{'X', 'S', 'I'},
				{'G', 'E', 'I', 'H', 'T'},
				{'H', 'T', 'R', 'E', 'E'},
				{'O', 'N', 'E'},
				{'S', 'E', 'V', 'E', 'N'},
				{'F', 'I', 'V', 'E'},
				{'N', 'I', 'N', 'E'}
			};
			
			for (int checkIdx = 0; checkIdx < checkOrder.length; ++checkIdx)
			{
				char checkChar = toCheck[checkIdx][0];
				while (counts[checkChar - 'A'] > 0)
				{
					list.add(checkOrder[checkIdx]);
					for (int extraChar = 0; extraChar < toCheck[checkIdx].length; ++extraChar)
					{
						counts[toCheck[checkIdx][extraChar] - 'A']--;
					}
				}
			}
			
			Collections.sort(list);
			System.out.printf("Case #%d: ", caseNum);
			for (int i = 0; i < list.size(); ++i)
			{
				System.out.print(list.get(i));
			}
			
			System.out.println();
		}
	}
}