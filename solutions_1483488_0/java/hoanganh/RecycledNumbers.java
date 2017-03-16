package year2012.RecycledNumbers;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

final class RecycledNumbers {

	/**
	 * @param args
	 * @throws IOException
	 */
	static int solve(int upper, int value)
	{
		if (value < 12) return 0;
		String strNum = value + "";
	
		int length = strNum.length();
					
		Set<Integer> setNewNumber = new HashSet<Integer> ();	               	        
		for (int i = 1; i < length; i++) 
		{
		
				if (strNum.charAt(i) != '0')
				{	
					String first = strNum.substring(0, i);
					String last = strNum.substring(i, length);
					
					int newNum = Integer.parseInt(last + first);
					if (newNum <= upper && newNum > value ) setNewNumber.add(new Integer(newNum)) ;
				}
		
		}
		return setNewNumber.size();
	}
	
	public static void main(String[] args) throws IOException {

		String file = "C-small-attempt0";
		Scanner sc = new Scanner(new FileReader(file + ".in"));
		PrintWriter pw = new PrintWriter(new FileWriter(file + ".out"));
				
		
		int T = sc.nextInt();
		int A = 0;
		int B = 0;
		sc.nextLine();
		for (int i = 0; i < T; i++) {
			A = sc.nextInt();
			B = sc.nextInt();
			int result = 0;
			for (int ii = A; ii <= B; ii++)
			{
				result += solve(B, ii);
			}			
			pw.println("Case #" + (i + 1) + ": " + result);

		}
		pw.flush();
		pw.close();
		sc.close();
	}
}
