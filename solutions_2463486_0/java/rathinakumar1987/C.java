import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class C{
	public ArrayList<Integer> palin(int n)
	{
		
		return null;
	}
	
	public static boolean isPalindrome(int num)
	{
		String s = ""+num;
		int len = s.length();
		for(int i=0; i<=(len/2); i++)
		{
			if(s.charAt(i)!=s.charAt(len-1-i))return false;
		}
		
		return true;
	}
	
	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner sc = new Scanner(new File("C.txt"));
		int testCase = sc.nextInt();
		for(int Case=1; Case<=testCase; Case++)
		{
			int A = sc.nextInt();
			int B = sc.nextInt();
			int a = (int)Math.sqrt(A);
			a = (Math.pow(a, 2)<A)? (a+1):a;
			int b = (int)Math.sqrt(B);
			int count =0;
			for(int i=a; i<=b; i++)
				if(isPalindrome(i) && isPalindrome((int)Math.pow(i, 2)))
					count++;
			System.out.println("Case #"+Case+": "+count);
		}
	}
}