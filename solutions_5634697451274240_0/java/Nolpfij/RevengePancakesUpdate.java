import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;


public class RevengePancakesUpdate {
	public static void main(String[] args){
		File a = new File("B-small-attempt4.in");
		Scanner input = null;
		try {
			input = new Scanner(a);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//Scanner input = new Scanner(System.in);
		
		File b = new File("B-output.txt");
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
			System.out.println (s);
			
			boolean[] flip = new boolean[s.length()];
			
			for(int i = 0; i < s.length(); i++){
				if (s.charAt(i) == '+') {
					flip[i] = true;
				} else {
					flip[i] = false;
				}
			}
			
			int count = 0;
			
			int index = 0;
			
			if(flip[0]){
				count = 0;
				index = findFirstFalse(index, flip);
				while (index != -1){
					if(flip[index]){
						index = findFirstFalse(index, flip);
					} else {
						count += 2;
						index = findFirstTrue(index, flip);
					}
				}
			} else {
				count = 1;
				index = findFirstTrue(index, flip);
				while (index != -1){
					if(flip[index]){
						index = findFirstFalse(index, flip);
					} else {
						count += 2;
						index = findFirstTrue(index, flip);
					}
				}
			}
			
			
			System.out.println (count);
			
			try {
				fw.write("Case #" + (cases - number + 1) + ": " + count + "\n");
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
	private static void flip(int index, boolean[] numbers) {
		boolean[] b = new boolean[index];
		for (int i = 0; i < index; i++){
			b[i] = !numbers[i];
		}
		for (int i = 0; i < index; i++){
			numbers[index - i - 1] = b[i];
		}
	}
	private static int findFirstFalse(int index, boolean[] numbers){
		for (int i = index; i < numbers.length; i++){
			if (!numbers[i]){
				return i;
			}
		}
		return -1;
	}
	private static int findFirstTrue(int index, boolean[] numbers){
		for (int i = index; i < numbers.length; i++){
			if (numbers[i]){
				return i;
			}
		}
		return -1;
	}
}
