import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;


public class Driver {

	static BufferedWriter out;
	static int testCount;
	
	static char[] vowels = {'a', 'e', 'i', 'o', 'u'};
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("/Users/blazejczapp/workspace/1C1/src/input.in"));
		out = new BufferedWriter(new FileWriter("/Users/blazejczapp/workspace/1C1/src/output.out"));

		String line;
		
		line = br.readLine();
		testCount = Integer.parseInt(line);
		
		for (int i = 0; i < testCount; i++) {
			
			if (i > 0) {
				out.newLine();
			}
			
			line = br.readLine();
			String[] values = line.split(" ");
			String name = values[0];
			int n = Integer.parseInt(values[1]);
			
			int result = findSubstrings(name, n);
			
			out.write("Case #" + (i + 1) + ": " + result);
			System.out.println("Case #" + (i + 1) + ": " + result);
		}

		br.close();
		out.close();
	}

	private static int findSubstrings(String name, int n) {
		char[] letters = name.toCharArray();
		int count = 0;
		for (int i = 0; i < name.length(); i++) {
			int consecutiveCons = 0;
			boolean foundStreak = false;
			for (int j = i; j < name.length(); j++) {
				if (!foundStreak) {
					if (!isVowel(letters[j])) {
						consecutiveCons++;
						if (consecutiveCons == n) {
							foundStreak = true;
							count++;
						}
					} else {
						consecutiveCons = 0;
					}
				} else {
					count++;
				}
			}
		}
		
		return count;
	}
	
	private static boolean isVowel(char letter) {
		for (int i = 0; i < vowels.length; i++)
			if (vowels[i] == letter) {
				return true;
			}
		
		return false;
	}

}
