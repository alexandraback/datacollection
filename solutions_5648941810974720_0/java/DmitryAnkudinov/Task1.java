package Round1B;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Task1 {
	
	private static String removeLetter(String input, char letter)
	{
		int firstIndexOfLetter = input.indexOf(letter);
		return input.substring(0, firstIndexOfLetter)+input.substring(firstIndexOfLetter + 1, input.length());
	}

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		File file = new File("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2016/data/Round1B/A-small-attempt1.in");
		PrintStream out = new PrintStream(new FileOutputStream("D:/Development/Competitions/GoogleCodeJam/GoogleCodeJam2016/data/Round1B/A-small-attempt1.out"));
		System.setOut(out);
		
		Scanner sc = new Scanner(file);
		int T = sc.nextInt();
		String[] result = new String[T];
		
		for (int i = 0; i < T; ++i)
		{
			String input = sc.next();
			ArrayList<Integer> numbers = new ArrayList<Integer>();
			while (input.indexOf('Z') != -1)
			{
				input = removeLetter(input, 'Z');
				input = removeLetter(input, 'E');
				input = removeLetter(input, 'R');
				input = removeLetter(input, 'O');
				numbers.add(0);
			}
			
			while (input.indexOf('W') != -1)
			{
				input = removeLetter(input, 'T');
				input = removeLetter(input, 'W');
				input = removeLetter(input, 'O');
				numbers.add(2);
			}
			
			while (input.indexOf('X') != -1)
			{
				input = removeLetter(input, 'S');
				input = removeLetter(input, 'I');
				input = removeLetter(input, 'X');
				numbers.add(6);
			}
			
			while (input.indexOf('S') != -1)
			{
				input = removeLetter(input, 'S');
				input = removeLetter(input, 'E');
				input = removeLetter(input, 'V');
				input = removeLetter(input, 'E');
				input = removeLetter(input, 'N');				
				numbers.add(7);
			}
			
			while (input.indexOf('G') != -1)
			{
				input = removeLetter(input, 'E');
				input = removeLetter(input, 'I');
				input = removeLetter(input, 'G');
				input = removeLetter(input, 'H');
				input = removeLetter(input, 'T');				
				numbers.add(8);
			}
			
			while (input.indexOf('H') != -1)
			{
				input = removeLetter(input, 'T');
				input = removeLetter(input, 'H');
				input = removeLetter(input, 'R');
				input = removeLetter(input, 'E');
				input = removeLetter(input, 'E');				
				numbers.add(3);
			}			

			while (input.indexOf('U') != -1)
			{
				input = removeLetter(input, 'F');
				input = removeLetter(input, 'O');
				input = removeLetter(input, 'U');
				input = removeLetter(input, 'R');
				numbers.add(4);
			}
			
			while (input.indexOf('F') != -1)
			{
				input = removeLetter(input, 'F');
				input = removeLetter(input, 'I');
				input = removeLetter(input, 'V');
				input = removeLetter(input, 'E');
				numbers.add(5);
			}
			
			while (input.indexOf('O') != -1)
			{
				input = removeLetter(input, 'O');
				input = removeLetter(input, 'N');
				input = removeLetter(input, 'E');
				numbers.add(1);
			}
			
			while (input.indexOf('N') != -1)
			{
				input = removeLetter(input, 'N');
				input = removeLetter(input, 'I');
				input = removeLetter(input, 'N');
				input = removeLetter(input, 'E');
				numbers.add(9);
			}
			
			numbers.sort(null);
			result[i] = "";
			for (int j = 0; j < numbers.size(); ++j)
				result[i] = result[i] + String.valueOf(numbers.get(j));
		}
		sc.close();
		
		for (int i = 0; i < T; ++i)
			System.out.println(String.format("Case #%d: %s", i + 1, result[i]));
	}

}