import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {

	/**
	 * @param args
	 */

	static boolean isRecycled(String s1, String s2) {
		if (s1.length() != s2.length())
			return false;

		if (s1.compareTo(s2) == 0)
			return true;

		for (int i = 0; i < s1.length(); i++) {
			char c = s1.charAt(0);
			s1 = s1.substring(1);
			s1 += c;

			if (s1.compareTo(s2) == 0)
				return true;
		}

		return false;
	}

	static int grade(int n)
	{
		int digits = Integer.toString(n).length();
		int mul = 10;
		int num = 9;
		for(int i=1;i<digits;i++,mul*=10)
			num+=mul*9;
		System.out.println( n + " "+ num);
		return num;		
	}
	static int solve1(int A, int B) {

		int count = 0;
		for (int i = A; i <= B; i++)
			for (int j = i + 1; j <= B; j++) {
				if (isRecycled(Integer.toString(i), Integer.toString(j)))
					count++;
				// System.out.println();
			}
		return count;

	}
	static int solve(int A, int B) {

		int count = 0;
		
		for (int i = A; i <= B; i++){
			
			boolean valid = false;
			int value = 0;
			String s = Integer.toString(i);
			Set<Integer> set = new HashSet<Integer>();
			for (int j = 0; j < s.length(); j++) {
				char c = s.charAt(0);
				s = s.substring(1);
				s += c;
				
				value = Integer.parseInt( s);
				
			
				if ( value >=A && value <=B && i<value && !set.contains(value))
				{
					valid = true;
					//System.out.println(i + " " + value);
					count++;
					set.add(value);
				}
				
			}

						
			
			}
		return count;

	}

	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));

		int N = scanner.nextInt();
		for (int i = 1; i <= N; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			int res = solve(A,B);
			writer.append("Case #" + i + ": " + res);
			writer.newLine();
		}
		writer.close();
		scanner.close();

	}

}
