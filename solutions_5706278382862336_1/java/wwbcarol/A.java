package C2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by wenbin on 11/5/14.
 */
public class A {


    static final String TYPE = "A";
    static String inputFile;
    static String outputFile;

    private static void Name(String s) {
        inputFile = s + ".in";
        outputFile = s + ".out";
    }

    private static long findGCD(long number1, long number2) {
        //base case
        if(number2 == 0){
            return number1;
        }
        return findGCD(number2, number1%number2);
    }

    public static void main(String[] args) throws FileNotFoundException {

        String root = "data/C2014";

        // Test
        Name(TYPE + "-large");
//        Name(TYPE);

        Scanner in = new Scanner(new File(root, inputFile));
        PrintWriter out = new PrintWriter(new File(root, outputFile));

        int T = in.nextInt();
        in.nextLine();

        for (int i = 0; i < T; i++) {

            String input_s = in.nextLine();
            System.out.println(i+" "+input_s);
            String[] input_array = input_s.split("/");
            long P = Long.parseLong(input_array[0], 10);
            long Q = Long.parseLong(input_array[1], 10);
            long gcd = A.findGCD(P, Q);
            P = P/gcd;
            Q = Q/gcd;

            boolean isDo = true;
            long tmp = Q;
            while(tmp>1){
                if(tmp%2==0){
                    tmp = tmp / 2;
                }else{
                    isDo = false;
                    break;
                }
            }

            if(!isDo){
                System.out.println("Case #" + (i + 1) + ": impossible");
                out.println("Case #" + (i + 1) + ": impossible");
            }else{

                int count=1;
                boolean isFound = false;
                while(count<=40){
                    if(P*2>=Q){
                        isFound = true;
                        break;
                    }else{
                        P = P * 2;
                        count++;
                    }
                }

                if(isFound){
                    System.out.println("Case #" + (i + 1) + ": " + count);
                    out.println("Case #" + (i + 1) + ": " + count);
                }else{
                    System.out.println("Case #" + (i + 1) + ": impossible");
                    out.println("Case #" + (i + 1) + ": impossible");
                }


            }

        }

        in.close();
        out.close();

    }
}
