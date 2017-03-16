import java.io.*;
import java.math.*;
import java.util.*;

public class A{
	public static void main(String[] args) throws IOException{
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter writer = new PrintWriter("out.txt", "UTF-8");
		int T = Integer.parseInt(reader.readLine());
		for(int i = 1; i<=T; i++){
			String word = reader.readLine();
			System.out.println(solve(word));
			writer.println("Case #" + i + ": " + solve(word));
		}
		writer.close();
	}

	static String solve(String word){
		char[] characters = word.toCharArray();
		TreeMap<Character, Integer> charCount = new TreeMap<>();
		for(int i = 0; i<characters.length; i++){	
			if(charCount.get(characters[i]) == null){
				charCount.put(characters[i],1);
			} else {
				charCount.put(characters[i], charCount.get(characters[i])+1);
			}
		} 

		char[] allChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();
		for(int i = 0; i<26 ;i++){
			if(charCount.get(allChars[i]) == null){
				charCount.put(allChars[i],0);
			}
		}

		int[] numberOfEach = new int[10];
		

		numberOfEach[6] = charCount.get('X');
		charCount.put('X', charCount.get('X')-numberOfEach[6]);
		charCount.put('I', charCount.get('I')-numberOfEach[6]);
		charCount.put('S', charCount.get('S')-numberOfEach[6]);

		numberOfEach[4] = charCount.get('U');
		charCount.put('F', charCount.get('F')-numberOfEach[4]);
		charCount.put('O', charCount.get('O')-numberOfEach[4]);
		charCount.put('U', charCount.get('U')-numberOfEach[4]);
		charCount.put('R', charCount.get('R')-numberOfEach[4]);

		numberOfEach[8] = charCount.get('G');
		charCount.put('E', charCount.get('E')-numberOfEach[8]);
		charCount.put('I', charCount.get('I')-numberOfEach[8]);
		charCount.put('G', charCount.get('G')-numberOfEach[8]);
		charCount.put('H', charCount.get('H')-numberOfEach[8]);
		charCount.put('T', charCount.get('T')-numberOfEach[8]);

		numberOfEach[0] = charCount.get('Z');
		charCount.put('Z', charCount.get('Z')-numberOfEach[0]);
		charCount.put('E', charCount.get('E')-numberOfEach[0]);
		charCount.put('R', charCount.get('R')-numberOfEach[0]);
		charCount.put('O', charCount.get('O')-numberOfEach[0]);

		numberOfEach[2] = charCount.get('W');
		charCount.put('T', charCount.get('T')-numberOfEach[2]);
		charCount.put('W', charCount.get('W')-numberOfEach[2]);
		charCount.put('O', charCount.get('O')-numberOfEach[2]);

		numberOfEach[5] = charCount.get('F');
		charCount.put('F', charCount.get('F')-numberOfEach[5]);
		charCount.put('I', charCount.get('I')-numberOfEach[5]);
		charCount.put('V', charCount.get('V')-numberOfEach[5]);
		charCount.put('E', charCount.get('E')-numberOfEach[5]);

		numberOfEach[7] = charCount.get('V');
		charCount.put('S', charCount.get('S')-numberOfEach[7]);
		charCount.put('E', charCount.get('E')-numberOfEach[7]);
		charCount.put('V', charCount.get('V')-numberOfEach[7]);
		charCount.put('E', charCount.get('E')-numberOfEach[7]);
		charCount.put('N', charCount.get('N')-numberOfEach[7]);

		numberOfEach[9] = charCount.get('I');
		charCount.put('N', charCount.get('N')-numberOfEach[9]);
		charCount.put('I', charCount.get('I')-numberOfEach[9]);
		charCount.put('N', charCount.get('N')-numberOfEach[9]);
		charCount.put('E', charCount.get('E')-numberOfEach[9]);

		numberOfEach[1] = charCount.get('O');
		numberOfEach[3] = charCount.get('R');

		StringBuilder retString = new StringBuilder();
		for(int i = 0; i<10; i++){
			for(int j = 0; j<numberOfEach[i]; j++){
				retString.append(i);
			}
		}
		return(retString.toString());
	}


}