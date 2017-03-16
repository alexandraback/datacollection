

import java.io.File;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;

public class B {

//	public final static String INPUT_FILE_NAME = "test.in";
	public final static String INPUT_FILE_NAME = "B-small-attempt1.in";
//	public final static String INPUT_FILE_NAME = "B-large.in";
	
	public FileWriter outputWriter;
	public Scanner scanner;
	public StringBuilder output = new StringBuilder();
	
	public void run() throws Exception {
		// Commons variables
		int testCaseNumber = 0;
		// Test start
		{
			int nbTests = Integer.parseInt(scanner.nextLine());
			
			for (testCaseNumber = 0; testCaseNumber < nbTests; testCaseNumber++) {
				double testCaseResult = 0;
				String[] line = scanner.nextLine().split(" ");
				int k = Integer.parseInt(line[0]);
				int l = Integer.parseInt(line[1]);
				int s = Integer.parseInt(line[2]);
				String keys = scanner.nextLine();
				String target = scanner.nextLine();
				HashMap<Character, Integer> map = new HashMap<Character, Integer>(k);
				for (int i = 0; i < k; i++) {
					Character character = keys.charAt(i);
					Integer count = map.get(character);
					if (count != null) {
						map.put(character, count + 1);
					} else {
						map.put(character, 1);
					}
				}
				boolean possible = true;
				double chance = 1.;
				for (int i = 0; i < l; i++) {
					Character character = target.charAt(i);
					if (!map.containsKey(character)) {
						possible = false;
						break;
					}
					chance *= map.get(character) / (double)k;
				}
				if (possible) {
					int index = target.indexOf(target.charAt(0), 1);
					while (index > 0 && index < l) {
						boolean ok = true;
						if (index >= l - index) {
							for (int i = 1; i < index; i++) {
								if (index + i < l) {
									if (target.charAt(i) != target.charAt(index) + i) {
										ok = false;
										break;
									}
								}
							}
						} else {
							ok = false;
						}
						if (ok) {
							break;
						} else {
							index = target.indexOf(target.charAt(0), index + 1);
						}
					}
					int realTargetLength = l;
					if (index > 0) {
						realTargetLength -= index;
					}
					int maxPossible = ((s / realTargetLength) + (s / l)) / 2;
					testCaseResult = maxPossible * (1 - chance);
				}
				String result = String.format(Locale.ENGLISH, "Case #%d: %.7f\n", testCaseNumber+1, testCaseResult);
				output.append(result);
			}
		}
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////
	
	public void init() throws Exception {
		File temp = new File("output/");
		if (!temp.exists()) {
			temp.mkdir();
		}
		// Output file
		outputWriter = new FileWriter("output/output.txt", false);
		// Input file
		scanner = new Scanner(new File("resources/" + INPUT_FILE_NAME));
	}

	public void stop() throws Exception {
		// Closing files
		outputWriter.write(output.toString(), 0, output.length());
		scanner.close();
		outputWriter.close();
	}
	
	public static void main(String[] args) throws Exception {
		B instance = new B();
		long start = System.currentTimeMillis();
		
		instance.init();
		instance.run();
		instance.stop();
		
		System.out.println("Finished in " + (System.currentTimeMillis() - start) + " ms");
	}
	
}
