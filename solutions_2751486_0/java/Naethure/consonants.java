import java.util.*;
import java.io.*;

public class consonants {
	public static long totalCases = 0;
	public static long successes = 0;
	public static void main(String[] args) throws Exception{
		Scanner in = new Scanner(new File("consonants.in"));
		FileWriter fStream = new FileWriter("consonants.out");
		BufferedWriter out = new BufferedWriter(fStream);

		int numCases = in.nextInt();
		in.nextLine();

		String vowels = "aeiou";

		for(int zCase = 1; zCase <= numCases; zCase++){
			String word = in.next();
			int na = in.nextInt();
			int nVal = 0;
		//	System.out.println(word + " " + na);
			for(int n = na; n < word.length() + 1; n++){
				for(int a = 0; a < word.length() - n + 1; a++){
					String substr = word.substring(a, a + n);
				//	System.out.print("\n" + substr + ": ");
					boolean works = false;
					int count = 0;
					for(int b = 0; b < substr.length(); b++){
						if(vowels.indexOf(substr.charAt(b) + "") == -1){
						//	System.out.print("INC: " + b + " (" + substr.charAt(b) + "); ");
							count++;
						} else {
						//	System.out.print("RESET: " + b + " (" + substr.charAt(b) + "); ");
							count = 0;
						}
						if(count == na){
						//	System.out.print("WORKS");
							works = true;
							break;
						}
					}
					if(works){
						nVal++;
					}
				}
			}
			String lineOut = "Case #" + zCase + ": " + nVal;

			System.out.println(lineOut);
			out.write(lineOut + "\n");


		}
		out.close();
		fStream.close();
		in.close();
	}
}