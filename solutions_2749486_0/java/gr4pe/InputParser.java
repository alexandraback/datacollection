package util;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;


public class InputParser {

	private String[] lines;
	private int nextLineIdx = 0;
	private OutputGenerator og;
	
	
	public InputParser(String filename) {
		File f = new File(filename);
		String content = readFile(f);
		lines = content.split("\n");
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
		String[] lits = getNextLine().split(" ");
		int[] ints = new int[lits.length];
		for(int i=0; i<lits.length; i++)
			ints[i] = Integer.parseInt(lits[i].trim());
		return ints;
	}
	
	public long[] la() {
		String[] lits = getNextLine().split(" ");
		long[] longs = new long[lits.length];
		for(int i=0; i<lits.length; i++)
			longs[i] = Long.parseLong(lits[i].trim());
		return longs;
	}
	
	
	public double[] da() {
		String[] lits = getNextLine().split(" ");
		double[] doubs = new double[lits.length];
		for(int i=0; i<lits.length; i++)
			doubs[i] = Double.parseDouble(lits[i].trim());
		return doubs;
	}
	
	public String[] sa() {
		String[] lits = getNextLine().split(" ");
		String[] strings = new String[lits.length];
		for(int i=0; i<lits.length; i++)
			strings[i] = lits[i].trim();
		return strings;
	}
	
	public char[] ca() {
		String[] lits = getNextLine().split(" ");
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
			System.out.println();
			System.out.println(og.get());
			og.wr();
			System.exit(0);
			return null;
		}
	}
	
	
	
	protected static final String LINE_SEP=System.getProperty("line.separator");
	
	/**
	 * Returns the text content of the file specified by file.
	 */
	public static String readFile(File f){
		String content="";
		String nextLine="";
		try {
			BufferedReader fileReader=new BufferedReader(new FileReader(f));
			nextLine = fileReader.readLine();
			while (nextLine!=null){
				content += nextLine + LINE_SEP;
				nextLine = fileReader.readLine();
			}
			fileReader.close();
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
		return content;
	}
	
//	private Enum Files {
//		
//	}
}
