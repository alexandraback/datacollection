import java.util.*;
import java.io.*;
import java.text.*;
import java.math.*;

public class SpeakingInTongues {
    public static BufferedReader BR;
    public static Map<Character, Character> decode;

    public static String readLine() {
        try {
            return BR.readLine();
        } catch(Exception E) {
            System.err.println(E.toString());
            return null;
        }
    }


    // ****** MAIN ******

    public static void main(String [] args) throws Exception {
        BR = new BufferedReader(new InputStreamReader(System.in));

				decode = new TreeMap<Character, Character>();
				String cipher =  "zyeqejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
				String english = "qaozour language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
				Set<Character> alphabet = new TreeSet<Character>();
				for (char c = 'a'; c <= 'z'; ++c) alphabet.add(c);
				alphabet.add(' ');
				for (int i = 0; i < cipher.length(); ++i) {
					decode.put(cipher.charAt(i), english.charAt(i));
					alphabet.remove(english.charAt(i));
				}
				// System.out.println(alphabet.toString());

        int testcases = Integer.parseInt(readLine());
        for (int t = 1; t <= testcases; t++) {
            SpeakingInTongues instance = new SpeakingInTongues();
            instance.solve(t);
        }

    }

    // ****** GLOBAL VARIABLES ******
		


    public SpeakingInTongues() {
    }

    public boolean solve(int caseNumber) {
    	String cipherText = readLine();
    	StringBuilder plainText = new StringBuilder();
    	for (int i = 0; i < cipherText.length(); ++i) {
    		plainText.append(decode.get(cipherText.charAt(i)));
    	}
      System.out.println("Case #" + caseNumber + ": " + plainText.toString());
      return false;
    }


}
