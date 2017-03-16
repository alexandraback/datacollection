import java.util.*;
import java.io.*;

public class tongue {
	private static BufferedReader in;
	private static PrintWriter out;
	public static final String NAME = "A-small-attempt1";

	private static String conv = "yhesocvxduiglbkrztnwjpfmaq";
	
	private static void main2() throws IOException {
		char [] arr = conv.toCharArray();
		
		String s = in.readLine();
		for (char c : s.toCharArray()) {
			if (c == ' ') out.print (' ');
			else out.print (arr [c - 'a']);
		}
		out.println();
	}

	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader (NAME + ".in"));
		out = new PrintWriter(new BufferedWriter(new FileWriter(NAME + ".out")));

		int numCases = Integer.parseInt (in.readLine());
		for (int test = 1; test <= numCases; test++) {
			out.print("Case #" + test + ": ");
			main2();
		}

		out.close();
		System.exit(0);
	}
}
