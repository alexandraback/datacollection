import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class Q1 {

	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new FileReader("input.in"));
		String input = null;
		String count = null;
		FileWriter fw = new FileWriter("output.out");  
		count = bf.readLine();
		for (int i = 0; i < Integer.parseInt(count); i++) {
				String a = bf.readLine();
				char first = '0';
				String merged = "";
				for (int i1 = 0; i1 < a.length(); i1++) {
					if (a.charAt(i1) >= first) {
						first = a.charAt(i1);
						merged = a.charAt(i1) + merged;
					}
					else {
						merged = merged + a.charAt(i1);
					}
				}
				fw.write("Case #" + (i + 1) + ": " + merged + "\n");
		}
		bf.close();
		fw.close();
	}
}
