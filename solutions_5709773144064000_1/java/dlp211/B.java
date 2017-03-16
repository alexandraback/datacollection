

import java.util.*;

public class B {


    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        for (int k = 1; k <= n; ++k ) {
            double c = scanner.nextDouble();
            double f = scanner.nextDouble();
            double x = scanner.nextDouble();
            double producing = 2;

            double time = 0;


            while ( true ) {
                if ( x/producing < c/producing + x/(producing + f)  ) {
                    time += x/producing;
                    System.out.format("Case #%d: %f\n", k, time);
                    break;
                }
                else {
                    time += c/producing;
                    producing += f;
                }
            }
        }
    }
}
