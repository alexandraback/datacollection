package round1C;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Consonants {
	static final char[] Vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
	
	
	static boolean isVowel(char character) {
	    for (char vowel : Vowels) {
	        if (vowel == character) {
	            return true;
	        }
	    }
	    return false;
	}
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner( new FileInputStream( "/home/hansen/workspace/CodeJam/src/round1C/Consonants.in" ) );
		BufferedWriter bw =  new BufferedWriter( new FileWriter( "/home/hansen/workspace/CodeJam/src/round1C/Consonants.out" ) );
		int testCases = scanner.nextInt();
		scanner.nextLine();
		for ( int cases = 0 ; cases < testCases; cases++ ){
			String test = scanner.nextLine();
			String name = test.split(" ")[0];
			boolean[] beginOk = new boolean[ name.length() ];
			Arrays.fill(beginOk, false);
			int N = Integer.parseInt( test.split(" ")[1] );
			int cont = 0;
			for (int i = name.length()-1; i >=0; i-- ) {
				if ( !isVowel ( name.charAt(i) ) ){
					cont ++;
				}
				else{
					cont = 0;
				}
				if ( cont >= N ){
					beginOk[i] = true;
				}				
			}
			long sum = 0; 
			int notPossible = - 1;
			for (int j = 0; j < beginOk.length; j++) {
				if ( beginOk[j] ){
					long left = j - notPossible;
					long right = beginOk.length - ( j + N ) + 1;					
					sum += left * right;
					notPossible = j ;
				}
			}
			bw.write( "Case #" + ( cases + 1 ) + ": " + sum ) ;
			bw.newLine();
		}
		scanner.close();
		bw.close();
	}
	
	
}
