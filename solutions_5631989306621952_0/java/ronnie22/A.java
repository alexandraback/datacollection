

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {

	public static void main(String[] args) throws FileNotFoundException
	{
		Scanner sc = new Scanner(new File("input.in"));
		PrintWriter pw = new PrintWriter("output.out");
		int n_case = sc.nextInt();
		
		for(int i=1;i<=n_case;i++)
		{
			String ris = solve(sc.next());
			pw.println("Case #"+i+": "+ris);
		}
		sc.close();
		pw.close();
	}

	public static String solve(String s)
	{
		String ris = ""+s.charAt(0);
		
		for(int i=1;i<s.length();i++)
		{
			char left = ris.charAt(0);
			char now = s.charAt(i);
			
			if(now >= left)
			{
				ris = now+ris;
			}
			else
			{
				ris = ris+now;
			}
		}
		
		return ris;
	}

}
