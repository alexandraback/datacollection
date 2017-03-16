/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package dancinggooglers;

import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;

/**
 *
 * @author administrator
 */
public class DancingGooglers {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String input = "c:\\input.in";
        String output = "c:\\output.txt";
        System.out.println("Hello World");
        DancingGooglers code1 = new DancingGooglers();
        File in = new File(input);
        File out = new File(output);
        code1.processOutput(in, out, "UTF-8");
    }

    public void processOutput(File input, File output, String charSet) {
        String temp = "";
        try {
            Scanner scanner = new Scanner(input, charSet);
            PrintWriter out = new PrintWriter(output);

            int count = 0;
            int test_case = 0;

            while (scanner.hasNext()) {

                String test = scanner.nextLine();
                int noOfGooglers;
                int surprising_triplets;
                int P;
                int t[];

                int surprises_left;
                int result;

                if (count == 0) {
                    test_case = Integer.parseInt(test);
                    count++;
                } else {
                    String[] line_data = test.split("\\s");
                    noOfGooglers = Integer.parseInt(line_data[0]);
                    surprising_triplets = Integer.parseInt(line_data[1]);
                    P = Integer.parseInt(line_data[2]);
                    t = new int[noOfGooglers];

                    result = 0;
                    surprises_left = surprising_triplets;
                    for (int i = 0; i < noOfGooglers; i++) {
                        t[i] = Integer.parseInt(line_data[i + 3]);
                    }
                    for (int i = 0; i < noOfGooglers; i++) {
                        if (isTGreaterThanP(t[i], P)) {
                            result++;
                        } else {
                            if (surprises_left > 0 && isTGreaterPSurprises(t[i], P)) {
                                result++;
                                surprises_left--;
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

    private boolean isTGreaterThanP(int total, int P) {
        int max = (total + 2) / 3;

        if (max >= P) {
            return true;
        }
        return false;
    }

    private boolean isTGreaterPSurprises(int total, int P) {
        int max = (total + 4) / 3;
        if (max >= 10) {
            max = 10;
        }
        if (total == 1) {
            max = 1;
        } else if (total == 0) {
            max = 0;
        }

        if (max >= P) {
            return true;
        }
        return false;
    }
}
