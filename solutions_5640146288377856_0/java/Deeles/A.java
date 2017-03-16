import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class A {
	
	private int solve(int R, int C, int W) {
		int hit = W;
		hit += (R-1) * (C/W);
		hit += C/W - 1;
		if (C % W == 0) {
		} else {
			hit++;
		}
		return hit;
	}

	public static void main(String[] args) throws FileNotFoundException {
		A a = new A();
		Scanner s = new Scanner(new File("inA.in"));
		PrintWriter pw = new PrintWriter(new File("outA.out"));
		int c = s.nextInt();
		for (int i = 0; i < c; i++) {
			pw.println("Case #" + (i + 1) + ": " + a.solve(s.nextInt(), s.nextInt(), s.nextInt()));
		}
		pw.close();
	}
	
}
