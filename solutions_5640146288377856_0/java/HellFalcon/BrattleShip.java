import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.Scanner;

public class BrattleShip {
	
	static int hits(int c, int w) {
		if (w == 0)
			return 0;
		if (c/w > 1)
			return hits(c - w*(c/w-1), w) + (c/w-1);
		else
			return hits(c - (2*w-c), w - (2*w-c)) + (2*w-c);
	}
	
	static int hits(int r, int c, int w) {
		return hits(c, w) + (r-1)*(c/w);
	}
	
	public static void main(String[] args) {
		try {
			Scanner in = new Scanner(new BufferedReader(new FileReader(new File("A-small-attempt1.in")), 256 << 10));
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("output.txt")), 256 << 10);

			int testsNumber = in.nextInt();
			for (int testId = 1; testId <= testsNumber; testId++) {
				int r = in.nextInt();
				int c = in.nextInt();
				int w = in.nextInt();
				out.append("Case #" + testId + ": " + hits(r, c, w));
				out.append("\n");
			}
			in.close();
			out.close();
		}
		catch (RuntimeException rte) {
			throw rte;
		}
		catch (Exception e) {
			System.err.println("Error:" + e.getMessage());
		}
	}
}
