package pack1;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

public class GarbledEmail {

	public static void main ( String [] arg ) throws IOException{
		Scanner s = new Scanner ( new File("input")); 
		System.setOut( new PrintStream( new File("output") ) ); 
		String [] dic = new String[521196];
		BufferedReader reader = new BufferedReader( new FileReader( new File("garbled_email_dictionary.txt") ));
		for ( int i=0; i<dic.length; i++ ){
			dic[i] = reader.readLine(); 
		}
		System.err.println( dic[ dic.length-1] );
		int cases = s.nextInt(); 
		for ( int c=1; c<=cases; c++ ){
			String str = s.next(); 
			int [][] dp = new int[str.length()+1][5];
			for ( int i=1; i<dp.length; i++ ) {
				Arrays.fill( dp[i], 1<<30 );
			}
			
			for ( int i=0; i<str.length(); i++ ){
				for ( int j=0; j<dic.length; j++ ){
					String cd = dic[j];
					if ( cd.length() <= (i+1) ){
						
						int firstMarcat = -1;
						int lastMarcat = -10; 
						int totalMatches = 0; 
						for ( int k=0; k<cd.length(); k++ ){
							int a = k;
							int b = i- cd.length() + k + 1;
							if ( cd.charAt(a) != str.charAt(b)) {
								if ( firstMarcat == -1 ) firstMarcat = k; 
								if ( k - lastMarcat >= 5 )  lastMarcat = k; else {
									lastMarcat = -2; // nu putem sa folosim sufix-ul
									break; 
								}
								totalMatches ++;
							}
						}
						if ( lastMarcat == -2 ) continue; 
						//System.err.println( i + " " + firstMarcat + " " + lastMarcat + " " + " " +totalMatches + " " + cd );
						int matches = 4; 
						if ( lastMarcat > -1 ) {
							matches = Math.min( matches, cd.length() - ( lastMarcat + 1) );
						}
						if ( firstMarcat == -1 ) firstMarcat = 20;
						int curr = i+1; 
						int back = i+1 - cd.length(); 
						for ( ; matches>=0; matches--)
						for ( int k=0; k<=4; k++ ){
							if ( k + firstMarcat >= 4 ) {
								dp[curr][matches] = Math.min( dp[curr][matches], dp[back][k] + totalMatches );
								//System.err.println( dp[curr][matches] + " " + k + " curr=" + curr+ " back="  + back );
							}
						}
						
					}
				}
			}
			int sol = 1<<30; 
			for ( int i=0; i<=4; i++ ){
				sol = Math.min( sol, dp[str.length()][i] );
			}
			
			System.err.println("Case #" + c + ": " + sol ); 
			System.out.println("Case #" + c + ": " + sol ); 
			
		}
	}
	
	
}
