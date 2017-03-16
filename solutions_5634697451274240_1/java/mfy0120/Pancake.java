import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Pancake {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new FileReader("input.in"));
		String input = null;
		String count = null;
		FileWriter fw = new FileWriter("output.out");  
		count = bf.readLine();
		for (int i = 0; i < Integer.parseInt(count); i++) {
			char nows = '+';
			int counts = 0;
			input = bf.readLine();
			for (int i1 = input.length() - 1; i1 >=0; i1--) {
				if (input.charAt(i1) != nows) {
					counts++;
					nows = input.charAt(i1);
				}
			}
			fw.write("Case #" + (i + 1) + ": " + counts + "\n");
			}
		bf.close();
		fw.close();
		}


}
