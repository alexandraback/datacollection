package roundonea2013;

import java.io.*;
import java.util.*;


public class Bullseye {
	public static void main(String args[]) throws Exception {
		BufferedReader in = new BufferedReader(new FileReader(new File(
				"src/roundonea2013/Bullseye.in")));
		FileWriter out = new FileWriter(new File(
				"src/roundonea2013/Bullseye.out"));

		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			long radius = Long.parseLong(st.nextToken());
			long paint = Long.parseLong(st.nextToken());
			
			long answer = (long) Math.sqrt(paint/2);
			while (2 * answer * answer + 2 * radius * answer + answer > paint) {
				answer--;
			}
			
			//Formatter format = new Formatter();
			//format.format("%.5f", answer);							 
			out.write("Case #" + t + ": " + answer + "\n");
		}

		in.close();
		out.close();
	}
}
