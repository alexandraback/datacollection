package bullseye;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Bullseye {

	static int testCases;

	static List<String> output = new ArrayList<String>();
	
	public static void main(String[] args) throws IOException{
		final String filename = "A-small-attempt0.in";
		FileReader fileReader;
		fileReader = new FileReader(filename);
		BufferedReader bufferedReader = new BufferedReader(fileReader);
		List<String> lines = new ArrayList<String>();
		String line = null;
		while ((line = bufferedReader.readLine()) != null) {
			lines.add(line);
		}
		bufferedReader.close();

		testCases = Integer.parseInt(lines.get(0));
		int linecount = 1;

		for (int i = 0; i < testCases; i++) {
			String[] values = lines.get(linecount).split(" ");
			linecount++;
			String out = "Case #" + (i+1) + ": " + calculate(values[0], values[1]);
			System.out.println(out);
			output.add(out);
		}

		FileWriter writer = new FileWriter("output.txt"); 
		for(String str: output) {
		  writer.write(str + "\n");
		}
		writer.close();
	}

	private static int calculate(String radius, String thickness) {
		int count = 0;
		
		long r = Long.parseLong(radius);
		long t = Long.parseLong(thickness);
		
		long w = r, b = r+1;
		
		while(t > 0){
			t -= b*b - w*w;
			if(t>=0){
				count++;
			}
			b += 2;
			w += 2;
		}
		
		return count;
	}
	
}
