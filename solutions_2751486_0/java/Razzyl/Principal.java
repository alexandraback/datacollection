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

	static long time = 0;
	static long measure = 0;
	
	public static void startTimer()
	{
		time = System.currentTimeMillis();
	}
	
	public static void stopTimer()
	{
		measure = System.currentTimeMillis() - time;
	}

	
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

		// Opens the file selected by the user
		openReader(askUser("Please enter the name of the problem input file >> "));
		
		// Opens a file for output.
		openWriter("output.txt");
		
		// Solves the problem
		solve();

		// Terminates the program, closes all files
		end();
	}
	// Solves the problem.
	// In here the Scanner 'input' is assumed open and can be used to read data.
	public static void solve() throws IOException{
		//TODO
		
		startTimer();
		int T = input.nextInt();
		int result, n;
		String name = input.nextLine();
		for(int i = 1; i <= T; i++){
			name = input.next();
			n = input.nextInt();
			result = solveCase(name, n);
			output.write("Case #" + i + ": " + result + "\n");
		}
		stopTimer();
		System.out.println("Solved in " + measure + " millis");
	}
	
	public static int solveCase(String name, int n){
		
		int consonantCounter = 0;
		int lastIndex = -1, startIndex = 0;
		int len = name.length();
		char ch;
		String vowels = "aeiou";
		
		int count = 0;
		int aux1, aux2;
		for(int currentIndex = 0; currentIndex < len; currentIndex ++){
			ch = name.charAt(currentIndex);
			if(vowels.indexOf(ch) == -1) {// Is consonant
				consonantCounter = consonantCounter + 1;
				if(consonantCounter == n + 1){
					consonantCounter --;
					startIndex++;
				}
					
			}
			else{
				consonantCounter = 0;
			}
			
			if(consonantCounter == 1){
				startIndex = currentIndex;
			}
			
			if(consonantCounter == n){
				aux1 = (startIndex - lastIndex);
				aux2 = (len - currentIndex);
				count += aux1 * aux2;
				lastIndex = startIndex;
			}
		}
		return count;
	}
	
}