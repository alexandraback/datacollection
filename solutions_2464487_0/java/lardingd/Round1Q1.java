package qualifierFun;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Round1Q1 {
	
	public static void main(String[] args) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter("output1.txt")); 
			BufferedReader in  = new BufferedReader(new FileReader("input.txt"));
			int answer =1;
			String strLine = in.readLine();
			int totalCases = Integer.parseInt(strLine);
			for(int i = 0; i < totalCases; i++) {
				strLine = in.readLine();
				String inputs[] = strLine.split(" ");
			    long r = Long.parseLong(inputs[0]);
			    long r2 = r*r;
			    long t = Long.parseLong(inputs[1]);
			    int rings = 1;
			    t -= (2*r)+1;
			    long x = r+2; 
			    while (t >= 0) {
//			    	System.out.println(String.format("%s %s", t, rings));
			    	rings++;
			    	long area = 2*x+1;
					t -=  area;
					x += 2;
			    }
			    rings--;
				System.out.print(String.format("Case #%s: %s\n", answer, rings));
				out.write(String.format("Case #%s: %s\n", answer, rings));
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
}
