package round1a;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	private static final String PATH = "src\\ressources";
	private static final String PROBLEM = "A";
	private static final String VERSION = "small-attempt0"; //small-attempt0
	private static final String EXT_IN = "in";
	private static final String EXT_OUT = "out";
	
	public String solve(Scanner in) {
		int radius = in.nextInt() + 1;
		int mlBlackPaint = in.nextInt();
		
		int nbCircle = 0;
		mlBlackPaint -= ((radius)*(radius)) - ((radius-1)*(radius-1));
		radius += 2;
		
		while(mlBlackPaint >= 0) {
			nbCircle++;
			mlBlackPaint -= ((radius)*(radius)) - ((radius-1)*(radius-1));
			radius += 2;
		}
		
		return String.valueOf(nbCircle);
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader(getCompletPath(EXT_IN)));
		PrintWriter out = new PrintWriter(new FileWriter(getCompletPath(EXT_OUT)));
		
		int nbTestCase = in.nextInt();
		A pb = new A();
		for(int i = 0; i < nbTestCase; i++) {
			out.println("Case #" + (i+1) + ": " + pb.solve(in));
			out.flush();
		}
		
		in.close();
		out.close();
	}
	
	private static String getCompletPath(String ext) {
		return PATH + "\\" + PROBLEM + "-" + VERSION + "." + ext;
	}
}
