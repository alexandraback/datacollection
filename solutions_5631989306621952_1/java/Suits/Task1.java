package suits.codejam.logic;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

/**
 * Hello world!
 *
 */
public class Task1 {
	public static void main(String[] args) throws FileNotFoundException, IOException {
		List<String> testCaseAll = new ArrayList<String>();
		try (BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"))) {
			String line;
			br.readLine();
			while ((line = br.readLine()) != null) {
				testCaseAll.add(line);
			}
			List<String> result = new ArrayList<>();

			
			for (String word : testCaseAll) {
			
				String[] wordByLetter = word.split("");
				String highest = getHighest(wordByLetter);
				int placeMent = 0;
				for (int i = 0; i < wordByLetter.length; i++) {
					String string = wordByLetter[i];
					if (string.equals(highest)){
						placeMent = i;
						break;
					}
				}
				
				String resultString = "";
				
				for (int i = 0; i < wordByLetter.length; i++) {
					String string = wordByLetter[i];
					if(resultString == "")
					{
						resultString = string;
						continue;
					}
					if (Character.toLowerCase(string.charAt(0)) >= Character.toLowerCase(resultString.charAt(0)))
						resultString = string + resultString;
					else
						resultString = resultString + string;
				}
				System.out.println("Done");
				
				result.add(resultString);
			}

			PrintWriter pw = new PrintWriter(new FileWriter("D:\\outPut.txt"));

			int i = 1;
			for (String string : result) {
				pw.println("Case #" + i + ": " + string);
				i++;
			}
			pw.close();

		}
	}

	private static String getHighest(String[] wordByLetter) {
		String[] clone = wordByLetter.clone();
		Arrays.sort(clone);
		return clone[clone.length-1];
	}
}
