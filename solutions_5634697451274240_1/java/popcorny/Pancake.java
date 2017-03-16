package idv.popcorny.jam2016;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by popcorny on 4/9/16.
 */
public class Pancake {


    private static int pancake(char[] array, int top) {

        int i=0;

//        System.out.println("[" + top + "] " + new String(array));

        for (i=top-1; i>=0; i--) {
            if(array[i] == '-') {
                break;
            }
        }

        if (i >= 0) {
            if (array[0] == '-') {
                /*  -xxxxxxxx-+++ */
                flipSwap(array, i + 1);
                return 1 + pancake(array, i+1);
            } else {
                /*  +xxxxxxxx-+++ */

                int j;
                for (j=0; j<top; j++) {
                    if(array[j] == '-') {
                        break;
                    }
                }
                flipSwap(array, j);
                return 1 + pancake(array, i+1);
            }
        } else {
            return 0;
        }

    }

    public static void flipSwap(char[] array, int pos) {
//        System.out.print("flip [" + pos + "] " + new String(array));
        char[] tmparray = new char[pos];
        for (int i = 0; i < pos; i++) {
            tmparray[i] = array[pos - i - 1] == '+' ? '-' : '+';
        }

        for (int i = 0; i < pos; i++) {
            array[i] = tmparray[i];
        }
//        System.out.println(" -> " + new String(array));
    }

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        PrintWriter writer;
        String quizname = "pancake";
        String testname = "large";
        String input   = String.format("quiz/%s/%s.in", quizname, testname);
        String output  = String.format("quiz/%s/%s.out", quizname, testname);

        if (new File(input).exists()) {
            scanner = new Scanner(new File(input));
            if (testname.equals("sample")) {
                writer = new PrintWriter(System.out);
            } else {
                writer = new PrintWriter(output);
            }
        } else {
            scanner = new Scanner(System.in);
            writer = new PrintWriter(System.out);
        }


        int t = scanner.nextInt();

        for (int i = 0; i < t; i++) {
            String string = scanner.next("[\\-\\+]+");
            char[] array = string.toCharArray();
            writer.printf("Case #%d: %s\n", i + 1, pancake(array, array.length));
        }
        writer.flush();
    }
}
