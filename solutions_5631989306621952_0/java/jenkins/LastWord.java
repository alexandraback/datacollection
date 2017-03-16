package round1A;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.JFileChooser;

public class LastWord {
	public static void main(String[] args) throws FileNotFoundException {
		Scanner input = chooseInput();
		PrintWriter output = new PrintWriter("Round1A_Part_A_Small.txt");
		process(input, output);
		output.close();
		System.out.println("done");
	}
	
	public static void process(Scanner input, PrintWriter out){
		int numTests = input.nextInt();
		for(int i=1; i<= numTests; i++){
			String s = input.next();
			String last = lastWord(s);
			out.printf("Case #%d: %s\n", i, last);
		}
	}
	
	public static String lastWord(String letters){
		LetterNode first = new LetterNode(letters.charAt(0));
		LetterNode last = first;
		for(int i=1; i<letters.length(); i++){
			LetterNode next = new LetterNode(letters.charAt(i));
			if((int)next.letter >= (int)first.letter){
				next.next = first;
				first = next;
			}
			else {
				last.next = next;
				last = next;
			}
		}
		StringBuilder ret = new StringBuilder();
		while(first != null){
			ret.append(first.letter);
			first = first.next;
		}
		
		return ret.toString();
	}
	
	private static class LetterNode {
		public char letter;
		public LetterNode next;
		public LetterNode(char ch){
			letter = ch;
		}
	}
	
	public static Scanner chooseInput() throws FileNotFoundException{
		JFileChooser fileChooser = new JFileChooser();
		int result = fileChooser.showOpenDialog(fileChooser);
		if(result == JFileChooser.APPROVE_OPTION){
			File selectedFile = fileChooser.getSelectedFile();
			Scanner ret = new Scanner(new FileReader(selectedFile));
			return ret;
		}
		return null;
	}
}
