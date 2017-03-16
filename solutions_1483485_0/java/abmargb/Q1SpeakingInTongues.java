import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Properties;
import java.util.Scanner;


public class Q1SpeakingInTongues {

	public static void main(String[] args) throws IOException {
		Properties properties = new Properties();
		properties.load(new FileReader("dict.txt"));
		Scanner scanner = new Scanner(new File("q1.input"));
		
		FileWriter writer = new FileWriter("q1.output");
		
		int cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int i = 1; i <= cases; i++) {
			
			String lineOne = scanner.nextLine();
			
			StringBuilder b = new StringBuilder();
			for (Character c : lineOne.toCharArray()) {
				b.append(properties.get(c.toString()));
			}
			
			writer.write("Case #" + i + ": " + b.toString() + "\n");
		}
		
		writer.close();
	}
	
}
