import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeMap;


public class TypewriterMonkey {
	public static int[] chances = new int[26];
	public static void main(String[] args){
		File a = new File("B-small-attempt2 (1).in");
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
		int cases = number;
		
		while(number > 0){
			int k = input.nextInt();
			int l = input.nextInt();
			int s = input.nextInt();
			String keyboard = input.next();
			String target = input.next();
			
			for(int i = 0; i < chances.length; i++) {
				chances[i] = 0;
			}
			
			for(int i = 0; i < keyboard.length(); i++){
				int val = ((int)keyboard.charAt(i)) - 65;
				chances[val]++;
			}
			double result = 0;
			double max = s / l;
			if(!find_possible(target)){
				max = 0;
			}
			
			result = max - find_prob(s, keyboard, target, 0, 0, false, 0);
			
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
	
	private static boolean find_possible(String target){
		for (int i = 0; i < target.length(); i++) {
			int val = ((int)target.charAt(i)) - 65;
			if(chances[val] == 0){
				return false;
			}
		}
		return true;
	}

	private static double find_prob(int s, String keyboard, String target, int index, int multiplier, boolean streak, int offset) {
		if(streak == false){
			offset = index;
			streak = true;
		}
		
		int position = (index - offset) % target.length() ;
		int val = ((int)target.charAt(position)) - 65;
		double chance = chances[val] / (double) keyboard.length();
		
		if(index == s - 1){
			if (position == target.length() - 1){
				return chance * (multiplier + 1) + (1- chance) * (multiplier);
			} else {
			    return multiplier;
			}
		} else if((index - offset) % target.length() == target.length()-1) {
			return chance * find_prob(s, keyboard, target, index + 1, multiplier + 1, true, offset) +
					(1 - chance) * find_prob(s, keyboard, target, index + 1, multiplier, false, offset);
		} else {
			double val1 = chance * find_prob(s, keyboard, target, index + 1, multiplier, true, offset);
			double val2 = (1 - chance) * find_prob(s, keyboard, target, index + 1, multiplier, false, offset);
			return val1 + val2;
		}
	}
}
