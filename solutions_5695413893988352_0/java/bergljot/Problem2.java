package round1B;

import java.util.Scanner;

public class Problem2 {
	
	static public String maximize(String input)
	{
		//System.out.println("max");
		String result = "";
		for (int i = 0; i < input.length(); i++)
		{
			if (input.charAt(i) == '?') result += '9';
			else result += input.charAt(i);
		}
		return result;
	}
	static public String minimize(String input)
	{
		//System.out.println("min");
		String result = "";
		for (int i = 0; i < input.length(); i++)
		{
			if (input.charAt(i) == '?') result += '0';
			else result += input.charAt(i);
		}
		return result;
	}
	
	public static StringPair minDifference(String string1, String string2)
	{
		//System.out.println("Strings are " + string1 + " " + string2);
		if (string1.length() == 0) 
		{
			StringPair res = new StringPair(string1, string2);
			return res;
		}
		if (string1.charAt(0) == string2.charAt(0) && string1.charAt(0) != '?')
		{
			// minimize rest of string
			StringPair pair = minDifference(string1.substring(1), string2.substring(1));
			StringPair res = new StringPair(string1.charAt(0) + pair.string1, string2.charAt(0) + pair.string2);
			return res;
		}
		if (string1.charAt(0) != '?' && string2.charAt(0) != '?')
		{
			int s1 = Integer.parseInt("" + string1.charAt(0));
			int s2 = Integer.parseInt("" + string2.charAt(0));
			if (s1 > s2)
			{
				// minimize remainder of string1, maximize remainder of string2
				String remainder1 = minimize(string1.substring(1));
				String remainder2 = maximize(string2.substring(1));
				StringPair res = new StringPair(string1.charAt(0) + remainder1, string2.charAt(0) + remainder2);
				return res;
			}
			else
			{
				String remainder1 = maximize(string1.substring(1));
				String remainder2 = minimize(string2.substring(1));
				StringPair res = new StringPair(string1.charAt(0) + remainder1, string2.charAt(0) + remainder2);
				return res;
			}
		}
		if (string1.charAt(0) == '?' && string2.charAt(0) != '?')
		{
			if (string2.length() == 1) return new StringPair(string2, string2);
			
			int s2 = Integer.parseInt("" + string2.charAt(0));
			StringPair pair1 = minDifference(string2.charAt(0) + string1.substring(1), string2);
			StringPair pair2 = null;
			if (s2 < 9) pair2 = minDifference((s2 + 1) + string1.substring(1), string2);
			StringPair pair3 = null;
			if (s2 > 0) pair3 = minDifference((s2 - 1) + string1.substring(1), string2);
			//System.out.println(pair1 + " " + pair2 + " " + pair3);
			return max(pair1, max(pair2, pair3)); 
		}
		if (string1.charAt(0) != '?' && string2.charAt(0) == '?')
		{
			if (string1.length() == 1) return new StringPair(string1, string1);
			
			int s1 = Integer.parseInt("" + string1.charAt(0));
			//StringPair pair1 = new StringPair(string2.charAt(0) + string1.substring(1), string2);
			StringPair pair1 = minDifference(string1, s1 + string2.substring(1));
			StringPair pair2 = null;
			if (s1 < 9) pair2 = minDifference(string1, (s1+1) + string2.substring(1));
			StringPair pair3 = null;
			if (s1 > 0) pair3 = minDifference(string1, (s1-1) + string2.substring(1));
			// System.out.println(pair1 + " " + pair2 + " " + pair3);
			return max(pair1, max(pair2, pair3)); 
		}

		if (string1.charAt(0) == '?' && string2.charAt(0) == '?')
		{
			/*StringPair pair1 = new StringPair('0' + string1.substring(1), '0' + string2.substring(1));
			StringPair pair2 = new StringPair('1' + string1.substring(1), '0' + string2.substring(1));
			StringPair pair3 = new StringPair('0' + string1.substring(1), '1' + string2.substring(1));*/
			StringPair pair1 = minDifference(string1.substring(1), string2.substring(1));
			//System.out.println(pair1);
			pair1.string1 = '0' + pair1.string1;
			pair1.string2 = '0' + pair1.string2;
			
			StringPair pair2 = new StringPair('1' + minimize(string1.substring(1)), '0' + maximize(string2.substring(1)));
			StringPair pair3 = new StringPair('0' + maximize(string1.substring(1)), '1' + minimize(string2.substring(1)));
			//System.out.println(pair1 + " " + pair2 + " " + pair3);
			// try to fill in
			return max(pair1, max(pair2, pair3));
		}
			
		
		return null;
	}
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		in.nextLine();
		for(int i = 0; i < cases; i++)
		{
			// code here
			String input = in.nextLine();
			String score1 = input.substring(0, input.indexOf(" "));
			String score2 = input.substring(input.indexOf(" ") + 1, input.length());
			// System.out.println("Case #" + (i + 1) + ": " + score1 + " " + score2);
			
			StringPair res = minDifference(score1, score2);
			System.out.println("Case #" + (i + 1) + ": " + res.string1 + " " + res.string2);
			
			
		}
		in.close();
	}
	
	static public class StringPair
	{
		public String string1;
		public String string2;
		
		public StringPair(String string1, String string2)
		{
			this.string1 = string1;
			this.string2 = string2;
		}
		public String toString()
		{
			return "StringPair: " + string1 + " " + string2; 
		}
	}
	
	static public StringPair max(StringPair pair1, StringPair pair2)
	{
		if (pair1 == null) return pair2;
		if (pair2 == null) return pair1;
		if (pair1.string1.contains("?") || pair1.string2.contains("?") || pair2.string1.contains("?") || pair2.string2.contains("?"))
		{
			return null;
		}
		int s11 = Integer.parseInt(pair1.string1);
		int s12 = Integer.parseInt(pair1.string2);
		int s21 = Integer.parseInt(pair2.string1);
		int s22 = Integer.parseInt(pair2.string2);
		
		// difference
		if (Math.abs(s11 - s12) > Math.abs(s21 - s22)) return pair2;
		if (Math.abs(s11 - s12) < Math.abs(s21 - s22)) return pair1;
		
		// first minimized
		if (s11 > s21) return pair2;
		if (s11 < s21) return pair1;
		
		// second minimized
		if (s12 > s22) return pair2;
		if (s22 < s12) return pair1;
		
		//System.out.println("WHAT???");
		
		return pair1;
		
	}
}
