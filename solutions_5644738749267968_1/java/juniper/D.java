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
import java.util.HashSet;
import java.util.Random;

public class D {

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


	public static int playDWar(double[] n, double[] k){
		if(n.length == 1){
			if(n[0] > k[0]){
				return 1;
			}
			else{
				return 0;
			}		
		}
		
		int scoreN = 0;
		int greatestKBlock = k.length-1;
		for(int i = 0; i < n.length; i++){
			//find greatest element in k smaller than n[i]
			
			int idx = -1;
			for(int j = 0; j < k.length && k[j] < n[i]; j++){
				if(k[j] != 0){
					idx = j;
				}
			}
			if(idx >= 0){
				k[idx] = 0;
				n[i] = 0;
				scoreN++;
			}else{
				k[greatestKBlock]=0;
				n[i] = 0;
				while(k[greatestKBlock] == 0 && greatestKBlock > 0){
					greatestKBlock--;
				}
					
			}
		}
		return scoreN;
	}
	public static int playWar(double[] n, double[] k){
		if(n.length == 1){
			if(n[0] > k[0]){
				return 1;
			}
			else{
				return 0;
			}		
		}
		int scoreN = 0;
		int smallestKBlock = 0;
		for(int i = 0; i < n.length; i++){
			boolean played = false;			
			for(int j = 0; j < k.length && !played; j++){
				if(k[j] > n[i]){
					k[j] = 0;
					n[i] = 0;
					played = true;
				}
			}
			if(!played){
				scoreN++;
				k[smallestKBlock] = 0;
				n[i] = 0;
				while(k[smallestKBlock] == 0 && smallestKBlock < k.length-1){
					smallestKBlock++;
				}
			}
		}
		return scoreN;
	}
	public static void solve(String fileName, String outputFileName){
		File testFile = new File(fileName); 
		String output = "";

		ArrayList<String> inputLines = getContents(testFile);

		int numOfTests = Integer.parseInt(inputLines.get(0));
		int lineIdx = 1;
		for(int testIdx = 0; testIdx < numOfTests; testIdx++){
			int numOfBlocks = Integer.parseInt(inputLines.get(lineIdx++));
			double[] n = new double[numOfBlocks];
			double[] k = new double[numOfBlocks];
			
			String[] blocksN = inputLines.get(lineIdx++).split(" ");
			String[] blocksK = inputLines.get(lineIdx++).split(" ");

			for(int i = 0; i < numOfBlocks; i++){
				n[i] = Double.parseDouble(blocksN[i]);
				k[i] = Double.parseDouble(blocksK[i]);
			}
			
			
			Arrays.sort(n);
			Arrays.sort(k);
			double[] n2 = Arrays.copyOf(n, n.length);
			double[] k2 = Arrays.copyOf(k, k.length);
					
			
			int dWarResult = playDWar(n, k);

			int warResult = playWar(n2, k2);
			
			output +=  "Case #" + (testIdx + 1) + ": ";				 		
			output += dWarResult + " " + warResult + System.getProperty("line.separator");
			
			
			
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
	
	
	public static void generateTest(int T, int N, String outputFileName){
		String output = T + System.getProperty("line.separator");
		for(int i = 0; i < T; i++){
			output += generateTestCase(N);
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
	public static String generateTestCase(int N){
		HashSet<Double> blocks = new HashSet<Double>();
		int cnt = 0;
		Random r = new Random();

		String out = N + System.getProperty("line.separator");
		while(cnt < 2*N){
			double randomValue =  r.nextDouble();
			if(randomValue != 0 && randomValue != 1.0 && !blocks.contains(randomValue)){
				cnt++;
				blocks.add(randomValue);
			}
		}
		Double[] blocksArray = new Double[2*N];
		blocksArray = blocks.toArray(blocksArray);
		for(int i = 0; i < N; i++){
			out += blocksArray[i] + " ";
		}
		out += System.getProperty("line.separator");
		for(int i = N; i < 2*N; i++){
			out += blocksArray[i] + " ";
		}
		out += System.getProperty("line.separator");
		
		return out;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {

	//	generateTest(50, 1000, "gen-test.in");
	//	solve("gen-test.in", "out-test-gen.txt");
	//	solve("D-small-attempt0.in", "D-out-small.txt");
		
		solve("D-large.in", "D-out-large.txt");

		

	}

}
