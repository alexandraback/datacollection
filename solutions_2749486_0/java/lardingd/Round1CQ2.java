package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Round1CQ2 {

	/**
	 * Brute force since due to input will always be under 201 of 500 limit
	 */
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output1c2.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			int totalCases = Integer.parseInt(strLine);
			for(int i = 0; i < totalCases; i++) {
				strLine = in.readLine();
				String inputs[] = strLine.split(" ");
				int x = Integer.parseInt(inputs[0]);
				int y = Integer.parseInt(inputs[1]);
				String way = goX(x) + goY(y);
				System.out.print(String.format("Case #%s: %s\n", answer, way));
				out.write(String.format("Case #%s: %s\n", answer, way));
				answer++;
			}
			out.close();
			in.close();
		} catch (FileNotFoundException e) {
			System.out.println("I'd want to know");
		} catch (IOException e) {
			System.out.println("I'd want to know io");
		}
		System.out.println("done");
	}
	
	private static String goX(int x) {
		if (x == 0) return "";
		String theWay = x < 0 ? "EW" : "WE";
		if ( x < 0) {
			x = -x;
		}
		StringBuilder returnString = new StringBuilder();
		for(int i = 0; i < x; i++ ) {
			returnString.append(theWay);
		}
		
		return returnString.toString();
	}
	
	private static String goY(int x) {
		if (x == 0) return "";
		String theWay = x < 0 ? "NS" : "SN";
		if ( x < 0) {
			x = -x;
		}
		StringBuilder returnString = new StringBuilder();
		for(int i = 0; i < x; i++ ) {
			returnString.append(theWay);
		}

		return returnString.toString();
	}

}
