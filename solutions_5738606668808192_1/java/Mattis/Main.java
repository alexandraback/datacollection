import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {

    private static long[] divisorArrayConst = new long[11];

    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            //these variables handle input and output from plain text files
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int cases = in.nextInt();
            int N = in.nextInt();
            int J = in.nextInt();
            int[] digitArray = new int[N/2-2];
            long[] divisorArray = new long[11];

            for (int base = 2; base <= 10 ; base++) {
                divisorArrayConst[base] = power(base, N/2 - 1) + 1;
            }

            out.printf("Case #1:\n");
            for (int i = 0; i < J; i++) {
                String s = "";
                for (int j = 0; j < digitArray.length; j++) {
                    s = digitArray[j] + s;
                }
                s = "1"+s+"1";
                s = s+s;

                //calculating divisors
                updateDivisorArray(divisorArray, digitArray);


                out.print(s);
                for (int base = 2; base <= 10 ; base++) {
                    out.printf(" %d", divisorArray[base]);
                }

                boolean cont = true;
                for (int index = 0; index < digitArray.length && cont; index++) {
                    if(digitArray[index]==0){
                        digitArray[index] = 1;
                        cont = false;
                    }else{
                        digitArray[index] = 0;
                    }
                }//end for increment array

                out.println();
                out.flush();





            }//end for J


        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }//end method main

    public static long power(int base, int exponent){

        long result = 1;
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
        return result;

    }//end method power
    
    public static void updateDivisorArray(long[] divisorArray, int[] digitArray){
        long m;
        long divisor;
        for (int base = 2; base <= 10; base++) {
            m=base;
            divisor=0;
            for (int index = 0; index < digitArray.length; index++) {
                divisor += m*digitArray[index];
                m *= base;
            }
            divisorArray[base] = divisor + divisorArrayConst[base];
        }
    }

}//end class Main
