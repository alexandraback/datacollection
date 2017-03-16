package monekeys;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

public class App {
	public static final String INPUT_FILE_NAME = "input.txt";
	public static final String OUTPUT_FILE_NAME = "output.txt";
	
	public static void main(String[] args) {
		long beginTime = System.currentTimeMillis();
		
		try {
			String inputName = INPUT_FILE_NAME;
			String outputName = OUTPUT_FILE_NAME;
		
			if (args.length > 0)
				inputName = args[0];
		
			if (args.length > 1)
				outputName = args[1];
		
			try (BufferedReader reader = new BufferedReader(new FileReader(new File(inputName)))) {
				try (PrintWriter writer = new PrintWriter(outputName)) {
					int nCases = Integer.parseInt(reader.readLine());
				
					for (int nCase = 0; nCase < nCases; ++nCase) {
						String[] data = reader.readLine().split(" ");
						int k = Integer.parseInt(data[0]);
						int l = Integer.parseInt(data[1]);
						int s = Integer.parseInt(data[2]);
						String keyboard = reader.readLine();
						String target = reader.readLine();
						
						System.out.println(keyboard);
						System.out.println(target);
						
						Map<String, Integer> letters = new HashMap<String, Integer>();
						
						for (int n = 0; n < k; ++ n) {
							String c = "" + keyboard.charAt(n);
							if (letters.containsKey(c))
								letters.put(c, letters.get(c) + 1);
							else
								letters.put(c, 1);
						}
						
						boolean possible = true;
						float chance = 1f;
						float bananas = 0f;
						
						for (int n = 0; n < l; ++n) {
							String c = "" + target.charAt(n);
							if (letters.containsKey(c))
								chance *= (float) letters.get(c) / (float)k; 
							else {
								possible = false;
								break;
							}
						}
						
						if (possible) {
							int o = 0;
							for (int n1 = 1; n1 < l; ++n1) {
								boolean over = true;
								for (int n2 = 0; n2 < l - n1; ++n2) {
									if (target.charAt(n2) != target.charAt(n1+n2)) {
										over = false;
										break;
									}
								}
								
								if (over) {
									o = l - n1;
									break;
								}
							}
							
							/*if (o > s - l)
								o = s - l;*/
							
							int required = 0;
							if (s == l)
								required = 1;
							else if (s > l)
								required = 1 + (s - l) / (l - o);
							bananas = (float)required - (float)required * chance;							
						}
						
						
						System.out.println("Case #" + (nCase + 1) + ": " + bananas);
						writer.println("Case #" + (nCase + 1) + ": " + bananas);
					}
				}
			}
		} catch (Exception e) {
			e.printStackTrace();
		} 
		
		long endTime = System.currentTimeMillis();
		
		System.out.println(String.format("Done. Spend %d ms", endTime - beginTime));
	}
}
