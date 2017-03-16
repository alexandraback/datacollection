import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class A {
	private int numConsecutiveConsonants(String substring) {
		int num = 0;
		int longest = 0;
		substring = substring.toLowerCase();

		for (int i = 0; i < substring.length(); i++) {
			switch (substring.charAt(i)) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				num = 0;
				break;
			default:
				num++;
				if (num > longest) {
					longest = num;
				}
				break;
			}
		}

		return longest;
	}

	private String process(String name, String nString) {
		int n = Integer.parseInt(nString);
		int L = name.length();
		String substring = "";
		int nValue = 0;

		for (int i = 0; i < L; i++) {
			for (int j = 1; j <= L - i; j++) {
				substring = name.substring(i, i + j);
				if (numConsecutiveConsonants(substring) >= n) {
//					System.out.println("substring = " + substring);
					nValue++;
				}
			}
		}

		return String.valueOf(nValue);
	}

	public static void main(String[] args) {
		A solution = new A();

		if (args.length == 1) {
			BufferedReader br = null;
			int numCases = 0;

			try {
				// Create the output file
				File outputFile = new File("output.out");
				if (!outputFile.exists()) {
					outputFile.createNewFile();
				}

				FileWriter fw = new FileWriter(outputFile.getAbsoluteFile());
				BufferedWriter bw = new BufferedWriter(fw);

				// Read input
				br = new BufferedReader(new FileReader(args[0]));

				// First line should contain the number of test cases
				String line = br.readLine();
				numCases = Integer.parseInt(line);

				long startTime = System.currentTimeMillis();

				// Following lines should contain test cases
				for (int i = 1; i <= numCases && line != null; i++) {
					line = br.readLine();
					String[] parts = line.split(" ");

					String outputLine = "Case #" + i + ": "
							+ solution.process(parts[0], parts[1]);
					System.out.println(outputLine);
					bw.write(outputLine + "\n");
				}

				long endTime = System.currentTimeMillis();

				System.out.println("Execution time = " + (endTime - startTime));

				br.close();
				bw.close();
			} catch (IOException e) {
				System.out.println("Input file not found!");
				e.printStackTrace();
			}
		} else {
			System.err.println("Input file required for processing");
		}
	}

}
