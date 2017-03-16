import java.io.*;
import java.util.*; 

public class Round0C {

	int cases;

	final int P1 = 0;
	final int Pi = 1;
	final int Pj = 2;
	final int Pk = 3;
	final int M1 = 4;
	final int Mi = 5;
	final int Mj = 6;
	final int Mk = 7;
	
	String[] symbols = {"1", "i", "j", "k", "-1", "-i", "-j", "-k"};
	int mulTable[][] = {{P1, Pi, Pj, Pk}, {Pi, M1, Pk, Mj}, {Pj, Mk, M1, Pi}, {Pk, Pj, Mi, M1}};	
	
	int mul(int a, int b) {
		boolean signA = a >= 4;
		boolean signB = b >= 4;
		int res = mulTable[a & 3][b & 3];
		if (signA != signB)
			res ^= 4;
		return res;
	}

	void process(Scanner scanner, PrintStream out) throws IOException {
		cases = scanner.nextInt();
		scanner.nextLine();
		
		for (int n = 0; n < cases; n++) {
			long L = scanner.nextLong();
			long X = scanner.nextLong();
			scanner.nextLine();
			String str = scanner.nextLine();
			
			long exp = 12 + (X % 4);
			if (exp > X)
				exp = X;
			
			int m = P1;
			boolean wasI = false;
			boolean wasJ = false;
			for (int rep = 0; rep < exp; rep++) {
				for (int i = 0; i < str.length(); i++) {
					char z = str.charAt(i);
					int v = "1ijk".indexOf(z);
					m = mul(m, v);
					if (m == Pi && !wasI)
						wasI = true;
					if (m == Pk && wasI && !wasJ)
						wasJ = true;					
				}
			}
			boolean passed = wasI && wasJ && m == M1;
			
			out.println("Case #" + (n + 1) + ": " + (passed ? "YES" : "NO"));
		}
	}
	
	Round0C() throws IOException {
		/*String sampleText = "5\r\n" + 
				"2 1\r\n" + 
				"ik\r\n" + 
				"3 1\r\n" + 
				"ijk\r\n" + 
				"3 1\r\n" + 
				"kji\r\n" + 
				"2 6\r\n" + 
				"ji\r\n" + 
				"1 10000\r\n" + 
				"i"; 
		Scanner in = new Scanner(sampleText);
		PrintStream out = System.out;*/
		
		
		/*Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\C-small-attempt0.in"));
		PrintStream out = new PrintStream("out-C-small.txt");*/
		
		
		Scanner in = new Scanner(new File("C:\\Users\\Olaf\\Downloads\\C-large.in"));
		PrintStream out = new PrintStream("out-C-large.txt");
		

		
		process(in, out);

		in.close();
		out.close();
	}	
	
	public static void main(String[] args) throws IOException {
		new Round0C();
	}	
	
}
