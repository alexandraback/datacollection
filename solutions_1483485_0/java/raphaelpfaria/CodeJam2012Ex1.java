import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class CodeJam2012Ex1 {

	private static String charactersGooglerese = "abcdefghijklmnopqrstuvxwyz ";
	private static String charactersEnglish    = "yhesocvxduiglbkrztnwjpmfaq ";
	public static void main(String[] args) throws FileNotFoundException{
		
		int numLines;
		String[] lines;
		File file = new File("A-small-attempt2.in");
		Scanner scanner = new Scanner(file);
		numLines = Integer.parseInt(scanner.nextLine());
		lines = new String[numLines];
		for(int i = 0; i < numLines;i++){
			lines[i] = scanner.nextLine();
		}
		CodeJam2012Ex1.translator(numLines, lines);
	}
	public static void translator(int numLines, String[] lines){
		String output;
		
		for(int i = 0; i < numLines; i++){
			StringBuffer buffer = new StringBuffer("Case #" + (i+1) + ": ");
			for(int j = 0; j < lines[i].length(); j++){
				char charGooglerese = lines[i].charAt(j);
				char character = charactersEnglish.charAt(charactersGooglerese.indexOf(charGooglerese));
				buffer.append(character);
			}
			if(i != numLines -1){
				buffer.append("\n");
			}
			output = buffer.toString();
			System.out.print(output);
		}
	}
	
}
