package Palindromes;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;

import static java.lang.Math.*;

public class Palindromes {

	public static final String FORMAT = "Case #%d: %d\n";	

	public static int amountOfPalindromes(int[] range){
		
		// Searching through the range of roots; as this is a smaller range
		int A = (int) ceil(sqrt(range[0])),
			B = (int) floor(sqrt(range[1]));
		
		int palindromes = 0;
		for (int i = A; i <= B; i++) {
			if(isPalindrome(i) && isPalindrome(i * i)){
				palindromes++;
			}
		}
		
		return palindromes;
	}
	
	public static boolean isPalindrome(int number) {
        int palindrome = number; 
        int reverse = 0;

        while (palindrome != 0) {
            int remainder = palindrome % 10;
            reverse = reverse * 10 + remainder;
            palindrome = palindrome / 10;
        }

        if (number == reverse) {
            return true;
        }
        return false;
    }
	
	public static int[][] getProblems(String file){
		
		BufferedReader br = null;
		int[][] problems = null;
		
	    try {
			br = new BufferedReader(new FileReader(file));
	    	int t = Integer.parseInt(br.readLine());
	    	
	    	problems = new int[t][2];
		
			for (int i = 0; i < t; i++) {
				String[] range = br.readLine().split(" ");
				
				problems[i][0] = Integer.parseInt(range[0]);
				problems[i][1] = Integer.parseInt(range[1]);
			}
	    } catch (NumberFormatException | IOException e) {
			e.printStackTrace();
		} finally {
	        try {
				br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
	    }
	    
	    return problems;
	}
	
	public static void main(String[] args){
		String id = "small-attempt0";
		String dir = "palindromes";
		int[][] problems = getProblems("input/"+dir+"/C-"+id+".in");
		
		StringBuffer buf = new StringBuffer();
		for (int i = 0; i < problems.length; i++) {
			
			int outcome = amountOfPalindromes(problems[i]);
			String result = String.format(FORMAT, i+1, outcome);
			
			buf.append(result);
			System.out.print(result);			
		}
		
		try {
			PrintWriter out = new PrintWriter("output/"+dir+"/output-"+id+".txt");
			out.print(buf.toString());
			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
}
