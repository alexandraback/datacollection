import java.io.*;
import java.util.*; 

public class Round0A {

	int cases;
	
	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			int sMax = scanner.nextInt();
			String text = scanner.next();
			int[] s = new int[sMax + 1];
			for (int i = 0; i <= sMax; i++)
				s[i] = Integer.parseInt(text.substring(i, i+1));
			int clapping = 0;
			int add = 0;
			for (int i = 0; i <= sMax; i++) {
				int added = 0;
				if (clapping < i) {
					added = i - clapping;					
				} else
					added = 0;
				add += added;
				clapping += s[i] + added;
			}
			out.println("Case #" + (n + 1) + ": " + add);
		}
	}
	
	Round0A() throws IOException {
		/*String sampleText = "4\r\n" + 
				"4 11111\r\n" + 
				"1 09\r\n" + 
				"5 110011\r\n" + 
				"0 1"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-small-attempt0.in"));
		PrintStream out = new PrintStream("out-A-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\A-large.in"));
		PrintStream out = new PrintStream("out-A-large.txt");
		

		
		process(in, out);
		
		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0A();
	}	
	
}
