

import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

// Using the Google Guava library.
public class C {

	public static void main(String [] args) throws IOException {
		String inputFile = "src/C-small-attempt0.in";
		Scanner in = new Scanner(new File(inputFile));
		PrintStream out = new PrintStream(inputFile.substring(0, inputFile.length()-2)+"out");
		int cases = in.nextInt();
		for (int cs = 1; cs <= cases; cs++) {
		    int n = in.nextInt();
		    String [][] topics = new String[n][2];
            Set<String> first = new HashSet<>();
            Set<String> second = new HashSet<>();
		    for (int i = 0; i < n; i++) {
                topics[i][0] = in.next();
                first.add(topics[i][0]);
                topics[i][1] = in.next();
                second.add(topics[i][1]);
		    }
		    int minBits = n;
		    for (int i = 1; i < (1 << n); i++) {
		        minBits = Math.min(minBits, minBits(i, n, topics, first.size(), second.size()));
		    }
			String ans = "Case #"+cs+": " + (n - minBits);
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		in.close();
	}
	
	private static int minBits(int i, int n, String[][] topics, int firstSize, int secondSize) {
	    int mask = 1;
	    int bits = 0;
        Set<String> first = new HashSet<>();
        Set<String> second = new HashSet<>();
	    for (int j = 0; j < n; j++) {
	        if ((i & mask) != 0) {
	            bits++;
                first.add(topics[j][0]);
                second.add(topics[j][1]);
	        }
	        mask *= 2;
	    }
	    if (first.size() == firstSize && second.size() == secondSize) {
	        return bits;
	    }
	    return n;
	}
}
