package codejam.round1a;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashSet;

/**
 * @author Cheng Chen
 * @since Apr 15, 2016
 */

public class TheLastWord {
	
	public static void main(String[] args) throws IOException {
		int casetotal = 0;
		int casenumber = 1;
		int totalline = 0;
		String line = "";
		
		try (FileReader fr = new FileReader("data/A-small-attempt0.in"); BufferedReader br = new BufferedReader(fr); FileWriter fw = new FileWriter("data/A-small-attempt0.out"); PrintWriter bw = new PrintWriter(fw);) {
			while ((line = br.readLine()) != null) {
				if (totalline == 0) {
					casetotal = Integer.parseInt(line);
				} else if (casenumber > casetotal) {
					System.out.println("###Error: The casenumber has problem!!!");
					System.out.println("###Error: This error happened in line number" + totalline);
					System.exit(0);
				} else {
					/**
					 *  processing
					 */
					StringBuilder sb=new StringBuilder();
					for(char c:line.toCharArray()){
						if(sb.length()==0) sb.append(c);
						else if(c>=sb.charAt(0))
							sb.insert(0, c);
						else
							sb.append(c);
					}
					bw.println("Case #"+casenumber+": "+sb.toString());
					casenumber++;
				}
				totalline++;
			}
		}
		
	}
	
}
