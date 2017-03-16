/**
 * 
 */
package hu.herba.codejam.cj2012.qualification;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.PrintWriter;

import hu.herba.codejam.AbstractCodeJamBase;

/**
 * Googlerese <h1>Input</h1>
 * 
 * <p>
 * The first line of the input gives the number of test cases, T. T test cases
 * follow, one per line.
 * 
 * Each line consists of a string G in Googlerese, made up of one or more words
 * containing the letters 'a' - 'z'. There will be exactly one space (' ')
 * character between consecutive words and no spaces at the beginning or at the
 * end of any line.
 * </p>
 * 
 * <h1>Output</h1>
 * 
 * <p>
 * For each test case, output one line containing "Case #X: S" where X is the
 * case number and S is the string that becomes G in Googlerese.
 * 
 * <h1>Limits</h1>
 * 
 * <p>
 * 1 ≤ T ≤ 30.<br/>
 * G contains at most 100 characters.<br/>
 * None of the text is guaranteed to be valid English.
 * </p>
 * 
 * @author csorbazoli
 */
public class ProblemA extends AbstractCodeJamBase {

    public static void main(String[] args) {
	new ProblemA(args);
    }

    int T; // number of test case
    // googlerese letters to english letter a-z
    // ------------------abcdefghijklmnopqrstuvwxyz
    private static final String translator = "yhesocvxduiglbkrztnwjpfmaq";

    public ProblemA(String[] args) {
	super(args, AbstractCodeJamBase.READER_TYPE);
    }

    /*
     * (non-Javadoc)
     * 
     * @see hu.herba.codejam.AbstractCodeJamBase#process(java.io.BufferedReader,
     * java.io.PrintWriter)
     */
    @Override
    protected void process(BufferedReader reader, PrintWriter pw) throws IOException, IllegalArgumentException {
	// The first line of the input gives the number of test cases, T. T test
	// cases follow, one per line. Each line contains the four integers A1,
	// A2, B1, B2, separated by spaces.
	this.T = this.readInt(reader, "Number of cases");
	String line;
	StringBuilder result;
	int len;
	char c;
	for (int i = 1; i <= this.T; i++) {
	    line = reader.readLine();
	    len = line.length();
	    if (len > 100) {
		System.out.println("Test case " + i + " INVALID: line too long (but it's okay)" + line);
	    }
	    // * TEST */System.out.println("Case #" + i + ": input  = " + line);
	    result = new StringBuilder(len);
	    for (int j = 0; j < len; j++) {
		c = line.charAt(j);
		if ((c >= 'a') && (c <= 'z')) {
		    result.append(ProblemA.translator.charAt(c - 'a'));
		} else {
		    result.append(' ');
		    if (c != ' ') {
			System.out.println("  Invalid character: '" + c + "', should be a-z");
		    }
		}
	    }
	    // * TEST */System.out.println("Case #" + i + ": output = " +
	    // result);
	    pw.println("Case #" + i + ": " + result.toString());
	}
    }
}
