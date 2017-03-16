import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class LastWord {
	public static void main(String[] args) throws Exception
    {
		String inPath = "/Users/Lynn/Downloads/A-small-attempt0.in.txt";
        String outPath = "/Users/Lynn/Downloads/A-small-attempt0.out.txt";

        Scanner input = new Scanner(new FileReader(inPath));

        File outFile = new File(outPath);
        BufferedWriter bw = new BufferedWriter(new FileWriter(outPath));
        
        int numCases = input.nextInt();
        for (int n = 0; n < numCases; n++)
        {
        	String S = input.next();
        	
        	char[] SArray = S.toCharArray();
        	int l = SArray.length;
        	ArrayList<Character> r = new ArrayList<Character>();
        	for (int i = 0; i < l; i ++) {
        		if (i == 0) {
        			r.add(SArray[i]);
        		} else {
        			if (SArray[i] >= r.get(0)) {
        				r.add(0, SArray[i]);
        			} else {
        				r.add(SArray[i]);
        			}
        		}
        	}

        	StringBuilder result = new StringBuilder(r.size());
        	for (Character c : r) {
        	  result.append(c);
        	}
        	String answer = result.toString();

            bw.write("Case #" + (n + 1) + ": " + answer);
            bw.newLine();
        }
        

        bw.close();
    }
}
