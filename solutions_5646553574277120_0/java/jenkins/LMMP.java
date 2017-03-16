package round_1C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

import javax.swing.JFileChooser;

public class LMMP {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner input = chooseInput();
		PrintWriter output = new PrintWriter("Round_1C_C_Small.txt");
		
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

	public static int c;
	public static int d;
	public static int v;
	public static ArrayList<Integer> denoms;
	
	public static int calculate(Scanner input){
		c = input.nextInt();
		d = input.nextInt();
		v = input.nextInt();
		denoms = new ArrayList<Integer>();
		for(int i=0; i<d; i++){
			denoms.add(input.nextInt());
		}
		int needed = 0;
		if(denoms.get(0)!=1){
			denoms.add(0, 1);
			needed++;
		}
		for(int j=1; j<denoms.size(); j++){
			needed += sumLeft(j);
		}
		while(!canMake()){
			needed++;
		}
		return needed;
	}
	
	public static boolean canMake(){
		int sum = 0;
		for(int i: denoms){
			sum += c*i;
		}
		if(sum>=v){
			return true;
		}
		denoms.add(sum+1);
		return false;
	}
	
	
	public static int sumLeft(int j){
		int sum = 0;
		for(int i=0; i<j; i++){
			sum += c*denoms.get(i);
		}
		if(sum >= denoms.get(j)-1){
			return 0;
		}
		denoms.add(j, sum+1);
		return 1;
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
