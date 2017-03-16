package round_1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

import javax.swing.JFileChooser;

public class Brattleship {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = chooseInput();
		PrintWriter output = new PrintWriter("Round_1C_A_Large.txt");
		
		process(input, output);
		output.close();
		System.out.println("done");
	}

	
	public static void process(Scanner input, PrintWriter out){
		int numCases = input.nextInt();
		for(int i=1; i<=numCases; i++){
			int min = calculate(input);
//			System.out.printf("Case #%d: %d", i, min);
//			System.out.println();
			out.printf("Case #%d: %d", i, min);
			if(i!=numCases) out.println();
		}
	}
	
	public static int calculate(Scanner input){
		int r = input.nextInt();
		int c = input.nextInt();
		int w = input.nextInt();
		if(w == 1){
			return r*c;
		}
		if(c%w == 0){
			return r*(c/w) + w-1;
		}
		return r*(c/w) + w;
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
