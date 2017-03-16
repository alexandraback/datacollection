import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


public class FairAndSquareSmall {
	public static void main(String[] args){
		int[] valid = {1, 4, 9, 121, 484};
		FileReader input;
		Scanner scanner;
		BufferedReader reader;
		try {
			input = new FileReader("C-small-attempt0.in.txt");
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			reader = new BufferedReader(input);
			int testcase = Integer.parseInt(reader.readLine());
			for(int k = 1; k <= testcase; k++){
				scanner = new Scanner(reader.readLine());
				int low = scanner.nextInt();
				int high = scanner.nextInt();
				int count = 0;
				for(int i : valid){
					if(i >= low && i <= high) count++;
					
				}
				out.println("Case #" + k + ": " + count); 
			}
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
