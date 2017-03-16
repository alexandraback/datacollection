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
	public static final String FILE_NAME = "A-large"; 
	private static boolean TEST = false;
	//private static final boolean BIG = false;
	//private static final BigInteger MAX = BIG ? BigInteger.valueOf(1000000) : BigInteger.valueOf(100);
	private static final BigInteger TWO = BigInteger.valueOf(2);

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
			int a = in.nextInt();
			int n = in.nextInt();
			int[] motes = new int[n];
			for(int i = 0; i < n; i++) {
				motes[i] = in.nextInt();
			}
			Arrays.sort(motes);
			BigInteger sizeOfMote1 = BigInteger.valueOf(a), sizeOfMote2 = sizeOfMote1;
			//System.out.println("initial: " + sizeOfMote);
			int numOfOperations1 = 0, numOfOperations2 = 0;
			int counter = 0;
			for(int i = 0; i < n; i++) {
				BigInteger currentMote = BigInteger.valueOf(motes[i]);
				//System.out.println("currentMote: " + currentMote);
				if(sizeOfMote1.compareTo(currentMote) != 1) {
					BigInteger candidate = sizeOfMote1;
					if(counter < n) {
						while(candidate.compareTo(currentMote) != 1 && counter < n) {
							numOfOperations1++;
							counter++;
							candidate = candidate.multiply(TWO).subtract(BigInteger.ONE);
							//System.out.println("not bigger");
							//System.out.println("candidate: " + candidate);
						}
					} else {
						numOfOperations1 = n;
						break;
					}
					sizeOfMote1 = candidate;
					if(sizeOfMote1.compareTo(currentMote) == 1) {
						//System.out.println("enlargened mote bigger");
						sizeOfMote1 = sizeOfMote1.add(currentMote);
					}
					/*System.out.println("not bigger");
					numOfOperations++;
					BigInteger candidate = sizeOfMote.multiply(TWO).subtract(BigInteger.ONE);
					System.out.println("candidate: " + candidate);
					if(candidate.compareTo(currentMote) == 1) {
						System.out.println("candidate bigger");
						sizeOfMote = candidate;
						sizeOfMote = sizeOfMote.add(currentMote);
					} else {
						System.out.println("candidate not bigger");
					}*/
				} else {
					sizeOfMote1 = sizeOfMote1.add(currentMote);
					//System.out.println("bigger, sizeOfMote: " + sizeOfMote1);
				}
			}
			
			for(int i = 0; i < n; i++) {
				BigInteger currentMote = BigInteger.valueOf(motes[i]);
				//System.out.println("currentMote: " + currentMote);
				if(sizeOfMote2.compareTo(currentMote) != 1) {
					//System.out.println("not bigger");
					numOfOperations2++;
					BigInteger candidate = sizeOfMote2.multiply(TWO).subtract(BigInteger.ONE);
					//System.out.println("candidate: " + candidate);
					if(candidate.compareTo(currentMote) == 1) {
						//System.out.println("candidate bigger");
						sizeOfMote2 = candidate;
						sizeOfMote2 = sizeOfMote2.add(currentMote);
					} else {
						//System.out.println("candidate not bigger");
						numOfOperations2 += (n-i-1);
						break;
					}
				} else {
					sizeOfMote2 = sizeOfMote2.add(currentMote);
					//System.out.println("bigger, sizeOfMote: " + sizeOfMote2);
				}
			}
			
			System.out.println("Case #" + z + ": " + Math.min(numOfOperations1, numOfOperations2));
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