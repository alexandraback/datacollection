package GoogleR1A;

import java.util.Scanner;

/**
 * Created by Jason on 4/15/2016.
 */
public class B {

    public static void main(String args[]) {
        Scanner reader = new Scanner(System.in);
        int T = reader.nextInt();
        for (int i = 0; i < T; i++) {
            System.out.print("Case #" + (i+1) + ": ");
            int length = reader.nextInt();
            int[] countarray = new int[2501];
            for (int j = 0; j < 2500; j++) {
                countarray[j] = 0;
            }
            for (int j = 0; j < ((length * 2) - 1) * length; j++) {
                countarray[reader.nextInt()]++;
            }
            for (int j = 0; j < 2500; j++) {
                if (countarray[j] % 2 == 1) {
                    System.out.print(j + " ");
                }
            }
            System.out.println();
        }
    }
}
