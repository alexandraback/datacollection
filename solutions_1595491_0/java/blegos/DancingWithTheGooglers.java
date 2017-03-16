import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class DancingWithTheGooglers {
	public static void main(String[] args) {
		int cases = 0, googlers = 0, suprs = 0, max = 0, point = 0;

		String in = "B-small-attempt0";
		
		try {
			BufferedReader br = readFile(new FileReader(in + ".in"));
			FileWriter fstream = new FileWriter(in + ".out");
			BufferedWriter out = new BufferedWriter(fstream);
			
			String inline;
			while ((inline = br.readLine()) != null) {
				int i = 0;
				
				String[] input = inline.trim().split(" ");
				
				while (i < input.length) {
					if (i == 0) {
						googlers = Integer.parseInt(input[i++]);
					} else if (i == 1) {
						suprs = Integer.parseInt(input[i++]);
					} else if (i == 2) {
						max = Integer.parseInt(input[i++]);
					} else {
						String result = "Case #" + (++cases) + ": ";
						int num = 0;
						
						while (i < input.length) {
							point = Integer.parseInt(input[i++]);
							
							//acceptable values
							int minNotSuprs = (max + ((max - 1) * 2));
							int minSuprs	= (max + ((max - 2) * 2));
							
							if (point >= minNotSuprs) {
								num++;
							} else if (point > 0) {
								if (point >= minSuprs && suprs > 0) {
									num++;
									suprs--;
								}
							}
						}
						
						result += String.valueOf(num);
						
						writeOutput(result, out);
					}
				}
			}
			out.close();
		} catch(Exception e) {
			e.printStackTrace();
		}
	}
	
	private static BufferedReader readFile(FileReader in) throws FileNotFoundException {
		return new BufferedReader(in);
	}
	
	private static void writeOutput(String text, BufferedWriter out) throws IOException {
		out.write(text);
		out.write("\n");
	}
}
