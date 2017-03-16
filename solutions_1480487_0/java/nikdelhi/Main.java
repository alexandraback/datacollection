import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;


public class Main {
	
	public static void main(String args[]) throws NumberFormatException, IOException {
		
		BufferedReader in = new BufferedReader(new FileReader("A-small-attempt2.in"));
		PrintWriter out = new PrintWriter(new FileWriter("out.txt")); 
		SafetyNumbers x = new SafetyNumbers();
		
		String inString = "";
		int t = Integer.parseInt(in.readLine());
		
		for(int i = 0; i < t; i++) {
			
			inString = in.readLine();
			String inp[] = inString.split(" ");
			int n = Integer.parseInt(inp[0]);
			int[] judgesScore = new int[n];
			for(int j = 0; j < n; j++) {
				
				judgesScore[j] = Integer.parseInt(inp[j+1]);
				
			}
			out.println("Case #" + (i+1) + ": " + x.get(n,judgesScore));
			
		}
		in.close();
		out.close();
		
	}

}
