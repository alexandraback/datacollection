import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.math.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashMap;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Main {
	public static String[] numbers = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}; 
	public static int[] digLengths = {4, 3, 3, 5, 4, 4, 3, 5, 5, 4};
	
    public static String solve(String N) {
    	if(N.length() <= 0)
    		return "";
    	
    	StringBuilder phonenumber = new StringBuilder();
    	
    	for(int num = 0; num < 10; num++) {
    		//Copy String
    		String Ncopy = N;
    		String temp = "";
			while(true) { //Take out all numbers
				boolean allContains = true; //Assume true
				for(char letter: numbers[num].toCharArray()) {
					if(Ncopy.indexOf(letter) == -1)
						allContains = false;
				}
				
				if(allContains) {
					//remove all letters
					for(char letter: numbers[num].toCharArray())
						Ncopy = Ncopy.replaceFirst("" + letter, "");
					temp += "" + num;
				} else 
					break;
			}
	
			String results = "";
			if(temp.length() > 0) {
				results = solve(Ncopy); //Try to solve again
				int length = 0;
				for(char digit: results.toCharArray())
					length += digLengths[Character.getNumericValue(digit)];
				
				//if result is less than original string, do not add
				if(length == Ncopy.length()) {
					phonenumber.append(temp).append(results);
					break;
				}
			}
    	}
		
    	char[] sorted = phonenumber.toString().toCharArray();
    	Arrays.sort(sorted);
		return new String(sorted);
    }
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= tests; t++) {
			String N = br.readLine().trim();
			
			System.out.println("Case #" + t + ": " + solve(N));
		}
	}
}
