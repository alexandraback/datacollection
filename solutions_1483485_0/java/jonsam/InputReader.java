import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
 

public class InputReader {

	public static String getInputFromConsole(String msg) {
		
		String readIn = "";
		
        try {
            InputStreamReader isr = new InputStreamReader(System.in);
            BufferedReader br = new BufferedReader(isr);
            System.out.println(msg);
            readIn = br.readLine();
            //System.out.println("You have Enterd :- " + readIn);
 
        } catch (IOException e) {
            e.printStackTrace();
        }
        
        return readIn;
	}
	
	public static String getInputFromConsole() {
		return getInputFromConsole("Enter : ");
	}
	
	public static String[] getInputFromFileFirstLineRepLineCount(String filename) {
		
		String output[] = new String[0];
		
		
        File file = new File(filename);
        
        try {
            
        	Scanner scanner = new Scanner(file);
            
        	int numOfLines = scanner.nextInt();
        	output = new String[numOfLines];
        	
        	scanner.nextLine();
        	
        	for (int i = 0; i < numOfLines; i++) {
        	
        		output[i] = scanner.nextLine();
        		
        	}
        	
        	while (scanner.hasNextLine()) {
                String line = scanner.nextLine();
                System.out.println(line);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        
        return output;
        
	}
}
