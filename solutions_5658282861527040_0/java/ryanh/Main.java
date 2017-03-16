import java.io.BufferedReader;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.List;

import com.google.common.base.Splitter;
import com.google.common.collect.Lists;
import com.google.common.primitives.Ints;

/**
 * Requires Google Guava, available from http://code.google.com/p/guava-libraries/.
 */
public class Main {
	public static void main(String[] args) throws IOException {
		File output = new File("output");
		try (
				PrintWriter writer = new PrintWriter(new FileWriter(output));
				BufferedReader reader = new BufferedReader(
						new InputStreamReader(Main.class.getClassLoader().getResourceAsStream("sample")))) {

			String line = reader.readLine();
			int problems = Integer.parseInt(line);
			for (int problem = 0; problem < problems; problem++) {
				List<Integer> input = Lists.transform(Splitter.on(' ').splitToList(reader.readLine()), Ints.stringConverter());
				int a = input.get(0);
				int b = input.get(1);
				int k = input.get(2);
				int winners = 0;
				for (int i = 0; i < a; i++) {
					for (int j = 0; j < b; j++) {
						if ((i & j) < k) {
							winners++;
						}
					}
				}
				String answer = "" + winners;
				String outputLine = String.format("Case #%d: %s", problem + 1, answer);
				System.out.println(outputLine);
				writer.println(outputLine);
			}
		}
	}
}
