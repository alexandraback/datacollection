

import java.io.*;
import java.util.*;
import java.math.*;

public class Consonants {

    static Scanner in;
    static BufferedWriter out;


    public static void main(String[] args) throws IOException {
        
        in = new Scanner(new File("Consonants.in"));
        out = new BufferedWriter(new FileWriter("Consonants.out"));

        int length = in.nextInt();

        for (int test = 0; test < length; test++) {
            List<Integer> con = new ArrayList<Integer>();
            String word = in.next();
            int n = in.nextInt();
            int count;
            int values = 0;

            for (int i = 0; i < word.length() - n + 1; i++) {
                count = 0;
                for (int j = i; j < i+n; j++) {
                    //System.out.println(i + " " + word.charAt(j));
                    if (word.charAt(j) != 'a' && word.charAt(j) != 'e' && word.charAt(j) != 'i' && word.charAt(j) != 'o' && word.charAt(j) != 'u') {
                        count++;
                    }
                }
                if (count == n) {
                    con.add(i+(n-1));
                }
            }
            System.out.println(con);

            for (int i = 0; i < word.length() && con.size() > 0; i++) {
                values += word.length() - con.get(0);

                if (i+n > con.get(0)) {
                    con.remove(0);
                }
            }
            out.write("Case #" + (test + 1) + ": " + values + "\n");
        }

        in.close();
        out.close();
    }

}    