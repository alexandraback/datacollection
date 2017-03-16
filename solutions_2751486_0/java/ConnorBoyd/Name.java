import java.util.List;
import java.util.ArrayList;
public class Name {
	
	private int n;
	private String name;
	private List<Integer> startValues, endValues;
	
	public Name(String s, int i)
	{
		n = i; name = s;
	}
	
	public long getValue()
	{
		long count = 0;
		
		for(int i = 0; i <= name.length()-n; ++i)
		{
			for(int j = i+n; j <= name.length(); ++j)
			{
				String s = name.substring(i, j);
				if(hasNConsecs(s))
				{
					++count;
				}
			}
		}
		
		return count;
	}
	
	private boolean isConsonant(char c)
	{
		return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
	}
	
	private boolean hasNConsecs(String s)
	{
//		System.out.print(s + "\t");
		if(s.length() < n) return false;	//Doesn't even have n
		
		for(int i = 0; i <= s.length()-n; ++i)
		{
			boolean b = true;
			int j;
			
			for(j = 0; j < n && j <= s.length(); ++j)
			{
				if( isConsonant( s.charAt(i+j) ) )
				{
					//Don't know what to do here
				}
				else
				{
					b = false;
					j = s.length();	//break out of inner loop
				}
			}
			
			if(b && j == n)
			{
//				System.out.println("true");
				return true;
			}
			
			
			
		}
		
//		System.out.println("false");
		return false;
	}
}
