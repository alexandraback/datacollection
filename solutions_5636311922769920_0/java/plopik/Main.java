import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("input.txt"));
		File write = new File("output.txt");
		FileWriter fWriter = new FileWriter(write);

		int nb = sc.nextInt();
		
		for (int i = 0; i < nb ; i++) {

			int k = sc.nextInt();
			int c = sc.nextInt();
			int s = sc.nextInt();
			
			String output = "";
			for (int j = 0; j < k; j++) {
				output+=(j+1)+" ";
			}
			fWriter.write("Case #"+(i+1)+": "+output+"\n");
			System.out.println(output);
		}
		fWriter.flush();
		fWriter.close();
		sc.close();
	}
}
