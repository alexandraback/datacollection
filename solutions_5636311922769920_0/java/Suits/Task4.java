package suits.codejam.logic;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Task4 {

	static int base, possibleCleaner;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		List<List<Integer>> testCaseAll = new ArrayList<List<Integer>>();
		try (BufferedReader br = new BufferedReader(new FileReader("D:\\input.txt"))) {
			String line;
			br.readLine();
			while ((line = br.readLine()) != null) {
				List<Integer> testList = new ArrayList<>();
				String[] parts = line.split(" ");
				for (String string : parts) {
					testList.add(Integer.valueOf(string));
				}
				testCaseAll.add(testList);
			}
			List<String> result = new ArrayList<>();

			for (List<Integer> strings : testCaseAll) {
				base = strings.get(0);
				possibleCleaner = strings.get(2);

				String outPut = "";
				if (possibleCleaner == base) {
					for (int i = 1; i <= possibleCleaner; i++)
						outPut = outPut + " " + i;
				} else {
					outPut = "IMPOSSIBLE";

				}
				result.add(outPut);
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
}
