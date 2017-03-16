package roundc;

import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Pogo {
	
	public static boolean found = false;

	/**
	 * @param args
	 * @throws Exception
	 */
	public static void main(String[] args) throws Exception {

		// Open the file that is the first
		// command line parameter

		// FileInputStream fstream = new FileInputStream(args[0]);
		FileInputStream fstream = new FileInputStream("c:\\Jam\\2013-1c\\B-small-attempt0 (1).in");

		// Get the object of DataInputStream
		DataInputStream in = new DataInputStream(fstream);
		BufferedReader br = new BufferedReader(new InputStreamReader(in));
		String strLine;

		FileWriter outFile = new FileWriter("c:\\Jam\\2013-1c\\output2.txt");
		PrintWriter out = new PrintWriter(outFile);

		long t = new Long(br.readLine());

		for (int i = 0; i < t; i++) {
			strLine = br.readLine();
			StringTokenizer token = new StringTokenizer(strLine);

			int x = new Integer(token.nextToken());
			int y = new Integer(token.nextToken());

			String string = handleCase(x, y);

			long index = i + 1;

			String strToPrint = "Case #" + index + ": " + string;
			out.println(strToPrint);
			System.out.println(strToPrint);
		}

		in.close();
		out.close();
	}

	private static String handleCase(int x, int y) {	
		
		boolean found = false;
		
		int jump = 1;
		
		Set<Dir> pairs = new HashSet<>();
		
		Dir firstPair = new Dir(0, 0);
		
		pairs.add(firstPair);
		
			
		while (!found) {
			
			Set<Dir> newPairs = new HashSet<>();
			
			
			for (Dir pair : pairs) {
				if (pair.a == x && pair.b == y) {
					found = true;
					
					return pair.str;
				}
									
				Dir eastDir = new Dir(pair.a + jump, pair.b, pair.str + "E");
				
				newPairs.add(eastDir);
				
				Dir westDir = new Dir(pair.a - jump, pair.b, pair.str + "W");
				
				newPairs.add(westDir);	
				
				Dir northDir = new Dir(pair.a, pair.b + jump, pair.str + "N");
				
				newPairs.add(northDir);				
				
				Dir southDir = new Dir(pair.a, pair.b - jump, pair.str + "S");
				
				newPairs.add(southDir);			
			}
	
			jump++;
			pairs = newPairs;
		}			
		
		return "";
	}
}
