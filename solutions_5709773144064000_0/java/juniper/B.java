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


public class B {

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


	public static void solve(String fileName, String outputFileName){
		File testFile = new File(fileName); 
		String output = "";

		ArrayList<String> inputLines = getContents(testFile);

		int numOfTests = Integer.parseInt(inputLines.get(0));
		int lineIdx = 1;
		for(int testIdx = 0; testIdx < numOfTests; testIdx++){
			String[] params = inputLines.get(lineIdx++).split(" ");
			double C = Double.parseDouble(params[0]);
			double F = Double.parseDouble(params[1]);
			double X = Double.parseDouble(params[2]);
			
			double time = play(C, F, X);
			
			output +=  "Case #" + (testIdx + 1) + ": ";				 		
			output += time + System.getProperty("line.separator");
			
			
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
	
	public static double play(double C, double F, double X){

		double prod = 2.0;
		double time = 0.0;
		boolean won = false;
		while(!won){
			double timeToWin = X/(prod);  //win w/o buying

			double timeToBuyFarm = C/(prod);
			double timeToWinWFarm = timeToBuyFarm  + X/(prod + F);
			if(timeToWinWFarm < timeToWin){
				//buy farm
				prod += F;
				time += timeToBuyFarm;
			}
			else{
				//do not buy farm
				time += timeToWin;
				won = true;
			}
		}
		return time;
	}

	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
	//	solve("test.in", "out-small.txt");

			solve("B-small-attempt0.in", "B-out-small.txt");

	}

}
