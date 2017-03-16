import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Pancake {
	public static void main(String args[]) throws FileNotFoundException{
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(new FileInputStream(new File("src/B-large.in")))));
//		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
	    int t = in.nextInt();  // Scanner has functions to read ints, longs, strings, chars, etc.
	    in.nextLine();
	    for (int i = 1; i <= t; i++){
	    	String s = in.nextLine();
	    	System.out.println("Case #" + i + ": " +count(s));
	    }
	}
	
	public static int count(String pancake){
		char[] array = pancake.toCharArray();
		int pointer = 0;
		int res = 0;
		if (array[0] == '-'){
			res += 1;
			while( pointer < array.length && array[pointer] == '-' ){
				pointer ++;
			}
		}
		while (pointer < array.length){
			while( pointer < array.length && array[pointer] == '+' ){
				pointer ++;
			}
			if ( pointer < array.length )
				res += 2;
			while( pointer < array.length && array[pointer] == '-' ){
				pointer ++;
			}
		}
		return res;
	}
}
