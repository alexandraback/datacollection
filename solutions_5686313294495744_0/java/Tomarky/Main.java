import java.util.*;

public class Main
{
	public static void main(String[] args) throws Exception
	{
		Scanner in = new Scanner(System.in);
		
		int t = in.nextInt();
		
		Map<String, Integer>
			first_map = new HashMap<>(),
			second_map = new HashMap<>();
		
		List<String>
			first_list = new ArrayList<>(),
			second_list = new ArrayList<>();
		
		for (int i = 0; i < t; i++)
		{
			int n = in.nextInt();
			
			first_map.clear();
			second_map.clear();
			first_list.clear();
			second_list.clear();
			
			for (int j = 0; j < n; j++)
			{
				String
					first = in.next(),
					second = in.next();
				
				Integer
					val1 = first_map.get(first),
					val2 = second_map.get(second);
				
				first_map.put(first, val1 == null ? 1 : val1 + 1);
				second_map.put(second, val2 == null ? 1 : val2 + 1);
				
				first_list.add(first);
				second_list.add(second);
			}
			
			int fakers = 0;
			
			for (int j = 0; j < n; j++)
			{
				String
					first = first_list.get(j),
					second = second_list.get(j);
				
				Integer
					val1 = first_map.get(first),
					val2 = second_map.get(second);
				
				if (val1 > 1 && val2 > 1)
				{
					fakers++;
				}
			}
			
			
			System.out.printf("Case #%d: %d\n", i + 1, fakers);
		}
	}
}