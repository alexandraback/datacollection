import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            //these variables handle input and output from plain text files
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int cases = in.nextInt();
            String s = "";
            boolean[] signs;
            boolean firstEntry;
            int result;
            for (int testCase = 1; testCase <= cases; testCase++) {
                s = in.next();
                signs = new boolean[s.length()];
                for (int i = 0; i < s.length(); i++) {
                    signs[i] = (s.charAt(i) == '+');
                }
                result = 0;
                while(!isAllTrue(signs)){
                    firstEntry = signs[0];
                    for (int i = 0; i < signs.length && signs[i]== firstEntry; i++) {
                       signs[i] = !signs[i];
                    }
                    result++;
                }//end while

                out.printf("Case #%d: %d\n", testCase, result);
            }


        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }//end mathod main

    public static boolean isAllTrue(boolean[] bools){

        boolean result = true;
        for (int i = 0; i < bools.length && result; i++) {
            result = bools[i];
        }

        return result;
    }//end method isAllTrue
}//end class Main
