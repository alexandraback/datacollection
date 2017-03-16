import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;


public class CountingSheep {
	public static void main(String[] args){
		File a = new File("A-large.in");
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
		int cases = number;
		
		while(number > 0){
			int n = input.nextInt();
			String result = "INSOMNIA";
			if (n != 0){
				boolean[] numbers = new boolean[10];
				
				for (int i = 0; i < 10; i++){
					numbers[i] = false;
				}
				
				
				int digitChecker = 0;
				int counter = 1;
				while (!checkBool(numbers)){
					digitChecker = n * counter;
					while (digitChecker > 0){
						int digit = digitChecker % 10;
						digitChecker /= 10;
						numbers[digit] = true;
					}
					counter++;
				}
				counter--;
				digitChecker = n * counter;
				
				result = "" + digitChecker;
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
