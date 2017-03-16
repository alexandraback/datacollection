package util;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;


public class InputParser {

	private String[] lines;
	private int nextLineIdx = 0;
	private OutputGenerator og;
	
	
	public InputParser(String filename) {
		lines = readFileIntoArray(new File(filename));
	}
	
	public final int noRemainingLines() {
		return lines.length - nextLineIdx;
	}
	
	public InputParser(String filename, OutputGenerator og) {
		this(filename);
		this.og = og;
	}
	
	public int i() {
		return Integer.parseInt(getNextLine().trim());
	}
	
	
	public double d() {
		return Double.parseDouble(getNextLine().trim());
	}
	
	public double c() {
		return getNextLine().trim().charAt(0);
	}
	
	public String s() {
		return getNextLine().trim();
	}
	
	public int[] ia() {
		String[] lits = getNextLine().split("\\s+");
		int[] ints = new int[lits.length];
		for(int i=0; i<lits.length; i++)
			ints[i] = Integer.parseInt(lits[i].trim());
		return ints;
	}
	
	public long[] la() {
		String[] lits = getNextLine().split("\\s+");
		long[] longs = new long[lits.length];
		for(int i=0; i<lits.length; i++)
			longs[i] = Long.parseLong(lits[i].trim());
		return longs;
	}
	
	
	public double[] da() {
		String[] lits = getNextLine().split("\\s+");
		double[] doubs = new double[lits.length];
		for(int i=0; i<lits.length; i++)
			doubs[i] = Double.parseDouble(lits[i].trim());
		return doubs;
	}
	
	public String[] sa() {
		String[] lits = getNextLine().split("\\s+");
		String[] strings = new String[lits.length];
		for(int i=0; i<lits.length; i++)
			strings[i] = lits[i].trim();
		return strings;
	}
	
	public char[] ca() {
		String[] lits = getNextLine().split("\\s+");
		char[] chars = new char[lits.length];
		for(int i=0; i<lits.length; i++)
			chars[i] = lits[i].trim().charAt(0);
		return chars;
	}
	
	public void skip() {
		getNextLine();
	}
	
	
	private final String getNextLine() {
		if(nextLineIdx < lines.length)
			return lines[nextLineIdx++];
		else {
			if(og!=null) {
				System.out.println();
				System.out.println(og.get());
				og.wr();
				System.exit(0);
			}
			return null;
		}
	}
	
	
	/**
	 * Returns the text content of the file in a String array, where each element
	 * of the array holds on line of the text.
	 */
	public static String[] readFileIntoArray(File f){
		final LinkedList<String> lines = new LinkedList<>();
		try {
			BufferedReader fileReader=new BufferedReader(new FileReader(f));
			String nextLine = fileReader.readLine();
			while (nextLine!=null){
				lines.add(nextLine);
				nextLine = fileReader.readLine();
			}
			fileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		return lines.toArray(new String[]{});
	}

	
//	private Enum Files {
//		
//	}
}
