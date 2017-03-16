import java.io.*;
import java.util.*; 

/** 
 * @author Olaf Matyja olafmat@gmail.com 
 */
public class Round1CA {

	int cases;
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int curCase = 0; curCase < cases; curCase++) {
			int R = scanner.nextInt();
			int C = scanner.nextInt();
			int W = scanner.nextInt();
			int shotsHor = C / W;
			int res = shotsHor * R + (W - 1);
			if (C % W > 0)
				res++;
			out.println("Case #" + (curCase + 1) + ": " + res);			
		}
	}
	
	Round1CA() throws IOException {
		/*String sampleText = "4\r\n" + 
				"1 4 2\r\n" + 
				"1 7 7\r\n" + 
				"2 5 1\r\n" +
				"1 7 3\r\n"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-small-attempt0.in"));
		PrintStream out = new PrintStream("out-A-small.txt");
		*/
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-large.in"));
		PrintStream out = new PrintStream("out-A-large.txt");
		

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round1CA();
	}	
	
}
