import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.HashSet;


public class RecycledNumbers {

    /**
     * Google Code Jam 2012: Problem C. Recycled Numbers
     * @author hullarb
     * @param args
     * @throws IOException 
     * @throws NumberFormatException 
     */
    public static void main(String[] args) throws NumberFormatException, IOException {
	BufferedReader input = new BufferedReader(new FileReader(args[0]));
	OutputStreamWriter out = new OutputStreamWriter(new FileOutputStream(args[0].contains("in")?args[0].replace("in", "out"):args[0] + ".out"));
	int testCases = Integer.parseInt(input.readLine());
	for(int i = 0; i < testCases; i++) {
	    String[] parts = input.readLine().split(" ");
	    int A = Integer.parseInt(parts[0]);
	    int B = Integer.parseInt(parts[1]);
	    int pairs = 0;
	    for(int j = A; j <B; j++) {
		pairs += possiblePairs(j,B);
	    }
	    out.write("Case #" + (i + 1) + ": " + pairs + "\n");
	}
	out.close();
	input.close();
    }

    private static int possiblePairs(int j, int b) {
	String digits = "" + j;
	int pairs = 0;
	HashSet<Integer> found = new HashSet<Integer>();
	for(int i = 0; i < digits.length() - 1; i++) {
	    int n = Integer.parseInt(digits.substring(digits.length() - 1 - i)
		    	+ digits.substring(0,digits.length() - 1 - i));
	    if(n > j && n <= b && !found.contains(n)) {
		found.add(n);
		pairs++;
	    }
	}
	return pairs;
    }

}
