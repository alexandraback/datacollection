import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class ProblemA {

	ProblemA() throws IOException {
		String map = "yhesocvxduiglbkrztnwjpfmaq";
		
		BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
		BufferedWriter writer = new BufferedWriter(new FileWriter("output.txt"));
		
		int cases = Integer.parseInt(reader.readLine());
		
		for(int i = 1; i <= cases; i++) {
			String output = "";
			String line = reader.readLine();
			for(char c : line.toCharArray()) {
				if(c==' ') output+=c;
				else output+=map.charAt(c-'a');
			}
			writer.write("Case #"+i+": "+output);
			writer.newLine();
		}
		
		reader.close();
		writer.close();
	}
	
	public static void main(String[] args) throws IOException {
		new ProblemA();
	}
}
