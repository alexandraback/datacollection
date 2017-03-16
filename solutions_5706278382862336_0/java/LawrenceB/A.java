import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class A {

	public static void main(String[] args) {
		Scanner s = null;
		int t;
		List<String> outputLines = new ArrayList<String>();

		try {
			s = new Scanner(new File("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return;
		}
		t = s.nextInt();
		s.nextLine();
		
		for (int i = 0; i < t; i++) {
			String str = s.nextLine();
			String ints[] = str.split("/");
			
			long p = Long.parseLong(ints[0]);
			long q = Long.parseLong(ints[1]);
			int r = solve(p,q, 0);
			if (r == -1)
				outputLines.add("Case #" + (i+1) + ": impossible");
			else
				outputLines.add("Case #" + (i+1) + ": " + r);
		}
		try {
			writeOutput(outputLines);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		s.close();
	}
	public static int solve(long p, long q, int gen) {
	
		if (p > q)
			return -1;
		else {
			boolean valid =false;
			for (int i = 0; i < 40; i++) {
				if (q == Math.pow(2, i))
					valid = true;
			}
			if (!valid)
				return -1;
			else if (p == 1 && q == 1)
				return gen;
			else if	( p==1 )
				return solve(p,q/2,gen+1);
			else if (p > q/2)
				return gen+1;
			else
				return solve(p,q/2,gen+1);

		}

	}
	
	public static void writeOutput(List<String> lines) throws IOException {
		if (lines == null)
			return;
		PrintWriter writer = new PrintWriter("output.txt", "UTF-8");
		for (String line : lines) {
			writer.println(line);
		}
		writer.close();
	}

}
