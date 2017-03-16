package r1a;

import com.google.common.base.Joiner;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;

// uses Guava

public class A {

    public static void main(String[] args) throws IOException {
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("in.txt")));
//        Scanner sc = new Scanner(Files.newInputStream(Paths.get("A-small-attempt0.in")));
        Scanner sc = new Scanner(Files.newInputStream(Paths.get("A-large.in")));

        int num = sc.nextInt();
        String s = "";
        for (int i = 0; i < num; i++) {

            String word = sc.next();

            s += String.format("Case #%d: %s\n", i + 1, solve(word));
        }
        System.out.println(s);
        Files.write(Paths.get("out.txt"), s.getBytes());
    }

    private static String solve(String word) {
        char[] cnts = new char[256];
        for (int i = 0; i < word.length(); i++) {
            cnts[word.charAt(i)]++;
        }

        List<Integer> ret = new LinkedList<>();

        int[] def1 = {0, 6, 2, 4, 5, 7, 1, 9, 8, 3};
        String[][] def = {
                { "Z", "ZERO"},
                { "X", "SIX"},
                { "W", "TWO"},
                { "U", "FOUR"},
                { "F", "FIVE"},
                { "V", "SEVEN"},
                { "O", "ONE"},
                { "N", "NINE"},
                { "I", "EIGHT"},
                { "R", "THREE"},
        };

        for (int i = 0; i < def.length; i++) {
            String[] defi = def[i];

            while (cnts[defi[0].charAt(0)] > 0) {
                ret.add(def1[i]);

                String curWord = defi[1];
                for (int j = 0; j < curWord.length(); j++) {
                    cnts[curWord.charAt(j)]--;
                    if (cnts[curWord.charAt(j)] < 0) throw new AssertionError();
                }
            }
        }

        Collections.sort(ret);
        return Joiner.on("").join(ret);
    }
}
