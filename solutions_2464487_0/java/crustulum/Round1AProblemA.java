import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class Round1AProblemA {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		int Case = 1;
		PrintStream out;
		out = new PrintStream(new FileOutputStream("1AoutputA.txt"));
		while(Case <= T){
			int r = sc.nextInt();
			int t = sc.nextInt();
			double p = (Math.sqrt(Math.pow(2*r-1, 2)+8*t));
			int a = (int)(((1-2*r)+p)/4);
			out.println("Case #" + Case + ": " + a);
			Case++;
		}
		System.setOut(out);
	}

}
