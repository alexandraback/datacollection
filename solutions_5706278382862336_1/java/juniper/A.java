import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;


public class A {

	/**
	 * Fetch the entire contents of a text file, and return it in a String.
	 *
	 * @param aFile is a file which already exists and can be read.
	 */
	static public ArrayList<String> getContents(File aFile) {
		ArrayList<String> inputLines = new ArrayList<String>();
		try {
			BufferedReader input =  new BufferedReader(new FileReader(aFile));
			try {
				String line = null; 

				while (( line = input.readLine()) != null){
					inputLines.add(line);	         
				}
			}
			finally {
				input.close();
			}
		}
		catch (IOException ex){
			ex.printStackTrace();
		}

		return inputLines ; 
	}

	/**
	 * Change the contents of text file in its entirety, overwriting any
	 * existing text.
	 *
	 * @param aFile is an existing file which can be written to.
	 * @throws IllegalArgumentException if param does not comply.
	 * @throws FileNotFoundException if the file does not exist.
	 * @throws IOException if problem encountered during write.
	 */
	static public void setContents(File aFile, String aContents)
			throws FileNotFoundException, IOException {
		if (aFile == null) {
			throw new IllegalArgumentException("File should not be null.");
		}
		if (!aFile.exists()) {
			throw new FileNotFoundException ("File does not exist: " + aFile);
		}
		if (!aFile.isFile()) {
			throw new IllegalArgumentException("Should not be a directory: " + aFile);
		}
		if (!aFile.canWrite()) {
			throw new IllegalArgumentException("File cannot be written: " + aFile);
		}

		//use buffering
		Writer output = new BufferedWriter(new FileWriter(aFile));
		try {
			output.write( aContents );
		}
		finally {
			output.close();
		}
	}
	
	public static int min2Fraction(long p, long q){
				
		long[] res = minim(p, q);
		p = res[0];
		q = res[1];
		
		long t = q;
		while(t != 0){
			long t2 = t >> 1;
			if(t2 != 0 && t2*2 != t){
				return -1;
			}
			t = t2;
		}
		
		
		long f1 = 1;
		long f2 = 2;
		//if f1/f2 < p/q -> found
		boolean found = false;
		int lev = -1;
		int i = 1;
		while(!found){
			if(f1 * q <= p * f2){
				found = true;
				lev = i;
			}else{
				f2 = f2 << 1;
				i++;
			}
		}
		
		return lev;
	}
	
	private static long[] minim(long p, long q){
		
		long[] res = new long[2];
		long div = gcd(p, q);
		while(div > 1){
			p = p / div;
			q = q / div;
					
			div = gcd(p, q);
		}
		res[0] = p;
		res[1] = q;
		return res;
	}
	private static long gcd(long a, long b)
	{
	  if(a == 0 || b == 0) return a+b; // base case
	  return gcd(b,a%b);
	}


	public static void solve(String fileName, String outputFileName){
		File testFile = new File(fileName); 
		String output = "";

		ArrayList<String> inputLines = getContents(testFile);

		int numOfTests = Integer.parseInt(inputLines.get(0));
		int lineIdx = 1;
		for(int testIdx = 0; testIdx < numOfTests; testIdx++){

			String[] params = inputLines.get(lineIdx++).split("/");

			//			int n = Integer.parseInt(inputLines.get(lineIdx++));

			long p = Long.parseLong(params[0]);
			long q = Long.parseLong(params[1]);



			int lev = min2Fraction(p, q);

			
			output +=  "Case #" + (testIdx + 1) + ": ";	

			if(lev == -1 || lev > 40){
			output += "impossible" + System.getProperty("line.separator");
			}else{
				output += lev + System.getProperty("line.separator");
			}
			//	System.out.println("test " + testIdx);

		}

		File outputFile = new File(outputFileName);
		if(!outputFile.exists()) {
			try {
				outputFile.createNewFile();
			} catch (IOException e) {
				e.printStackTrace();
			}
		} 
		try {
			setContents(outputFile, output);
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//solve("test-a.in", "test-a.txt");

		//	solve("A-small-attempt0.in", "A-out-small0.txt");
			solve("A-large.in", "A-out-large.txt");



	}

}

