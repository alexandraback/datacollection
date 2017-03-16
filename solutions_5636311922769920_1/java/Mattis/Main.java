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
            int K;
            int C;
            int S;
            for (int testCase = 1; testCase <= cases; testCase++) {
                K = in.nextInt();
                C = in.nextInt();
                S = in.nextInt();
                int check = K / C;
                if(K % C >0){
                    check++;
                }
                if(check>S){
                    out.printf("Case #%d: IMPOSSIBLE", testCase);
                }else{
                    out.printf("Case #%d:", testCase);
                    for (int i = 0; i < K; i+=C) {
                        long d = 0;
                        int numberOfDigits = ((i+C)<=K ? C : K - i);
                        for (int j = i; j < Math.min(K, i + C); j++) {
                            d += j * power(K,numberOfDigits-(j-i)-1);
                        }
                        d++;
                        out.printf(" %d",d);
                    }
                }//enf if-else check
                out.println();
                out.flush();

            }//enf for testCase


        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }//end method main

    public static long power(long base, long exponent){

        long result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;

    }//end mathod power
}//end class Main
