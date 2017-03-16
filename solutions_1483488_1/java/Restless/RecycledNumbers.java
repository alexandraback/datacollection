/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package recyclednumbers;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author administrator
 */
public class RecycledNumbers {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String input = "c:\\input.in";
        String output = "c:\\output.txt";
        System.out.println("Hello World");
        RecycledNumbers code1 = new RecycledNumbers();
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
                int A = 0, B = 0;
                String test = scanner.nextLine();
                if (count == 0) {
                    test_case = Integer.parseInt(test);
                    count++;
                } else {
                    String[] line_data = test.split("\\s");
                    A = Integer.parseInt(line_data[0]);
                    B = Integer.parseInt(line_data[1]);
                    int result = 0;
                    if (A > B) {
                        int t = A;
                        A = B;
                        B = t;
                    }
                    for (int i = A; i < B; i++) {
                        int list[] = getCycledNumbers(i);
                        for (int j = 0; j < list.length; j++) {
                            if (list[j] > i && list[j] <= B) {
                                result++;
                            }
                        }

                    }
                    
                    System.out.println("Case #" + count + ": " + result);
                    if (count == test_case) {
                        out.print("Case #" + count + ": " + result);
                    } else {
                        out.println("Case #" + count + ": " + result);
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

    private int[] getCycledNumbers(int number) {
        int cycled[];
        int recycled[];
        String num = String.valueOf(number);
        cycled = new int[num.length()];
        for (int i = 0; i < num.length(); i++) {
            int part1 = number / (int) Math.pow(10, i);
            int part2 = number % (int) Math.pow(10, i);
            cycled[i] = part2 * (int) Math.pow(10, num.length() - i) + part1;
        }

        for (int i = 0; i < (num.length() - 1); i++) {
            for (int j = 0; j < (num.length() - (i + 1)); j++) {
                if (cycled[j] > cycled[j + 1]) {
                    int temp = cycled[j];
                    cycled[j] = cycled[j + 1];
                    cycled[j + 1] = temp;
                }
            }
        }

        int save = cycled[0];
        int final_len = num.length();
        for (int i = 1; i < (num.length()); i++) {
            if (cycled[i] == save) {
                final_len--;
            }
            save = cycled[i];
        }

        if (final_len == num.length()) {
            return cycled;
        }


        recycled = new int[final_len];
        save = recycled[0] = cycled[0];
        int ctr = 0;
        for (int i = 1; i < (num.length()); i++) {
            if (cycled[i] != save) {
                ctr++;
                recycled[ctr] = cycled[i];
            }
            save = cycled[i];
        }
        return recycled;
    }
}
