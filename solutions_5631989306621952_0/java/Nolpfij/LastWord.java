import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;


public class LastWord {
	public static void main(String[] args){
		File a = new File("A-small-attempt0.in");
		Scanner input = null;
		try {
			input = new Scanner(a);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//Scanner input = new Scanner(System.in);
		
		File b = new File("A-output.txt");
		FileWriter fw = null;
		try {
			fw = new FileWriter(b);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		int number = input.nextInt();
		input.nextLine();
		int cases = number;
		
		while(number > 0){
			String s = input.nextLine();
			String result = "";
			
			result = "" + s.charAt(0);
			
			int index = 1;
			while (index < s.length()){
				if (s.charAt(index) >= result.charAt(0)){
					result = s.charAt(index) + result;
				} else {
					result = result + s.charAt(index);
				}
				index++;
			}
			
			
			try {
				fw.write("Case #" + (cases - number + 1) + ": " + result + "\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			number--;
		}
		
		try {
			fw.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	private static boolean checkBool(boolean[] numbers) {
		for (int i = 0; i < numbers.length; i ++){
			if (!numbers[i]){
				return false;
			}
		}
		return true;
	}
}
