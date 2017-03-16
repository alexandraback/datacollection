import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.Writer;
import java.util.HashMap;
import java.util.Scanner;


public class Main {
	static class Solver
	{
		HashMap<Character,Character> dic = new HashMap<Character,Character>();
		
		Solver() //setup dictionary
		{
			dic.put('a', 'y');
			dic.put('b', 'h');
			dic.put('c', 'e');
			dic.put('d', 's');
			dic.put('e', 'o');
			dic.put('f', 'c');
			dic.put('g', 'v');
			dic.put('h', 'x');
			dic.put('i', 'd');
			dic.put('j', 'u');
			
			dic.put('k', 'i');
			dic.put('l', 'g');
			dic.put('m', 'l');
			dic.put('n', 'b');
			dic.put('o', 'k');
			dic.put('p', 'r');
			dic.put('q', 'z');
			dic.put('r', 't');
			dic.put('s', 'n');
			dic.put('t', 'w');
			
			dic.put('u', 'j');
			dic.put('v', 'p');
			dic.put('w', 'f');
			
			dic.put('x', 'm');
			dic.put('y', 'a');
			dic.put('z', 'q');
			
			dic.put(' ', ' '); //space
			
			
		}
		String decrypt (String input)
		{
			StringBuilder str = new StringBuilder("");
			for(char c:input.toCharArray())
				str.append(dic.get(c));
				
			return str.toString();
		}
		
	}
	
	
	
	public static void main(String[] args) throws Exception {
		
		Scanner scanner  = new Scanner(new File("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int N = scanner.nextInt(); scanner.nextLine();
		Solver solver = new Solver();
		for(int i=1;i<=N;i++)
		{
			String line = scanner.nextLine();
			String result = solver.decrypt(line);
			writer.write("Case #" + i +  ": " + result);
			writer.newLine();
			
		}
		writer.close();
		scanner.close();
	}

}
