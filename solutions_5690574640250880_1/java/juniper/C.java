import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;


public class C {

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

	public static int[] getValidDims(int R, int C, int bombs){
		int emptyCells = R*C - bombs;
		int[] dims = new int[4];
		for(int i = 2; i <= R; i++){
			for(int j = 2; j <= C; j++){
				if(i*j >= emptyCells){
					int rest = i*j - emptyCells;
					if(rest == 0 ){
						dims[0] = i;
						dims[1] = j;
						dims[2] = 0;
						dims[3] = 0;
						return dims;
					}
					else{
						if(i > 2  && j > 2){
							int emptyRest = (i + j - 1) - rest;
							if(emptyRest > 1){

								if(emptyRest <= j-1 && emptyRest > 1){
									dims[0] = i-1;
									dims[1] = j-1;
									dims[2] = emptyRest;
									dims[3] = 0;
									return dims;
								}
								else{
									if(emptyRest <= i-1 && emptyRest > 1){
										dims[0] = i-1;
										dims[1] = j-1;
										dims[2] = 0;
										dims[3] = emptyRest;
										return dims;
									}else{
										dims[0] = i-1;
										dims[1] = j-1;

										dims[2] = j-1; //fill in last row
										dims[3] = emptyRest - (j-1);   // fill in last column
										if(dims[3] == 1){
											dims[2]--;
											dims[3]++;
										}
										if(dims[2] > 1 && dims[3] > 1){
											return dims;
										}
									}

								}
							}
						}
					}
				}
			}
		}
		return null;
	}

	public static int[][] isWinPossible(int R, int C, int bombs){
		int[][] desk = new int[R][C];

		if(bombs == 0){
			//empty desk
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++){
					desk[i][j] = 1; //empty
				}
			}
			desk[0][0] = 2; //click

			return desk;
		}

		if(bombs == R*C - 1){
			for(int i = 0; i < R; i++){
				for(int j = 0; j < C; j++){
					desk[i][j] = 3; //bomb
				}
			}
			desk[0][0] = 2; //click
			return desk;
		}
		if(R == 1){

			for(int j = 0; j < C; j++){
				desk[0][j] = 1; //empty	
			}
			for(int j = C-bombs; j < C; j++){
				desk[0][j] = 3; //bomb	
			}
			desk[0][0] = 2; //click
			return desk;
		}
		if(C == 1){

			for(int i = 0; i < R; i++){
				desk[i][0] = 1; //empty	
			}
			for(int i = R-bombs; i < R; i++){
				desk[i][0] = 3; //bomb	
			}
			desk[0][0] = 2; //click
			return desk;
		}

		int emptyCells = R*C - bombs;
		if(emptyCells < 4){
			if(R > 1 && C > 1){
				return null; //impossible
			}
			else{
				if(R == 1){
					for(int j = emptyCells; j < C; j++){
						desk[0][j] = 3; //bomb
					}
					for(int j = 1; j < emptyCells; j++){
						desk[0][j] = 1; //empty
					}
					desk[0][0] = 2; //click
				}
				else{
					if(C == 1){
						for(int i = emptyCells; i < R; i++){
							desk[i][0] = 3; //bomb
						}
						for(int i = 1; i < emptyCells; i++){
							desk[i][0] = 1; //empty
						}
						desk[0][0] = 2; //click

					}
				}
				return desk;
			}
		}		
		else{
			int[] dims = getValidDims(R, C, bombs);
			if(dims == null){
				return null;
			}
			else{

				for(int i = 0; i < R; i++){
					for(int j = 0; j < C; j++){
						desk[i][j] = 3;
					}
				}
				for(int i = 0; i < dims[0]; i++){
					for(int j = 0; j < dims[1]; j++){
						desk[i][j] = 1;						
					}		
				}
				for(int j = 0; j < dims[2]; j++){
					desk[dims[0]][j] = 1;						
				}
				for(int i = 0; i < dims[3]; i++){
					desk[i][dims[1]] = 1;						
				}
				desk[0][0] = 2;
				return desk;
			}
		

		}


	}

	public static String printDesk(int[][] desk, int R, int C){
		String out = "";
		for(int i = 0; i < R; i++){
			for(int j = 0; j < C; j++){
				if(desk[i][j] == 1){
					out += ".";
				}
				else{
					if(desk[i][j] == 3){
						out += "*";
					}
					else{
						if(desk[i][j] == 2){
							out += "c";
						}
						else{
							out += "!";
						}
					}
				}
			}
			out += System.getProperty("line.separator");
		}
		return out;
	}


	public static void solve(String fileName, String outputFileName){
		File testFile = new File(fileName); 
		String output = "";

		ArrayList<String> inputLines = getContents(testFile);

		int numOfTests = Integer.parseInt(inputLines.get(0));
		int lineIdx = 1;
		for(int testIdx = 0; testIdx < numOfTests; testIdx++){

			String[] params = inputLines.get(lineIdx++).split(" ");
			int R = Integer.parseInt(params[0]);
			int C = Integer.parseInt(params[1]);
			int M = Integer.parseInt(params[2]);

			int[][] desk = isWinPossible(R, C, M);
			output +=  "Case #" + (testIdx + 1) + ":" + System.getProperty("line.separator");	
	//		output += R + " x " + C + ", bombs = " + M + System.getProperty("line.separator");
			if(desk == null){
				output += "Impossible" + System.getProperty("line.separator");
			}
			else{
				output += printDesk(desk, R, C);
			}
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
		//		solve("test.in", "out-small.txt");

	//	solve("C-small-attempt2.in", "C-out-small2.txt");
		solve("C-large.in", "C-out-large.txt");


	}

}
