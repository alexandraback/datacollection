package round1B;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class GettingtheDigits {

	public static void main(String[] args) throws Exception
	{
		String path = "C:\\Users\\Ziming\\Downloads\\";
		String input = path + "A-large.in";
		String output = path + "A-large.out";

		Scanner scanner = new Scanner(new FileReader(input));
		PrintWriter writer = new PrintWriter(output);
		int T = scanner.nextInt();
		scanner.nextLine();
		for (int i = 0; i < T; i++) 
		{
			String S = scanner.nextLine();
			ArrayList<Integer> numbers = new ArrayList<>();
			while (S.contains("Z"))
			{
				numbers.add(0);
				S = S.replaceFirst("Z", "");
				S = S.replaceFirst("E", "");
				S = S.replaceFirst("R", "");
				S = S.replaceFirst("O", "");
			}
			while (S.contains("W"))
			{
				numbers.add(2);
				S = S.replaceFirst("T", "");
				S = S.replaceFirst("W", "");
				S = S.replaceFirst("O", "");
			}
			while (S.contains("U"))
			{
				numbers.add(4);
				S = S.replaceFirst("F", "");
				S = S.replaceFirst("O", "");
				S = S.replaceFirst("U", "");
				S = S.replaceFirst("R", "");
			}
			while (S.contains("X"))
			{
				numbers.add(6);
				S = S.replaceFirst("S", "");
				S = S.replaceFirst("I", "");
				S = S.replaceFirst("X", "");
			}
			while (S.contains("G"))
			{
				numbers.add(8);
				S = S.replaceFirst("E", "");
				S = S.replaceFirst("I", "");
				S = S.replaceFirst("G", "");
				S = S.replaceFirst("H", "");
				S = S.replaceFirst("T", "");
			}
			while (S.contains("O"))
			{
				numbers.add(1);
				S = S.replaceFirst("O", "");
				S = S.replaceFirst("N", "");
				S = S.replaceFirst("E", "");
			}
			while (S.contains("R"))
			{
				numbers.add(3);
				S = S.replaceFirst("T", "");
				S = S.replaceFirst("H", "");
				S = S.replaceFirst("R", "");
				S = S.replaceFirst("E", "");
				S = S.replaceFirst("E", "");
			}
			while (S.contains("F"))
			{
				numbers.add(5);
				S = S.replaceFirst("F", "");
				S = S.replaceFirst("I", "");
				S = S.replaceFirst("V", "");
				S = S.replaceFirst("E", "");
			}
			while (S.contains("S"))
			{
				numbers.add(7);
				S = S.replaceFirst("S", "");
				S = S.replaceFirst("E", "");
				S = S.replaceFirst("V", "");
				S = S.replaceFirst("E", "");
				S = S.replaceFirst("N", "");
			}
			while (S.contains("N"))
			{
				numbers.add(9);
				S = S.replaceFirst("N", "");
				S = S.replaceFirst("I", "");
				S = S.replaceFirst("N", "");
				S = S.replaceFirst("E", "");
			}
			
			Collections.sort(numbers);
			String r = "";
			for (int j=0;j<numbers.size();j++)
				r += numbers.get(j);
			System.out.println(i);
			writer.println("Case #" + (i + 1) + ": " + r);
		}
		
		writer.flush();
		writer.close();
		scanner.close();
		System.out.println("program finished :)");
	}
}
