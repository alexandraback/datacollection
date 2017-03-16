import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.List;

public class Pancake {

	public static void main(String[] args) throws IOException {
		List<String> readAllLines = Files.readAllLines(Paths.get("J:\\dev\\eclipse\\imports\\B-large.in"));
		BufferedWriter writer = Files.newBufferedWriter(Paths.get("J:\\dev\\eclipse\\imports\\outputPancakeLarge.txt"),
				StandardOpenOption.CREATE, StandardOpenOption.WRITE);
		for (int i = 1; i < readAllLines.size(); i++) {
			String string = readAllLines.get(i);
			int count = pancakeFlips(string);
			if (i != 1)
				writer.newLine();
			writer.write("Case #" + i + ": " + count);

		}
		writer.flush();
		writer.close();
	}
	
	public static int pancakeFlips(String pancakes){		
		char[] charArray = pancakes.toCharArray();
		char current = '+';
		int count = 0;
		for (int i = charArray.length-1; i >= 0; i--) {
			char c = charArray[i];
			if(current != c){
				count++;
				current = c;
			}	
		}
		return count;
	}
}
