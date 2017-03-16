import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;

/**
 * 
 */

/**
 * @author Bryan
 * 
 */
public class problemA {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String filePath = "/Users/Bryan/Documents/CodeJam/ProblemA/A-small-attempt0.in";
		boolean isFirstLine = true;
		int counter = 1;
		StringBuffer resultString = new StringBuffer();
		
		try {
			// Open the file that is the first
			// command line parameter
			FileInputStream fstream = new FileInputStream(filePath);
			// Get the object of DataInputStream
			DataInputStream in = new DataInputStream(fstream);
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String strLine;
			// Read File Line By Line
			while ((strLine = br.readLine()) != null) {
				if (isFirstLine){
					isFirstLine = false;
					continue;
				}
				resultString.append("Case #" + counter + ": ");
				for ( int a = 0; a < strLine.length(); a++){
					resultString.append(translator(strLine.charAt(a)));
				}
				resultString.append("\n");
				counter++;
			}
			// Close the input stream
			in.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
		
		writeStringToFile(resultString.toString());

	}

	private static char translator(char source) {
		char result = '\u0000';
		switch (source) {
		case 'a':
			result = 'y';
			break;
		case 'b':
			result = 'h';
			break;
		case 'c':
			result = 'e';
			break;
		case 'd':
			result = 's';
			break;
		case 'e':
			result = 'o';
			break;
		case 'f':
			result = 'c';
			break;
		case 'g':
			result = 'v';
			break;
		case 'h':
			result = 'x';
			break;
		case 'i':
			result = 'd';
			break;
		case 'j':
			result = 'u';
			break;
		case 'k':
			result = 'i';
			break;
		case 'l':
			result = 'g';
			break;
		case 'm':
			result = 'l';
			break;
		case 'n':
			result = 'b';
			break;
		case 'o':
			result = 'k';
			break;
		case 'p':
			result = 'r';
			break;
		case 'q':
			result = 'z';
			break;
		case 'r':
			result = 't';
			break;
		case 's':
			result = 'n';
			break;
		case 't':
			result = 'w';
			break;
		case 'u':
			result = 'j';
			break;
		case 'v':
			result = 'p';
			break;
		case 'w':
			result = 'f';
			break;
		case 'x':
			result = 'm';
			break;
		case 'y':
			result = 'a';
			break;
		case 'z':
			result = 'q';
			break;
		case ' ':
			result = ' ';
		default:
			
			break;
		}

		if (result == '\u0000'){
			System.err.println("Unmapped char found source = " + source);
		}
		return result;
	}

	private static void writeStringToFile(String outputString) {
		try {
			// Create file
			FileWriter fstream = new FileWriter("/Users/Bryan/Documents/CodeJam/ProblemA/output.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			out.write(outputString);
			// Close the output stream
			out.close();
		} catch (Exception e) {// Catch exception if any
			System.err.println("Error: " + e.getMessage());
		}
	}

//	private static String readFileAsString(String filePath)
//			throws java.io.IOException {
//		StringBuffer fileData = new StringBuffer(1000);
//		BufferedReader reader = new BufferedReader(new FileReader(filePath));
//		char[] buf = new char[1024];
//		int numRead = 0;
//		while ((numRead = reader.read(buf)) != -1) {
//			String readData = String.valueOf(buf, 0, numRead);
//			fileData.append(readData);
//			buf = new char[1024];
//		}
//		reader.close();
//		return fileData.toString();
//	}
}
