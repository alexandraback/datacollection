package CodeJam;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class ThelastWord {

    public String getLast(String s) {
        int len = s.length();
        StringBuffer sb = new StringBuffer();
        char last = 'A';
        for (int i = 0; i < s.length();i++) {
            char c = s.charAt(i);
            if (i == 0) {
                sb.append(c);
                last = c;
            } else {
                if (c < last) {
                    sb.append(c);
                } else {
                    sb.insert(0,c);
                }
                last = sb.charAt(0);
            }
        }

        return sb.toString();
    }



    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(new File("A-large (1).in"));
        PrintWriter pw = new PrintWriter(new FileWriter("output.txt"));
        ThelastWord test = new ThelastWord();

        int n = in.nextInt();
        for (int i = 0; i < n ;i++) {
            pw.print("Case #" + (i + 1) + ": ");
            pw.println(test.getLast(in.next()));
        }
        pw.flush();
        pw.close();
        in.close();

    }
}
