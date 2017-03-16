

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;
import java.util.Set;

import com.google.common.collect.Sets;

public class C {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/C-small-attempt0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int c = 1; c <= cases; c++) {
			int a = in.nextInt();
			int b = in.nextInt();
			int count = 0;
			for (int i = a; i < b; i++) {
				String is = String.valueOf(i);
				Set<Integer> matches = Sets.newHashSet();
				for (int j = 1; j < is.length(); j++) {
					is = is.substring(1) + is.charAt(0);
					int t = Integer.parseInt(is);
					if (t > i && t <= b && !matches.contains(t)) {
						count++;
						matches.add(t);
					}
				}
			}
			out.print("Case #"+c+": " + count);
			out.println();
		}
		out.close();
	}
}
