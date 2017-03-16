/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlerese;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author administrator
 */
public class Googlerese {

    public static String[][] code = {
        {"y", "a"},
        {"h", "b"},
        {"e", "c"},
        {"s", "d"},
        {"o", "e"},
        {"c", "f"},
        {"v", "g"},
        {"x", "h"},
        {"d", "i"},
        {"u", "j"},
        {"i", "k"},
        {"g", "l"},
        {"l", "m"},
        {"b", "n"},
        {"k", "o"},
        {"r", "p"},
        {"z", "q"},
        {"t", "r"},
        {"n", "s"},
        {"w", "t"},
        {"j", "u"},
        {"p", "v"},
        {"f", "w"},
        {"m", "x"},
        {"a", "y"},
        {"q", "z"},};

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String input = "c:\\input.in";
        String output = "c:\\output.txt";
        System.out.println("Hello World");
        Googlerese code1 = new Googlerese();
        File in = new File(input);
        File out = new File(output);
        code1.getFileContents(in, out, "UTF-8");
    }

    public void getFileContents(File input, File output, String charSet) {
        String temp = "";
        try {
            Scanner scanner = new Scanner(input, charSet);
            PrintWriter out = new PrintWriter(output);



            int count = 0;
            int test_case = 0;
            while (scanner.hasNext()) {

                String test = scanner.nextLine();
                if (count == 0) {
                    test_case = Integer.parseInt(test);
                    System.out.println(test_case);
                    count++;
                } else {
                    char dst[] = new char[test.length()];
                    test.getChars(0, test.length(), dst, 0);
                    System.out.println(test);
                    for (int i = 0; i < dst.length; i++) {
                        dst[i] = getDecoded(dst[i]);
                    }
                    test = new String(dst);
                    System.out.println("Case #" + count + ": " + test);
                    if (count == test_case) {
                        out.print("Case #" + count + ": " + test);
                    } else {
                        out.println("Case #" + count + ": " + test);
                    }
                    count++;
                }
                temp = temp + "\n" + test;
            }
            out.close();
            scanner.close();
        } catch (Exception e) {
            System.out.println("File read/write error");

            return;
        }

    }

    private char getDecoded(char c) {
        for (int i = 0; i < 26; i++) {
            if ((code[i][1].charAt(0)) == c) {
                return code[i][0].charAt(0);
            }
        }
        return c;
    }
}
