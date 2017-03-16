package codejam.qual_2012;

import java.io.File;
import java.io.PrintStream;
import java.util.Scanner;

public class MainB {

    public static void main(String[] args) throws Exception {

        String f = "/home/floris/dev/java/Test/src/codejam/qual_2012/B-small-attempt0.in";
        Scanner sc = new Scanner(new File(f));
        System.setOut(new PrintStream(new File(f+".out")));
        int T = sc.nextInt();
        for (int i=1; T-- > 0; i++) {
            int numberOfGooglers = sc.nextInt();
            int numberOfSurprises = sc.nextInt();
            int p = sc.nextInt();
            int[] values = new int[numberOfGooglers];
            for (int j = 0; j < numberOfGooglers; j++) {
                values[j] = sc.nextInt();
            }
            
            System.out.printf("Case #%d: %d%n", i, solve(numberOfGooglers, numberOfSurprises, p, values));
        }
    }

    private static int solve(int numberOfGooglers, int numberOfSurprises, int p, int[] values) {
        int result = 0;
        for (int v : values) {
            int d = v % 3;
            if (v == 0) {
                if (p==0) result++;
            } else if (v == 1) {
                if (p<=1) result++;
            } else if (d == 0) {
                if (v/3 >= p) result++;
                else if (numberOfSurprises>0 && (v/3+1)>=p) {result++; numberOfSurprises--;}
            } else if (d==1) {
                if (v/3+1 >= p) result++;
            } else if (d==2) {
                if (v/3+1 >= p) result++;
                else if (numberOfSurprises>0 && (v/3+2)>=p) {result++; numberOfSurprises--;}
            }
        }
        return result;
    }
}
