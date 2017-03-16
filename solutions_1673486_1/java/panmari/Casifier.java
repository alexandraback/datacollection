import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Scanner;


public class Casifier {

	
	private String[] cases;
	private String fileName;
	
	/**
	 * Reads in a file and splits it into single lines which can be returned 
	 * as an array of strings. It is expected that the first line only consists
	 * of one number which signifies the number of cases.
	 * @param filename
	 * @throws FileNotFoundException 
	 */
	public Casifier(String fileName) {
		this(fileName, "\\r?\\n");
	}
	
	/**
	 * You can set your own delimiter with this constructor, has to be a regex
	 * @param fileName
	 * @param delimiter
	 */
	public Casifier(String fileName, String delimiter) {
		this.fileName = fileName;
		Scanner inFile;
		try {
			inFile = new Scanner(new File(fileName));
			int n = inFile.nextInt();
			inFile.useDelimiter(delimiter);
			cases = new String[n];
			for (int i = 0; i < n; i++) {
				cases[i] = inFile.next();
				cases[i]+= " " + inFile.next();
			}
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public String[] getInputAsArray() {
		return cases;
	}
	
	public void writeOutput(List result) {
		PrintWriter out;
		try {
			out = new PrintWriter(new FileWriter(fileName + ".out"));
			for (int i = 0; i < result.size(); i++) {
				out.println("Case #" + (i+1) + ": " + result.get(i));
			}
			out.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} 
		System.out.println("Finished!");
	}
}
