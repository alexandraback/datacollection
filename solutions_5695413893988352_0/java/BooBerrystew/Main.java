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
	
	public static boolean template(int number, String temp) {
		String num = String.format("%0" + temp.length() + "d", number);
		//pad left side with zeros
		for(int i = 0 ; i < temp.length(); i++) {
			char c = temp.charAt(i);
			if(c != '?') {
				if(c != num.charAt(i)) {
					return false;
				}
			}
		}
		return true;
	}
	private static String solve(String str1, String str2) {
		int min = Integer.MAX_VALUE;
		int coders = Integer.MAX_VALUE;
		int jammers = Integer.MAX_VALUE;
		
		int maxNum = 0;
		
		if(str1.length() == 1)
			maxNum = 10;
		else if(str1.length() == 2)
			maxNum = 100;
		else if(str1.length() == 3)
			maxNum = 1000;
		
	    for(int i = 0; i < maxNum; i++){ //coders
	    	if(template(i, str1))
		    	for(int j = 0; j < maxNum; j++) { //jammers
		    		if(template(j, str2)) {
		    			int diff = Math.abs(i - j);
		    			if(diff < min) {
		    				min = diff;
		    				coders = i;
		    				jammers = j;
		    			} else if(diff == min) {
		    				if(coders > i) {
			    				coders = i;
			    				jammers = j;
		    				} else if(coders == i) {
		    					if(jammers > j) {
				    				coders = i;
				    				jammers = j;
		    					}
		    				}
		    			}
		    		}
		    	}
	    }
	    
	    return String.format("%0" + str1.length() + "d", coders) + " " + String.format("%0" + str1.length() + "d", jammers);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int tests = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= tests; t++) {
			String N = br.readLine().trim();
			String[] temps = N.split("\\ ");
			System.out.println("Case #" + t + ": " + solve(temps[0], temps[1]));
		}
	}
}
