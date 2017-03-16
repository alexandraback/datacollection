import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Scanner;

public class LastWord {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("/home/mbroshi/Downloads/A-large.in"));
        int numCases = sc.nextInt();
        StringBuffer output = new StringBuffer();
        for (int i = 1; i <= numCases; i++) {
            String word = sc.next();
            LinkedList<Character> chars = new LinkedList<>();
            chars.add(word.charAt(0));
            for (int j = 1; j < word.length(); j++) {
                Character c = word.charAt(j);
                if (c >= chars.peekFirst()) {
                    chars.addFirst(c);
                } else {
                    chars.addLast(c);
                }
            }
            output.append(String.format("Case #%d: %s\n", i, convert(chars)));
        }
        System.out.println(output);
        FileWriter fw = new FileWriter(new File("/home/mbroshi/Downloads/A-large.out"));
        BufferedWriter bw = new BufferedWriter(fw);
        bw.write(output.toString());
        bw.close();
    }

    private static String convert(LinkedList<Character> chars) {
        StringBuilder builder = new StringBuilder(chars.size());
        for (Character c : chars) {
            builder.append(c);
        }
        return builder.toString();
    }
}
