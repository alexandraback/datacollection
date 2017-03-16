import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;


public class Alphabet {
	public static void main(String [] args)
	{		

		// Input

		File file = new File("alphabet/small.txt");

		String[] problem = null;
		int size = 0;

		try {

			Scanner sc = new Scanner(file);

			size = sc.nextInt();
			
			sc.nextLine();

			problem = new String[size];

			for (int i=0; i<size; i++) {
				problem[i] = sc.nextLine();
				System.out.println(i + problem[i]);
			}
			sc.close();
		} 
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		// Main

		String[] sol =  new String[size];

		for (int i=0; i<size; i++) {
			String s = "" + problem[i].toCharArray()[0];
			
			
			for(int j = 1; j<problem[i].length(); j++) {
				if(s.toCharArray()[0]<=problem[i].toCharArray()[j]) {
					s = problem[i].toCharArray()[j] + s;
				}
				else {
					s = s + problem[i].toCharArray()[j];
				}
			}
			
			sol[i] = s;
			

		}


		// Output

		PrintWriter writer = null;
		try {
			writer = new PrintWriter("sol.txt", "UTF-8");
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (UnsupportedEncodingException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		for (int i=0; i<size; i++) {

			writer.print("Case #" + (i+1) + ": ");
			long index = i+1;
			System.out.print("Case #" + index + ": ");
			
			writer.println(sol[i]);
			System.out.println(sol[i]);

		}
		writer.close();

	}
}
