package br.com.feasoft.jam;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * User: Homer
 * Date: 4/1/12
 * Time: 9:52 PM
 */
public class Tongue {

    public static void main(String[] args) throws IOException {
        Map<Character, Character> dictionary = initDictionary();
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int numberOfCases = Integer.parseInt(reader.readLine());
        for (int i = 0; i < numberOfCases; i++) {
            String line = reader.readLine();
            System.out.printf("Case #%d: ", i + 1);
            for (int j = 0; j < line.length(); j++) {
                System.out.print(dictionary.get(line.charAt(j)));
            }
            System.out.println();
        }
    }

    private static Map<Character, Character> initDictionary() {
        Map<Character, Character> dictionary = new HashMap<Character, Character>();
        String[] googlerese = new String[4];
        String[] english= new String[4];
        
        googlerese[0] = "y qee z";
        english[0]    = "a zoo q";
        
        googlerese[1] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
        english[1]    = "our language is impossible to understand";
        
        googlerese[2] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
        english[2]    = "there are twenty six factorial possibilities";
        
        googlerese[3] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
        english[3]    = "so it is okay if you want to just give up";

        for (int i = 0; i <4; i++) {
            for (int j=0; j < googlerese[i].length(); j++) {
                dictionary.put(googlerese[i].charAt(j), english[i].charAt(j));
            }
        }
        return dictionary;
    }

}
