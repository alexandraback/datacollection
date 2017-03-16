import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception
	{
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);

		int total = sc.nextInt();
		
		for (int i = 0; i < total ; i++) 
		{

			int k = sc.nextInt();
			int cTailleTotal = sc.nextInt(); /* lol */
			int sEtudiants = sc.nextInt();
			
			String output = "";
			for (int j = 0; j < k; j++) 
			{
				output+=(j+1)+" ";
			}
			fWriter.write("Case #"+(i+1)+": "+output+"\n");
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}
}
