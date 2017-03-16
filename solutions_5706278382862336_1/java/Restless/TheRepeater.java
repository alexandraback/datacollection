package googlecodejam;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
import Round1C.Fraction;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author biman
 */
public class TheRepeater {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String input = "c:\\A-large.in";
        String output = "c:\\output.txt";
        try {
            Scanner scanner = new Scanner(new File(input), "UTF-8");
            PrintWriter out = new PrintWriter(output);
            System.out.println("Hello World");

            int T = Integer.parseInt(scanner.nextLine());
            for (int x = 0; x < T; x++) {
                //Read Data
                String fraction = scanner.nextLine();
                String farc[] = fraction.split("/");
                Fraction f = new Fraction(Long.parseLong(farc[0]), Long.parseLong(farc[1]));
                
                int Generations = 0;
                
                if (isPowerOfTwo(f.denominator)) {
                    double ratio =  (double)f.numerator / (double)f.denominator;
                    
                    while(ratio < 1.0) {
                        ratio = ratio * 2.0;
                        Generations++;
                    }
                    out.printf("Case #%d: %d\n", x + 1, Generations);
                } else {
                    out.printf("Case #%d: impossible\n", x + 1);
                }
                
                
                
                
                
            }
            out.close();
            scanner.close();

        } catch (Exception e) {

        }
    }

    private static boolean isPowerOfTwo(long num) {
        while (num > 1) {
            if (num %2 == 0)
                num = num/2;
            else
                return false;
        }
        
        return true;
    }

}
