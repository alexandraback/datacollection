import java.io.*;
import java.util.*; 

public class Round0D {

	int cases;
	int[] minWidth = {0,0,1,2,3,3,4}; 
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			int X = scanner.nextInt();
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			
			boolean always = true;
			if ((R*C) % X != 0)
				always = false;
			else if (X >= 7)
				always = false;
			else if (Math.min(R, C) < minWidth[X])
				always = false;
			else if (R+C < X)
				always = false;
			
			//out.println(X +" " + R + " " + C + " " +  (always ? "GABRIEL" : "RICHARD"));
			out.println("Case #" + (n + 1) + ": " + (always ? "GABRIEL" : "RICHARD"));
		}
	}
	
	Round0D() throws IOException {
		
		/*String sampleText = "4\r\n" + 
				"2 2 2\r\n" + 
				"2 1 3\r\n" + 
				"4 4 1\r\n" + 
				"3 2 3";*/

		/*String sampleText = "15\r\n" +
				"4 4 1\r\n"+
				"4 4 2\r\n"+
				"4 4 3\r\n"+
				"4 4 4\r\n"+
				"5 5 1\r\n"+
				"5 5 2\r\n"+
				"5 5 3\r\n"+
				"5 5 4\r\n"+
				"5 5 5\r\n"+
				"6 6 1\r\n"+
				"6 6 2\r\n"+
				"6 6 3\r\n"+
				"6 6 4\r\n"+
				"6 6 5\r\n"+
				"6 6 6\r\n";*/
		
		/*String sampleText = "64\r\n" + 
				"1 1 1\r\n" + 
				"1 1 2\r\n" + 
				"1 1 3\r\n" + 
				"1 1 4\r\n" + 
				"1 2 1\r\n" + 
				"1 2 2\r\n" + 
				"1 2 3\r\n" + 
				"1 2 4\r\n" + 
				"1 3 1\r\n" + 
				"1 3 2\r\n" + 
				"1 3 3\r\n" + 
				"1 3 4\r\n" + 
				"1 4 1\r\n" + 
				"1 4 2\r\n" + 
				"1 4 3\r\n" + 
				"1 4 4\r\n" + 
				"2 1 1\r\n" + 
				"2 1 2\r\n" + 
				"2 1 3\r\n" + 
				"2 1 4\r\n" + 
				"2 2 1\r\n" + 
				"2 2 2\r\n" + 
				"2 2 3\r\n" + 
				"2 2 4\r\n" + 
				"2 3 1\r\n" + 
				"2 3 2\r\n" + 
				"2 3 3\r\n" + 
				"2 3 4\r\n" + 
				"2 4 1\r\n" + 
				"2 4 2\r\n" + 
				"2 4 3\r\n" + 
				"2 4 4\r\n" + 
				"3 1 1\r\n" + 
				"3 1 2\r\n" + 
				"3 1 3\r\n" + 
				"3 1 4\r\n" + 
				"3 2 1\r\n" + 
				"3 2 2\r\n" + 
				"3 2 3\r\n" + 
				"3 2 4\r\n" + 
				"3 3 1\r\n" + 
				"3 3 2\r\n" + 
				"3 3 3\r\n" + 
				"3 3 4\r\n" + 
				"3 4 1\r\n" + 
				"3 4 2\r\n" + 
				"3 4 3\r\n" + 
				"3 4 4\r\n" + 
				"4 1 1\r\n" + 
				"4 1 2\r\n" + 
				"4 1 3\r\n" + 
				"4 1 4\r\n" + 
				"4 2 1\r\n" + 
				"4 2 2\r\n" + 
				"4 2 3\r\n" + 
				"4 2 4\r\n" + 
				"4 3 1\r\n" + 
				"4 3 2\r\n" + 
				"4 3 3\r\n" + 
				"4 3 4\r\n" + 
				"4 4 1\r\n" + 
				"4 4 2\r\n" + 
				"4 4 3\r\n" + 
				"4 4 4\r\n";*/
		/*Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\D-small-attempt0.in"));
		PrintStream out = new PrintStream("out-D-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\D-large.in"));
		PrintStream out = new PrintStream("out-D-large.txt");
		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0D();
	}	
	
}
