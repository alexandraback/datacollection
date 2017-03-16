import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;
import java.util.regex.Pattern;

import javax.management.Query;



class Consonants {
	
	private int T;
	private final String consonants = "aeiou";
	
	public void solve(String in, String out) throws IOException {
		
		Scanner scanner = new Scanner(new File(in));
		Writer outFile = new FileWriter(out);
				
		T = Integer.valueOf(scanner.nextLine());
		
		for (int i = 1; i <= T; ++i) {			

			String str = scanner.next();
			int n = scanner.nextInt();
			
			int number = 0;
			for (int j = 0; j < str.length(); ++j) {
				for (int k = j; k < str.length(); ++k) {
					
					int nConsonants = 0;
					
					for (int m = j; m <=k; ++m) {
						if (consonants.indexOf(str.charAt(m)) < 0) {
							nConsonants++;
							if (nConsonants >= n) {								
								number++;
								break;
							}
						}
						else {
							nConsonants = 0;
						}
					}
				}
			}
			
			String resStr = "Case #"+i+": " + number+'\n';
			outFile.write(resStr);
			System.out.println(resStr);	
		}
		
		outFile.flush();
		outFile.close();		
	}


	public static void main(String[] args) {
		Consonants сonsonants = new Consonants();

		try {
			сonsonants.solve("A-small-attempt0-2.in.txt", "out");
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}