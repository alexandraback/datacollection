package qualification;

import java.util.Arrays;
import java.util.Scanner;

public class Recycle {
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		int num = scan.nextInt();
		
		for(int i=1; i<=num; i++)
		{
			int a = scan.nextInt();
			int b = scan.nextInt();
			int count = 0;
			for(int j = a; j<b; j++)
			{
				String one = "" + j;
				count += recycled(one, b);
			}
		
			System.out.println("Case #" + i + ": " + count);
		}
	}
	
	public static int recycled(String number, int max)
	{
		int result = 0;
		int num = Integer.parseInt(number);
		int perm;
		for(int i=0; i<number.length(); i++)
		{
			number = (number + number.charAt(0)).substring(1);
			perm = Integer.parseInt(number);
			if(perm == num)
				break;
			if(perm > num && perm <= max)
				result++;
			
		}
		
		
		return result;
	}
	
	public static boolean isRecycled(String a, String b)
	{
		if(a.length() != b.length())
			return false;
		
		if(!anagram(a,b))
			return false;
		
		for(int i=0; i<a.length(); i++)
		{
			if(a.equals(b))
				return true;
			b = (b + b.charAt(0)).substring(1);
		}
		
		return false;
	}
	
	public static boolean anagram(String a, String b)
	{
		char[] one = a.toCharArray();
		char[] two = b.toCharArray();
		Arrays.sort(one);
		Arrays.sort(two);
		String first = new String(one);
		String second = new String(two);
		return first.equals(second);
		
	}

}
