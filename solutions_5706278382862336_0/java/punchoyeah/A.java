package _2014.round._1c;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

	public static int solution (long P, long Q, int G) {		
		if(P == Q)
			return 1;
		
		for(int g=1; g<=G; g++) {
			if (Q%2 != 0) 
				return -1;
			
			Q = Q/2;
			if((P==Q) || (P>Q  && solution(P-Q, Q, G-g) != -1))
				return g;
		}
		
		return -1;
	}
	
	public static void main(String[] args) throws IOException {
		
		String dir = System.getProperty("user.dir")+"\\src\\_2014\\round\\_1c\\";
		Scanner reader = new Scanner(new FileReader(dir+"A-small-attempt0.in"));
		PrintWriter writer = new PrintWriter(new FileWriter(dir+"A-small-attempt0.out"));
		
	//	Scanner reader = new Scanner(new FileReader(dir+"A-large.in"));
	//	PrintWriter writer = new PrintWriter(new FileWriter(dir+"A-large.out"));	
		
	//	Scanner reader=new Scanner(System.in);
		
		int numOfCases = Integer.parseInt(reader.nextLine());
		for(int i=1; i<=numOfCases; i++) {
			String P_Q = reader.nextLine();
			int split_index = P_Q.indexOf('/');
			long P = Long.parseLong(P_Q.substring(0, split_index));
			long Q = Long.parseLong(P_Q.substring(split_index+1));
			
	//		System.out.println("P: " + P + "   Q: " + Q);
			
			int g = solution(P, Q, 40);
			String result = (g == -1) ? "impossible" : Integer.toString(g);
		//	System.out.println("Case #"+i+": " + result);
			writer.println("Case #"+i+": "+result);
		}
		
		reader.close();
		writer.flush();
		writer.close();
	}

}
