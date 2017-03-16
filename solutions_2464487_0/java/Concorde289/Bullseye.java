import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Bullseye {

	public static void main (String [] args) throws IOException{

		//Timing
		//long s = System.currentTimeMillis ();

		//Set up the reader and printer
		BufferedReader in = new BufferedReader (new FileReader ("IN.txt"));
		PrintWriter out = new PrintWriter (new BufferedWriter (new FileWriter ("OUT.txt")));
		int noCases = Integer.parseInt(in.readLine());
		//Insert reading here TODO edit
		
		//Solve the cases
		for (int caseNo = 1; caseNo <= noCases; caseNo++){
			String [] input = in.readLine().split(" ");
			int radius = Integer.parseInt(input[0]);
			int noPaint = Integer.parseInt(input[1]);
			String answer = getAnswer(radius, noPaint);
			out.println(String.format("Case #%d: %s", caseNo, answer));
			out.flush();//So I can see how my program is doing
		}
		//Insert code here TODO edit
		
		//Close the files
		in.close();
		out.close();

		//Timing
		//long e = System.currentTimeMillis();
		//System.out.println((e - s) / 1000.0);

		//Terminate the program
		System.exit(0);

	} //Main method
	
	static String getAnswer(int radius, int noPaint){
		radius++;
		int noRings = 0;
		while (noPaint >= 0){
			int area = radius * radius - (radius-1) * (radius-1);
			if (noPaint >= area){
				noPaint -= area;
				noRings++;
				radius+=2;
			}
			else{
				return String.valueOf(noRings);
			}
		}
		return "";
	}
}
