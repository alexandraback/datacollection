import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	
	public static void main(String[] args) {
		try {
			BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
				String line = br.readLine();
				BufferedWriter out = new BufferedWriter(new FileWriter("output.txt"));
				int tests = Integer.valueOf(line.trim());
				for (int i = 0; i < tests; i++) {
					String[] number = br.readLine().split(" ");
					int a = Integer.valueOf(number[0]);
					int b = Integer.valueOf(number[1]);
					int digits = number[1].length();
					int result = 0;
					int multiplier = 1;
					for (int j = 0; j < digits - 1; j++) {
						multiplier *= 10;
					}
					for (int j = a; j < b; j++) {
						int value = j;
						int size = 0;
						while (true) {
							value = value/10 + (value % 10)*multiplier;
							if (a <= value && value <= b) {
								size++;
							}
							
							if (a <= value && value < j) {
								break;
							}
							if (value == j) {
								result += size*(size - 1)/2;
								break;
							}
						}
					}
					out.write("Case #"+ (i + 1) +": " + result + "\n");
				}
				out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}