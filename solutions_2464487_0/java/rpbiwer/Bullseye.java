import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;


public class Bullseye {
	private static int nextIntLine(Scanner in) {
		return Integer.parseInt(in.nextLine());
	}

	public static void main(String[] args) throws FileNotFoundException {
		File f = new File("output.out");
		f.delete();
		PrintStream out = new PrintStream(f);
//		PrintStream out = System.out;

		Scanner in = new Scanner(new File("input.in"));
		int numCases = nextIntLine(in);
//		for(;;)System.out.println("\""+in.nextLine()+"\"");
		for(int i = 0; i < numCases; ++i) {
			out.printf("Case #%d: %d\n", i+1, getAnswer(in));
		}
		
		out.close();
		in.close();
	}

	private static long getAnswer(Scanner in) {
		long r = in.nextLong();
		long paint = in.nextLong();
		
		long res = 0;
		long paintUsed = 0;
		for(long i = r; paintUsed < paint; i += 2) {
			paintUsed += paintForRing(i);
			if(paintUsed <= paint) ++res;
		}
		
		return res;
	}

	private static long paintForRing(long i) {
		return 2*i + 1;
	}
}
