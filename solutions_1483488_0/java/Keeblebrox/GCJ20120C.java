import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Google Code Jam 2012
 * 	Qualifier Round
 * 	Problem C
 * 
 * @author Brian Crockford
 */
public class GCJ20120C {
	public static final String inputFilename = "C-small-attempt0.in";	

	
	
	static class LongPair {		
		final long[] data = new long[2];
		
		public LongPair(long x, long y) {
			set(x, y);
		}
		
		public long getX() { return data[0]; }
		public long getY() { return data[1]; }
		public void set(long x, long y) {
			data[0] = Math.min(x,y); data[1] = Math.max(x,y);
		}
		
		@Override public boolean equals(Object o) {
			LongPair p = (LongPair) o;
			if (null != p) {
				return (data[0] == p.getX() && data[1] == p.getY())
						|| (data[1] == p.getY() && data[0] == p.getX());
			}
			return false;
		}
		
		@Override public int hashCode() {
	        long hash = 1;
	        hash = hash * 31 + data[0];
	        hash = hash * 31 + data[1];
	        return (int) hash;
		}
	}
	
	static class DataSet {
		private static HashSet<LongPair> pairs;
		static {
			pairs = new HashSet<LongPair>(500000);
		}
		
		public long begin,
					end;
		
		@Override
		public String toString() {
			return new StringBuilder("<$DataSet: ").append(begin).append(", ").append(end).append(">").toString();
		}
		
		public long countRecycles() {
			int digits = countDigits(begin);
			for (long i=begin; i<=end; ++i) {
				for (int j=1; j<digits; ++j) {
					long result = shiftLong(i, j);
					if (i != result && result >= begin && result <= end)
						pairs.add(new LongPair(i, result));
				}
			}
			long result = pairs.size();
			pairs.clear();
			return result;
		}
		
		public static DataSet parse(String s) {
			DataSet result = new DataSet();
				result.begin = Long.parseLong(s.substring(0, s.indexOf(' ')));
				result.end = Long.parseLong(s.substring(1+s.indexOf(' ')));
			return result;
		}
	}
	
	
	
	public static Reader getFileReader(String filename) {
		BufferedReader result = null;
		try {
			result = new BufferedReader(new FileReader(filename));
		}
		catch (FileNotFoundException e) {
			System.err.println("Couldn't find the file \""+filename+"\"");
			e.printStackTrace();
		}
		return result;
	}
	
	
	
	public static String readLine(BufferedReader reader) {
		try {
			return reader.readLine();
		} catch (IOException e) {
			e.printStackTrace();
		}
		return null;
	}
	
	
	
	public static void closeReader(Reader r) {
		try { 
			r.close(); 
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	
	
	public static Writer getFileWriter(String filename) {
		BufferedWriter result = null;
		try {
			result = new BufferedWriter(new FileWriter(filename));
		}
		catch (IOException e) {
			e.printStackTrace();
		}
		return result;
	}
	
	
	
	public static void writeLine(BufferedWriter writer, String line) {
		try {
			writer.write(line);
			writer.newLine();
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	
	
	public static void closeWriter(Writer w) {
		try { 
			w.close(); 
		} catch (IOException e) { e.printStackTrace(); }
	}
	
	
	
	public static String formatCase(int caseNumber, long result) {
		return new StringBuilder("Case #").append(caseNumber).append(": ").append(result).toString();
	}
	
	
	
	public static int countDigits(long n) {
		return (int) 1 + (int)Math.floor(Math.log10(n));
	}
	
	
	public static int getDigit(long n, int digit) {
		return(int)(n/(long)Math.pow(10, digit-1)) % 10;
	}
	
	
	public static long shiftLong(long n, int digits) {
		long mask = (long) Math.pow(10, digits);
		long upshift = (long) Math.pow(10, (countDigits(n)-digits));
		return (upshift*(n%mask)) + (n/mask);		
	}
	
	
	
	public static void main(String[] args) {		
		BufferedReader in = (BufferedReader) getFileReader(inputFilename);
		int lineCount = Integer.parseInt(readLine(in));
		List<DataSet> dataSets = new ArrayList<DataSet>();
		for (int i=0; i<lineCount; ++i) {
			dataSets.add(DataSet.parse(readLine(in)));
		}
		closeReader(in);
		
		BufferedWriter out = (BufferedWriter) getFileWriter(inputFilename.replace(".in", ".out"));
		for (int i=0; i<lineCount; ++i) {
			long result = dataSets.get(i).countRecycles();
			System.out.println(formatCase(i+1, result));
			writeLine(out, formatCase(i+1, result));
		}
		closeWriter(out);
	}

}