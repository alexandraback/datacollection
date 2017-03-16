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
	public static final String FILE_NAME = "A-small-attempt0"; 
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
		
		BigDecimal one = new BigDecimal(1);
		
		/*Map<BigDecimal, BigDecimal> powers = new HashMap<BigDecimal, BigDecimal>();
		BigDecimal radius = new BigDecimal("1");
		BigDecimal limit = new BigDecimal("10000000");
		
		while(radius.compareTo(limit) < 1) {
			powers.put(radius, radius.pow(2));
			radius = radius.add(one);
		}*/
		
		
		for (int z = 1; z <= t; z++) {
			BigDecimal r = new BigDecimal(in.nextString());
			BigDecimal t1 = new BigDecimal(in.nextString());
			
			BigInteger numOfCases = new BigInteger("0");
			BigDecimal zero = new BigDecimal(0);
			BigDecimal pi = new BigDecimal(Math.PI);
			BigInteger oneI = new BigInteger("1");
			
			//int i = 0;
			while(true) {
				//BigDecimal inner = pi.multiply(r.pow(2));
				BigDecimal inner = r.pow(2);
				//System.out.println("inner: " + inner);
				r = r.add(one);
				BigDecimal outer = r.pow(2);
				//System.out.println("outer: " + outer);
				r = r.add(one);
				t1 = t1.subtract(outer.subtract(inner));
//				if(i % 100 == 0) {
//					System.out.println("t1: " + t1);
//				}
				if(t1.compareTo(zero) >= 0) {
					numOfCases = numOfCases.add(oneI);
				} else {
					break;
				}
				//i++;
			}
			
			System.out.println("Case #" + z + ": " + numOfCases);
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