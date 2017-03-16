package gcj;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Consonants {

	/**
	 * @param args
	 * @throws IOException
	 */
	public static void main(String[] args) throws IOException {

		char vowels[] = {'a', 'e', 'i', 'o', 'u'};

		BufferedReader reader = new BufferedReader(new FileReader(args[0]));
		BufferedWriter writer = new BufferedWriter(new FileWriter(args[1]));
		int cases = Integer.valueOf(reader.readLine());
		for (int i = 0; i < cases; i++) {
			String[] splittedLine = reader.readLine().split(" ");
			String name = splittedLine[0];
			int n = Integer.valueOf(splittedLine[1]);
			int nValue = 0;

			for (int j = 0; j < name.length(); j++) {
				int counter = 0;
				for (int k = j; k < name.length(); k++) {
					char currentChar = name.charAt(k);
					if (currentChar == vowels[0] || currentChar == vowels[1] || currentChar == vowels[2] || currentChar == vowels[3] || currentChar == vowels[4]) {
						counter = 0;
					}
					else {
						counter++;
						if (counter >= n) {
							nValue += name.length() - k;
							break;
						}
					}
				}
			}

			writer.write(String.format("Case #%d: %d\n", i + 1, nValue));
		}
		reader.close();
		writer.close();
	}

}
