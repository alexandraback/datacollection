

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import com.google.common.base.Joiner;

// Using the Google Guava library.
public class B {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/B-large.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    final int n = in.nextInt();
		    boolean [] ha = new boolean[2501];
		    for (int i = 0; i < 2*n - 1; i++) {
		        for (int j = 0; j < n; j++) {
		            int h = in.nextInt();
		            ha[h] = !ha[h];
		        }
		    }
		    List<Integer> res = new ArrayList<>();
		    for (int i = 0; i < ha.length && res.size() < n; i++) {
		        if (ha[i]) {
		            res.add(i);
		        }
		    }
			String ans = "Case #"+cs+": " + Joiner.on(' ').join(res);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
}
