import java.io.*;
import java.util.*;
import java.util.regex.*;
import java.math.*;

/**
 * 
 * Google Code Jam 2013
 * @author Miloš Èernilovský - milhaus
 *
 */
public class Main {
	public static final String FILE_NAME = "B-small-attempt1"; 
	private static boolean TEST = false;

	public static void main(String[] args) throws IOException {
		if(TEST) {
			System.out.println("TEST !!!");
			createTestFile();
		}
		System.setIn(new FileInputStream(FILE_NAME + ".in"));
		System.setOut(new PrintStream(FILE_NAME + ".out"));
		FastReader in = FastReader.SYSTEM_READER;
		int t = in.nextInt();
		
		for (int z = 1; z <= t; z++) {
			int e = in.nextInt();
			int r = in.nextInt();
			int n = in.nextInt();
			int currentEnergy = e;
			int values[] = new int[n];
			for (int i = 0; i < values.length; i++) {
				values[i] = in.nextInt();
			}
			int total = 0;
			for(int i = 0; i < values.length; i++) {
				int spendCandidate = currentEnergy;
				outer:
				while(spendCandidate > 0) {
					//double dNumOfTries = (double) (spendCandidate-r)/r;
					double dNumOfTries = (double) (e-(currentEnergy-spendCandidate)-r)/r;
					//System.out.println("dNumOfTries: " + dNumOfTries);
					if(dNumOfTries > 0) {
						int iNumOfTries;
						if(dNumOfTries > Math.floor(dNumOfTries)) {
							iNumOfTries = ((int) dNumOfTries)+1;
						} else {
							iNumOfTries = (int) dNumOfTries;
						}
						//System.out.println("iNumOfTries: " + iNumOfTries);
						for(int j = i+1; j < Math.min(values.length, i+iNumOfTries+1); j++) {
							//System.out.println("comparing " + values[j] + " with " + values[i]);
							if(values[j] > values[i]) {
								spendCandidate--;
								continue outer;
							}
						}
						break outer;
					} else {
						break outer;
					}
				}
				total += values[i]*spendCandidate;
				currentEnergy =  Math.min(e, currentEnergy+r-spendCandidate);
				//System.out.println(values[i] + "*" + spendCandidate + ", current energy = " + currentEnergy);
			}
			
			System.out.println("Case #" + z + ": " + total);
		}
	}
	
	private static void createTestFile() throws FileNotFoundException {
		System.out.println("Creating a test file ...");
		PrintWriter pw = new PrintWriter(FILE_NAME + ".in");
		
		
		
		pw.flush();
		pw.close();
		System.out.println("Done.");
	}

}

final class FastReader {
	public static final FastReader SYSTEM_READER = new FastReader(System.in);
	private final InputStream in;
	private final byte[] buffer = new byte[512];
	private int pos, count;

	public FastReader(InputStream in) {
		this.in = in;
		pos = count = 0;
	}

	public int nextInt() {
		int c;
		while ((c = read()) < '0')
			;
		int result = c - '0';
		while ((c = read() - '0') >= 0)
			result = 10 * result + c;
		if(c == -35) { // new line's \r (attention, here c = read()-'0', that's why it's -35)
			if(read() != 10) { // check whether the next one is \n
				pos--;// if not, go back
			}
		}
		return result;
	}

	public String nextString() {
		StringBuilder s = new StringBuilder();
		int c;
		while ((c = read()) >= 33)
			s.append((char) c);
		if(c == 13) { // new line's \r
			if(read() != 10) { // check whether the next one is \n
				pos--;// if not, go back
			}
		}
		return s.toString();
	}

	private void fillBuffer() {
		try {
			count = in.read(buffer, pos = 0, buffer.length);
		} catch (Exception e) {
		}
	}

	public int read() {
		if (pos == count)
			fillBuffer();
		return buffer[pos++];
	}
}