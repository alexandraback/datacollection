import java.io.File;
import java.util.*;
import java.io.FileWriter;
import java.io.IOException;

/* Google Code Jam
 * arielperezch@gmail.com
 * Code Base
 * May 2013
 */

public class Principal {

	static Scanner input;
	static FileWriter output;

	/* User Input */
	static Scanner consoleScanner;
	// Asks the user for a String by printing a given prompt.
	public static String askUser(String prompt) throws IOException{
		System.out.print(prompt);
		String str = consoleScanner.next();			
		return str;
	}

	// Begins the consoleScanner for user input
	public static void begin(){
		consoleScanner = new Scanner(System.in);
	}

	// Terminates the program
	public static void end() throws IOException{
		System.out.println("Program finished!");
		
		input.close();
		consoleScanner.close();
		output.close();
	}

	// Initializes the 'input' scanner with a given file.
	// If no such file exists, it prompts the user to re-enter the file name.
	public static void openReader(String fileName) throws IOException{
		File f = new File(fileName);
		while(!f.exists()){
			fileName = askUser("Please enter a valid file name >> ");
			f = new File(fileName);
		}
		input = new Scanner(f);
	}

	// Initializes the 'output' FileWriter with a given file.
	// If no such file exists, it prompts the user to re-enter the file name.
	public static void openWriter(String fileName) throws IOException{
		File f = new File(fileName);
		output = new FileWriter(f);
	}

	public static void main(String[] args) throws IOException{

		// Initializes the user input
		begin();

		// Does the preprocessing
		preprocessing();

		// Opens the file selected by the user
		openReader(askUser("Please enter the name of the problem input file >> "));
		
		// Opens a file for output.
		openWriter("output.txt");
		
		// Solves the problem
		solve();

		// Terminates the program, closes all files
		end();
	}

	// Does any preprocessing required
	public static void preprocessing() throws IOException{
		String s = "";
		while(!(s.equalsIgnoreCase("Y") || s.equalsIgnoreCase("N"))){
			s = askUser("Would you like to preprocess from scratch? (Y/N) >> ");
		}
		
		if(s.equalsIgnoreCase("N")){
			loadPreprocessing(askUser("Please enter the name of the file with your preprocessed data >> "));
		}		
		else{
			// TODO
			
			savePreprocessing("preprocessing.data");
		}
		
		System.out.println("Ready!");
	}

	public static void savePreprocessing(String fileName) throws IOException{
		openWriter(fileName);
		
		//TODO
		
		System.out.println("Preprocessing saved to: " + '"' + fileName + '"');
		output.close();
	}
	// Loads a preprocessing file into memory
	public static void loadPreprocessing(String fileName) throws IOException{
		openReader(fileName);

		//TODO 		
		
		input.close();
	}

	// Solves the problem.
	// In here the Scanner 'input' is assumed open and can be used to read data.
	public static void solve() throws IOException{
		//TODO
		
		int T = input.nextInt();
		long A;
		int N, result;
		for(int i = 1; i <= T; i++){
			A = input.nextInt();
			N = input.nextInt();
			List<Integer> motes = new ArrayList<Integer>(N);
			for(int j = 0; j < N; j++){
				motes.add(input.nextInt());
			}
			result = solveCase(A, motes);
			output.write("Case #" + i + ": " + result + "\n");
		}
	}
	
	public static int solveCase(long moteSize, List<Integer> motes){
		
		// sort all motes: smallest > > biggest
		Collections.sort(motes);
		
		int len = motes.size();
		
		int[] values = new int[len + 1];
		int[] remaining = new int[len + 1];
		
		remaining[0] = len;
		values[0] = 0;
		int attempts = 0;
		for(int i = 0; i < len;){
			
			if(motes.get(i) < moteSize){
				moteSize += motes.get(i);
				values[i + 1] = values[i] + attempts;
				remaining[i + 1] = remaining[i] - 1;
				attempts = 0;
				i++;
			}
			else{
				moteSize += (moteSize - 1);
				if(++attempts > remaining[i]){
					remaining[i + 1] = -1;
					break;
				}
			}
		}
		
		int minValue = remaining[0];
		int currentValue;
		for(int i = 0; i <= len; i++){
			if(remaining[i] == -1)
				break;
			
			currentValue = values[i] + remaining[i];
			if(currentValue < minValue)
				minValue = currentValue;
		}
		
		return minValue;//maxValue > currentValue? currentValue : maxValue;
	}
}