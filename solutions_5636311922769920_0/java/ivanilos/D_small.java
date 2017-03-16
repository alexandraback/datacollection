import java.io.*;
import java.util.*;

public class D_small {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int t = in.nextInt();
        int k, c, s;

        for (int caso = 1; caso <= t; caso++) {
            k = in.nextInt();
            c = in.nextInt();
            s = in.nextInt();

            System.out.print("Case #" + caso + ":");
            for (int i = 1; i <= s; i++) {
                System.out.print(" " + i);
            }
            System.out.println();
        }
    }
}
